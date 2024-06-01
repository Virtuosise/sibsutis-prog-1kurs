#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Открыть текстовый файл "do.txt" для чтения
    FILE *fp = fopen("do.txt", "r");
    if (fp == NULL) {
        printf("Не удалось открыть файл input.txt\n");
        return EXIT_FAILURE;
    }

    // Получить размер файла
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Выделить память для хранения текста из файла
    char *text = malloc(fsize + 1);
    if (text == NULL) {
        printf("Не удалось выделить память для текста\n");
        return EXIT_FAILURE;
    }

    // Считать текст из файла
    fread(text, fsize, 1, fp);
    text[fsize] = '\0';

    // Выделить память для нового текста с точками
    char *new_text = malloc(2 * strlen(text) + 1);
    if (new_text == NULL) {
        printf("Не удалось выделить память для нового текста\n");
        return EXIT_FAILURE;
    }

    // Переменные для индексов
    int i = 0;  // Индекс для исходного текста
    int j = 0;  // Индекс для нового текста

    // Пройти по исходному тексту
    while (text[i] != '\0') {
        // Скопировать символ из исходного текста в новый текст
        new_text[j++] = text[i++];

        if (text[i] == ' ' || text[i] == '\n') {
            new_text[j++] = '.';
        }
    }

    // Добавить завершающий символ в новый текст
    new_text[j] = '\0';

    // Освободить исходный текст
    free(text);

    // Открыть текстовый файл "ps.txt" для записи
    fp = fopen("ps.txt", "w");
    if (fp == NULL) {
        printf("Не удалось открыть файл output.txt\n");
        return EXIT_FAILURE;
    }

    // Записать новый текст в файл
    fprintf(fp, "%s", new_text);

    // Закрыть файлы
    fclose(fp);

    // Освободить новый текст
    free(new_text);

    return EXIT_SUCCESS;
}

