#include "tests_main.h"

START_TEST(memchr_test_1) {
  void *result = s21_memchr("Hello! I'm 23456789", '!', 20);
  void *expected = memchr("Hello! I'm 23456789", '!', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(memchr_test_2) {
  void *result = s21_memchr("", 'a', 0);
  void *expected = memchr("", 'a', 0);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(memchr_test_3) {
  void *result = s21_memchr("", '!', 20);
  void *expected = memchr("", '!', 20);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(memchr_test_4) {
  void *result = s21_memchr("Hello! I'm 23456789", '9', 10);
  void *expected = memchr("Hello! I'm 23456789", '9', 10);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite *memchr_suite(void) {
  Suite *memchr_suite = suite_create("memchr_suite");

  TCase *tc_memchr = tcase_create("memchr");

  tcase_add_test(tc_memchr, memchr_test_1);

  tcase_add_test(tc_memchr, memchr_test_2);
  tcase_add_test(tc_memchr, memchr_test_3);
  tcase_add_test(tc_memchr, memchr_test_4);

  suite_add_tcase(memchr_suite, tc_memchr);

  return memchr_suite;
}