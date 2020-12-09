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

TEST_CASE("Verify Roll die"){
   Die die1;
   Die die2;
   Roll roll(die1,die2);
   for (int i = 0; i<10; i++)
   {
       roll.roll_die();
       int value = roll.roll_value();
       REQUIRE((value>=2 && value<=12));
     
   }
};

TEST_CASE("Verify Shoot die"){
   Die die1;
   Die die2;
   Shooter shoot;
   for (int i = 0; i<10; i++)
   {
       Roll* roll = shoot.throw_die(die1,die2);
       int value = roll->roll_value();
       REQUIRE((value >=2 && value<=12));
   } 
};

 
TEST_CASE("Verify ComeOutPhase 1"){
   ComeOutPhase come;
   Die die1;
   Die die2;
   int value = 0;
   Roll* roll;
   Shooter shoot;
   do{
       roll = shoot.throw_die(die1,die2);
       value = roll->roll_value();
 
   }while (value!=7 && value!=11);
   value = come.get_outcome(roll);
   REQUIRE(value == RollOutcome::natural);
};
 
TEST_CASE("Verify ComeOutPhase 2"){
   ComeOutPhase come;
   Die die1;
   Die die2;
   int value = 0;
   Roll* roll;
   Shooter shoot;
   do{
       roll = shoot.throw_die(die1,die2);
       value = roll->roll_value();
 
   }while (value!=2 && value!=3 && value!=12);
   value = come.get_outcome(roll);
   REQUIRE(value == RollOutcome::craps);
};
 
TEST_CASE("Verify ComeOutPhase 3"){
   ComeOutPhase come;
   Die die1;
   Die die2;
   int value = 0;
   Roll* roll;
   Shooter shoot;
   do{
       roll = shoot.throw_die(die1,die2);
       value = roll->roll_value();
 
   }while (value==2 || value==3 || value==7 || value==2 || value==11 );
   value = come.get_outcome(roll);
   REQUIRE(value == RollOutcome::point);
};


TEST_CASE("Verify PointPhase 1"){
   PointPhase pp(2);
 
   Die die1;
   Die die2;
   int value = 0;
   Roll* roll;
   Shooter shoot;
 
   do{
       roll = shoot.throw_die(die1,die2);
       value = roll->roll_value();
 
   }while (value!= 2);
   value = pp.get_outcome(roll);
   REQUIRE(value == RollOutcome::point);
};

TEST_CASE("Verify PointPhase 2"){
   PointPhase pp(2);
 
   Die die1;
   Die die2;
   int value = 0;
   Roll* roll;
   Shooter shoot;
 
   do{
       roll = shoot.throw_die(die1,die2);
       value = roll->roll_value();
 
   }while (value!= 7);
   value = pp.get_outcome(roll);
   REQUIRE(value == RollOutcome::seven_out);
};
 
 
TEST_CASE("Verify PointPhase 3"){
	PointPhase pp(2);
 
   	Die die1;
   	Die die2;
   	int value = 0;
   	Roll* roll;
   	Shooter shoot;

	do{
		roll = shoot.throw_die(die1,die2);
		value = roll->roll_value();
 	}while (value == 2 || value == 7);
 	value = pp.get_outcome(roll);
   	REQUIRE(value == RollOutcome::nopoint);
};


