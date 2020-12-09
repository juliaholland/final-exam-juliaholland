#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "phase.h"
#include "shooter.h"
#include "roll.h"
#include "come_out_phase.h"
#include "point_phase.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Verify Random Die"){
   Die game;
   for (int i = 0; i<10; i++)
   {
       game.roll();
       int value = game.rolled_value();
       REQUIRE((value>=1&&value<=6));
   }   
};
