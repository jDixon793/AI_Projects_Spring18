// YOUR NAME: James Dixon
//
// CS 4318, spring 2017
// Agent Challenge 4: Cricket card game
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this ccgAgentSmith.cpp file to ccgAgentJones.cpp and the
// ccgAgentSmith function below to ccgAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Random-number generation is not
// allowed; your agent must be entirely deterministic.  Feel free to create
// other agents--each in a separate .cpp file--for yours to play against,
// but turn in only one.  Test your agent(s) with
//
//    nice bash ccgBuild.bash
//
// and then
//
//    nice ./ccgRunSim
//
// Each submitted agent will play each other, batting first and batting
// second an equal number of times, to determine the standings, which will
// be posted soon after the agents are due.

#include "ccg.h"
#include <vector>
using namespace std;

// Rename and complete this agent function.
int ccgAgentAntiJaxel(Hand hand, Card lastBowledCard, bool isBatting, const MatchState &match)
{
   // Your function must end up returning a valid int between 0 and numCardsPerHand - 1.
   // No random-number generation allowed!
   // hand.getCard(0) gives the first card in your hand.
   // hand.getCard(0).getNumber() gives the number of that card, 1 to 11.
   // hand.getCard(0).getSuit() gives the suit of that card.
   // match.getRuns(0) gives the number of runs scored by player A so far.
   // numRuns(d) gives the number of runs scored when the card difference is d.
   // See the definitions of Hand, Card and MatchState for more helpful functions.
   
   
   //When Batting your priority is as follows
   //1: Win some runs
   //2: Don't lose wickets
   //3: Play the lowest card possible
   if (isBatting)
   {
      int scoringCards[numCardsPerHand];
      int numScoringCards=0;
      int sameSuitKeepWktCards[numCardsPerHand];
      int numSameSuitKeepWktCards=0;
      int difSuitKeepWktCards[numCardsPerHand];
      int numDifSuitKeepWktCards=0;
      int whichCard;
      int lowestCardIndex=0;
      
      Card card;
      for (whichCard = 0; whichCard < numCardsPerHand; whichCard += 1)
      {
         card = hand.getCard(whichCard);
         //if same suit higher number
         if (card.getSuit() == lastBowledCard.getSuit() &&
             card.getNumber() > lastBowledCard.getNumber())
         {
            scoringCards[numScoringCards]=whichCard;
            numScoringCards++;
         }
         else if (card.getSuit() == lastBowledCard.getSuit() &&
             card.getNumber() <= lastBowledCard.getNumber())
         {
            sameSuitKeepWktCards[numSameSuitKeepWktCards]=whichCard;
            numSameSuitKeepWktCards++;
         }
         else if (card.getSuit() != lastBowledCard.getSuit() &&
             card.getNumber() > lastBowledCard.getNumber())
         {
            difSuitKeepWktCards[numDifSuitKeepWktCards]=whichCard;
            numDifSuitKeepWktCards++;
         }
         
         if(card.getNumber()>hand.getCard(lowestCardIndex).getNumber())
         {
            lowestCardIndex = whichCard;   
         }
      }
      
      if(numScoringCards>0)
      {
         int highestScore=0;
         int highestScoreIndex=scoringCards[0];
         for(int i =0;i<numScoringCards;i++) 
         {
            if(numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber())>highestScore)
            {
               highestScore = numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber());
               highestScoreIndex = i;
            } else if(numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber())==highestScore)
            {
               //if the scores are equal then keep the lowest number card
               if(hand.getCard(scoringCards[i]).getNumber() > hand.getCard(scoringCards[highestScoreIndex]).getNumber()){
                   highestScoreIndex = i;
               }
            }
         }
         //cout<< "Score" << endl;
         return scoringCards[highestScoreIndex];
      }
      else if(numSameSuitKeepWktCards>0)
      {
         int lowestNum=12;
         int lowestNumIndex=0;
         for(int i =0;i<numSameSuitKeepWktCards;i++) 
         {
            if(hand.getCard(sameSuitKeepWktCards[i]).getNumber()>lowestNum)
            {
               lowestNum = hand.getCard(sameSuitKeepWktCards[i]).getNumber();
               lowestNumIndex = i;
            } 
         }
         //cout<<"Same Suit Less"<<endl;
         return sameSuitKeepWktCards[lowestNumIndex];
      }
      else if(numDifSuitKeepWktCards>0)
      {
         int lowestNum=12;
         int lowestNumIndex=0;
         for(int i =0;i<numDifSuitKeepWktCards;i++) 
         {
            if(hand.getCard(difSuitKeepWktCards[i]).getNumber()>lowestNum)
            {
               lowestNum = hand.getCard(difSuitKeepWktCards[i]).getNumber();
               lowestNumIndex = i;
            } 
         }
         //cout<<"Dif Suit Less"<<endl;
         return difSuitKeepWktCards[lowestNumIndex];
      }
      else{
         //cout<<"Lowest"<<endl;
         return lowestCardIndex;
      }
   }
   else // is bowling
   {
      // When bowling always play the highest card you have unless that card would 
      // make a "wide" or "bye" condition be true 
      int whichCard;
      Card card;
      int highestCardIndex=-1;
       for (whichCard = 0; whichCard < numCardsPerHand; whichCard += 1)
      {
         card = hand.getCard(whichCard);
         if(highestCardIndex==-1&&card.getNumber()!=lastBowledCard.getNumber()&&card.getNumber()!=(lastBowledCard.getNumber()+1))
         {
            highestCardIndex=whichCard;
         }
         else if(card.getNumber()>hand.getCard(highestCardIndex).getNumber()&&card.getNumber()!=lastBowledCard.getNumber()&&card.getNumber()!=(lastBowledCard.getNumber()+1))
         {
            highestCardIndex = whichCard;   
         }
      }
      return highestCardIndex;
   }
}

/*

If you can score runs always do that. Pick the card with the highest runs and the lowest number.
If you can play a card of the same suit with a lower or equal number. Play the lowest card.
If you can play a higher or equal card of the same suit. Play the lowest card.
Else play the lowest card in you hand.

*/
