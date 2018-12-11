// YOUR NAME: Joseph Lynch
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
handsign rpsAgentPinkGuy(const vector<handsign> focal, const vector<handsign> opponent)
{
   // Your function must end up returning rock, paper or scissors.
   // Number of choices made by you so far: focal.size()
   // Last choice made by you: focal.back() (or focal.at(focal.size() - 1))
   // Second-to-last choice made by you: focal.at(focal.size() - 2)
   // Last choice made by your opponent: opponent.back() (or opponent.at(focal.size() - 1))
   // Second-to-last choice made by your opponent: opponent.at(focal.size() - 2)
   
   
   
   //Creat variables to hold the amount of times a choice has won.
   int rockCount = 50, paperCount = 20, scissorsCount = 30;
   
   //Determine how many times each choice has won to later determine the propability of a certain choice winning again.
   for (uint i = 1; i < focal.size(); ++i)
   {   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == 3)
	   {
		   //If outcome = 3, then rock won, so increase its win count by 1
		   ++rockCount;
	   }
	   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == 2)
	   {
		   //If outcome = 2, then scissors won, so increase its win count by 1
		   ++scissorsCount;
	   }
	   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == 1)
	   {
		   //If outcome = 1, then paper won, so increase its win count by 1
		   ++paperCount;
	   }
	   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == -1)
	   {
		   if (rockCount == 50)
		   {
			   //Cannot put any of the counts below 1, it will breka the calculations
			   continue;
		   }
		   //If outcome = -1, then rock lost, so decrease its win count by 1
		   --rockCount;
	   }
	   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == -2)
	   {
		   if (paperCount == 20)
		   {
			   //Cannot put any of the counts below 1, it will breka the calculations
			   continue;
		   }
		   //If outcome = -2, then paper lost, so decrease its win count by 1
		   --paperCount;
	   }
	   
	   if (outcome(focal.at(focal.size() - i), opponent.at(focal.size() - i)) == -3)
	   {
		   if (scissorsCount == 30)
		   {
			   //Cannot put any of the counts below 1, it will breka the calculations
			   continue;
		   }
		   //If outcome = -3, then scissors lost, so decrease its win count by 1
		   --scissorsCount;
	   }
   }
   
   //Calculate total of the counts
   double total = rockCount + paperCount + scissorsCount;
   
   //Variables to hold a choice's probability
   double rockProb, paperProb, scissorsProb;
   
   //Calc probabilities
   rockProb = (rockCount / total) * 100;
   paperProb = (paperCount / total) * 100;
   scissorsProb = (scissorsCount / total) * 100;
   
   //Generate a random int between 0 and the value held in total
   int determine = randomInt(100);
   
   //Using the probability figured earlier, determine a choice based on weighted, chaning probabilities
   if (determine > 0 && determine < rockProb)
   {
	   return rock;
   }
   
   if (determine > rockProb && determine < rockProb + paperProb)
   {
	   return paper;
   }
   
   if (determine > rockProb + paperProb && determine < rockProb + paperProb + scissorsProb)
   {
	   return scissors;
   }
   
   //Fail Safe, in case something goes wrong, default to rock.
   return rock;
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
