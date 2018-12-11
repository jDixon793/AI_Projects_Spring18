// James Dixon
//
// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors

#include "rps.h"

/*
Rock Paper Sciccors Agent
This agent plays RPS by calculating how many points the agent would recieve per round with the last 10 played handsigns.
The agent then plays the handsign that would have won the most points.
*/
handsign rpsAgentJaxel(const vector<handsign> focal, const vector<handsign> opponent)
{
   //If there have been no moves, play the default move of rock
   handsign move = rock;
   if(focal.size() < 1)
   {
      return move;
   }
   
   //If we have past rounds to consider then, do come calculations to determine the moves points
   else
   {
      //Decaration and initialization of the points counter for each handsign
      int rockPoints = 0;
      int paperPoints = 0;
      int scissorsPoints = 0;
      
      //for each of the last 10 moves, test each handsign
      //using the array.at() function prevents memory errors
      //using an unsigned integer to match the type so the compiler is happy
      for(uint i = (focal.size() - 1);i > (focal.size() - 10); i--) 
      {
            rockPoints+= outcome(rock,opponent.at(i));
            paperPoints+= outcome(paper,opponent.at(i));
            scissorsPoints+= outcome(scissors,opponent.at(i));
         
      }
      
      //Pick the handsign with the most points
      if(rockPoints>=paperPoints&&rockPoints>=scissorsPoints)
      {
         move = rock;
      }
      else if (paperPoints>=rockPoints&&paperPoints>=scissorsPoints)
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




/*
I created multiple agents with different approaches and this method won the most with the most points.
Because this game of rock-paper-scissors is about winning the most points, I decided to focus on the 
agent maximizing the number of points it recieves instead of the number of rounds won. Using only the last
ten rounds makes this agent much more flexable and reactive than if it considered all the rounds.
Referenced http://www.cplusplus.com/ for syntax and function descriptions.
*/
