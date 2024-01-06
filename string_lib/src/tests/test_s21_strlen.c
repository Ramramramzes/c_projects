#include "tests_main.h"

START_TEST(strlen_test_1) {
  char str[100] = "Hello, world!";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_2) {
  char str[100] = "123456789";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_3) {
  char str[100] = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_4) {
  char str[100] = "     ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_test_5) {
  char str[100] = "Hello, world! This, is a test.";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *strlen_suite = suite_create("strlen_suite");

  TCase *tc_strlen = tcase_create("strlen");

  tcase_add_test(tc_strlen, strlen_test_1);

  tcase_add_test(tc_strlen, strlen_test_2);
  tcase_add_test(tc_strlen, strlen_test_3);
  tcase_add_test(tc_strlen, strlen_test_4);
  tcase_add_test(tc_strlen, strlen_test_5);

  suite_add_tcase(strlen_suite, tc_strlen);

  return strlen_suite;
}