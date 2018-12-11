// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here's an example agent function.

#include "rps.h"

handsign rpsAgentDefenseProbs(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Play randomly, choosing each sign with 1/3 probability.
   //Decaration and initialization of the points counter for each handsign
      int points = 0;
      
      //for each of the last 10 moves, test each handsign
      //using the array.at() function prevents memory errors
      //using an unsigned integer to match the type so the compiler is happy
      if(focal.size()>1)
      for(uint i = (focal.size() - 1);i > (focal.size() - 10); i--) 
      {
            points+= outcome(focal.at(i),opponent.at(i));
         
      }
   int r = randomInt(6);
   if (r < 2)
   {
      return rock;
   }
   if (r < 5)
   {
      return paper;
   }
   return scissors;
}
