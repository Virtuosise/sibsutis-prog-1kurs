#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для проверки, является ли билет счастливым
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

int main(int argc, char *argv[]) {
  // Проверка количества аргументов командной строки
  if (argc < 3) {
    printf("Недостаточно аргументов командной строки. Использование: %s <номер билета 1> <имя_файла>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Открытие текстового файла для записи
  FILE *fp = fopen(argv[argc - 1], "w");
  if (fp == NULL) {
    printf("Не удалось открыть файл %s для записи.\n", argv[argc - 1]);
    return EXIT_FAILURE;
  }

  // Обработка каждого номера билета
  for (int i = 1; i < argc - 1; i++) {
    // Преобразование аргумента командной строки в число
    int number;
    if (sscanf(argv[i], "%d", &number) != 1) {
      printf("Не удалось преобразовать аргумент %d в число.\n", i);
      fclose(fp);
      return EXIT_FAILURE;
    }

    // Проверка, является ли число шестизначным
    if (number < 100000 || number > 999999) {
      printf("Число %d не является шестизначным.\n", number);
      fclose(fp);
      return EXIT_FAILURE;
    }

    // Проверка, является ли билет счастливым
    int result = is_lucky_ticket(number);
    if (result) {
      fprintf(fp, "Билет %d счастливый.\n", number);
    } else {
      fprintf(fp, "Билет %d не счастливый.\n", number);
    }
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
/* Динамическая библиотека:
// Объектный файл с главной функцией:
gcc -c main.c
// Объектный файл для создания дин. либы:
gcc -c -fPIC func.c

// Собираем дин. библиотеку:
gcc -shared -o libMY_PRINT.so func.o

// Линковка:
gcc -o dyn_example main.o -L. -lMY_PRINT -Wl,-rpath,.

// Запуск
./dyn_example*/
