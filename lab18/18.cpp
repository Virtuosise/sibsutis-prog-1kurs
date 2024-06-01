// Включаем необходимые библиотеки
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include <bits/stdc++.h> 

// Определяем значение числа пи
#define pi 3.14
using namespace std;

// Определяем класс circ
class circ
{
    public:
    double r;
public:
    // Конструктор для инициализации радиуса
    circ(int rad)
    {
        r = rad;
    }

    // Функция для вычисления площади круга
    double S()
    {
        double s = pi * r * r;
        return s;
    }

    // Функция для вычисления длины окружности
    double C()
    {
        double c = 2 * pi * r;
        return c;
    }

    // Функция для получения радиуса круга
    double get_r()
    {
        return r;
    }

    // Функция для установки радиуса круга
    void set_r(double r1)
    {
        r = r1;
    }

    // Функция для вывода информации о круге (радиус, площадь, длина окружности)
    void get_inf()
    {
        cout<<"Радиус = "<<r<<endl;
        cout<<"Площадь = "<<S()<<endl;
        cout<<"Длинна = "<<C()<<endl;
    }
};

// Определяем класс cylinder, который наследуется от класса circ
class cylinder: public circ
{
    public:
    double h;

public:
    // Конструктор для инициализации радиуса и высоты цилиндра
    cylinder(double rad, double hi):circ(r)
    {
        r = rad;
        h = hi;
    }

    // Функция для получения высоты цилиндра
    double get_h()
    {
        return h;
    }

    // Функция для установки высоты цилиндра
    void set_h(double hi)
    {
        h = hi;
    }

    // Функция для вычисления объема цилиндра
    double V()
    {
        double v =  S() * h;
        return v;
    }

    // Функция для вывода информации о цилиндре (радиус, площадь, длина окружности, высота, объем)
    void get_inf()
    {
        cout<<"Радиус = "<<r<<endl;
        cout<<"Площадь = "<<S()<<endl;
        cout<<"Длинна = "<<C()<<endl;
        cout<<"Высота = "<<h<<endl;
        cout<<"Объём = "<<V()<<endl;
    }
    
};

// Функция для сравнения двух цилиндров по их высоте
bool compare_by_h(const cylinder& p1, const cylinder& p2) 
{ 
    return p1.h < p2.h ; 
} 

int main()
{
    int p;
    
    // Получаем количество цилиндров от пользователя
    cout<<"Количество элементов: ";
    cin>>p;
    
    // Создаем вектор цилиндров
    std::vector<cylinder> cyli ;
    int rr, hh;
    
    // Получаем радиус и высоту для каждого цилиндра и сохраняем его в векторе
    for(int i = 0; i < p; i++)
    {
        cout<<"Радиус: ";
        cin>>rr;
        cout<<"Высота: ";
        cin>>hh;
        cyli.push_back(cylinder(rr,hh));
    }
    
    // Выводим информацию о каждом цилиндре
    for(int i = 0; i < (int)cyli.size(); i++)
    {
        cout<<i+1<<endl;
        cyli[i].get_inf();

    }
   
    // Создаем новый вектор для хранения цилиндров с нечетным радиусом
    std::vector<cylinder> cylin;
   
    // Перебираем исходный вектор и добавляем в новый вектор цилиндры с нечетным радиусом
    for(int i = 0; i < (int)cyli.size(); i++)
    {
        if(std::fmod(cyli[i].get_r(), 2)) cylin.push_back(cyli[i]);

    }
    
    // Проверяем, пуст ли новый вектор
    int flag = 0;
    if(cylin.empty())
    {
        cout<<"Пусто"<<endl;
        flag = 1;
    }
   
    // Если новый вектор не пуст, выводим информацию о цилиндрах с нечетным радиусом и сортируем их по высоте
    if(flag == 0)
    {
        for(int i = 0; i < (int)cylin.size(); i++)
            {
                cout<<endl<<i+1<<endl;
                cylin[i].get_inf();

            }
        
        // Сортируем цилиндры по высоте с помощью функции compare_by_h
        sort(cylin.begin(), cylin.end(), compare_by_h);
        cout<<endl;
        
        // Выводим информацию о отсортированных цилиндрах
        for(int i = 0; i < (int)cylin.size(); i++)
            {
                cout<<endl<<i<<endl;
                cylin[i].get_inf();
            }
    }
   
   
   

    return 0;
}

