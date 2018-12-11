// YOUR NAME: James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken

#include "ich.h"


strategy ichAgentAkira(const vector<strategy> focal, const vector<strategy> opponent)
{

   uint size = focal.size();                       //convenience variable
   if(size < 3)                                    //when we lack information play D
      return playD;
  else                                             //Play the main strategy
  {
     int numC=0;                                   //number of times C has been played in response to the last game
     int numD=0;                                   //number of times D has been played in response to the last game
     int mNumRounds=25;                            //number of times the round has happened
     int pCert = 95;                               //percentage sure that the move will be played
     strategy predictedMove = playC;               //opponents predicted move
     
     for(uint i = size-2;i>0&&i>size-100;i--)      //look through only up to the past 100 games
     {
        
        if(opponent.at(size-1)==opponent.at(i) && focal.at(size-1)==focal.at(i)) //if the moves are the same as the previous game
        {
          opponent.at(i+1)==playC?numC++:numD++;   //add the opponents response to the game
        }
        
        
     }
     predictedMove = numC>numD?playC:playD;        //the predicted move is which ever is greater C plays or D plays
     
     if(numC+numD>=mNumRounds)                     //if we have enough sample rounds to make a prediction
     {
        if(predictedMove == playC && ((numC*100/(numC+numD))>=pCert))   //if the predicted C move is at least 95% of the responses played
        {
           return playD;                                                //counter with a D play
           
        }
        else if(predictedMove == playD && (numD*100/(numC+numD)>=pCert))//if the predicted C move is at least 95% of the responses played
        {
           return playC;                                                //counter with a C play
        }
     }
     
     //if we couldn't make a reliable prediction then use this strategy:
     //  -play C if the same moves were played in the last game
     //  -play D if the moves were different in the last game
     return opponent.at(opponent.size()-1)==focal.at(focal.size()-1)? playC:playD;
  }
}

/*

I expect this agent to do well because the default strategy was the strongest against any agent I made and the prediction strategy should keep
the agent from being exploited and losing points to D/D games.

The first part of the strategy tries to make an accurate prediction of the opponents next move
 -if they are going to play C get all the points we can with D
 -if they are going to play D at least get some of the points by playing C
I got the numbers I used for mNumRounds(minimum number of same games played) and pCert(the lowest percent for a prediction to be made)
by evolving the agent. I had ichMain.cpp play multiple times while iterating nNumRounds and pCert. I saved the numbers with the highest score
and used them in this agent.

The default strategy is:
   -play C if the same moves were played in the last game
   -play D if the moves were different in the last game
*/
