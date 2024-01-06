#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *line = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (line[i] == c) {
      return &line[i];
    }
  }
  return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int counter = 0;
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (s1[i] > s2[i]) {
      if (s1[i] != '\0' && s2[i] != '\0')
        counter++;
      else
        counter += s1[i];
    } else if (s1[i] < s2[i]) {
      if (s1[i] != '\0' && s2[i] != '\0')
        counter--;
      else
        counter -= s2[i];
    }
    if (counter != 0) {
      break;
    }
  }
  return counter;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((char *)dest + i) = *((char *)src + i);
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *ptr = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *line = dest;
  s21_size_t length = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++) {
    *(char *)(line + length + i) = *(char *)(src + i);
  }
  *(char *)(line + length + n) = '\0';
  return line;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t counter = 0;
  while (str[counter] != '\0') {
    counter++;
  }
  return counter;
}

char *s21_strchr(const char *str, int c) {
  char *line = (char *)str;
  for (s21_size_t i = 0; i <= s21_strlen(line); i++) {
    if (line[i] == c) {
      return &line[i];
    }
  }
  return S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int counter = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*(str1 + i) > *(str2 + i)) {
      if (s21_strlen(str1) != s21_strlen(str2)) {
        counter += *((char *)str1 + i);
      } else
        counter++;
    } else if (*(str1 + i) < *(str2 + i)) {
      if (s21_strlen(str1) != s21_strlen(str2)) {
        counter -= *((char *)str2 + i);
      } else
        counter--;
    }
    if (counter != 0) {
      break;
    }
  }
  return counter;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(dest + i) = *(src + i);
  }
  *(dest + n) = '\0';
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int counter = 0;
  int flag = 0;
  for (s21_size_t i = 0; str1[i] != '\0'; i++) {
    if (flag) {
      break;
    }
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) counter++;
  }
  return counter;
}

char *s21_strerror(int errnum) {
  static char answer[500];
  if (errnum < 0 || errnum > S21_ERRLIST_SIZE - 1) {
    s21_strncpy(answer, ERROR, 500);
    s21_sprintf(answer, S21_ERRORS, answer, errnum);
  } else {
    s21_strncpy(answer, (char *)s21_sys_errlist[errnum], 500);
  }
  return answer;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  for (; *str1 != '\0'; str1++) {
    for (const char *substring = str2; *substring != '\0'; substring++) {
      if (*str1 == *substring) {
        return (char *)str1;
      }
    }
  }
  return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *line = (char *)str;
  int n = s21_strlen(line) + 1;
  for (int i = n; i >= 0; i--)
    if (line[i] == c) {
      return &line[i];
    }

  return S21_NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int not_found = 0;
  if (*needle == '\0') return (char *)haystack;
  for (char *substring = (char *)haystack; *substring != '\0'; substring++) {
    if (*substring == *needle) {
      char *substring_copy = (char *)substring;
      while (*needle != '\0' && !not_found) {
        if (*substring_copy != *needle) {
          not_found = 1;
        } else {
          substring_copy++;
          needle++;
        }
      }
      if (!not_found) return (char *)substring;
    }
  }
  return S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *token = NULL;
  if (str != NULL) token = str;
  if (token == NULL || *token == '\0') return S21_NULL;

  while (*token != '\0' && s21_strchr(delim, *token) != S21_NULL) token++;

  if (*token == '\0') return S21_NULL;
  char *start = token;

  while (*token != '\0' && s21_strchr(delim, *token) == S21_NULL) token++;

  if (*token != '\0') {
    *token = '\0';
    token++;
  }

  return start;
}

// вспомогательные функции
int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

int s21_atoi(const char *str) {
  long long res = 0;
  int sign = 1;
  while (*str == ' ') str++;
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }
  while (s21_isdigit(*str)) {
    res = res * 10 + (*str - '0');
    str++;
  }
  if (res > INT_MAX) {
    res = INT_MAX;
  } else if (res < INT_MIN) {
    res = INT_MIN;
  } else {
    res *= sign;
  }
  return (int)res;
}

char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }

  dest[s21_strlen(src)] = '\0';

  return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *to = (char *)dest;
  char *from = (char *)src;

  char *tmp = (char *)malloc(sizeof(char) * n);

  if (tmp) {
    s21_memcpy(tmp, from, n);
    s21_memcpy(to, tmp, n);
    free(tmp);
  }
  return dest;
}

// бонусные функции
void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  char *res = calloc(s21_strlen(str) + 1, sizeof(char));
  if (res) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        res[i] = str[i] - 32;
      } else {
        res[i] = str[i];
      }
    }
    res[s21_strlen(str)] = '\0';
  }
  return (void *)res;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  char *res = calloc(s21_strlen(str) + 1, sizeof(char));
  if (res) {
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        res[i] = str[i] + 32;
      } else {
        res[i] = str[i];
      }
    }
    res[s21_strlen(str)] = '\0';
  }
  return (void *)res;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *new_str = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    size_t src_len = s21_strlen(src);
    size_t str_len = s21_strlen(str);
    size_t new_len = src_len + str_len + 1;

    // Выделяем память для новой строки
    new_str = (char *)malloc(new_len);

    if (new_str) {
      for (s21_size_t i = 0, j = 0, m = 0; i < new_len; i++) {
        if (i < start_index || !str[m])
          new_str[i] = src[j++];
        else
          new_str[i] = str[m++];
      }
      new_str[new_len] = '\0';
    }
  } else if (str == S21_NULL && src != S21_NULL) {
    new_str = calloc(s21_strlen(src) + 1, sizeof(char));
    s21_strcpy(new_str, src);
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = S21_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      s21_size_t src_len = s21_strlen(src);
      s21_size_t trim_chars_len = s21_strlen(trim_chars);
      s21_trim_left_part(&src, trim_chars, &src_len, trim_chars_len);
      if (src_len)
        s21_trim_right_part(&src, trim_chars, &src_len, trim_chars_len);

      new_str = (char *)malloc(sizeof(char) * (src_len + 1));

      if (new_str) {
        for (s21_size_t i = 0; i < src_len + 1; i++) {
          if (i < src_len) {
            new_str[i] = src[i];
          } else {
            new_str[i] = '\0';
          }
        }
      }
    } else {
      new_str = s21_trim(src, " \t\n");
    }
  }
  return new_str;
}

void s21_trim_left_part(const char **src, const char *trim_chars,
                        s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;
  while (src && m != trim_chars_len) {
    if ((**src) == trim_chars[m]) {
      (*src)++;
      (*src_len) -= 1;
      m = 0;
      continue;
    }
    m++;
  }
}

void s21_trim_right_part(const char **src, const char *trim_chars,
                         s21_size_t *src_len, const s21_size_t trim_chars_len) {
  s21_size_t m = 0;
  s21_size_t i = (*src_len) - 1;

  while (src && m != trim_chars_len) {
    if ((*src)[i] == trim_chars[m]) {
      i--;
      (*src_len)--;
      m = 0;
      continue;
    }
    m++;
  }
}