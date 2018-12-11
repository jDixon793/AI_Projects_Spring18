// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here's an example agent function.

#include "rps.h"

handsign rpsAgentCopyOpponent(const vector<handsign> focal, const vector<handsign> opponent)
{
   if (opponent.size() <= 0)
   {
      // Play rock on the first move.
      return rock;
   }
   else
   {
      // In subsequent rounds, play whatever the opponent just played in the previous round.
      return opponent.back();
   }
}
