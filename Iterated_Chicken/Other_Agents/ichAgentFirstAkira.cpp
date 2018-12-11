// James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken

#include "ich.h"

strategy ichAgentFirstAkira(const vector<strategy> focal, const vector<strategy> opponent)
{
   if(focal.size() < 1)                            //if the move list is less than 1 it is the first turn
   {                       
      return playC;                                //play C as the first move
   }
  else                                             //Play the strat 
  {
     if(focal.at(focal.size()-1)==playD)           //if the last move we played was D then we are in the D-loop
     {
        int numMe=1;
        int numThem =0;
        int i =2;
        
        while(focal.at(focal.size()-i)==playD)     //Calculate the number of D's that have been played in a row for numMe
        {
           numMe++;
           i++;                                    //this iterates and finds the starting location of the D-loop
        }
        for(int x =opponent.size()-i;x>=0;x--)    //Calculate the number of D's that have been played by the opponent
        {
           if(opponent.at(x)== playD)
              numThem++;
        }
        
        if(numThem>numMe)                          //if we have not played as many D's as they played total before the d-loop,
        {
           return playD;                           //plays a D and continues D-loop
        }
        else
        {
           return playC;                           //stops the D-loop and starts only playing C
        }
     }
     else if (opponent.at(opponent.size()-1)==playD) //if the opponent played a D against us we must retaliate with increasing strength
     {
        return playD;                              //play a D which starts the D-loop, the D-loop plays a gradually increasing number of D's
     }
     else
        return playC;                              //peacefully play C
  }
}

/*

      This Agent wants to play C the whole game unless the opponent plays D
      -if the opponent plays a D then return the favor
      -each time the opponent plays a D the number of retaliation D-plays increases
      for instance, if the opponent plays their 3rd D of the game then this Agent will play D for the next 3 moves
      this should do a good job of encouraging cooperation and punishing defectors
*/
