//roll.cpp
#include "roll.h"
#include <iostream>
 
 
void Roll::roll_die(){
   die1.roll();
   int die1_rolled_value = die1.rolled_value();
  
   die2.roll();
   int die2_rolled_value = die2.rolled_value();
 
   rolled = true;
   value = die1_rolled_value + die2_rolled_value;
  
};
int Roll::roll_value() const{
   return value;
};
