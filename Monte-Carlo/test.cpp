#include "doctest.h"
#include "Monte-Carlo.hpp"
#define PI 3.1415926535897932
#define e  2.7182818284590452

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
//   std::string function = "5*x";
//   // printf("Write the function ");
// //   std::getline(std::cin, function); // запарсим функцию)
//   for (double a = 0.0; a < 10.0; a++) {
//     for(double b = a + 1.0; b < 10.0; b++) {
//       REQUIRE(abs(f(b, function) == higher_point(a, b, 0.001, function, 1)) < 0.1);
//     }
//   }
// }

// TEST_CASE("CHECK_PARSER") {
//     REQUIRE(f(10, "2*x") == 20);
//     REQUIRE(f(10, "x^2") == 100);
//     REQUIRE(f(10, "x/5") == 2);
//     REQUIRE(f(10, "2+x") == 12);
//     REQUIRE(f(10, "2-x") == -8);
//     REQUIRE(f(0, "2*x") == 0);
// }

// TEST_CASE("CHECK_PARSER2") {
//     REQUIRE(f(0, "x/2") == 0);
//     REQUIRE(f(0, "2/x") == 0); // Мда, 1/0=0, к счастью, на интеграл это не должно повлиять
// }

// TEST_CASE("CHECK_ACCURACY") {
//   int n = 5;
//   double * S = (double *)malloc(sizeof(double)*n);
//   S[0] = 1478.554989;
//   S[1] = 1487.618209;
//   S[2] = 1489.180833;
//   S[3] = 1493.0657;
//   S[4] = 1477.349536;
//   REQUIRE(truth_value(S, n) - 1485.1538534 < 0.001);
//   REQUIRE(summ_of_delta_x(S, n) - 189.3393113< 0.001 );
//   REQUIRE(accuracy(S, n) - 3.076843442 < 0.001);
// }

// TEST_CASE("CHECK_POLAR") {
//   double a = 0;
//   double b = 2*PI;
//   double e = 0.001;
//   std::string function = "";
//   printf("Set a polar function ");
//   std::cin >> function;
//   int choice = 1;
//   int num = 100000;
//   int count = 0;
//   printf("Set count of integrals ");
//   scanf_s("%d", &count);
//   double * S = (double *)malloc(sizeof(double)*count);
//   double border = higher_point(a, b, 0.001, function, choice);
//   integral_cycle(S, a, b, border, num, function, choice, count);
//   printf("accuracy %lf\n", accuracy(S, count));
//   double accur = accuracy(S , count);
//   double truth = truth_value(S, count);
//   // for (int k = 0; k < count; k++) {
//   //   REQUIRE(S[k] + abs(accur) > truth);
//   //   REQUIRE(S[k] - abs(accur) < truth);
//   // }
//   for (int k = 0; k < count; k++) {
//     S[k] = abs(S[k] - truth);
//     REQUIRE(S[k] <= 10/(sqrt(num)));
//     REQUIRE(S[k] >= 0.9/(sqrt(num)));
//   }
// }

// TEST_CASE("CHECK_POLAR1") {
//   double a = PI;
//   double b = 2*PI;
//   double e = 0.001;
//   std::string function = "x^2";
//   int choice = 2;
//   int num = 100000;
//   REQUIRE(intergral(a, b, 16*PI*PI*PI*PI, num, function, choice) == 948.66);
// }

// TEST_CASE("CHECK_POLAR2") {
//   double a = 0;
//   double b = PI;
//   double e = 0.001;
//   std::string function = "x^3";
//   int choice = 2;
//   int num = 100000;
//   REQUIRE(intergral(a, b, 64*PI*PI*PI*PI*PI*PI, num, function, choice) == 215.74);
// }

// TEST_CASE("e^x") {
//   REQUIRE(abs(f(10, "e^x") - pow(e, 10)) == 0.0);
// }

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