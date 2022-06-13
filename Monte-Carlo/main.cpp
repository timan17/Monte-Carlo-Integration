#include <stdio.h>
#include <stdlib.h>
#include "Monte-Carlo.hpp"

double f(double x);
double intergral(double a, double b, double bordy, int num, std::string function, int choice);
double higher_point(double a, double b, double e, std::string function, int choice);

int main() {
    int choice = 1;
    printf("Press 1 for cartesian coordinate system or 2 for polar coordinate system ");
    scanf_s("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("EROR: you have not wrote 1 or 2");
        exit(0);
    }
    std::string function;
    printf("Write the function ");
    std::cin >> function; // запарсим функцию)
    int num = 0; // кол-во точек
    printf("Set count of dots ");
    scanf_s("%d", &num);
    double a = 0; // предел интегрирования слева
    printf("Set left limit of integratiom ");
    scanf_s("%lf", &a);
    double b = 0; // предел интегрирования справа
    printf("Set right limit of integration ");
    scanf_s("%lf", &b);
    double border = higher_point(a, b, 0.001, function, choice); // граница y compare der() and bordy!!!!
    printf("Shape below graph is %lf\n", intergral(a, b, border, num, function, choice));
    // printf("Accuracy is %lf", accuracy());
    // printf("Hello world");
    return 0;
}