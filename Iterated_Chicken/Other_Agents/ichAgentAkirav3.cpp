// James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken

#include "ich.h"

strategy ichAgentAkirav3(const vector<strategy> focal, const vector<strategy> opponent)
{
   if(focal.size() < 1)                            //if the move list is less than 1 it is the first turn
   {                       
      return playD;                                //play C as the first move
   }
   int scores[10]={0,0,0};
   strategy moves[10]={playC,playC,playC};
   for(int x = opponent.size()-1;x>2&&focal.size()>2;x--)    //Calculate the number of D's that have been played by the opponent
  {
     
     moves[0] = opponent.at(x-1)==focal.at(x-1)? playC:playD;
     scores[0] += outcome(moves[0],opponent.at(x));
     
     moves[1] = outcome(playC,opponent.at(x-1)) > outcome(playD,opponent.at(x-1)) ? playC:playD;
     scores[1] += outcome(moves[1],opponent.at(x));
     
     moves[2] = opponent.at(x-1);
     scores[2] += outcome(moves[2],opponent.at(x));
     
  }
  int topScoreIndex=0;
  for(int i=0;i<3;i++)
  {
     if(scores[i]>scores[topScoreIndex])
     {
        topScoreIndex = i;
     }
  }
     return moves[topScoreIndex];
}

/*

      This Agent wants to play C the whole game unless the opponent plays D
      -if the opponent plays a D then return the favor
      -each time the opponent plays a D the number of retaliation D-plays increases
      for instance, if the opponent plays their 3rd D of the game then this Agent will play D for the next 3 moves
      this should do a good job of encouraging cooperation and punishing defectors
*/
