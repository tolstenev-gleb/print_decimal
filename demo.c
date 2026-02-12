#include <limits.h>
#include <stdio.h>

#include "src/print_decimal.h"

int main() {
  s21_decimal d = {{0, 0, 0, 0}};
  char* bin_str =
      "101001110000111100111011100110001011111010011111000110001111100110";

  binstr_to_decimal(bin_str, &d);
  set_sign_decimal(&d);
  set_scale_decimal(&d, 5);

  printf("Это s21_decimal\n");
  print_decimal(d);
  printf("\n");

  printf("Это отображение s21_decimal для инициализации в коде\n");
  print_decimal_init_unsigned(d);
  printf("\n");

  printf(
      "Ниже идёт подробное побитовое отображение s21_decimal\n"
      "Строка индексов, затем значения битов по этому индексу, и представление "
      "bits в int\n"
      "Индексы старше 100, отображаются без 1\n"
      "Это значит, что 27, которое вы видете ниже, это 127\n");
  printf("\n");

  print_bit_decimal(d);

  printf(
      "Если вывод поплыл, измените размер своего терминала.\n"
      "Ширина - минимум 110 символов\n");
  return 0;
}
