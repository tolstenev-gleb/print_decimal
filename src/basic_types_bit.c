#include <stdio.h>

unsigned get_bit_int(unsigned value, unsigned index);
void print_binary_int(unsigned value);
void print_index_32(void);
void print_bit_int(unsigned value);
void print_bit_float(float value);

int main() {
  // Побитовое представление int
  print_bit_int(5);
  printf("\n");
  
  // Побитовое представление float
  print_bit_float(0.2);

}

/**
 * Проверяет бит по индексу index в переменной value типа int
 * @param value
 * @param index
 * @return 1 - бит установлен; 0 - бит не установлен
 */
unsigned get_bit_int(unsigned value, unsigned index) {
  unsigned mask = 1 << index;
  return (value & mask) != 0;
}

/**
 * Печатает содержимое переменной value в бинарном виде с пробелами
 * @param value
 */
void print_binary_int(unsigned value) {
  for (int i = 31; i >= 0; --i) {
    if (get_bit_int(value, i)) {
      printf("%s%3d%s", "\033[1;33m", 1, "\033[1;0m");
    } else {
      printf("%3d", 0);
    }
  }
}

/**
 * Печатает индексы битов для 32-битных переменных
 */
void print_index_32(void) {
  for (int i = 31; i >= 0; --i) {
    printf("|%2d", i);
  }
}

/**
 * Печатает биты, содержащиеся в переменной типа int в подробном виде
 * @param value
 */
void print_bit_int(unsigned value) {
  print_index_32();
  printf("  <- index\n");
  print_binary_int(value);
  printf("  <- bit\n");
  printf("%96d", value);
  printf("  <- value\n");
}

/**
 * Печатает биты, содержащиеся в переменной типа float в подробном виде
 * @param num
 */
void print_bit_float(float value) {
  unsigned int fbits;
  fbits = *((unsigned int *)&value);

  print_index_32();
  printf("  <- index\n");
  print_binary_int(fbits);
  printf("  <- bit\n");
  printf(
      "sign \\_________exp________/  "
      "\\_____________________________mantissa____________________________/\n");
  printf("%96f", value);
  printf("  <- value\n");
}

