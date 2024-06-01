#include <math.h>
#include <stdio.h>
#define E 0.001
float rec(int n){//Объявление функции rec с возвращаемым значением типа float и аргументом n
    float x=1;
    float result=0;
    float f=(pow(-1,(n+1)))*((pow((x-1),n))/(float)n);
    if (fabs(f)>=E){//Проверка условия: если абсолютное значение f больше или равно значению E
        result=f;
        return result+rec(n+1);//рекурсивный вызов функции rec с увеличенным параметром n и формирование суммы текущего значения f и результата рекурсивного вызова
    }
    else{
        return 0;
    }
}
int main()
{
    int n=1;
    printf("%.6f\n",rec(n));
    return 0;
}