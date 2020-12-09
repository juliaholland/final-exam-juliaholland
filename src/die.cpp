//die.cpp
#include "die.h"
#include <stdlib.h>
#include <iostream>
 
 
void Die::roll(){
   roll_value = rand()%6 + 1;
 };
int Die::rolled_value() const{
return roll_value;
};
