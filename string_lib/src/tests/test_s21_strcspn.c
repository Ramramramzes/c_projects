#include "tests_main.h"

START_TEST(strcspn_test_1) {
  char str[] = "Hello, world! This, is a test.";
  char cmp[] = "Hello, world!";
  int result = strcspn(str, cmp);
  int expected = s21_strcspn(str, cmp);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strcspn_test_2) {
  char str[] = "Hello, world! This, is a test.";
  char cmp[] = "";
  int result = strcspn(str, cmp);
  int expected = s21_strcspn(str, cmp);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strcspn_test_3) {
  char str[] = "";
  char cmp[] = "Hello, world!";
  int result = strcspn(str, cmp);
  int expected = s21_strcspn(str, cmp);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strcspn_test_4) {
  char str[] = "";
  char cmp[] = "";
  int result = strcspn(str, cmp);
  int expected = s21_strcspn(str, cmp);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strcspn_test_5) {
  char str[] = "Hello, world!";
  char cmp[] = "Hello, world! This, is a test.";
  int result = strcspn(str, cmp);
  int expected = s21_strcspn(str, cmp);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *strcspn_suite = suite_create("strcspn_suite");

  TCase *tc_strcspn = tcase_create("strcspn");

  tcase_add_test(tc_strcspn, strcspn_test_1);

  tcase_add_test(tc_strcspn, strcspn_test_2);
  tcase_add_test(tc_strcspn, strcspn_test_3);
  tcase_add_test(tc_strcspn, strcspn_test_4);
  tcase_add_test(tc_strcspn, strcspn_test_5);

  suite_add_tcase(strcspn_suite, tc_strcspn);

  return strcspn_suite;
}