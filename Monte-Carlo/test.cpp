#include "doctest.h"
#include "Monte-Carlo.hpp"
#include <math.h>
#include <iomanip>
#define pi 3.1415926535897932
#define e  2.7182818284590452

bool compare(double const &a, double const &b, int const &sampling) { // необходимо для double и float
    if (std::ceil(a*sampling)/sampling == std::ceil(b*sampling)/sampling) {
        return true;
    }
    return false;
}

TEST_CASE("CHECK_RATIO") {
    REQUIRE(getRatio(1) == 0.0);
    REQUIRE(getRatio(2) == 31.599);
    REQUIRE(getRatio(11) == 4.436);
    REQUIRE(getRatio(22) == 3.792);
    REQUIRE(getRatio(30) == 3.645);
    REQUIRE(getRatio(60) == 3.460);
    REQUIRE(getRatio(120) == 3.373);
    REQUIRE(getRatio(12000000) == 3.373);
    REQUIRE(getRatio(1147483646) == 3.290);
}

TEST_CASE("CHECK_PARSER") {
    double numround = 1000;
    double x = random(-10, 10);
    REQUIRE(compare(f(x, "abs(x)"), abs(x), 10000));
    x = random(0, 10);
    REQUIRE(compare(f(x, "x"), x, numround));
    REQUIRE(compare(f(x, "x+x"), 2*x, numround));
    REQUIRE(compare(f(x, "x-x"), 0, numround));
    REQUIRE(compare(f(x, "x/x"), 1, numround));
    REQUIRE(compare(f(x, "1/x"), 1/x, numround));
    REQUIRE(compare(f(x, "x/1"), x, numround));
    REQUIRE(compare(f(x, "2*x"), 2*x, numround));
    REQUIRE(compare(f(x, "x/2"), x/2, numround));
    REQUIRE(compare(f(x, "x+1^x"), x+1, numround));
    REQUIRE(compare(f(x, "x^x"), pow(x, x), numround));
    REQUIRE(compare(f(x, "x^x+1"), pow(x, x)+1, numround));
    REQUIRE(compare(f(x, "x^(x+1)"), pow(x,x+1), numround));
    REQUIRE(compare(f(x, "(x^x)+1"), pow(x,x)+1, numround));
    REQUIRE(compare(f(x, "(x+1)^x"), pow(x+1, x), numround));
    REQUIRE(compare(f(x, "1+x^x"), pow(x,x)+1, numround));
    REQUIRE(compare(f(x, "(1+x)^x"), pow(1+x,x), numround));
    REQUIRE(compare(f(x, "e^x"), pow(e, x), numround));
    REQUIRE(compare(f(x, "pi^x"), pow(pi, x), numround));
}

TEST_CASE("CHECK_RANDOM") {
    int a = 20;
    int b = 40;
    int n = 100000;
    double summ = 0;
    for (int j = 0; j < n; j++)
        summ += random(a, b);
    REQUIRE(std::round(2*summ/(a+b)/n) == 1);
}

TEST_CASE("CHECK_MAX") {
    int j = 0;
    double a = 0;
    double b = random(2, 20);
    double c = 0;
    double d = 0;
    double xmax = 0;
    double xmin = 0;
    double er = 0.001;
    double minus_border = 0;
    double border = 0;
    std::vector<std::string> vec;
    std::vector<double> val;
    vec.push_back("1");
    val.push_back(0.0);
    vec.push_back("abs(x)");
    val.push_back(b);
    vec.push_back("-abs(x)");
    val.push_back(0.0);
    vec.push_back("x^2");
    val.push_back(b);
    vec.push_back("e^x");
    val.push_back(b);
    vec.push_back("pi^x");
    val.push_back(b);
    vec.push_back("x^x");
    val.push_back(b);
    vec.push_back("1+2*x");
    val.push_back(b);
    vec.push_back("1-x");
    val.push_back(0.0);
    for (std::string function: vec) {
        higher_lower__point_x_and_minus_border(a, b, er, function, xmax, xmin, c, d);
        REQUIRE(compare(xmax, val.at(j), 100));
        j++;
    }
}

TEST_CASE("CHECK_RANDOM") {
    int a = 20;
    int b = 40;
    int n = 100000;
    double summ = 0;
    for (int j = 0; j < n; j++)
        summ += random(a, b);
    REQUIRE(std::round(2*summ/(a+b)/n) == 1);
}

TEST_CASE("CHECK_C_D") {
    int j = 0;
    double a = 0;
    double b = 10;
    double c = 0;
    double d = 0;
    double xmax = 0;
    double xmin = 0;
    double er = 0.001;
    double minus_border = 0;
    double border = 0;
    std::vector<std::string> vec;
    std::vector<double> val;
    vec.push_back("(x-5)^2-5");
    val.push_back(5-sqrt(5));
    val.push_back(5+sqrt(5));
    for (std::string function: vec) {
        higher_lower__point_x_and_minus_border(a, b, er, function, xmax, xmin, c, d);
        REQUIRE(compare(c, val.at(j++), 100));
        REQUIRE(compare(d, val.at(j++), 100));
    }
}

TEST_CASE("CHECK_CARTESIAN") {
    int j = 0;
    double minus_border = 0;
    double border = 0;
    double a = 0;
    double b = 10;
    double c = 0;
    double d = 0;
    int num = (int)random(2000, 2000); // можно выбрать точность (лучше от 1000 точек, иначе большие числа может не посчитать)
    int count = 10;
    std::vector<std::string> vec;
    std::vector<double> val;
    double truth = 0;
    double accur = 0;
    double er = 0.001;
    
    vec.push_back("(x-5)^2-5");
    val.push_back(33.333);
    vec.push_back("x");
    val.push_back(50);
    vec.push_back("10+2*x");
    val.push_back(200);
    vec.push_back("x^2");
    val.push_back(333.333);
    vec.push_back("1+x+x^2");
    val.push_back(393.333);
    vec.push_back("e^x");
    val.push_back(22025);
    printf("\nCatesian coordinate system\n");
    for (std::string function : vec) {
        // border = higher_point(a, b, 0.001, function);
        std::cout << "\n" << function << "\n";
        integral_block(a, b, er, function, num, count, truth, accur);
        REQUIRE(val.at(j) < truth + accur);
        REQUIRE(val.at(j) > truth - accur);
        j++;
    }
}

TEST_CASE("CHECK_POLAR") {
    int j = 0;
    double minus_border = 0;
    double border = 0;
    double a = 0;
    double b = 10;
    double c = 0;
    double d = 0;
    int num = (int)random(2000, 2000); // можно выбрать точность (лучше от 1000 точек, иначе большие числа может не посчитать)
    int count = 10;
    std::vector<std::string> vec;
    std::vector<double> val;
    double truth = 0;
    double accur = 0;
    double er = 0.001;
    

    // vec.push_back("x");
    // val.push_back(50);
    // vec.push_back("10+2*x");
    // val.push_back(200);
    // vec.push_back("x^2");
    // val.push_back(333.333);
    // vec.push_back("1+x+x^2");
    // val.push_back(393.333);
    vec.push_back("e^x");
    val.push_back(121000000);
    printf("\nPolar coordinate system\n");
    for (std::string function : vec) {
        // border = higher_point(a, b, 0.001, function);
        function = "0.5*(" + function + ")^2";
        std::cout << "\n" << function << "\n";
        integral_block(a, b, er, function, num, count, truth, accur);
        REQUIRE(val.at(j) < truth + accur);
        REQUIRE(val.at(j) > truth - accur);
        j++;
    }
}