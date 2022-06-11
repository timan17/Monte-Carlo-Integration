#include <math.h>
#include <random>
#include <iostream>

double f(double x) {
    // return pow(x, 2); // функция, например y = x^2
    return pow(x, 2);
}

double random(double a, double b) {
    std::random_device radm;
    std::mt19937_64 mt(radm());
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(mt);
}

double inter(double a, double b, double bordy, int n) {
    int count = 0; // счётчик точек под графиком функции
    for (int i = 0; i < n; i++) {
        // srand((unsigned int)time(NULL));
        // srand((unsigned int)(time(NULL))+i);
        // double x = (((double)rand()/(double)(RAND_MAX)) * (b - a)) + a;
        // srand((unsigned int)(time(NULL))+i+b+a+bordY+rand());
        // double y = ((double)rand()/(double)(RAND_MAX)) * bordY;
        double x = random(a, b);
        double y = random(0, bordy);
        if (f(x) > y) {
            count++;
        }
    }
    return ((double)count*(double)(b-a)*(double)bordy)/(double)n;
}