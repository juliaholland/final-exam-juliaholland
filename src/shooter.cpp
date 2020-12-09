//shooter.cpp
 
#include "shooter.h"
#include<iostream>
 
using std::cout;
 
Roll* Shooter::throw_die(Die& die1, Die die2){
   Roll* roll = new Roll(die1,die2);
   roll->roll_die();
   rolls.push_back(roll);
   return roll;
};
 
void operator<<(std::ostream& out, Shooter& game){
  
  
   for (std::size_t i=0; i<game.rolls.size(); i++){
      
       out<<game.rolls[i]->roll_value()<<"\n";
   }
};
