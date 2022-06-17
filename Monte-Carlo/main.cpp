#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Monte-Carlo.hpp"
#include "Draw.h"

// double f(double x, std::string function);
// double intergral(double a, double b, double bordy, int num, std::string function, int choice);
void integral_cycle(double * S, double a, double b, double border, int num, std::string function, int choice, int count);
double higher_point(double a, double b, double e, std::string function, int choice);
double accuracy(double * S, int num, int count);

int main() {
    int choice = 1;
    printf("Press 1 for cartesian coordinate system or 2 for polar coordinate system ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("EROR: you have not wrote 1 or 2");
        exit(0);
    }
    std::string function;
    printf("Write the function ");
    std::cin >> function; // запарсим функцию)
    int num = 0; // кол-во точек
    printf("Set count of dots (10^5 dots - 3 sec for each integral) ");
    scanf("%d", &num);
    double a = 0; // предел интегрирования слева
    printf("Set left limit of integration ");
    scanf("%lf", &a);
    double b = 0; // предел интегрирования справа
    printf("Set right limit of integration ");
    scanf("%lf", &b);
    double e = 0; // дискретизация
    printf("Set sampling frequency (better to use e = 0.001) ");
    scanf("%lf", &e);
    double border = higher_point(a, b, e, function, choice); // граница y compare der() and bordy!!!!
    // printf("Shape below graph is %lf\n", intergral(a, b, border, num, function, choice));
    int count = 0;
    printf("Set count of integrals ");
    scanf("%d", &count);
    printf("Are you sure to continue?\n");
    printf("Press 1 (is yes) or another number (is no)\n");
    int flag = 0;
    scanf("%d", &flag);
    if (flag != 1)
        exit(0);
    double * S = (double *)malloc(sizeof(double)*count);
    // for (int j = 0; j < count; j++ ) {
    //     S[j] = intergral(a, b, border, num, function, choice);
    //     printf("Integral is %lf\n", S[j]);
    // }
    integral_cycle(S, a, b, border, num, function, choice, count);
    printf("Accuracy is %lf +- %lf\n", truth_value(S, count), accuracy(S, num, count));
    // printf("Accuracy is %lf", accuracy());
    // printf("Hello world");
    Draw(num, a, b, e, border, function);
    return 0;
}