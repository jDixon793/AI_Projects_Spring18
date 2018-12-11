// CS 4318, spring 2017
// Agent Challenge 4: Cricket card game
//
// Here's an example agent function.

#include "ccg.h"

int ccgAgentDefensive(Hand hand, Card lastBowledCard, bool isBatting, const MatchState &match)
{
   Card card;
   int bestCard, bestScore, score, whichCard;

   if (isBatting)
   {
      // When batting, play the first card you see that doesn't lose a
      // wicket (and otherwise card 0).
      bestScore = 0;
      bestCard = 0;
      for (whichCard = 0; whichCard < numCardsPerHand; whichCard += 1)
      {
         card = hand.getCard(whichCard);
         score = 0;
         if (card.getSuit() == lastBowledCard.getSuit() ||
             card.getNumber() >= lastBowledCard.getNumber())
         {
            score += 100;
         }
         if (score > bestScore)
         {
            bestScore = score;
            bestCard = whichCard;
         }
      }
      return bestCard;
   }
   else // is bowling
   {
      // When bowling, play the first card you see that's higher than the
      // last card bowled (and otherwise card 0).
      bestScore = 0;
      bestCard = 0;
      for (whichCard = 0; whichCard < numCardsPerHand; whichCard += 1)
      {
         card = hand.getCard(whichCard);
         score = 0;
         if (card.getNumber() > lastBowledCard.getNumber())
         {
            score += 100;
         }
         if (score > bestScore)
         {
            bestScore = score;
            bestCard = whichCard;
         }
      }
      return bestCard;
   }
}
