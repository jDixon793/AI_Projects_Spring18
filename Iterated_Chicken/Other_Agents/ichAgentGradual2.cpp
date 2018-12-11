// YOUR NAME: 
//
// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this ichAgentSmith.cpp file to ichAgentJones.cpp and the
// ichAgentSmith function below to ichAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Random-number generation is not
// allowed; your agent must be entirely deterministic.  Feel free to create
// other agents--each in a separate .cpp file--for yours to compete against,
// but turn in only one.  Test your agent(s) with
//
//    nice bash ichBuild.bash
//
// and then
//
//    nice ./ichRunSim
//
// Each submitted agent will play each other in contests of some number of
// rounds each (at least 100) to determine the standings, which will be
// posted soon after the agents are due.

#include "ich.h"
#include <stdlib.h>
// Rename and complete this agent function.
strategy ichAgentGradual2(const vector<strategy> focal, const vector<strategy> opponent)
{
   //if it is the first move playC
   if(focal.size() < 1)
   {
      return playC;
   }
  else//we are in the strat
  {
     if(focal.at(focal.size()-1)==playD)
     {
        //we are in a furious revenge loop of pain
        int numMe=1;
        int numThem =0;
        int i =2;
        while(focal.at(focal.size()-i)==playD)
        {
           numMe++;
           i++;
        }
        for(int x =opponent.size()-i;x>=0;x--)
        {
           if(opponent.at(x)== playD)
              numThem++;
        }
        if(numThem>numMe)
        {
           return playD;
        }
        else
        {
           return playC;
        }
     }
     else if (opponent.at(opponent.size()-1)==playD) //start the pain train
     {
        return playD;
     }
     else
     {
        int r = rand() % 10 + 1;
        return r<4?playD:playC;
     }
  }
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
