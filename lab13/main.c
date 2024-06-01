
int main() {
    int n;
    printf("Введите количество людей: ");
    scanf("%d", &n);

    struct Date people[n];

    for (int i = 0; i < n; ++i) {
        printf("Введите день, месяц и год рождения для человека %d: ", i + 1);
        scanf("%d %d %d", &people[i].day, &people[i].month, &people[i].year);

        printf("Человек родился в %s, в сезоне %s, в %d веке.\n", getDecade(people[i].day), getSeason(people[i].month), getCentury(people[i].year));
    }

    return 0;
}