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
   
   bool patternFound= false;
   int patternSize =1;
   if(focal.size() > 11)
   {
      for(uint x = 1;x <=3; x++)    //group loop (pattern of 1 is just a repeating sign pattern of 2 is a sequence)
      {
         
         bool seqMatch = true;
         for(uint y = 0;y < 2; y++) 
         {
               for(uint z = 0;x>z;z++)
               {          
                  seqMatch = seqMatch && ( opponent.at(opponent.size()-(((y*x)+z))-1)==opponent.at(opponent.size()-((((y+1)*x)+z))-1));
                        

                 
               }
         }
         if(seqMatch)
         {
            patternSize = x;
            patternFound=true;
            break;
         }
      }
   
   }
   //If we have past rounds to consider then, do come calculations to determine the moves points
   if(patternFound)
   {
      switch(opponent.at(focal.size() - (patternSize)))
      {
         case rock:
            return paper;
            break;
         case paper:
            return scissors;
            break;
         case scissors:
            return rock;
            break;
      }
   }
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
      //find the lowest points
      // random number from 0 - distance from lowest to highest+distance from lowest to medium
      //
      //do a random number from 0 - ()
 
      int total=0;
      int dice=0;
      //if rock is the lowest score pick paper or scissors weighted by points
      if(rockPoints<paperPoints&&rockPoints<scissorsPoints)
      {
         total = abs(rockPoints-paperPoints)+abs(rockPoints-scissorsPoints);
         dice = randomInt(total);
         if(abs(rockPoints-paperPoints)<abs(rockPoints-scissorsPoints))
         {
            if(dice<abs(rockPoints-paperPoints))
            {
               //paper won the dice
               move = paper;
            }
            else
            {
               //scissors won the dice
               move = scissors;
            }
         }
         else{
            if(dice<abs(rockPoints-scissorsPoints))
            {
               //paper won the dice
               move = scissors;
            }
            else
            {
               //scissors won the dice
               move = paper;
            }
         }
      }
      else if (paperPoints<rockPoints&&paperPoints<scissorsPoints)
      {
         total = abs(paperPoints-rockPoints)+abs(paperPoints-scissorsPoints);
         dice = randomInt(total);
         if(abs(paperPoints-rockPoints)<abs(paperPoints-scissorsPoints))
         {
            if(dice<abs(paperPoints-rockPoints))
            {
               //rock won the dice
               move = rock;
            }
            else
            {
               //scissors won the dice
               move = scissors;
            }
         }
         else{
            if(dice<abs(paperPoints-scissorsPoints))
            {
               //scissors won the dice
               move = scissors;
            }
            else
            {
               //rock won the dice
               move = rock;
            }
         }
      }
      else
      {
         total = abs(scissorsPoints-rockPoints)+abs(scissorsPoints-paperPoints);
         dice = randomInt(total);
         if(abs(scissorsPoints-rockPoints)<abs(scissorsPoints-paperPoints))
         {
            if(dice<abs(scissorsPoints-rockPoints))
            {
               //rock won the dice
               move = rock;
            }
            else
            {
               //paper won the dice
               move = paper;
            }
         }
         else{
            if(dice<abs(scissorsPoints-paperPoints))
            {
               //paper won the dice
               move = paper;
            }
            else
            {
               //rock won the dice
               move = rock;
            }
         }
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
Tested against and worked with Brian Leary, Joseph Lynch, and James Crawford
*/
