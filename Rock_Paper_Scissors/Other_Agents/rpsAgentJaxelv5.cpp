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
//most points agent

handsign rpsAgent1(const vector<handsign> focal, const vector<handsign> opponent)
{
   if(focal.size()<1)
   {
      return rock;
   }
   else
   {
      int numMove = randomInt(3);
      handsign move = rock;
		switch(numMove)
		{
		case 0:
				move =rock;
			break;
		case 1:
				move =paper;
			break;
		case 2:
				move =scissors;
			break;
		}
		return move;
   }
   return rock;
}

handsign rpsAgent2(const vector<handsign> focal, const vector<handsign> opponent)
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

handsign rpsAgent3(const vector<handsign> focal, const vector<handsign> opponent)
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
      for(uint i=0;i<focal.size() -1; i++)
      {
         switch(focal.at(i))
         {
            case rock:
               moveWeight[0]+= outcome(focal.at(i),opponent.at(i));
               break;
            case paper:
               moveWeight[1]+= outcome(focal.at(i),opponent.at(i));
               break;
            case scissors:
               moveWeight[2]+= outcome(focal.at(i),opponent.at(i));
               break;
         }
      }
      if(moveWeight[0]>=moveWeight[1]&&moveWeight[0]>=moveWeight[2])
      {
         move = rock;
      }
      else if (moveWeight[1]>=moveWeight[0]&&moveWeight[1]>=moveWeight[2])
      {
         move = paper;
      }
      else
      {
         move = scissors;
      }
   }
   return move;
}

handsign rpsAgent4(const vector<handsign> focal, const vector<handsign> opponent)
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
      for(uint i=focal.size() -1;i> focal.size() - 6; i--)
      {
            moveWeight[0]+= outcome(rock,opponent.at(i));
            moveWeight[1]+= outcome(paper,opponent.at(i));
            moveWeight[2]+= outcome(scissors,opponent.at(i));
         
      }
      if(moveWeight[0]>=moveWeight[1]&&moveWeight[0]>=moveWeight[2])
      {
         move = rock;
      }
      else if (moveWeight[1]>=moveWeight[0]&&moveWeight[1]>=moveWeight[2])
      {
         move = paper;
      }
      else
      {
         move = scissors;
      }
   }
   return move;
}

handsign rpsAgentJaxelv5(const vector<handsign> focal, const vector<handsign> opponent)
{
   if(focal.size()<1)
   {
      return rock;
   }
   vector<int> pointsPerAgent(4);
   handsign move = rock;
   
   vector<handsign> subFocal;
   vector<handsign> subOpponent;
   if(focal.size()<100)
   {
      for(uint i=0;i<focal.size()-1; i++)
      {
         subFocal.push_back(focal.at(i));
         subOpponent.push_back(opponent.at(i));

         pointsPerAgent[0]+=outcome(rpsAgent1(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[1]+=outcome(rpsAgent2(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[2]+=outcome(rpsAgent3(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[3]+=outcome(rpsAgent4(subFocal,subOpponent),focal[i+1]);
      }
   }
   else
   {
      for(uint i=focal.size()-100;i<focal.size()-1; i++)
      {
         subFocal.push_back(focal.at(i));
         subOpponent.push_back(opponent.at(i));

         pointsPerAgent[0]+=outcome(rpsAgent1(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[1]+=outcome(rpsAgent2(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[2]+=outcome(rpsAgent3(subFocal,subOpponent),focal[i+1]);
         pointsPerAgent[3]+=outcome(rpsAgent4(subFocal,subOpponent),focal[i+1]);
      }
   }
   int max= pointsPerAgent.at(0), maxIndex=0;
   for(uint i=0;i<pointsPerAgent.size();i++)
   {
      if(pointsPerAgent.at(i)>max)
      {
         max=pointsPerAgent.at(i);
         maxIndex = i;
      }
      cout<<i<<" "<<pointsPerAgent.at(i)<<"\t";
      
   }
   cout<<endl;
   switch(maxIndex)
   {
      case 0:
         move = rpsAgent1(focal,opponent);
         break;
      case 1:
         move = rpsAgent2(focal,opponent);
         break;
      case 2:
         move = rpsAgent3(focal,opponent);
         break;
      case 3:
         move = rpsAgent4(focal,opponent);
         break;
      
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

