#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Monte-Carlo.hpp"
#include "Draw.h"

void integral_cycle(double * S, double a, double b, double border, int num, std::string function, int count);
double higher_point(double a, double b, double e, std::string function);
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
    if (choice == 2)
        function = "0.5*(" + function + ")^2";
    std::cin >> function; // вводим функцию (в будущем она запарсится)
    if (choice == 2) {
        printf("Do it in polar coordinate system is unreal, but we can use formula f = 0.5*(f)^2\n");
        function = "0.5*(" + function + ")^2";
    }
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
    double border = higher_point(a, b, e, function); // глобальный экстремум
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
    integral_cycle(S, a, b, border, num, function, count);
    printf("Accuracy is %lf +- %lf\n", truth_value(S, count), accuracy(S, num, count));
    Draw(num, a, b, e, border, function);
    return 0;
}