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

// Rename and complete this agent function.
strategy ichAgentSmith(const vector<strategy> focal, const vector<strategy> opponent)
{
   // Your function must end up returning either playC or playD.
   // No random-number generation allowed!

   // Replace this return statement with your agent code.
   if(focal.size()>2)
   {
      if(opponent.at(opponent.size()-1)==playC && opponent.at(opponent.size()-2)==playC)
         return playD;
   }
   else
      return playC;
   return playC;
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
