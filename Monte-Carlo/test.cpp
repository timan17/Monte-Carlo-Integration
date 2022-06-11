#include "doctest.h"
#include "Monte-Carlo.hpp"

// TEST_CASE("CHECK_FUNC") {
//   for (int i=0; i < 10; i++)
//     REQUIRE(f(i) == i*i);
// }

TEST_CASE("CHECK_COUNTER") {
  double u = inter(3, 9, f(9), 100000);
  REQUIRE(u < 235);
  REQUIRE(u > 233);
  u = inter(5, 18, f(18), 100000);
  REQUIRE(u < 2000);
  REQUIRE(u > 1700);
  u = inter(15, 60, f(60), 100000);
  REQUIRE(u < 75000);
  REQUIRE(u > 60000);
  u = inter(30, 90, f(90), 100000);
  REQUIRE(u < 250000);
  REQUIRE(u > 220000);
  u = inter(300, 900, f(900), 100000);
  REQUIRE(u < 240000000);
  REQUIRE(u > 220000000);
}