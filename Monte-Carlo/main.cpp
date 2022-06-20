#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Monte-Carlo.hpp"
#include "Draw.h"

void integral_cycle(double * S, double a, double b, double c, double d, double minus_border, double border, int num, std::string function, int count);
void integral_block(double a, double b, double e, std::string function, double &minus_border, double &border, int num, int count, double &truth, double &accur);
void higher_lower_point(double a, double b, double e, std::string function, double &ymax, double &ymin);
void higher_lower__point_x_and_minus_border(double a, double b, double e, std::string function, double &xmax, double &xmin, double &c, double &d);
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
    double e = 0.001; // дискретизация
    printf("Set sampling frequency (better to use e = 0.001) ");
    scanf("%lf", &e);
    int count = 0;
    printf("Set count of integrals ");
    scanf("%d", &count);
    printf("Are you sure to continue?\n");
    printf("Press 1 (is yes) or another number (is no)\n");
    int flag = 0;
    scanf("%d", &flag);
    if (flag != 1)
        exit(0);
    double c = 0;
    double d = 0;
    double xmin = 0;
    double xmax = 0;
    double border = 0;
    double minus_border = 0;
    double truth = 0;
    double accur = 0;
    // double upperBorder = highest_point(a, b, e, function); // глобальный максимум
    // higher_lower_point(a, b, e, function, border, minus_border);
    // double lowerBorder = lowest_point(a, b, e, function); // глобальный минимум
    // higher_lower_point(a, b, e, function, border, minus_border);
    // higher_lower__point_x_and_minus_border(a, b, e, function, xmax, xmin, c, d);
    // double * S = (double *)malloc(sizeof(double)*count);
    // printf("3*sin(x)-sin(x)-1\n");
    // integral_cycle(S, a, b, c, d, minus_border, border, num, function, count);
    integral_block(a, b, e, function, minus_border, border, num, count, truth, accur);
    printf("\nResult:  %lf +- %lf\n", truth, accur);
    printf("Absolute error:  %lf\n", accur);
    printf("Relative error:  %lf%%\n\n", accur/abs(truth)*100);
    Draw(num, a, b, e, minus_border, border, function);
    return 0;
}