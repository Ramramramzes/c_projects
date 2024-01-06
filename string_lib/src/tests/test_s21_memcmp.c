#include "tests_main.h"

START_TEST(memcmp_test_1) {
  int result = s21_memcmp("Hello", "Hello", 5);
  int expected = memcmp("Hello", "Hello", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_2) {
  int result = s21_memcmp("Hella", "Hellb", 5);
  int expected = memcmp("Hella", "Hellb", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_3) {
  int result = s21_memcmp("Hellb", "Hella", 5);
  int expected = memcmp("Hellb", "Hella", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_4) {
  int result = s21_memcmp("Hello1234", "Hello5678", 5);
  int expected = memcmp("Hello1234", "Hello5678", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_5) {
  int result = s21_memcmp("abllo", "ballo", 5);
  int expected = memcmp("abllo", "ballo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_6) {
  int result = s21_memcmp("ballo", "abllo", 5);
  int expected = memcmp("ballo", "abllo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_7) {
  int result = s21_memcmp("balli", "abllo", 5);
  int expected = memcmp("balli", "abllo", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(memcmp_test_8) {
  int result = s21_memcmp("ballo", "bal", 5);
  int expected = memcmp("ballo", "bal", 5);
  ck_assert_int_eq(result > 0, expected > 0);
}
END_TEST

START_TEST(memcmp_test_9) {
  int result = s21_memcmp("bal", "ballo", 5);
  int expected = memcmp("bal", "ballo", 5);
  ck_assert_int_eq(result < 0, expected < 0);
}
END_TEST

START_TEST(memcmp_test_10) {
  int result = s21_memcmp("", "", 5);
  int expected = memcmp("", "", 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *memcmp_suite = suite_create("memcmp_suite");

  TCase *tc_memcmp = tcase_create("memcmp");

  tcase_add_test(tc_memcmp, memcmp_test_1);

  tcase_add_test(tc_memcmp, memcmp_test_2);
  tcase_add_test(tc_memcmp, memcmp_test_3);
  tcase_add_test(tc_memcmp, memcmp_test_4);
  tcase_add_test(tc_memcmp, memcmp_test_5);
  tcase_add_test(tc_memcmp, memcmp_test_6);
  tcase_add_test(tc_memcmp, memcmp_test_7);
  tcase_add_test(tc_memcmp, memcmp_test_8);
  tcase_add_test(tc_memcmp, memcmp_test_9);
  tcase_add_test(tc_memcmp, memcmp_test_10);

  suite_add_tcase(memcmp_suite, tc_memcmp);

  return memcmp_suite;
}