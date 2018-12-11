// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here's an example agent function.

#include "ich.h"

strategy ichAgentAlternateFour(const vector<strategy> focal, const vector<strategy> opponent)
{
   // Always play strategy D.
   switch(focal.size() % 5 )
   {
      case 0:
            return playD;
         break;
      case 1:
            return playD;
         break;
      case 2:
            return playC;
         break;
      case 3:
            return playD;
         break;
      case 4:
            return playD;
         break;
   }
   return playC;
}
