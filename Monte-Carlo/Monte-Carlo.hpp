#pragma once

#include <math.h>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../parser/fparser.hh"

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

double intergral(double a, double b, double c, double d, double minus_border, double border, int num, std::string function) {
    int count = 0;
    double x = 0;
    double y = 0;
    // for (int i = 0; i < num; i++) {
    //     double x = random(a, b);
    //     double y = random(0, border);
    //     double fun = f(x, function);
    //     if (fun < 0 && y < abs(fun)) {
    //         count--;
    //     }
    //     if (fun > y) {
    //         count++;
    //     }
    // }
    for (int i = 0; i < num; i++) {
        x = random(a, b);
        if (minus_border > 0)
            minus_border = 0;
        y = random(minus_border, border);
        double fun = f(x, function);
        if (y > 0 && y < fun)
            count++;
        if (y < 0 && y > fun)
            count--;
    }
    return ((double)count*(b-a)*(border-minus_border))/(double)num;
}

void higher_lower_point(double a, double b, double e, std::string function, double &ymax, double &ymin) {
    double high = 0;
    double low = 0;
    double fun = f(a, function);
    for (double x = a+e; x <= b; x += e) {
        double fin = f(x, function);
        if (fin > fun) {
            high = fin;
        } else {
            low = fin;
        }
        fun = fin;
    }
    ymax = high;
    ymin = low;
}

void higher_lower__point_x_and_minus_border(double a, double b, double e, std::string function, double &xmax, double &xmin, double &c, double &d) {
    double high = 0;
    double low = 0;
    double fun = f(a, function);
    bool flag1 = true;
    bool flag2 = true;
    for (double x = a+e; x < b; x += e) {
        double fin = f(x, function);
        if (fun > 0 && fin <= 0 && flag1 == true) {
            c = x-e;
            flag1 == false;
        }
        if (fun < 0 && fin >= 0 && flag2 == true) {
            d = x;
            flag2 == false;
        }
        if (fin > fun) {
            high = x;
        } else {
            low = x;
        }
        fun = fin;
    }
    xmax = high;
    xmin = low;
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

double accuracy(double * S, int num, int count) {
    return getRatio(num)*sqrt(summ_of_delta_x(S, count)/((count-1)*count));
}

void integral_cycle(double * S, double a, double b, double c, double d, double minus_border, double border, int num, std::string function, int count) {
    for (int j = 0; j < count; j++) {
        S[j] = intergral(a, b, c, d, minus_border, border, num, function);
        printf("%d Integral is %lf\n", j+1, S[j]);
    }
}

void integral_block(double a, double b, double e, std::string function, int num, int count, double &truth, double &accur) {
    double minus_border = 0;
    double border = 0;
    double xmin = 0;
    double xmax = 0;
    double c = 0;
    double d = 0;
    higher_lower_point(a, b, e, function, border, minus_border);
    higher_lower__point_x_and_minus_border(a, b, e, function, xmax, xmin, c, d);
    double * S = (double *)malloc(sizeof(double)*count);
    integral_cycle(S, a, b, c, d, minus_border, border, num, function, count);
    truth = truth_value(S, count);
    accur = accuracy(S, num, count);
}
