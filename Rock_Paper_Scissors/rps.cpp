// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here are the functions available to each agent.

#include "rps.h"

int outcome(handsign focal, handsign opponent)
{
   // Return the focal player's outcome given the two handsigns.
   if (focal == opponent)
   {
      return 0;
   }
   if (focal == rock)
   {
      if (opponent == paper)
      {
         return -1;
      }
      return 3;
   }
   if (focal == paper)
   {
      if (opponent == scissors)
      {
         return -2;
      }
      return 1;
   }
   if (focal == scissors)
   {
      if (opponent == rock)
      {
         return -3;
      }
      return 2;
   }
   if (opponent == rock)
   {
      return -3;
   }
   if (opponent == paper)
   {
      return -1;
   }
   if (opponent == scissors)
   {
      return -2;
   }
   return 0;
}

int randomInt(int n)
{
   // Return a random integer between 0 and n - 1.
   int r;
   if (n <= 0)
   {
      return 0;
   }
   do
   {
      r = random();
   }
   while (r >= INT_MAX / n * n);
   return r / (INT_MAX / n);
}
