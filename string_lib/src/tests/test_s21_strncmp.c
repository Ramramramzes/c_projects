#include "tests_main.h"

START_TEST(strncmp_test_1) {
  int result = s21_strncmp("Hello", "Hello", 5);
  int expected = strncmp("Hello", "Hello", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_2) {
  int result = s21_strncmp("Hella", "Hellb", 5);
  int expected = strncmp("Hella", "Hellb", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_3) {
  int result = s21_strncmp("Hellb", "Hella", 5);
  int expected = strncmp("Hellb", "Hella", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_4) {
  int result = s21_strncmp("Hello1234", "Hello5678", 5);
  int expected = strncmp("Hello1234", "Hello5678", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_5) {
  int result = s21_strncmp("abllo", "ballo", 5);
  int expected = strncmp("abllo", "ballo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_6) {
  int result = s21_strncmp("ballo", "abllo", 5);
  int expected = strncmp("ballo", "abllo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_7) {
  int result = s21_strncmp("balli", "abllo", 5);
  int expected = strncmp("balli", "abllo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_8) {
  int result = s21_strncmp("ballo", "bal", 5);
  int expected = strncmp("ballo", "bal", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_9) {
  int result = s21_strncmp("bal", "ballo", 5);
  int expected = strncmp("bal", "ballo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(strncmp_test_10) {
  int result = s21_strncmp("", "", 5);
  int expected = strncmp("", "", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *strncmp_suite = suite_create("strncmp_suite");

  TCase *tc_strncmp = tcase_create("strncmp");

  tcase_add_test(tc_strncmp, strncmp_test_1);

  tcase_add_test(tc_strncmp, strncmp_test_2);
  tcase_add_test(tc_strncmp, strncmp_test_3);
  tcase_add_test(tc_strncmp, strncmp_test_4);
  tcase_add_test(tc_strncmp, strncmp_test_5);
  tcase_add_test(tc_strncmp, strncmp_test_6);
  tcase_add_test(tc_strncmp, strncmp_test_7);
  tcase_add_test(tc_strncmp, strncmp_test_8);
  tcase_add_test(tc_strncmp, strncmp_test_9);
  tcase_add_test(tc_strncmp, strncmp_test_10);

  suite_add_tcase(strncmp_suite, tc_strncmp);

  return strncmp_suite;
}