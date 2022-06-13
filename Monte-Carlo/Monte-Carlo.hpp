#include <math.h>
#include <random>
#include <stdlib.h>
#include <iostream>
#include "../parser/fparser.hh"
#define PI 3.14

double f(double x, std::string function) {
    FunctionParser fparser;
    fparser.Parse(function, "x");
    return fparser.Eval(&x);
}

double random(double a, double b) {
    std::random_device radm;
    std::mt19937_64 mt(radm());
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(mt);
}

double intergral(double a, double b, double border, int num, std::string function, int choice) {
    int count = 0; // счётчик точек под графиком функции
    if (choice == 2) {
        function = "(1/2)*(" + function + ")^2";
    }
    for (int i = 0; i < num; i++) {
        double x = random(a, b);
        double y = random(0, border);
        if (f(x, function) > y) {
            count++;
        }
    }
    return ((double)count*(double)(b-a)*(double)border)/(double)num;
}

double higher_point(double a, double b, double e, std::string function, int choice) {
    e = 0.001;
    // double v[2] = {0, 0};
    // double h = 0;
    double g = 0;
    if (choice == 2) {
        function = "(1/2)*(" + function + ")^2";
    }
    for (double i = a; i < b; i += e) {
        // v[0] = v[1];
        // double u = f(i, function);
        g = std::max(g, f(i, function));
        // v[1] = (f(i+e, function)-u)/e;
        // if (v[1] <= 0 && v[0] > 0){
        //     h = std::max(h, u);
        // }
    }
    return g;
}

double truth_value(double * S, int num) {
    double result = 0;
    for (int i = 0; i < num; i++) {
        result += S[i];
    }
    return result / num;
}

double summ_of_delta_x(double * S, int num) {
    double result = 0;
    double truth_x = truth_value(S, num);
    for (int i = 0; i < num; i++) {
        result = pow((S[i]-truth_x), 2);
    }
    return result;
}

double accuracy(double * S, int num) { // Оценка погрешности
    return sqrt(summ_of_delta_x(S, num)/((num-1)*num));
}