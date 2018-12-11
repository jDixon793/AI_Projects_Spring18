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
strategy ichAgentGetToKnowYouv4(const vector<strategy> focal, const vector<strategy> opponent)
{
   // Your function must end up returning either playC or playD.
   // No random-number generation allowed!

   // Replace this return statement with your agent code.
   int size = focal.size();
   if(size < 2)
      return playD;
   else if(size < 3)
   {
       return opponent.at(opponent.size()-1)==focal.at(focal.size()-1) && opponent.at(opponent.size()-2)==focal.at(focal.size()-2)? playC:playD;
   }
  else  
  {
     int numC=0;
     int numD=0;
     int mNumRounds=2;
     int pCert = 50;
     strategy predictedMove = playC;
     for(uint i = size-2;i>0;i--)
     {
        
        if(opponent.at(size-1)==opponent.at(i) && focal.at(size-1)==focal.at(i))
        {
          opponent.at(i+1)==playC?numC++:numD++;
        }
        
        
     }
     predictedMove = numC>numD?playC:playD;
     
     if(numC+numD>=mNumRounds)
     {
        if(predictedMove == playC && ((numC*100/(numC+numD))>=pCert))
        {
           //cout<<focal.at(size-1)<<"/"<<opponent.at(size-1)<<": "<<numC<<" "<<numD<<" = "<<predictedMove<<endl;
           return playD;
           
        }
        else if(predictedMove == playD && (numD*100/(numC+numD)>=pCert))
        {
           //cout<<focal.at(size-1)<<"/"<<opponent.at(size-1)<<": "<<numC<<" "<<numD<<" = "<<predictedMove<<endl;
           return playC;
        }
     }
     return opponent.at(opponent.size()-1)==focal.at(focal.size()-1) && opponent.at(opponent.size()-2)==focal.at(focal.size()-2)? playC:playD;
  }
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
