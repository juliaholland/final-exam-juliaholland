//shooter.h
#include "die.h"
#include "roll.h"
#include<vector>
 
#ifndef SHOOTER_H
#define SHOOTER_H
class Shooter {
   public:
       Roll* throw_die(Die& die1, Die die2);
       friend void operator<<(std::ostream& out, Shooter& game);
   private:
       std::vector<Roll*>rolls;
};
#endif
