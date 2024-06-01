#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000 // Максимальная длина строки

int main() {
    char **lines; // Динамический массив для хранения строк
    int num_lines; // Количество строк
    char longest_line[MAX_LENGTH] = ""; // Самая длинная строка
    char first_word[MAX_LENGTH], last_word[MAX_LENGTH]; // Первое и последнее слово

    // Получаем количество строк от пользователя
    printf("Введите количество строк: ");
    scanf("%d", &num_lines);

    // Выделяем память для массива строк
    lines = (char **) malloc(num_lines * sizeof(char *));
    if (lines == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    // Считываем строки и сохраняем их в массиве
    for (int i = 0; i < num_lines; i++) {
        printf("Введите строку %d: ", i + 1);
        lines[i] = (char *) malloc(MAX_LENGTH * sizeof(char));
        if (lines[i] == NULL) {
            printf("Не удалось выделить память.\n");
            return 1;
        }
        scanf(" %[^\n]%*c", lines[i]); // Считываем строку с пробелами
    }

    // Находим самую длинную строку
    int max_length = 0;
    for (int i = 0; i < num_lines; i++) {
        int length = strlen(lines[i]);
        if (length > max_length) {
            max_length = length;
            strcpy(longest_line, lines[i]);
        }
    }

    // Находим первое и последнее слово в самой длинной строке
    char *token = strtok(longest_line, " \t\n");
    strcpy(first_word, token);
    while ((token = strtok(NULL, " \t\n")) != NULL) {
        strcpy(last_word, token);
    }

    // Меняем местами первое и последнее слово
    strcpy(last_word, longest_line);
    strcat(longest_line, " ");
    strcat(longest_line, first_word);

    // Освобождаем память, выделенную для строк
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    // Освобождаем память, выделенную для массива строк
    free(lines);

    printf("Программа успешно завершена.\n");

    return 0;
}
