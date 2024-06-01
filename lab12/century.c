#include "head.h"
// Функция определения века
int getCentury(int year) {
    return (year - 1) / 100 + 1;
}
