#include "tests_main.h"

START_TEST(strncpy_test_1) {
  char str[10] = "Hello";
  char result[10];
  char expected[10];
  s21_strncpy(result, str, 5);
  strncpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_test_2) {
  char str[10] = "Hello12345";
  char result[10];
  char expected[10];
  s21_strncpy(result, str, 5);
  strncpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_test_3) {
  char str[10] = "";
  char result[10];
  char expected[10];
  s21_strncpy(result, str, 5);
  strncpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_test_4) {
  char str[6] = "Hello";
  char result[10];
  char expected[10];
  strncpy(expected, str, 6);
  s21_strncpy(result, str, 6);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(strncpy_test_5) {
  char str[10] = "Hello";
  char result[10];
  char expected[10];
  ck_assert_str_eq(s21_strncpy(result, str, 5), strncpy(expected, str, 5));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *strncpy_suite = suite_create("strncpy_suite");

  TCase *tc_strncpy = tcase_create("strncpy");

  tcase_add_test(tc_strncpy, strncpy_test_1);

  tcase_add_test(tc_strncpy, strncpy_test_2);
  tcase_add_test(tc_strncpy, strncpy_test_3);
  tcase_add_test(tc_strncpy, strncpy_test_4);
  tcase_add_test(tc_strncpy, strncpy_test_5);

  suite_add_tcase(strncpy_suite, tc_strncpy);

  return strncpy_suite;
}