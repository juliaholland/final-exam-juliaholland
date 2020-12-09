//main.cpp
#include "die.h"
#include "phase.h"
#include "roll.h"
#include "shooter.h"
#include "point_phase.h"
#include "come_out_phase.h"
#include<iostream>
 
using std::cout;
int main()
{
   srand(time(0));
   Die die1;
   Die die2;
   Shooter shooter;
   Roll* roll;
   roll = shooter.throw_die(die1, die2);
   ComeOutPhase come_out_phase;
   
   do{
       cout<<"Roll "<<roll->roll_value()<<" roll again\n";
       roll = shooter.throw_die(die1,die2);  
      
   } while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps);
 
   cout<<"Rolled "<<roll->roll_value()<<" start of point phase\n";
 
   cout<<"Roll until "<<roll->roll_value()<< " or 7 is rolled\n";
 
  
   roll = shooter.throw_die(die1,die2);
   int point = roll->roll_value();
 
   PointPhase point_phase(point);
 
   do{
       cout<<"Roll "<<roll->roll_value()<<" roll again\n";
       roll = shooter.throw_die(die1,die2);
   }while (point_phase.get_outcome(roll) == RollOutcome::point||point_phase.get_outcome(roll) == RollOutcome::nopoint);
 
   cout<<"Rolled "<<roll->roll_value()<<" end of point phase\n";
 
   cout<<shooter;
  
}
