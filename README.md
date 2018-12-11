# AI_Projects_Spring18
A few of the projects that I did well on in CS4318: Artificial Intelligence

Rock Paper Scissors-
Plays Rock Paper Scissors agains other AI agents. This agent was the top in the class.
I created multiple agents with different approaches and this method won the most with the most points.
Because this game of rock-paper-scissors is about winning the most points, I decided to focus on the 
agent maximizing the number of points it recieves instead of the number of rounds won. Using only the last
ten rounds makes this agent much more flexable and reactive than if it considered all the rounds.
This agent has 3 parts. 
-Offessively looks for patterns that it can exploit. If it finds one then exploit it.
-Netrually chooses a move based on the weighted probability of points from the last 10 rounds
-Defensively chooses a move using the probability weights we used in class if has lost a lot in the previous rounds

Iterated Chicken-
Plays the game theory game iterated chicken against other AI agents. Using the folling logic:
The first part of the strategy tries to make an accurate prediction of the opponents next move
 -if they are going to play C get all the points we can with D
 -if they are going to play D at least get some of the points by playing C
I got the numbers I used for mNumRounds(minimum number of same games played) and pCert(the lowest percent for a prediction to be made)
by evolving the agent. I had ichMain.cpp play multiple times while iterating nNumRounds and pCert. I saved the numbers with the highest score
and used them in this agent.
The default strategy is:
   -play C if the same moves were played in the last game
   -play D if the moves were different in the last game

Cricket Card Game-
Plays the card game version of Cricket vs other AI agents. Using the following logic:
If you can score runs always do that. Pick the card with the highest runs and the lowest number.
If you can play a card of the same suit with a lower or equal number. Play the lowest card.
If you can play a higher or equal card of the same suit. Play the lowest card.
Else play the lowest card in you hand.
Attempted to make bowling better by playing the same suit back to back but my other agents kept beating it
