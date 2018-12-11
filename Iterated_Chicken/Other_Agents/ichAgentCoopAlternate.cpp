// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here's an example agent function.

#include "ich.h"

strategy ichAgentCoopAlternate(const vector<strategy> focal, const vector<strategy> opponent)
{
   if(focal.size()<1)
   {
      return playC;
   }
   else                 //check to see if we have been decived
   {
      for(int i = focal.size()-1;i>=0;i--)
      {
         if(focal.at(i)==playD)
         {
            return focal.at(focal.size()-1)==playD?playC:playD;
         }
      }
   }
   return playC;
}
