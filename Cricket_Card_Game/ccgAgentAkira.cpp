// YOUR NAME: James Dixon
//
// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game

#include "ccg.h"
#include <vector>
using namespace std;

int ccgAgentAkira(Hand hand, Card lastBowledCard, bool isBatting, const MatchState &match)
{
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
         //if same suit higher number add card to the array
         if (card.getSuit() == lastBowledCard.getSuit() &&
             card.getNumber() > lastBowledCard.getNumber())
         {
            scoringCards[numScoringCards]=whichCard;
            numScoringCards++;
         }
         //if same suit lower or equal number add card to the array
         else if (card.getSuit() == lastBowledCard.getSuit() &&
             card.getNumber() <= lastBowledCard.getNumber())
         {
            sameSuitKeepWktCards[numSameSuitKeepWktCards]=whichCard;
            numSameSuitKeepWktCards++;
         }
         //if dif suit and greater number add card to the array
         else if (card.getSuit() != lastBowledCard.getSuit() &&
             card.getNumber() >= lastBowledCard.getNumber())
         {
            difSuitKeepWktCards[numDifSuitKeepWktCards]=whichCard;
            numDifSuitKeepWktCards++;
         }
         //find the lowest number
         if(card.getNumber()<hand.getCard(lowestCardIndex).getNumber())
         {
            lowestCardIndex = whichCard;   
         }
      }
      
      //if we can score fin the lowest number with the highest score
      if(numScoringCards>0)
      {
         int highestScore=0;
         int highestScoreIndex=scoringCards[0];
         for(int i =0;i<numScoringCards;i++) 
         {
            //if the score is higher
            if(numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber())>highestScore)
            {
               highestScore = numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber());
               highestScoreIndex = i;
            } 
            //if the score is the same but the card number is lower
            else if(numRuns(hand.getCard(scoringCards[i]).getNumber()-lastBowledCard.getNumber())==highestScore)
            {
               //if the scores are equal then keep the lowest number card
               if(hand.getCard(scoringCards[i]).getNumber() < hand.getCard(scoringCards[highestScoreIndex]).getNumber()){
                   highestScoreIndex = i;
               }
            }
         }
         //cout<< "Score" << endl;
         return scoringCards[highestScoreIndex];
      }
      
      //if we can not lose a wicket
      else if(numSameSuitKeepWktCards>0)
      {
         int lowestNum=12;
         int lowestNumIndex=0;
         for(int i =0;i<numSameSuitKeepWktCards;i++) 
         {
            if(hand.getCard(sameSuitKeepWktCards[i]).getNumber()<lowestNum)
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
            if(hand.getCard(difSuitKeepWktCards[i]).getNumber()<lowestNum)
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
      // if we find a high card of the same suit play that card
      
      int whichCard;
      Card card;
      int highestCardIndex=-1;
      int lSuit = lastBolwedCard.getSuit();
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
         else if(card.getNumber()==hand.getCard(highestCardIndex).getNumber()&&card.getSuit==lSuit)&&card.getNumber()!=lastBowledCard.getNumber()&&card.getNumber()!=(lastBowledCard.getNumber()+1))
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
Attempted to make bowling better by playing the same suit back to back but my other agents kept beating it
*/
