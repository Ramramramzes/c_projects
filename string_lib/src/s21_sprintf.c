#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  form_args arguments = {0};
  va_list args;
  va_start(args, format);
  char *src = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&arguments, 0, sizeof(form_args));
    }
    format = getting_args(format, &arguments);
    format = getting_width(format, &arguments, args);
    format = getting_precision(format, &arguments, args);
    format = getting_length(format, &arguments);
    arguments.spec = *format;
    format++;
    char temp[BUFF_SIZE] = {'\0'};
    working_with_values(temp, &arguments, args);
    for (int i = 0; temp[i]; i++, str++) *str = temp[i];
    if (arguments.spec == 'n') {
      int *ptr = va_arg(args, int *);
      *ptr = str - src;
    }
  }
  *str = '\0';
  va_end(args);
  return (str - src);
}

const char *getting_args(const char *format, form_args *arguments) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format) {
      case '-':
        arguments->minus = 1;
        break;
      case '+':
        arguments->plus = 1;
        break;
      case ' ':
        arguments->space = 1;
        break;
      case '#':
        arguments->sharp = 1;
        break;
      case '0':
        arguments->zero = 1;
        break;
    }
    format++;
  }

  return format;
}

// получаем значние ширины строки
//переводим это значение в целочисленный формат
const char *getting_width(const char *format, form_args *arguments,
                          va_list args) {
  if (*format == '*') {
    format++;
    arguments->width = va_arg(args, int);
  } else if (s21_isdigit(*format)) {
    char str[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); format++, i++) {
      str[i] = *format;
    }
    arguments->width = s21_atoi(str);
  }
  return format;
}

// получаем значение точности
// устанавливаем флаг precision_set
// проверяем на наличие установления значения ширины строки
// переводим это значение в целочисленный формат
const char *getting_precision(const char *format, form_args *arguments,
                              va_list args) {
  if (*format == '.') {
    arguments->precision_set = 1;
    format++;
  }
  if (*format == '*') {
    format++;
    arguments->precision = va_arg(args, int);
  } else if (s21_isdigit(*format)) {
    char str[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); format++, i++) {
      str[i] = *format;
    }
    arguments->precision = s21_atoi(str);
  }
  return format;
}

// получаем значение длины строки в зависимости от спецификатора
const char *getting_length(const char *format, form_args *arguments) {
  switch (*format) {
    case 'h':
      arguments->length = 'h';  // краткое представление параметра
      format++;
      break;
    case 'l':
      arguments->length = 'l';  // лонг лонг
      format++;
      break;
    case 'L':
      arguments->length = 'L';  // лонг дабл
      format++;
      break;
  }
  return format;
}

// обработка всех парсеров
void working_with_values(char *str, form_args *arguments, va_list args) {
  if (arguments->spec == 'd' || arguments->spec == 'i') {
    parsing_decimals(str, arguments, args);
  } else if (arguments->spec == 'u') {
    parsing_unsigned_ints(str, arguments, args);
  } else if (arguments->spec == 'o') {
    parsing_octals(str, arguments, args);
  } else if (arguments->spec == 'x' || arguments->spec == 'X') {
    parsing_hex(str, arguments, args);
  } else if (arguments->spec == '%') {
    str[0] = '%';
  } else if (arguments->spec == 'c') {
    parsing_char(arguments, str, args);
  } else if (arguments->spec == 's') {
    parsing_strings(arguments, str, args);
  } else if (arguments->spec == 'p') {
    parsing_pointers(arguments, str, args);
  } else if (arguments->spec == 'f') {
    parsing_floats(arguments, str, args);
  } else if (arguments->spec == 'e' || arguments->spec == 'E') {
    parsing_specifier_e(arguments, str, args);
  } else if (arguments->spec == 'g' || arguments->spec == 'G') {
    parsing_floats_with_specifier_gG(arguments, str, args);
  }
}

// парсинг по интовым значениям в 10 системе исчисления
char *parsing_decimals(char *str, form_args *arguments, va_list args) {
  long long int num = va_arg(args, long long int);
  if (arguments->length == 'l') {
    num = (long int)num;
  } else if (arguments->length == 'h') {
    num = (short int)num;
  } else {
    num = (int)num;
  }
  any_num_to_string(num, str, 10);
  format_precision(str, arguments);
  format_parameters(str, arguments);
  return 0;
}

// парсинг по интовым значениям в 16 системе исчисления
//для 16 системы исчисления добавляем prefix_0x при условии наличия в
//обрабатываемой строке символа #
char *parsing_hex(char *str, form_args *arguments, va_list args) {
  int flag = 0;
  unsigned long int num = va_arg(args, unsigned long int);
  if (arguments->length == 'l') {
    num = (unsigned long int)num;
  } else if (arguments->length == 'h') {
    num = (unsigned short int)num;
  } else {
    num = (unsigned int)num;
  }
  unsigned_num_to_string(num, str, 16, arguments);
  if (s21_strncmp(str, "0", s21_strlen(str)) == 0)
    flag = 1;  // проверка на 0, крайний случай
  format_precision(str, arguments);
  if (arguments->sharp && !flag) {
    prefix_ox(str, arguments);
  }
  format_parameters(str, arguments);
  return 0;
}

// парсинг по интовым значениям в 8 системе исчисления
char *parsing_octals(char *str, form_args *arguments, va_list args) {
  str[0] = '0';  // добавляем 0 для корректного отображения чисел в 8 системе
  any_num_to_string(va_arg(args, long int), str + arguments->sharp, 8);
  format_precision(str, arguments);
  format_parameters(str, arguments);
  return 0;
}

// парсинг по большим интовым значениям в 10 системе исчисления
char *parsing_unsigned_ints(char *str, form_args *arguments, va_list args) {
  unsigned long long int num = va_arg(args, unsigned long long int);
  if (arguments->length == 'l') {
    num = (unsigned long int)num;
  } else if (arguments->length == 'h') {
    num = (unsigned short int)num;
  } else {
    num = (unsigned int)num;
  }

  unsigned_num_to_string(num, str, 10, arguments);
  format_precision(str, arguments);
  format_parameters(str, arguments);
  return 0;
}

// парсинг по символам
void parsing_char(form_args *arguments, char *str, va_list args) {
  char c = va_arg(args, int);
  format_char(str, arguments, c);
}

// парсинг по строкам
void parsing_strings(form_args *arguments, char *str, va_list args) {
  char *line = va_arg(args, char *);
  format_string(arguments, str, line);
}

// парсинг по флотам в зависимости от спецификатора
// настройка точности флота по умолчанию на 6 символов после запятой
void parsing_floats(form_args *arguments, char *str, va_list args) {
  long double num = 0;
  if (arguments->length == 'L') {
    num = va_arg(args, long double);
  } else {
    num = va_arg(args, double);
  }
  if (!arguments->precision_set) {
    arguments->precision = 6;
  }
  double_to_string(num, str, arguments);
  format_parameters(str, arguments);
}

// парсинг по указателям
void parsing_pointers(form_args *arguments, char *str, va_list args) {
  unsigned_num_to_string(va_arg(args, unsigned long int), str, 16, arguments);
  format_precision(str, arguments);
  prefix_ox(str, arguments);
  format_parameters(str, arguments);
}

// парсинг по мантиссе
void parsing_specifier_e(form_args *arguments, char *str, va_list args) {
  long double value = 0;
  if (arguments->length == 'L') {
    value = va_arg(args, long double);
  } else {
    value = va_arg(args, double);
  }
  int pow_of_exp = 0;  // степень экспоненты
  char sign;
  if ((int)value == 0) {
    sign = '-';  // если значение равно нулю, то экспонента отрицательна
  } else {
    sign = '+';  // иначе положительна
  }
  if ((int)value - value) {  // если есть дробная часть
    while ((int)value == 0) {
      pow_of_exp++;
      value *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)value / 10 != 0) {
    pow_of_exp++;
    value /= 10;
  }
  if (!arguments->precision_set) {  // устанавливаем дефолтную точность
    arguments->precision = 6;
  }
  double_to_string(value, str, arguments);
  adding_specifier_e(str, pow_of_exp, sign, arguments);
  format_parameters(str, arguments);
}

// парсинг по флотам с применением спецификатора g
// кратчайшее представление 10 числа (до 2 знаков после запятой)
void parsing_floats_with_specifier_gG(form_args *arguments, char *str,
                                      va_list args) {
  long double value = 0;
  if (arguments->length == 'L') {
    value = va_arg(args, long double);
  } else {
    value = va_arg(args, double);
  }
  long double new_value = value;
  int pow_of_exp = 0;
  if ((int)value - value) {  // если есть дробная часть
    while ((int)new_value == 0) {
      pow_of_exp++;
      new_value *= 10;
    }
  }
  if (pow_of_exp > 4) {  // если значение больше 4 знаков после запятой
    arguments->precision = 0;
    double_to_string(new_value, str, arguments);
  } else {
    if (!arguments->precision_set) arguments->precision = 6;
    if (arguments->precision == 0) {
      int prec = 0;
      long double mantissa =
          fmodl(value, 1.0);  // остаток отделения возвращается в формате флота
      while ((int)mantissa == 0) {
        mantissa *= 10;
        prec++;
      }
      arguments->precision = prec;
    }
    double_to_string(value, str, arguments);
  }
  format_specifier_gG(str, arguments);
  if (pow_of_exp > 4) adding_specifier_e(str, pow_of_exp, '-', arguments);
  removing_extra_zeroes(str);
  format_parameters(str, arguments);
}

//перевод числа любого ОПРЕДЕЛЕННОГО типа в строку, согласно основанию системы
//исчисления
// записываем число в буфер в обратном порядке
void any_num_to_string(long int value, char *buff, int base) {
  char temp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int negative = value < 0 ? 1 : 0;  // проверка на отрицательность
  value = negative ? -value : value;
  if (value == 0) temp[index] = '0';
  while (value > 0) {
    index--;
    temp[index] = "0123456789abcdef"[value % base];
    value /= base;
  }
  for (int i = 0; temp[index]; index++, i++) {
    if (negative && i == 0) {
      buff[i++] = '-';
    }
    buff[i] = temp[index];
  }
}

// перевод числа НЕОПРЕДЕЛЕННОГО типа в строку, согласно основанию системы
// исчисления
void unsigned_num_to_string(unsigned long int value, char *buff, int base,
                            form_args *arguments) {
  char temp[BUFF_SIZE + 1] = {'\0'};
  int index = BUFF_SIZE - 2;
  if (value == 0) {
    temp[index] = '0';
    index--;
  }
  for (; value && index; index--, value /= base) {
    if (arguments->spec == 'X')
      temp[index] = "0123456789ABCDEF"[value % base];
    else
      temp[index] = "0123456789abcdef"[value % base];
    if (temp[index] == 'e' && arguments->spec == 'X') temp[index] = 'E';
  }
  for (int i = 0; temp[index + 1]; index++, i++) {
    buff[i] = temp[index + 1];
  }
}

// перевод дробного числа в строку
// записываем дробную часть в буфер в обратном порядке
void double_to_string(long double value, char *str, form_args *arguments) {
  char temp[BUFF_SIZE] = {'\0'};
  int index = BUFF_SIZE - 2;
  int negative = value < 0 ? 1 : 0;  // проверка на отрицательность
  value = negative ? -value : value;
  long double int_part = (int)value,
              float_part = modfl(
                  value, &int_part);  // делим число на целую и дробную части
  if (arguments->precision == 0) {
    int_part =
        roundl(value);  // float_part дробная часть значения, int_part целая
    float_part = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < arguments->precision; i++) {
    float_part = float_part * 10;
    fractions[i] = (int)float_part + '0';
  }
  unsigned long long right = roundl(float_part), left = int_part;
  if (!right) {
    for (int i = 0; i < arguments->precision; index--, i++) {
      temp[index] = '0';
    }
  } else {
    for (int i = s21_strlen(fractions); right || i > 0;
         right /= 10, index--, i--) {
      temp[index] = (int)(right % 10) + '0';
    }
  }
  if ((arguments->precision_set && arguments->precision != 0) ||
      (int)float_part || (!arguments->precision_set && value == 0) ||
      s21_strlen(fractions)) {
    temp[index--] = '.';
  }
  if (!left) {
    temp[index--] = '0';  // возможна ошибка
  } else {
    for (; left; left /= 10, index--) {
      temp[index] = (int)(left % 10) + '0';
    }
  }
  for (int i = 0; temp[index + 1]; index++, i++) {
    if (negative && i == 0) {
      str[i++] = '-';
    }
    str[i] = temp[index + 1];
  }
}

// форматирование точности
void format_precision(char *str, form_args *arguments) {
  char temp[BUFF_SIZE] = {'\0'};
  int sign = 0;
  int length = s21_strlen(str);
  // проверка числа на отрицательность
  if (str[0] == '-') {
    temp[0] = '-';
    length--;
    sign = 1;
  }
  //добавление нулей в начало строки, если заданная точность больше длины строки
  if (arguments->precision > length) {
    int index;
    for (index = sign; index < arguments->precision - length + sign; index++) {
      temp[index] = '0';
    }
    for (int i = sign; str[i]; i++, index++) {
      temp[index] = str[i];
    }
    s21_strcpy(str, temp);
  }
  if (arguments->precision_set && arguments->precision == 0 &&
      int_specifier_check(arguments->spec) &&
      str[0] == '0') {  // если точность задана и равна нулю, целое число и его
                        // первый элемент равен 0
    str[0] = '\0';
  }
}

// форматирование параметров
void format_parameters(char *str, form_args *arguments) {
  char temp[BUFF_SIZE + 1] = {'\0'};
  if (arguments->plus && arguments->spec != 'u') {
    if (str[0] == '-') {
      temp[0] = str[0];
      s21_strcpy(temp + 1, str + 1);
    } else {
      temp[0] = '+';
      s21_strcpy(temp + 1, str);
    }
    s21_strcpy(str, temp);
  } else if (arguments->space && str[0] != '-' && arguments->spec != 'u') {
    temp[0] = ' ';
    s21_strcpy(temp + 1, str);
    s21_strcpy(str, temp);
  }
  if (arguments->width >
      (int)s21_strlen(str)) {  // работа с выравниванием по ширине строки
    int index = arguments->width - s21_strlen(str);
    if (!arguments->minus) {
      if (arguments->zero) {
        s21_memset(temp, '0',
                   index);  // если +0 то выравнивание вправо с нулями
      } else {
        s21_memset(temp, ' ', index);  // иначе выравнивание вправо пробелами
      }
      s21_strcpy(temp + index, str);
    } else {
      s21_strcpy(temp, str);
      s21_memset(temp + s21_strlen(str), ' ', index);
    }
    s21_strcpy(str, temp);
  }
}

// форматирование символов
void format_char(char *str, form_args *arguments, char c) {
  if (arguments->width && !arguments->minus) {
    int i = 0;
    while (i < arguments->width) {  // заполнение строки пробелами по ширине
      if (i == arguments->width - 1) {
        str[i] = c;
        break;
      }
      str[i] = ' ';
      i++;
    }
  } else if (arguments->width) {
    str[0] = c;
    int i = 1;
    while (i < arguments->width) {
      str[i] = ' ';
      i++;
    }
  } else {
    str[0] = c;
  }
}

// форматирование строк
void format_string(form_args *arguments, char *str, char *line) {
  char temp[BUFF_SIZE] = {'\0'};
  s21_strcpy(temp, line);
  if (arguments->precision_set) {  // регулируем длину строки по точности
    temp[arguments->precision] = '\0';
  }
  int length = s21_strlen(temp);
  int difference = arguments->width - length;
  if (difference < 0) {
    difference = 0;
  }
  if (arguments->minus && difference > 0) {  // добавление пробелов
    s21_strcpy(str, temp);
    s21_memset(str + length, ' ', difference);
  } else if (difference > 0) {
    s21_memset(str, ' ', difference);
    s21_strcpy(str + difference, temp);
  } else {
    s21_strcpy(str, temp);
  }
}

// форматирование по спецификатору G (краткое представление дробной части)
void format_specifier_gG(char *str, form_args *arguments) {
  int significant_digits = 0;
  s21_size_t len = s21_strlen(str);
  int non_zero_counter = 0;
  for (s21_size_t i = 0; i < len; i++) {
    if ((str[i] == '0' && !non_zero_counter) || str[i] == '.')
      continue;
    else
      non_zero_counter = 1;

    if (s21_isdigit(str[i]) && non_zero_counter) {
      significant_digits++;
    }

    if (significant_digits == arguments->precision && i + 1 < len) {
      int next = str[i + 1] == '.' ? 2 : 1;  // определяем шаг вперед по строке
      str[i] = str[i + next] - '0' > 5 ? (char)(str[i] + 1) : str[i];
      str[i + 1] = '\0';
      break;
    }
  }
}
// проверка на спецификатор для работы с целыми числами
int int_specifier_check(char c) {
  char specifiers[] = {'d', 'i', 'o', 'u', 'x', 'X'};
  int res = 0;
  for (s21_size_t i = 0; i < sizeof(specifiers); i++) {
    if (c == specifiers[i]) {
      res = 1;
      break;
    }
  }
  return res;
}

// префикс 0x для 16 системы исчисления и указателей
void prefix_ox(char *str, form_args *arguments) {
  if (s21_strlen(str) == 0 || (s21_strncmp(str, "0", s21_strlen(str)) == 0)) {
    str[0] = '0';
    str[1] = 'x';
    str[2] = '0';
  } else if (str[0] == '0' && s21_strlen(str) == 1) {
    str[0] = '0';
  } else if ((str[0] != '\0' &&
              (arguments->spec == 'x' || arguments->spec == 'X' ||
               arguments->spec == 'o' || arguments->spec == 'p'))) {
    s21_memmove(str + 2, str, s21_strlen(str));
    str[0] = '0';
    if (arguments->spec == 'X')
      str[1] = 'X';
    else
      str[1] = 'x';
  }
}

// добавление спецификатора E
void adding_specifier_e(char *str, int pow_of_exp, char sign,
                        form_args *arguments) {
  int length = s21_strlen(str);
  if (arguments->spec == 'E' || arguments->spec == 'G')
    str[length] = 'E';
  else
    str[length] = 'e';
  str[length + 1] = sign;
  str[length + 3] = pow_of_exp % 10 + '0';
  pow_of_exp /= 10;
  str[length + 2] = pow_of_exp % 10 + '0';
  str[length + 4] = '\0';
}

// удалание лишних нулей
void removing_extra_zeroes(char *str) {
  int len = s21_strlen(str);
  char *dot = s21_strchr(str, '.');
  if (dot) {
    for (int i = len - 1; str[i] != '.'; i--) {
      if (str[i] == '0')
        str[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0')
      dot[0] = '\0';  // проверка на ноль символ после мантиссы
  }
}