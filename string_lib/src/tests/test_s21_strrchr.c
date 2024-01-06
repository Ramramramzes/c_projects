#include "tests_main.h"

START_TEST(strrchr_test_1) {
  ck_assert_str_eq(strrchr("Hello, world!", 'l'),
                   s21_strrchr("Hello, world!", 'l'));
}
END_TEST

START_TEST(strrchr_test_2) {
  ck_assert_ptr_null(strrchr("Hello, world!", 'g'));
  ck_assert_ptr_null(s21_strrchr("Hello, world!", 'g'));
}
END_TEST

START_TEST(strrchr_test_3) {
  ck_assert_str_eq(strrchr("Hello, world!", ' '),
                   s21_strrchr("Hello, world!", ' '));
}
END_TEST

START_TEST(strrchr_test_4) {
  ck_assert_ptr_null(strrchr("", 'l'));
  ck_assert_ptr_null(s21_strrchr("", 'l'));
}

Suite *strrchr_suite(void) {
  Suite *strrchr_suite = suite_create("strrchr_suite");

  TCase *tc_strrchr = tcase_create("strrchr");

  tcase_add_test(tc_strrchr, strrchr_test_1);

  tcase_add_test(tc_strrchr, strrchr_test_2);
  tcase_add_test(tc_strrchr, strrchr_test_3);
  tcase_add_test(tc_strrchr, strrchr_test_4);

  suite_add_tcase(strrchr_suite, tc_strrchr);

  return strrchr_suite;
}