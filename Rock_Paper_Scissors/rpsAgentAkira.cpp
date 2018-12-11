// James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 1: Rock, paper, scissors

#include "rps.h"

/*
Rock Paper Sciccors Agent
This agent plays RPS by calculating how many points the agent would recieve per round with the last 10 played handsigns.
The agent then plays the handsign that would have won the most points.
*/
handsign rpsAgentAkira(const vector<handsign> focal, const vector<handsign> opponent)
{
   //If there have been no moves, play the default move of rock
   handsign move = rock;
   if(focal.size() < 1)
   {
      return move;
   }
   
   //here we are testing to see if we can find a repeated sequence of hands to take advantage of
   bool patternFound= false;
   int patternSize =1;
   if(focal.size() > 15)
   {
      
      for(uint x = 1;x <=4; x++)    //group loop (pattern of 1 is just a repeating sign pattern of 2 is a sequence)
      {
         
         bool seqMatch = true;
         for(uint y = 0;y < 2; y++) //the sequence the pattern only needs to happen twice
         {
               for(uint z = 0;x>z;z++) //make sure the hand signs are matching and that it is indeed a sequence pattern
               {          
                  seqMatch = seqMatch && ( opponent.at(opponent.size()-(((y*x)+z))-1)==opponent.at(opponent.size()-((((y+1)*x)+z))-1));
               }
         }
         //if we found a sequence pattern 
         if(seqMatch)
         {
            patternSize = x;
            patternFound=true;
            break;
         }
      }
   
   }
   //if the move the oppenent just played matchs our move from two games ago matchs twice
   //we assume that we have a copy cat so we move to counter
   bool copyCat = true;
   if(focal.size()>4)
   {
      for(int x=1;x<3;x++)
      {
         copyCat = copyCat && (focal.at(focal.size()-x-1)==opponent.at(focal.size()-x));
      }
   }
   
   //if the move the oppenent just played counters our move from two games ago matchs twice
   //we assume that we have a anti copy cat so we move to counter
   bool antiCopyCat = true;
   if(focal.size()>4)
   {
      for(int x=1;x<3;x++)
      {
         switch(focal.at(focal.size()-x-1))
         {
            case rock:
               antiCopyCat = antiCopyCat && (opponent.at(focal.size()-x) == paper);
               break;
            case paper:
               antiCopyCat = antiCopyCat && (opponent.at(focal.size()-x) == scissors);
               break;
            case scissors:
               antiCopyCat = antiCopyCat && (opponent.at(focal.size()-x) == rock);
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
   else if(copyCat)
   {
      switch(focal.at(focal.size()-1))
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
   else if(antiCopyCat)
   {
      switch(focal.at(focal.size()-1))
      {
         case rock:
            return scissors;
            break;
         case paper:
            return rock;
            break;
         case scissors:
            return paper;
            break;
      }
   }
   else
   {

      //Decaration and initialization of the points counter for each handsign
      int rockPoints = 0;
      int paperPoints = 0;
      int scissorsPoints = 0;
      int totalPoints = 0;
      
      //for each of the last 10 moves, test each handsign
      //using the array.at() function prevents memory errors
      //using an unsigned integer to match the type so the compiler is happy
      for(uint i = (focal.size() - 1);i > (focal.size() - 10); i--) 
      {
            rockPoints+= outcome(rock,opponent.at(i));
            paperPoints+= outcome(paper,opponent.at(i));
            scissorsPoints+= outcome(scissors,opponent.at(i));
            totalPoints += outcome(focal.at(i),opponent.at(i));
      }
      
      //if the totalPoints for the last 10 rounds is <= -10
      //use the perfect defense probability method
      if(totalPoints<=-10)
      {
         int r = randomInt(6);
         if (r < 2)
         {
            move = rock;
         }
         if (r < 5)
         {
            move = paper;
         }
         move = scissors;
      } 
      //else use the point optimizing move method
      else
      {
      
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
   }
   return move;
}




/*
I created multiple agents with different approaches and this method won the most with the most points.
Because this game of rock-paper-scissors is about winning the most points, I decided to focus on the 
agent maximizing the number of points it recieves instead of the number of rounds won. Using only the last
ten rounds makes this agent much more flexable and reactive than if it considered all the rounds.
Referenced http://www.cplusplus.com/ for syntax and function descriptions.

This agent has 3 parts. 
-Offessively looks for patterns that it can exploit. If it finds one then exploit it.
-Netrually chooses a move based on the weighted probability of points from the last 10 rounds
-Defensively chooses a move using the probability weights we used in class if has lost a lot in the previous rounds
*/
