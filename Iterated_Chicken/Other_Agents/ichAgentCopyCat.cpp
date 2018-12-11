// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here's an example agent function.

#include "ich.h"

strategy ichAgentCopyCat(const vector<strategy> focal, const vector<strategy> opponent)
{
   // Always play strategy D.
   if(focal.size()<1)
   {
      return playC;
   }
   if(outcome(playC,opponent.at(opponent.size()-1)) > outcome(playD,opponent.at(opponent.size()-1)))
   {
      return playC;
   }
   return playD;
}
