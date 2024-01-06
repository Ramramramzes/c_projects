#include "tests_main.h"

START_TEST(strncat_test_1) {
  char str[1000] = "Hello, ";
  ck_assert_str_eq(strncat(str, "world!", 7), s21_strncat(str, "world!", 7));
}
END_TEST

START_TEST(strncat_test_2) {
  char str[1000] = "Hello, ";
  ck_assert_str_eq(strncat(str, "world!", 5), s21_strncat(str, "world!", 5));
}
END_TEST

START_TEST(strncat_test_3) {
  char str[1000] = "";
  ck_assert_str_eq(strncat(str, "world!", 10), s21_strncat(str, "world!", 10));
}
END_TEST

START_TEST(strncat_test_4) {
  char str[1000] = "Hello, ";
  ck_assert_str_eq(strncat(str, "world!", 10), s21_strncat(str, "world!", 10));
}
END_TEST

START_TEST(strncat_test_5) {
  char str[1000] = "Hello, ";
  ck_assert_str_eq(strncat(str, "", 5), s21_strncat(str, "", 5));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *strncat_suite = suite_create("strncat_suite");

  TCase *tc_strncat = tcase_create("strncat");

  tcase_add_test(tc_strncat, strncat_test_1);

  tcase_add_test(tc_strncat, strncat_test_2);
  tcase_add_test(tc_strncat, strncat_test_3);
  tcase_add_test(tc_strncat, strncat_test_4);
  tcase_add_test(tc_strncat, strncat_test_5);

  suite_add_tcase(strncat_suite, tc_strncat);

  return strncat_suite;
}