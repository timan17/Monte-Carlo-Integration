#include "doctest.h"
#include "Monte-Carlo.hpp"
#define PI 3.14

// TEST_CASE("CHECK_FUNC") {
//   for (int i=0; i < 10; i++)
//     REQUIRE(f(i) == i*i);
// }

// TEST_CASE("CHECK_COUNTER") {
//   double u = inter(3, 9, f(9), 100000);
//   REQUIRE(u < 235);
//   REQUIRE(u > 233);
//   u = inter(5, 18, f(18), 100000);
//   REQUIRE(u < 2000);
//   REQUIRE(u > 1700);
//   u = inter(15, 60, f(60), 100000);
//   REQUIRE(u < 75000);
//   REQUIRE(u > 60000);
//   u = inter(30, 90, f(90), 100000);
//   REQUIRE(u < 250000);
//   REQUIRE(u > 220000);
//   u = inter(300, 900, f(900), 100000);
//   REQUIRE(u < 240000000);
//   REQUIRE(u > 220000000);
// }

TEST_CASE("CHECK_BORDER") {
  std::string function = "5*x";
  printf("Write the function ");
//   std::getline(std::cin, function); // запарсим функцию)
  for (double a = 0.0; a < 10.0; a++) {
    for(double b = a + 1.0; b < 10.0; b++) {
      REQUIRE(abs(f(b, function) == higher_point(a, b, 0.001, function, 1)) < 0.1);
    }
  }
}

TEST_CASE("CHECK_PARSER") {
    REQUIRE(f(10, "2*x") == 20);
    REQUIRE(f(10, "x^2") == 100);
    REQUIRE(f(10, "x/5") == 2);
    REQUIRE(f(10, "2+x") == 12);
    REQUIRE(f(10, "2-x") == -8);
    REQUIRE(f(0, "2*x") == 0);
}

TEST_CASE("CHECK_PARSER2") {
    REQUIRE(f(0, "x/2") == 0);
    REQUIRE(f(0, "2/x") == 0); // Мда, 1/0=0, к счастью, на интеграл это не должно повлиять
}

TEST_CASE("CHECK_POLAR") {
  double a = 0;
  double b = 2*PI;
  double e = 0.001;
  std::string function = "5*x";
  int choice = 2;
  int num = 100000;
  REQUIRE(intergral(a, b, 100*PI*PI, num, function, choice) == 1033);
}

TEST_CASE("CHECK_POLAR1") {
  double a = PI;
  double b = 2*PI;
  double e = 0.001;
  std::string function = "x^2";
  int choice = 2;
  int num = 100000;
  REQUIRE(intergral(a, b, 16*PI*PI*PI*PI, num, function, choice) == 948.66);
}

TEST_CASE("CHECK_POLAR2") {
  double a = 0;
  double b = PI;
  double e = 0.001;
  std::string function = "x^3";
  int choice = 2;
  int num = 100000;
  REQUIRE(intergral(a, b, 64*PI*PI*PI*PI*PI*PI, num, function, choice) == 215.74);
}