//phase.h
#include "roll.h"
 
#ifndef PHASE_H
#define PHASE_H
 
enum RollOutcome {natural, craps, point, seven_out, nopoint};
class Phase {
   public:
      RollOutcome get_outcome(Roll* roll);
 
};
 
#endif
