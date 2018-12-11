// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here's an example agent function.

#include "ich.h"

strategy ichAgentAlternate(const vector<strategy> focal, const vector<strategy> opponent)
{
   // Always play strategy D.
   return focal.size() % 2 == 0 ? playC:playD;
}
