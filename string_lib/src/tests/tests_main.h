#ifndef TEST_S21_MATH_H
#define TEST_S21_MATH_H

#include </opt/homebrew/Cellar/check/0.15.2/include/check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *memcpy_suite(void);
Suite *memset_suite(void);
Suite *strncat_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strncpy_suite(void);
Suite *strcspn_suite(void);
Suite *strlen_suite(void);
Suite *strpbrk_suite(void);
Suite *strstr_suite(void);
Suite *strtok_suite(void);
Suite *strrchr_suite(void);
Suite *strerror_suite(void);

Suite *sprintf_suite(void);

Suite *to_upper_suite(void);
Suite *to_lower_suite(void);
Suite *insert_suite(void);
Suite *trim_suite(void);

#endif
