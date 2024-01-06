// #include <assert.h>
#include <string.h>

#include "s21_string.h"

// void test_format_precision() {
//     char str[BUFF_SIZE] = "12345";
//     form_args arguments;
//     arguments.precision = 8;
//     format_precision(str, &arguments);
//     // Ожидаемый результат: "00012345"
//     assert(strcmp(str, "00012345") == 0);

//     strcpy(str, "-9876");
//     arguments.precision = 6;
//     format_precision(str, &arguments);
//     // Ожидаемый результат: "-009876"
//     assert(strcmp(str, "-009876") == 0);

//     strcpy(str, "0");
//     arguments.precision = 3;
//     format_precision(str, &arguments);
//     // Ожидаемый результат: "000"
//     assert(strcmp(str, "000") == 0);

//     strcpy(str, "123");
//     arguments.precision = 2;
//     format_precision(str, &arguments);
//     // Ожидаемый результат: "123"
//     assert(strcmp(str, "123") == 0);
// }

// void test_format_parameters() {
//     char str[BUFF_SIZE] = "12345";
//     form_args arguments;
//     arguments.plus = 1;
//     format_parameters(str, &arguments);
//     // Ожидаемый результат: "+12345"
//     assert(strcmp(str, "+12345") == 0);

//     strcpy(str, "9876");
//     arguments.plus = 0;
//     arguments.space = 1;
//     format_parameters(str, &arguments);
//     // Ожидаемый результат: " 9876"
//     assert(strcmp(str, " 9876") == 0);

//     strcpy(str, "123");
//     arguments.width = 8;
//     arguments.minus = 0;
//     format_parameters(str, &arguments);
//     // Ожидаемый результат: "     123"
//     assert(strcmp(str, "     123") == 0);

//     strcpy(str, "123");
//     arguments.width = 8;
//     arguments.minus = 1;
//     format_parameters(str, &arguments);
//     // Ожидаемый результат: "123     "
//     assert(strcmp(str, "123     ") == 0);
// }

// void test_int_specifier_check() {
//     assert(int_specifier_check('d') == 1);
//     assert(int_specifier_check('i') == 1);
//     assert(int_specifier_check('o') == 1);
//     assert(int_specifier_check('u') == 1);
//     assert(int_specifier_check('x') == 1);
//     assert(int_specifier_check('X') == 1);
//     assert(int_specifier_check('c') == 0);
//     assert(int_specifier_check('f') == 0);
// }

int main() {
  // printf("%p\n", memchr("Hello! I'm 23456789", '!', 20));
  // printf("%p\n", s21_memchr("Hello! I'm 23456789", '!', 20));

  // printf("%d\n", memcmp("ballo", "balla", 20));
  // printf("%d\n", s21_memcmp("ballo", "balla", 20));
  // printf("%c - %d\n%c - %d\n", 'o', 'o', 'a', 'a');

  // char str1[10] = "Hello";
  // char str2[10];
  // char str3[10];
  // char str4[20] = "351352431352345678";
  // char cmp[10] = "H3";
  // memcpy(str2, str1, 5);
  // s21_memcpy(str3, str1, 5);
  // if (str3 == str1) {
  //     printf("yes\n");
  // } else printf("no\n");
  // printf("%s\n%s\n", str2, str3);
  // s21_strpbrk(str4, cmp);
  // strpbrk(str4, cmp);
  // // s21_memcpy(str3, c, 10);
  // printf("%s\n", str4);
  // printf("%s\n", cmp);

  // memset(str1, '!', 10);
  // s21_memset(str4, '!', 10);
  // printf("%s\n", str1);
  // printf("%s\n", str4);

  // printf("%s\n", strncat("ERROR,", "Hello", 4));
  // printf("%s\n", s21_strncat("ERROR,", "Hello", 4));

  // printf("%d\n", strlen(str1));
  // printf("%d\n", s21_strlen(str1));

  // printf("%s\n%s\n", strchr(str2, 'l'),
  //                s21_strchr(str2, 'l'));

  // printf("%d\n", strncmp("223456799", "223456789", 5));
  // printf("%d\n", s21_strncmp("223456799", "223456789", 5));

  // strncpy(str2, str1, 5);
  // s21_strncpy(str3, str1, 5);
  // printf("%s\n", str2);
  // printf("%s\n", str3);

  // printf("%d\n", strcspn(str1, cmp));
  // printf("%d\n", s21_strcspn(str1, cmp));

  // printf ("%s\n", strpbrk(str3, cmp));
  // printf ("%s\n", strstr(str4, "q"));
  // printf ("%s\n", s21_strstr(str4, "135"));
  // char *line2 = s21_strrchr(str4, '5');
  // printf("%s", strtok(str4, "3"));
  // char str[] = "Hello, world! This, is a test.";
  // const char delimiters[] = ",! .";  // разделители - пробел, запятая, точка,
  // восклицательный знак

  // char *token = strtok(str, delimiters);
  // while (token != NULL) {
  //     printf("%s\n", token);
  //     token = strtok(NULL, delimiters);
  // }
  // printf("Now, with my strtok\n");
  // char *s21_token = s21_strtok(str, delimiters);

  // while (s21_token != NULL) {
  //     printf("%s\n", s21_token);
  //     s21_token = s21_strtok(NULL, delimiters);
  // }
  // printf ("%s\n", line);
  // printf ("%s\n", s21_strrchr(str4, 'q'));

  //   printf("%s\n", strerror(-2));
  //   printf("%s\n", s21_strerror(-2));

  // printf("%s\n", strstr("Hello, world!", "llo"));
  // printf("%s\n", s21_strstr("Hello, world!", "llo"));

  //     char str[10] = "Hello";
  //     char result[10];
  //     char expected[10];
  //     s21_memcpy(result, str, 10);

  //   memcpy(expected, str, 10);
  //   printf("%s\n", result);
  //   printf("%s", expected);

  // TEST sprintf
  // char str[1000];
  // char s21_str[1000];
  // sprintf(str, "%s %d %s %f", "Hello", 5, "world", 3.14);
  // printf("%s\n", str);
  // s21_sprintf(s21_str, "%s %d %s %f", "Hello", 5, "world", 3.14);
  // printf("%s\n", s21_str);

  // Проверка работы s21_atoi
  // char str1[] = " -asas 12345";
  // char str2[] = "-98765";
  // char str3[] = "+42";
  // char str4[] = " 123abc";

  // int expected_result1 = atoi(str1);
  // int expected_result2 = atoi(str2);
  // int expected_result3 = atoi(str3);
  // int expected_result4 = atoi(str4);

  // int your_result1 = s21_atoi(str1);
  // int your_result2 = s21_atoi(str2);
  // int your_result3 = s21_atoi(str3);
  // int your_result4 = s21_atoi(str4);

  // printf("Результаты сравнения:\n");
  // printf("str1: Ожидаемый результат: %d, Ваш результат: %d\n",
  // expected_result1, your_result1); printf("str2: Ожидаемый результат: %d, Ваш
  // результат: %d\n", expected_result2, your_result2); printf("str3: Ожидаемый
  // результат: %d, Ваш результат: %d\n", expected_result3, your_result3);
  // printf("str4: Ожидаемый результат: %d, Ваш результат: %d\n",
  // expected_result4, your_result4);

  // form_args args = { 5, 3, 1, 0, 0, 0, 2, 1, 0, 0, 0 };
  // long int num = 12345.145;
  // s21_size_t result = getting_length_of_decimals(&args, num);
  // printf("Result: %llu\n", result);

  // test_format_precision();
  // test_format_parameters();
  // test_int_specifier_check();

  // printf("All tests passed successfully.\n");
  // char str1[] = "Hella";
  // char str2[] = "Halle";

  // int result = s21_memcmp(str1, str2, sizeof(str1));

  // if (result == 0) {
  //     printf("Строки равны\n %d\n", result);
  // } else {
  //     printf("Строки отличаются\n %d\n", result);
  // }

  //  int value = 255;
  // char buffer[10];

  // sprintf(buffer, "%#X", value);

  // printf("Formatted value: %s\n", buffer);

  // char word_s21[BUFF_SIZE];
  // char word_std[BUFF_SIZE];
  // char *format = "This is a simple value %d";
  // int val = 69;

  // int result_s21 = s21_sscanf(word_s21, "%s%d", format, val);
  // int result_std = sscanf(word_std, "%s%d", format, val);

  // printf("Результат вызова s21_sscanf: %d\n", result_s21);
  // printf("Результат вызова sscanf: %d\n", result_std);

  // printf("Считанное слово с помощью s21_sscanf: %s\n", word_s21);
  // printf("Считанное слово с помощью sscanf: %s\n", word_std);

  // char str1[BUFF_SIZE];
  // char str2[BUFF_SIZE];
  // int a = s21_sprintf(
  //     str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3,
  //     126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  // int b = sprintf(
  //     str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3,
  //     126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);

  // char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  // long double k = 333.33213;

  // char format[] = "%g";
  // double hex = 1.000005;
  // int a = s21_sprintf(str1, format, hex);
  // int b = sprintf(str2, format, hex);

  // printf("Our results:      %d and string %s\n", a, str1);
  // printf("Standard results: %d and string %s\n", b, str2);

  // any_num_to_string(123456789987654321, str1, 10);
  // printf("%s\n", str1);
  // for (int i = -1; i<108;i++){
  //   // printf("%d %s\n",i, strerror(i));
  //   // printf("%d %s\n",i, s21_strerror(i));
  //   if (strcmp(strerror(i), s21_strerror(i)) != 0) {
  //     printf("i = %d Error: %s != %s\n", i, strerror(i), s21_strerror(i));
  //   }
  //   // assert(strerror(i) == s21_strerror(i));
  // }
  // char *str = "";
  // char sym = 'i';
  // char *res_str = strrchr(str, sym);
  // char *s21_str = s21_strrchr(str, sym);
  // printf("%s\n", res_str);
  // printf("%p\n", res_str);
  // printf("%s\n", s21_str);
  // printf("%p\n", s21_str);
  return 0;
}
