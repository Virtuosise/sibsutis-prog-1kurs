
// Функция определения сезона
char* getSeason(int month) {
    if (month >= 3 && month <= 5) {
        return "Весна";
    } else if (month >= 6 && month <= 8) {
        return "Лето";
    } else if (month >= 9 && month <= 11) {
        return "Осень";
    } else if (month >= 12 && month <= 2) {
        return "Зима" 
    } else {
        return "Некорректный месяц" } 
}