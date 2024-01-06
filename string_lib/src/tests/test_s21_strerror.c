#include "tests_main.h"

START_TEST(strerror_test_1) { ck_assert_str_eq(strerror(0), s21_strerror(0)); }
END_TEST

START_TEST(strerror_test_2) { ck_assert_str_eq(strerror(5), s21_strerror(5)); }
END_TEST

START_TEST(strerror_test_3) {
  ck_assert_str_eq(strerror(123), s21_strerror(123));
}
END_TEST

START_TEST(strerror_test_4) {
  ck_assert_str_eq(strerror(10), s21_strerror(10));
}
END_TEST

START_TEST(strerror_test_5) {
  ck_assert_str_eq(strerror(110), s21_strerror(110));
}
END_TEST

Suite *strerror_suite(void) {
  Suite *strerror_suite = suite_create("strerror_suite");

  TCase *tc_strerror = tcase_create("strerror");

  tcase_add_test(tc_strerror, strerror_test_1);

  tcase_add_test(tc_strerror, strerror_test_2);
  tcase_add_test(tc_strerror, strerror_test_3);
  tcase_add_test(tc_strerror, strerror_test_4);
  tcase_add_test(tc_strerror, strerror_test_5);

  suite_add_tcase(strerror_suite, tc_strerror);

  return strerror_suite;
}