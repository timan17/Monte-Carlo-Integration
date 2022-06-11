#include <math.h>
#include <random>
#include <iostream>
#include "../fparser.hh"

double f(double x, std::string function) {
    // return pow(x, 2); // функция, например y = x^2
    FunctionParser fparser;
    fparser.Parse(function, "x");
    return fparser.Eval(&x);
    // return pow(x, 2);
}

double random(double a, double b) {
    std::random_device radm;
    std::mt19937_64 mt(radm());
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(mt);
}

double inter(double a, double b, double bordy, int n, std::string function) {
    int count = 0; // счётчик точек под графиком функции
    for (int i = 0; i < n; i++) {
        // srand((unsigned int)time(NULL));
        // srand((unsigned int)(time(NULL))+i);
        // double x = (((double)rand()/(double)(RAND_MAX)) * (b - a)) + a;
        // srand((unsigned int)(time(NULL))+i+b+a+bordY+rand());
        // double y = ((double)rand()/(double)(RAND_MAX)) * bordY;
        double x = random(a, b);
        double y = random(0, bordy);
        if (f(x, function) > y) {
            count++;
        }
    }
    return ((double)count*(double)(b-a)*(double)bordy)/(double)n;
}
double der(double a, double b, double e, std::string function) {
    e = 0.001;
    double v[2] = {0, 0};
    double h = 0;
    for (double i = a; i < b-e; i += e) {
        v[0] = v[1];
        double u = f(i, function);
        v[1] = (u-f(i+e, function))/e;
        if (v[1] <= 0 && v[0] > 0){
            h = std::max(h, u);
        }
    }
    return h;
}