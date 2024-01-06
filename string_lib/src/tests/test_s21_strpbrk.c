#include "tests_main.h"

START_TEST(strpbrk_test_1) {
  char str[] = "Hello, world! This, is a test.";
  char cmp[] = "Hello, world!";
  ck_assert_str_eq(s21_strpbrk(str, cmp), strpbrk(str, cmp));
}
END_TEST

START_TEST(strpbrk_test_2) {
  char str[] = "";
  char cmp[] = "Hello, world!";
  ck_assert_ptr_null(s21_strpbrk(str, cmp));
  ck_assert_ptr_null(strpbrk(str, cmp));
}
END_TEST

START_TEST(strpbrk_test_3) {
  char str[] = "Hello, world! This, is a test.";
  char cmp[] = "";
  ck_assert_ptr_null(s21_strpbrk(str, cmp));
  ck_assert_ptr_null(strpbrk(str, cmp));
}
END_TEST

START_TEST(strpbrk_test_4) {
  char str[] = "";
  char cmp[] = "";
  ck_assert_ptr_null(s21_strpbrk(str, cmp));
  ck_assert_ptr_null(strpbrk(str, cmp));
}
END_TEST

START_TEST(strpbrk_test_5) {
  char str[] = "Hello, world! This, is a test.";
  char cmp[] = "qzm";
  ck_assert_ptr_null(s21_strpbrk(str, cmp));
  ck_assert_ptr_null(strpbrk(str, cmp));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *strpbrk_suite = suite_create("strpbrk_suite");

  TCase *tc_strpbrk = tcase_create("strpbrk");

  tcase_add_test(tc_strpbrk, strpbrk_test_1);

  tcase_add_test(tc_strpbrk, strpbrk_test_2);
  tcase_add_test(tc_strpbrk, strpbrk_test_3);
  tcase_add_test(tc_strpbrk, strpbrk_test_4);
  tcase_add_test(tc_strpbrk, strpbrk_test_5);

  suite_add_tcase(strpbrk_suite, tc_strpbrk);

  return strpbrk_suite;
}