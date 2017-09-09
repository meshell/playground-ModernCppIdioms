#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "variant.h"

#include <cmath>

TEST_CASE("Estimate velocity", "") {

  double acceleration = 1.3;
  auto distance = [=](double t){ return acceleration * t * t / 2; };

  SECTION("constant acceleration") {
    REQUIRE(estimated_velocity(distance, 8, 0.01) == "Estimated velocity after 8 seconds is 10.4 m/s.");
  }

  SECTION("bad precision") {
    REQUIRE(estimated_velocity(distance, 8, 0) == "Estimation failed because of invalid precision.");
    REQUIRE(estimated_velocity(distance, 8, -0.1) == "Estimation failed because of invalid precision.");
    REQUIRE(estimated_velocity(distance, 8, std::nan("")) == "Estimation failed because of invalid precision.");
  }

  SECTION("bad motion function") {
    REQUIRE(estimated_velocity([](double){ return std::nan(""); }, 8, 0.01) == "Estimation failed because of bad motion function.");
  }

  SECTION("bad time") {
    REQUIRE(estimated_velocity(distance, -7, 0.01) == "Estimation failed because of invalid time.");
    REQUIRE(estimated_velocity(distance, std::nan(""), 0.01) == "Estimation failed because of invalid time.");
  }
}

