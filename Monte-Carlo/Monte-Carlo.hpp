#pragma once

#include <math.h>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../parser/fparser.hh"
#define PI 3.1415926535897932

double f(double x, std::string function) {
    FunctionParser fparser;
    fparser.AddConstant("pi", 3.1415926535897932);
    fparser.AddConstant("e", 2.7182818284590452);
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
        function = "0.5*(" + function + ")^2";
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
    double g = 0;
    if (choice == 2) {
        function = "0.5*(" + function + ")^2";
    }
    for (double i = a; i < b; i += e) {
        g = std::max(g, f(i, function));
    }
    return g;
}

double truth_value(double * S, int count) {
    double result = 0;
    for (int i = 0; i < count; i++) {
        result += S[i];
    }
    return result / (double)count;
}

double summ_of_delta_x(double * S, int count) {
    double result = 0;
    double truth_x = truth_value(S, count);
    for (int i = 0; i < count; i++) {
        result += pow((S[i]-truth_x), 2);
    }
    return result;
}

double getRatio(int num) {
    FILE * fp;
    double ratio = 0;
    int n = 0;
    double ratio1 = 0;
    int n1 = 0;
    fp = fopen("../../Monte-Carlo/ratios_of_Student.txt", "r");
    do {
        n1 = n;
        ratio1 = ratio;
        fscanf(fp, "%d",&n);
        fscanf(fp, "%lf",&ratio);
    } while (n <= num);
    fclose(fp);
    if (n+(n1 - n)/2 >= num)
        return ratio1;
    return ratio;
}

double accuracy(double * S, int num, int count) { // Оценка 
    return getRatio(num)*sqrt(summ_of_delta_x(S, count)/((count-1)*count));
}

void integral_cycle(double * S, double a, double b, double border, int num, std::string function, int choice, int count) {
    for (int j = 0; j < count; j++) {
        S[j] = intergral(a, b, border, num, function, choice);
        printf("%d Integral is %lf\n", j+1, S[j]);
    }
}