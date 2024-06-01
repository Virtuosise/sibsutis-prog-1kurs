#include "head.h"
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

