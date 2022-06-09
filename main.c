#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

double func(int x) {
    return 2*x; // функция, например y = x^2
}
int main() {
    setlocale(LC_ALL, "Russian");
    int count = 0; // счётчик точек под графиком функции
    double s = 0; // площадь под графиком функции
    int n = 100; // кол-во точек
    printf("Задайте колв-о точек ");
    scanf_s("%d", &n);
    double a = 10; // предел интегрирования слева
    printf("Задайте левый предел интегрирования ");
    scanf_s("%lf", &a);
    double b = 15; // предел интегрирования справа
    printf("Задайте правый предел интегрирования ");
    scanf_s("%lf", &b);
    double bordY = 0; // граница y
    printf("Задайте граничный y ");
    scanf_s("%lf", &bordY);
    //    ((rand() % (b - a + 1)) + 10) x in range from a to b
    for (int i=0; i < n; ++i) {
        // srand((unsigned int)time(NULL));
        srand((unsigned int)(time(NULL))+i);
        double x = (((double)rand()/(double)(RAND_MAX)) * (b - a)) + a;
        srand((unsigned int)(time(NULL))+i+b+a+bordY+rand());
        double y = ((double)rand()/(double)(RAND_MAX)) * bordY;
        if (func(x) > y)   
            count++;
    }
    s = (double)count/(double)n;
    printf("Площадь под графиком функции: %lf", s);
    // printf("Hello world");
    return 0;
}