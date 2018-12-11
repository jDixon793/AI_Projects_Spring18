// James Dixon
//
// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this rpsAgentSmith.cpp file to rpsAgentJones.cpp and the
// rpsAgentSmith function below to rpsAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Feel free to create other
// agents--each in a separate .cpp file--for yours to compete against, but
// turn in only one.  Test your agent(s) with
//
//    nice bash rpsBuild.bash
//
// and then
//
//    nice ./rpsRunSim
//
// Each submitted agent will play each other in contests of some number of
// rounds each (at least 100) to determine the standings, which will be
// posted soon after the agents are due.

#include "rps.h"

// Rename and complete this agent function.

   // Your function must end up returning rock, paper or scissors.
   // Number of choices made by you so far: focal.size()
   //    (You may assume that focal.size() and opponent.size() are equal.)
   // Last choice made by you: focal.back() (or focal.at(focal.size() - 1))
   // Second-to-last choice made by you: focal.at(focal.size() - 2)
   // Third-to-last choice made by you: focal.at(focal.size() - 3)
   //    etc.
   // Last choice made by your opponent: opponent.back() (or opponent.at(focal.size() - 1))
   // Second-to-last choice made by your opponent: opponent.at(focal.size() - 2)
   //    etc.

   // Replace this return statement with your agent code.
   
   //This uses a weighted random to counter the most played hand.
handsign rpsAgentJaxelv2(const vector<handsign> focal, const vector<handsign> opponent)
{
   handsign move = rock;
   if(focal.size()<1)
   {
      return rock;
   }
   else
   {
      int moveWeight[3];
      moveWeight[0]= moveWeight[1]= moveWeight[2]=0;
      for(uint i=0;i<opponent.size() -1; i++)
      {
         switch(opponent.at(i))
         {
            case rock:
               moveWeight[0]++;
               break;
            case paper:
               moveWeight[1]++;
               break;
            case scissors:
               moveWeight[2]++;
               break;
         }
      }
      int moveNum = randomInt(opponent.size());
      if(moveNum<=moveWeight[0])
      {
         //their move will be rock so counter
         move = paper;
      }
      else if(moveNum<moveWeight[0]+moveWeight[1])
      {
         //their move will be paper so counter
         move = scissors;
      }
      else{
         //their move will be scissors so counter
         move = rock;
      }
      
   }
   return move;
} 




/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
