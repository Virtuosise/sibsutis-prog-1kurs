#include "head.h"
// Функция определения декады
char* getDecade(int day) {
    int decade = (day - 1) / 10+1;
    switch (decade) {
        case 0: case 1:
            return "Первой декаде";
        case 2: case 3:
            return "Второй декаде";
        case 4: case 5:
            return "Третьей декаде";
        
        default:
            return "Некорректный день";
    }
}