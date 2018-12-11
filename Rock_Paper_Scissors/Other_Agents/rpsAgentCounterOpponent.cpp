// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here's an example agent function.

#include "rps.h"

handsign rpsAgentCounterOpponent(const vector<handsign> focal, const vector<handsign> opponent)
{
   if (opponent.size() <= 0)
   {
      // Play rock on the first move.
      return rock;
   }
   else
   {
      // In subsequent rounds, play to counter what the opponent just played
      switch(opponent.back())
      {
         case rock:
            return paper;
            break;
         case paper:
            return scissors;
            break;
         case scissors:
            return rock;
            break;
      }
      return rock;
   }
}
