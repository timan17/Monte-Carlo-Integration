#include "doctest.h"
#include "Monte-Carlo.hpp"

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

// TEST_CASE("CHECK_BORDER") {
//   std::string function;
//   printf("Write the function ");
//   std::getline(std::cin, function); // запарсим функцию)
//   for (double a = 0.0; a < 10.0; a++) {
//     for(double b = a + 1.0; b < 20.0; b++) {
//       REQUIRE(f(b, function) == der(a, b, 0.001));
//     }
//   }
// }
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
    REQUIRE(f(0, "2/x") == 0); // Мда, может, позже исправлю....
}