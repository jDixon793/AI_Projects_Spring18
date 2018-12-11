// YOUR NAME: Brian Leary
//
// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors

#include "rps.h"

handsign rpsAgentTheLegend27(const vector<handsign> focal, const vector<handsign> opponent)
{
	// Return a random choice for the first 5 rounds, 
	// but weight the choices based on their possible point worth
	if (focal.size() <= 5)
	{
		int r = randomInt(100);
		if (r < 50)
		{
			return rock;
		}
		if (r < 80)
		{
			return scissors;
		}
		return paper;
	}
	
	// Check to see if the opponent is constantly playing the same handsign
	// Don't start this check until at least 5 rounds have been played, because
	// it will check to see if the last 5 opponent handsigns were the same.
	if (opponent.back() == rock)
	{
		for (int i = 1; i <= 5; i += 1)
		{
			if (opponent.at(focal.size() - i) != rock)
			{
				break;
			}
			if (i == 5)
			{
				return paper;
			}
		}
	}
	
	if (opponent.back() == paper)
	{
		for (int i = 1; i <= 5; i += 1)
		{
			if (opponent.at(focal.size() - i) != paper)
			{
				break;
			}
			if (i == 5)
			{
				return scissors;
			}
		}
	}
	
	if (opponent.back() == scissors)
	{
		for (int i = 1; i <= 5; i += 1)
		{
			if (opponent.at(focal.size() - i) != scissors)
			{
				break;
			}
			if (i == 5)
			{
				return rock;
			}
		}
	}
	
	// Check to see if the opponent is copying the agent's previous move.
	for (int i = 1; i <= 5; i += 1)
	{
		if (focal.at(focal.size() - i - 1) != opponent.at(focal.size() - i))
		{
			break;
		}
		if (i == 5)
		{
			if (focal.back() == rock)
			{
				return paper;
			}
			if (focal.back() == paper)
			{
				return scissors;
			}
			return rock;
		}
	}
	
	// Check to see if the opponent played the same handsign for the past
	// two rounds. If they did, assume that they will change on the next round
	// and play accordingly.
	if (opponent.at(focal.size() - 1) == opponent.at(focal.size() - 2))
	{
		if (opponent.back() == rock)
		{
			return rock;
		}
		if (opponent.back() == paper)
		{
			return paper;
		}
		if (opponent.back() == scissors)
		{
			return scissors;
		}
	}
	
	
	
	// If the agent won the previous round, assume the opponent will most 
	// likely change their handsign accordingly, so try to stay ahead and
	// play against what the agent assumes the opponent will play.
	if (outcome(focal.back(), opponent.back()) > 0)
	{
		if (focal.back() == rock)
		{
			return scissors;
		}
		if (focal.back() == paper)
		{
			return rock;
		}
		return paper;
	}
	
	// If the agent tied the previous round, play a weighted random choice,
	// heavily preferring that the next handsign will be different from the previous.
	if (outcome(focal.back(), opponent.back()) == 0)
	{
		if (focal.back() == rock)
		{
			int r = randomInt(100);
			if (r < 10)
			{
				return rock;
			}
			if (r < 55)
			{
				return scissors;
			}
			return paper;
		}
		if (focal.back() == paper)
		{
			int r = randomInt(100);
			if (r < 10)
			{
				return paper;
			}
			if (r < 55)
			{
				return scissors;
			}
			return rock;
		}
		int r = randomInt(100);
		if (r < 10)
		{
			return scissors;
		}
		if (r < 55)
		{
			return rock;
		}
		return paper;
	}
	
	// If the agent lost the previous round, return what the opponent played in the
	// previous round.
	return opponent.back();
}

/*
I made the first 5 choices random so that I could get some results to work with for the rest of the code.
The randomness was weighted, however, to prefer rock over scissors over paper. These weights are based on
the possible score values that can be obtained when the agent wins with these handsigns.

A large part of the agent's actions is determined by whether or not it lost the previous round. Before it
takes action based on that, however, it will run a few checks based on the past 5 rounds to see if it can
tell how the opponent is playing. Some of these checks are based on the sample agents, which won't be part
of the agent challenge. I still included the checks in case some opponent agent decides to use these types
of playstyles in part of their code.

First, the agent prevents losing to an opponent who is playing the same handsign repeatedly. This is done
by analyzing the previous 5 opponent handsigns. If they are the same, the agent will play the handsign that 
will beat whatever handsign the opponent is playing repeatedly. This check runs every round once 5 rounds have
been played, regardless of whether the agent won or lost the previous round. If the opponent only plays the 
same handsigns, the most rounds the agent can lose is the first 5.

Next, the agent checks to see if the opponent is copying the agent's previous move. If for the past 5 rounds,
the opponent has been copying the agent's moves, the agent will play in such a way that it will stay one step
ahead of the opponent, and win all subsequent rounds so long as the opponent continues to play in this fashion.

The agent then checks to see if the opponent played the same handsign for only the past two rounds. If this is
true, the agent plays that same handsign to try to stay ahead of the opponent predicting the agent's actions.

Once the checks are done, the agent determines its next move based on how it scored in the previous round.

If the agent won, assume the opponent will try to play a handsign to beat what the agent just played, and
play accordingly.

If the agent tied, prefer playing something different from the handsign that just tied, but allow for the
same handsign to be played again to make the agent less predictable.

If the agent lost, return what the opponent just played, as opposed to playing what will beat the opponent's
last move.

I tested my agent against Joey Lynch's, and discussed some ideas with him as we worked on this assignment.
I also tested it against James Dixon's.
*/
