#include <stdio.h>
#include <stdlib.h>
double findmin(double* arr, int n, double min){ //вщзращаемое значение указатель на массив
    if(n==0){
        return min;
    }
    else{
        if (arr[n]>= 3.5 && arr [n] <=8.5){
            if (arr[n]<min){
                min=arr [n];
            }
        }
        return findmin (arr, n-1, min);//рекурсия для нахождения мин значения в массиве
        }
}
int main (){
    double min= 8.5;
    int n;
    printf("\narray size \n");
    scanf("%d",&n); //считывает значение рахмера массива, введённого пользователем
    double* arr=(double*)malloc(n*sizeof(double));//Выделение блока памяти под массив `arr` размером `n` 
    for (int i=0; i<n;i++){
        printf("enter %d array element ", i);
        scanf("%lf", &arr[i]);
    }
    for (int i=0; i<n; i++){
        printf ("%.2f ", arr[i]);
    }
    printf("\n %.1f \n", findmin(arr, n-1, min));
    free(arr);
      return 0;
}