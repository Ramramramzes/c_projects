#include "tests_main.h"

START_TEST(strtok_test_1) {
  char str[] = "Hello, world! This, is a test.";
  char s21_str[] = "Hello, world! This, is a test.";
  char delim[] = ",! .";
  char *token = strtok(str, delim);
  char *s21_token = s21_strtok(s21_str, delim);
  while (token != NULL) {
    ck_assert_str_eq(token, s21_token);
    token = strtok(NULL, delim);
    s21_token = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

START_TEST(strtok_test_2) {
  char str[] = "Hello, world! This, is a test.";
  char s21_str[] = "Hello, world! This, is a test.";
  char delim[] = "";
  char *token = strtok(str, delim);
  char *s21_token = s21_strtok(s21_str, delim);
  while (token != NULL) {
    ck_assert_str_eq(token, s21_token);
    token = strtok(NULL, delim);
    s21_token = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

START_TEST(strtok_test_3) {
  char str[] = "";
  char s21_str[] = "";
  char delim[] = ",! .";
  char *token = strtok(str, delim);
  char *s21_token = s21_strtok(s21_str, delim);
  while (token != NULL) {
    ck_assert_str_eq(token, s21_token);
    token = strtok(NULL, delim);
    s21_token = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

START_TEST(strtok_test_4) {
  char str[] = "";
  char s21_str[] = "";
  char delim[] = "";
  char *token = strtok(str, delim);
  char *s21_token = s21_strtok(s21_str, delim);
  while (token != NULL) {
    ck_assert_str_eq(token, s21_token);
    token = strtok(NULL, delim);
    s21_token = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

START_TEST(strtok_test_5) {
  char str[] = "Hello, world! This, is a test.";
  char s21_str[] = "Hello, world! This, is a test.";
  char delim[] = "?";
  char *token = strtok(str, delim);
  char *s21_token = s21_strtok(s21_str, delim);
  while (token != NULL) {
    ck_assert_str_eq(token, s21_token);
    token = strtok(NULL, delim);
    s21_token = s21_strtok(NULL, delim);
  }
  ck_assert_ptr_null(token);
  ck_assert_ptr_null(s21_token);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *strtok_suite = suite_create("strtok_suite");

  TCase *tc_strtok = tcase_create("strtok");

  tcase_add_test(tc_strtok, strtok_test_1);

  tcase_add_test(tc_strtok, strtok_test_2);
  tcase_add_test(tc_strtok, strtok_test_3);
  tcase_add_test(tc_strtok, strtok_test_4);
  tcase_add_test(tc_strtok, strtok_test_5);

  suite_add_tcase(strtok_suite, tc_strtok);

  return strtok_suite;
}