// James "Ryan" Crawford
// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
#include "rps.h"
#include <cmath>

handsign rpsAgentPHDinCatBehavior(const vector<handsign> focal, const vector<handsign> opponent)
{
  vector<handsign> histC, histSHEA,histMe,histDECAY;//used to iterate my choices if needed
  //int p1,p2,p3; //used to hold how many points each strat would have won
  int oppR = 0;
  int oppP = 0;
  int oppS = 0;//used to record how often the opponent played a move
  int meR = 0;
  int meP = 0;
  int meS = 0;//used to record how often I played a move
  int r = randomInt(3);//used to enact a random number
  int score =0;
  int Cscore = 0;
  int SHEAscore = 0;
  int MEscore = 0;
  int DEscore = 0;
  float rateR = 0;
  float rateP = 0;
  float rateS = 0;
  double number = 0;
  
  
  if(opponent.size() != 0)
  {
	for(unsigned i = 0; i != focal.size(); i++)//iterates through the history of both players
	{
		rateR *= 0.95;
		rateS *= 0.95;
		rateP *= 0.95;
		
		if(focal.at(i) == rock){meR+=1;}
		else if(focal.at(i) == paper){meP+=1;}
		else if(focal.at(i) == scissors){meS+=1;}
			
	    if(opponent.at(i) == rock)
		{
			oppR += 1;
			rateP += 0.1;
			rateS -= 0.1;
		}
		else if(opponent.at(i) == paper)
		{
			oppP += 1;
			rateS += 0.1;
			rateR -= 0.1;
		}
		else if(opponent.at(i) == scissors)
		{
			oppS += 1;
			rateR += 0.1;
			rateP -= 0.1;
		}
		
		number = ((randomInt(1000000000)/1000000000)*exp(rateR))+exp(rateS)+exp(rateP);
		  
		if(number < exp(rateR)){histDECAY.push_back(rock);}
		else if(number < exp(rateR) + exp(rateP)){histDECAY.push_back(paper);}
		else{histDECAY.push_back(scissors);}
		  
		if(oppS >= oppP && oppS>=oppR){histC.push_back(rock);}
		if(oppR >= oppP && oppR>=oppS){histC.push_back(paper);}
		if(oppP >= oppS && oppP>= oppR){histC.push_back(scissors);}
		  
		if(meS>=meP && meS>=meR){histMe.push_back(paper);}
		if(meR>=meP && meR>=meS){histMe.push_back(scissors);}
		if(meP>=meS && meP>=meR){histMe.push_back(rock);}
		  
		if(i%3 == 0 && i != 0)
		{
			int r = randomInt(2);
			if (r+1 < 2)
			{
				histSHEA.push_back(paper);
			}
			histSHEA.push_back(scissors);
		}
		histSHEA.push_back(rock);
	  
	  
		if(focal.at(i) == rock && opponent.at(i) == paper ){score -= 1;}
		if(focal.at(i) == rock && opponent.at(i) == scissors ){score += 3;}
		if(focal.at(i) == paper && opponent.at(i) == rock ){score += 1;}
		if(focal.at(i) == paper && opponent.at(i) == scissors ){score -= 2;}
		if(focal.at(i) == scissors && opponent.at(i) == rock ){score -= 3;}
		if(focal.at(i) == scissors && opponent.at(i) == paper ){score += 2;}
		
		if(histSHEA.at(i) == rock && opponent.at(i) == paper ){SHEAscore -= 1;}
		if(histSHEA.at(i) == rock && opponent.at(i) == scissors ){SHEAscore += 3;}
		if(histSHEA.at(i) == paper && opponent.at(i) == rock ){SHEAscore += 1;}
		if(histSHEA.at(i) == paper && opponent.at(i) == scissors ){SHEAscore -= 2;}
		if(histSHEA.at(i) == scissors && opponent.at(i) == rock ){SHEAscore -= 3;}
		if(histSHEA.at(i) == scissors && opponent.at(i) == paper ){SHEAscore += 2;}
		
		if(histMe.at(i) == rock && opponent.at(i) == paper ){MEscore -= 1;}
		if(histMe.at(i) == rock && opponent.at(i) == scissors ){MEscore += 3;}
		if(histMe.at(i) == paper && opponent.at(i) == rock ){MEscore += 1;}
		if(histMe.at(i) == paper && opponent.at(i) == scissors ){MEscore -= 2;}
		if(histMe.at(i) == scissors && opponent.at(i) == rock ){MEscore -= 3;}
		if(histMe.at(i) == scissors && opponent.at(i) == paper ){MEscore += 2;}
		
		if(histC.at(i) == rock && opponent.at(i) == paper ){Cscore -= 1;}
		if(histC.at(i) == rock && opponent.at(i) == scissors ){Cscore += 3;}
		if(histC.at(i) == paper && opponent.at(i) == rock ){Cscore += 1;}
		if(histC.at(i) == paper && opponent.at(i) == scissors ){Cscore -= 2;}
		if(histC.at(i) == scissors && opponent.at(i) == rock ){Cscore -= 3;}
		if(histC.at(i) == scissors && opponent.at(i) == paper ){Cscore += 2;}
		
		if(histDECAY.at(i) == rock && opponent.at(i) == paper ){DEscore -= 1;}
		if(histDECAY.at(i) == rock && opponent.at(i) == scissors ){DEscore += 3;}
		if(histDECAY.at(i) == paper && opponent.at(i) == rock ){DEscore += 1;}
		if(histDECAY.at(i) == paper && opponent.at(i) == scissors ){DEscore -= 2;}
		if(histDECAY.at(i) == scissors && opponent.at(i) == rock ){DEscore -= 3;}
		if(histDECAY.at(i) == scissors && opponent.at(i) == paper ){DEscore += 2;}
		
	}
		int hold = 0;
		if(DEscore >= Cscore && DEscore >= MEscore && DEscore >= SHEAscore)
		{hold = 4;}
		else if(Cscore >= DEscore && Cscore >= MEscore && Cscore >= SHEAscore)
		{hold = 3;}
		else if(MEscore >=DEscore && MEscore >= Cscore && MEscore >= SHEAscore)
		{hold = 2;}
		else if(SHEAscore >= DEscore && SHEAscore >= Cscore && SHEAscore>=MEscore )
		{hold = 1;}
		
	switch(hold)
	{
		case 1:
			if(focal.size()%3 == 0 && focal.size() != 0)
			{
				int r = randomInt(2);
				if (r+1 < 2)
				{return scissors;}
				return rock;
			}
			return paper;
		break;
		
		case 2:
			if(meS >= meP && meS>=meR){return paper;}
			if(meR >  meP && meR>meS){return scissors;}
			if(meP > meS && meP> meR){return rock;}
		break;
	 
		case 3:
			if(oppS >= oppP && oppS>=oppR){return paper;}
			if(oppR > oppP && oppR>oppS){return scissors;}
			if(oppP > oppS && oppP> oppR){return rock;}
		break;
		
		case 4://decay frequency http://www.rpscontest.com/entry/13015
			if(number < exp(rateR)){return scissors;}
			else if(number < exp(rateR) + exp(rateP)){return rock;}
			else {return paper;}
		break;
		
		default:
			if (r < 1)
			{return rock;}
			if (r < 2)
			{return paper;}
			return scissors;
	}
  }
  return rock;
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.

*/
