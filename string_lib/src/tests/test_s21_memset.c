#include "tests_main.h"

START_TEST(memset_test_1) {
  char result[100] = "Hello";
  char expected[100] = "Hello";
  ck_assert_ptr_eq(s21_memset(expected, '!', 5), memset(expected, '!', 5));
  s21_memset(result, '!', 5);
  memset(expected, '!', 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memset_test_2) {
  char result[100] = "";
  char expected[100] = "";
  ck_assert_ptr_eq(s21_memset(expected, '1', 10), memset(expected, '1', 10));
  s21_memset(result, '1', 10);
  memset(expected, '1', 10);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memset_test_3) {
  char result[100] = "Hello";
  char expected[100] = "Hello";

  ck_assert_ptr_eq(s21_memset(expected, ' ', 5), memset(expected, ' ', 5));
  s21_memset(result, ' ', 5);
  memset(expected, ' ', 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memset_test_4) {
  char result[100] = "Hello";
  char expected[100] = "Hello";

  ck_assert_ptr_eq(s21_memset(expected, 'e', 1), memset(expected, 'e', 1));
  s21_memset(result, 'e', 1);
  memset(expected, 'e', 1);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memset_test_5) {
  char result[100] = "Hello";
  char expected[100] = "Hello";
  ck_assert_ptr_eq(s21_memset(expected, 2, 2), memset(expected, 2, 2));
  s21_memset(result, 2, 2);
  memset(expected, 2, 2);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memset_test_6) {
  char result[10] = "Hello";
  char expected[10] = "Hello";
  char replace = '\0';
  ck_assert_ptr_eq(memset(expected, replace, 10),
                   s21_memset(expected, replace, 10));
  s21_memset(result, replace, 10);
  memset(expected, replace, 10);
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *memset_suite(void) {
  Suite *memset_suite = suite_create("memset_suite");

  TCase *tc_memset = tcase_create("memset");

  tcase_add_test(tc_memset, memset_test_1);
  tcase_add_test(tc_memset, memset_test_2);
  tcase_add_test(tc_memset, memset_test_3);
  tcase_add_test(tc_memset, memset_test_4);
  tcase_add_test(tc_memset, memset_test_5);
  tcase_add_test(tc_memset, memset_test_6);

  suite_add_tcase(memset_suite, tc_memset);

  return memset_suite;
}