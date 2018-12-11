// YOUR NAME: James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken

#include "ich.h"


strategy ichAgentGetToKnowYouv5(const vector<strategy> focal, const vector<strategy> opponent)
{

   uint size = focal.size();                       //convenience variable
   if(size < 3)                                    //
      return playD;
  else  
  {
     int numC=0;
     int numD=0;
     int mNumRounds=24;
     int pCert = 75;
     strategy predictedMove = playC;
     for(uint i = size-2;i>0&&i>size-100;i--)
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
           return playD;
           
        }
        else if(predictedMove == playD && (numD*100/(numC+numD)>=pCert))
        {
           return playC;
        }
     }
     return opponent.at(opponent.size()-1)==focal.at(focal.size()-1) && opponent.at(opponent.size()-2)==focal.at(focal.size()-2) ? playC:playD;
  }
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
