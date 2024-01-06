#include "tests_main.h"

START_TEST(strchr_test_1) {
  ck_assert_str_eq(strchr("Hello, world!", 'l'),
                   s21_strchr("Hello, world!", 'l'));
}
END_TEST

START_TEST(strchr_test_2) {
  ck_assert_ptr_null(strchr("Hello, world!", 'g'));
  ck_assert_ptr_null(s21_strchr("Hello, world!", 'g'));
}
END_TEST

START_TEST(strchr_test_3) {
  ck_assert_str_eq(strchr("Hello, world!", ' '),
                   s21_strchr("Hello, world!", ' '));
}
END_TEST

START_TEST(strchr_test_4) {
  ck_assert_ptr_null(strchr("", 'l'));
  ck_assert_ptr_null(s21_strchr("", 'l'));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *strchr_suite = suite_create("strchr_suite");

  TCase *tc_strchr = tcase_create("strchr");

  tcase_add_test(tc_strchr, strchr_test_1);

  tcase_add_test(tc_strchr, strchr_test_2);
  tcase_add_test(tc_strchr, strchr_test_3);
  tcase_add_test(tc_strchr, strchr_test_4);

  suite_add_tcase(strchr_suite, tc_strchr);

  return strchr_suite;
}