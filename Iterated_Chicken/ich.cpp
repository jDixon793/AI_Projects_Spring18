// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here are the functions available to each agent.

#include "ich.h"
int minNumRounds=2;
int percentCertain=50;
int maxx=0;
int mrounds=0;
int mpercent=0;
int outcome(strategy focal, strategy opponent)
{
   // Return the focal player's outcome given the two strategies.
   return opponent == playC ? focal == playC ? 2 : 3 : focal == playC ? 1 : 0;
}

int getRounds()
{
   return minNumRounds;
}
int getPercent()
{
   return percentCertain;
}
int getMax()
{
   return maxx;
}
int getMRounds()
{
   return mrounds;
}
int getMPercent()
{
   return mpercent;
}
void setMax(int m,int r, int p)
{
   maxx = m;
   mrounds = r;
   mpercent=p;
}
void setRounds(int r)
{
   minNumRounds = r;
}
void setPercent(int p)
{
   percentCertain = p;
}
