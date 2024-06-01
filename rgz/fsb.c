#include "head.h"
int is_lucky_ticket(int number) {
  // Инициализация указателя number
  int number_copy = number;

  // Разложение числа на цифры
  int digits[6];
  for (int i = 0; i < 6; i++) {
    digits[i] = number_copy % 10;
    number_copy /= 10;
  }

  // Вычисление сумм первых и последних трех цифр
  int sum1 = digits[0] + digits[1] + digits[2];
  int sum2 = digits[3] + digits[4] + digits[5];

  // Проверка, является ли билет счастливым
  return sum1 == sum2;
}