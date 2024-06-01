#include <stdio.h>
#include <string.h>

// Структура для хранения информации о маршруте
struct Route {
    char start_point[50];    // Начальный пункт
    char end_point[50];      // Конечный пункт
    int route_number;       // Номер маршрута
};

int main() {
    FILE *file;             // Указатель на файл
    struct Route route;      // Структура для хранения маршрута
    char search_point[50];  // Пункт для поиска
    int found = 0;          // Флаг, указывающий, найден ли маршрут

    // Открываем файл для записи
    file = fopen("Spravka.dat", "wb");
    if (file == NULL) {
        printf("Ошибка при создании файла.n");
        return 1;
    }

    // Записываем данные о маршрутах в файл
    struct Route routes[] = {
        {"Moscov", "NSK", 1},  
        {"NSK", "Kazan", 2},    
        {"Moscov", "Kazan", 3} 
    };

    fwrite(routes, sizeof(struct Route), 3, file);  // Записываем массив структур в файл
    fclose(file);                                  // Закрываем файл

    // Открываем файл для чтения
    file = fopen("Spravka.dat", "rb");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    // Вводим пункт для поиска
    printf("Введите название пункта маршрута: ");
    scanf("%s", search_point);

    // Ищем маршруты, начинающиеся или заканчивающиеся в заданном пункте
    while (fread(&route, sizeof(struct Route), 1, file) == 1) {
        // Сравниваем начальный и конечный пункты маршрута с заданным пунктом
        if (strcmp(route.start_point, search_point) == 0 || strcmp(route.end_point, search_point) == 0) {
            // Если пункт найден, выводим информацию о маршруте
            printf("Маршрут %d: %s - %s\n", route.route_number, route.start_point, route.end_point);
            found = 1;  // Устанавливаем флаг, что маршрут найден
        }
    }

    if (found == 0) {
        printf("Маршрутов с указанным пунктом не найдено.\n");
    }

    fclose(file);  // Закрываем файл

    return 0;
}
