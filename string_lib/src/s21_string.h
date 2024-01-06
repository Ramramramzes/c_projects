#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <errno.h>
#include <limits.h>  // Для макросов INT_MAX/MIN
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_size_t unsigned long long
#define S21_NULL ((void *)0)
#define BUFF_SIZE 1024

#include "s21_data.h"
#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

//функции для реализации s21_sprintf
typedef struct {
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int width;
  int precision;
  int precision_set;
  int flags_for_size_set;
  char length;
  char spec;
} form_args;

int s21_sprintf(char *str, const char *format, ...);

const char *getting_args(const char *format, form_args *arguments);
const char *getting_precision(const char *format, form_args *arguments,
                              va_list args);
const char *getting_length(const char *format, form_args *arguments);
const char *getting_width(const char *format, form_args *arguments,
                          va_list args);

void working_with_values(char *str, form_args *arguments, va_list args);

char *parsing_decimals(char *str, form_args *arguments, va_list args);
char *parsing_octals(char *str, form_args *arguments, va_list args);
char *parsing_hex(char *str, form_args *arguments, va_list args);
char *parsing_unsigned_ints(char *str, form_args *arguments, va_list args);
void parsing_char(form_args *arguments, char *str, va_list args);
void parsing_strings(form_args *arguments, char *str, va_list args);
void parsing_floats(form_args *arguments, char *str, va_list args);
void parsing_pointers(form_args *arguments, char *str, va_list args);
void parsing_specifier_e(form_args *arguments, char *str, va_list args);
void parsing_floats_with_specifier_gG(form_args *arguments, char *str,
                                      va_list args);

void any_num_to_string(long int value, char *buff, int base);
void unsigned_num_to_string(unsigned long int value, char *buff, int base,
                            form_args *arguments);
void double_to_string(long double value, char *str, form_args *arguments);

void format_precision(char *str, form_args *arguments);
void format_parameters(char *str, form_args *arguments);
void format_char(char *str, form_args *arguments, char c);
void format_string(form_args *arguments, char *str, char *line);
void format_specifier_gG(char *str, form_args *arguments);

int int_specifier_check(char c);
void prefix_ox(char *str, form_args *arguments);
void adding_specifier_e(char *str, int powered, char sign,
                        form_args *arguments);  // mantissa
void removing_extra_zeroes(char *str);

// вспомогательные функции
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void s21_trim_left_part(const char **src, const char *trim_chars,
                        s21_size_t *src_len, const s21_size_t trim_chars_len);
void s21_trim_right_part(const char **src, const char *trim_chars,
                         s21_size_t *src_len, const s21_size_t trim_chars_len);

int s21_isdigit(char c);
int s21_atoi(const char *str);
char *s21_strcpy(char *dest, const char *src);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str, const char *charset);

#endif