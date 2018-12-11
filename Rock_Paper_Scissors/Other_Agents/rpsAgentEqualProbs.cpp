// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here's an example agent function.

#include "rps.h"

handsign rpsAgentEqualProbs(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Play randomly, choosing each sign with 1/3 probability.
   int r = randomInt(3);
   if (r < 1)
   {
      return rock;
   }
   if (r < 2)
   {
      return paper;
   }
   return scissors;
}
