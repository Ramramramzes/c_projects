#include "tests_main.h"

START_TEST(strstr_test_1) {
  char str[] = "Hello, world! This, is a test.";
  char needle[] = "!";
  ck_assert_str_eq(s21_strstr(str, needle), strstr(str, needle));
}
END_TEST

START_TEST(strstr_test_2) {
  char str[] = "Hello, world! This, is a test.";
  char needle[] = "";
  ck_assert_str_eq(s21_strstr(str, needle), strstr(str, needle));
}
END_TEST

START_TEST(strstr_test_3) {
  char str[] = "";
  char needle[] = "!";
  ck_assert_ptr_null(s21_strstr(str, needle));
  ck_assert_ptr_null(strstr(str, needle));
}
END_TEST

START_TEST(strstr_test_4) {
  char str[] = "";
  char needle[] = "";
  ck_assert_str_eq(s21_strstr(str, needle), strstr(str, needle));
}
END_TEST

START_TEST(strstr_test_5) {
  char str[] = "!";
  char needle[] = "Hello, world! This, is a test.";
  ck_assert_ptr_null(s21_strstr(str, needle));
  ck_assert_ptr_null(strstr(str, needle));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *strstr_suite = suite_create("strstr_suite");

  TCase *tc_strstr = tcase_create("strstr");

  tcase_add_test(tc_strstr, strstr_test_1);

  tcase_add_test(tc_strstr, strstr_test_2);
  tcase_add_test(tc_strstr, strstr_test_3);
  tcase_add_test(tc_strstr, strstr_test_4);
  tcase_add_test(tc_strstr, strstr_test_5);

  suite_add_tcase(strstr_suite, tc_strstr);

  return strstr_suite;
}