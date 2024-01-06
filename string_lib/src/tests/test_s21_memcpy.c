#include "tests_main.h"

// Тесты для функции s21_memcpy
START_TEST(memcpy_test_1) {
  char str[10] = "Hello";
  char result[10] = {'\0'};
  char expected[10] = {'\0'};
  s21_memcpy(result, str, 5);
  memcpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memcpy_test_2) {
  char str[10] = "Hello1234";
  char result[10] = {'\0'};
  char expected[10] = {'\0'};
  s21_memcpy(result, str, 5);
  memcpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memcpy_test_3) {
  char str[10] = "";
  char result[10] = {'\0'};
  char expected[10] = {'\0'};
  s21_memcpy(result, str, 5);
  memcpy(expected, str, 5);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memcpy_test_4) {
  char str[6] = "Hello";
  char result[10] = {'\0'};
  char expected[10] = {'\0'};
  memcpy(expected, str, 6);
  s21_memcpy(result, str, 6);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(memcpy_test_5) {
  char str[10] = "Hello";
  char result[10] = {'\0'};
  char expected[10] = {'\0'};
  ck_assert_str_eq(s21_memcpy(result, str, 5), memcpy(expected, str, 5));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *memcpy_suite =
      suite_create("memcpy_suite");  // создание набора тестов "memcpy_suite"
  // Набор разбивается на тест-кейсы, разделённые по каким-либо критериям
  TCase *tc_memcpy = tcase_create("memcpy");  // создание тест-кейса "memcpy"

  tcase_add_test(tc_memcpy,
                 memcpy_test_1);  // добавление тестовой функции
                                  // memcpy_test_1 в тест-кейс "memcpy"
  tcase_add_test(tc_memcpy, memcpy_test_2);
  tcase_add_test(tc_memcpy, memcpy_test_3);
  tcase_add_test(tc_memcpy, memcpy_test_4);
  tcase_add_test(tc_memcpy, memcpy_test_5);

  suite_add_tcase(memcpy_suite,
                  tc_memcpy);  // добавление тест-кейса "memcpy" в набор тестов
                               // "memcpy_suite"

  return memcpy_suite;
}