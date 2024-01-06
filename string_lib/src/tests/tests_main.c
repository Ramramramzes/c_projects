#include "tests_main.h"

int main() {
  int failed_cnt;
  Suite *s1 = memchr_suite();  // создание набора тестов
  Suite *s2 = memcmp_suite();
  Suite *s3 = memcpy_suite();
  Suite *s4 = memset_suite();
  Suite *s5 = strncat_suite();
  Suite *s6 = strchr_suite();
  Suite *s7 = strncmp_suite();
  Suite *s8 = strncpy_suite();
  Suite *s9 = strcspn_suite();
  Suite *s10 = strlen_suite();
  Suite *s11 = strpbrk_suite();
  Suite *s12 = strstr_suite();
  Suite *s13 = strtok_suite();
  Suite *s14 = strrchr_suite();
  Suite *s15 = strerror_suite();
  Suite *s16 = sprintf_suite();
  Suite *s17 = to_upper_suite();
  Suite *s18 = to_lower_suite();
  Suite *s19 = insert_suite();
  Suite *s20 = trim_suite();
  SRunner *sr;  // Объект для запуска тестов

  sr = srunner_create(NULL);  // создание объекта для запуска тестов
  Suite *arr[] = {
      s1,  s2,  s3,  s4,  s5,  s6,  s7,  s8,  s9,  s10,
      s11, s12, s13, s14, s15, s16, s17, s18, s19, s20};  // массив Suit'ов
  for (int i = 0; i < 20; i++) {
    srunner_add_suite(sr, arr[i]);  // добавление i-го Suite в объект SRunner
  }

  srunner_run_all(
      sr,
      CK_NORMAL);  // запуск всех тестов из объекта sr со стандартным выводом
  failed_cnt =
      srunner_ntests_failed(sr);  // получение количества неудачных тестов

  srunner_free(sr);  // освобождение памяти, занятой объектом sr

  return (failed_cnt == 0) ? EXIT_SUCCESS
                           : EXIT_FAILURE;  // возврат значения в зависимости
                                            // от количества неудачных тестов
}
