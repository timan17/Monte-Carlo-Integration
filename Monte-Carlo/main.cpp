#include <stdio.h>
#include <stdlib.h>
#include "Monte-Carlo.hpp"

double f(double x);
// double inter(double a, double b, double bordy, int count, int n);
double inter(double a, double b, double bordy, int n);

int main() {
    int n = 0; // кол-во точек
    printf("Set count of dots ");
    scanf_s("%d", &n);
    double a = 0; // предел интегрирования слева
    printf("Set left limit of integratiom ");
    scanf_s("%lf", &a);
    double b = 0; // предел интегрирования справа
    printf("Set right limit of integration ");
    scanf_s("%lf", &b);
    double bordy = 0; // граница y
    printf("Set border y ");
    scanf_s("%lf", &bordy);
    //    ((rand() % (b - a + 1)) + 10) x in range from a to b
    // for (int i=0; i < n; ++i) {
    //     // srand((unsigned int)time(NULL));
    //     // srand((unsigned int)(time(NULL))+i);
    //     // double x = (((double)rand()/(double)(RAND_MAX)) * (b - a)) + a;
    //     // srand((unsigned int)(time(NULL))+i+b+a+bordY+rand());
    //     // double y = ((double)rand()/(double)(RAND_MAX)) * bordY;
    //     // double x = random(a, b);
    //     // double y = random(0, bordy);
    //     // if (f(x) > y)   
    //     //     count++;
    // }
    printf("Shape below graph is %lf", inter(a, b, bordy, n));
    // printf("Hello world");
    return 0;
}