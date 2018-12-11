// CS 4318, spring 2018
// Agent Challenge 2: Iterated chicken
//
// Here's the main function that plays all agents against each other and
// summarizes the results.

#include "ich.h"

extern const int numAgents;
extern strategy (*agentFunc[])(const vector<strategy>, const vector<strategy>);
extern string agentStr[];

void printHistory(const vector<strategy>);

int main()
{
   const int numRounds = 1000;   // Change if you like.
   int best[numAgents], countCC[numAgents], countCD[numAgents],
       countDC[numAgents], countDD[numAgents], i, j, losses[numAgents],
       matchupScoreI, matchupScoreJ, order[numAgents], round, temp,
       ties[numAgents], totalScore[numAgents], wins[numAgents],
       worst[numAgents];
   strategy stratI, stratJ;
   vector<strategy> histI, histJ;
        int maxPoints=0;
     int bestNum =0;
     int bestPercent=0;
   //while(getRounds()<50)
{
   setPercent(getPercent()+15);
   if(getPercent()>97)
   {
      setPercent(50);
      setRounds(getRounds()+1);
   }
   cout << "Agent Challenge 2: Iterated chicken\n"
        << "Iteration results\n\n"
        << "One-on-one contests:\n\n";
   for (i = 0; i < numAgents; i += 1)
   {
      countCC[i] = countCD[i] = countDC[i] = countDD[i] = 0;
      losses[i] = ties[i] = totalScore[i] = wins[i] = 0;
      best[i] = INT_MIN;
      worst[i] = INT_MAX;
   }
   for (i = 0; i < numAgents - 1; i += 1)
   {
      for (j = i + 1; j < numAgents; j += 1)
      {
         histI.clear();
         histJ.clear();
         matchupScoreI = matchupScoreJ = 0;
         for (round = 0; round < numRounds; round += 1)
         {
            stratI = (*agentFunc[i])(histI, histJ) == playC ? playC : playD;
            stratJ = (*agentFunc[j])(histJ, histI) == playC ? playC : playD;
            histI.push_back(stratI);
            histJ.push_back(stratJ);
            matchupScoreI += outcome(stratI, stratJ);
            matchupScoreJ += outcome(stratJ, stratI);
            if (stratI == playC)
            {
               if (stratJ == playC)
               {
                  countCC[i] += 1;
                  countCC[j] += 1;
               }
               else
               {
                  countCD[i] += 1;
                  countDC[j] += 1;
               }
            }
            else
            {
               if (stratJ == playC)
               {
                  countDC[i] += 1;
                  countCD[j] += 1;
               }
               else
               {
                  countDD[i] += 1;
                  countDD[j] += 1;
               }
            }
         }
         if (matchupScoreI > matchupScoreJ)
         {
            wins[i] += 1;
            losses[j] += 1;
         }
         else if (matchupScoreI < matchupScoreJ)
         {
            losses[i] += 1;
            wins[j] += 1;
         }
         else
         {
            ties[i] += 1;
            ties[j] += 1;
         }
         totalScore[i] += matchupScoreI;
         totalScore[j] += matchupScoreJ;
         if (matchupScoreI > best[i])
         {
            best[i] = matchupScoreI;
         }
         if (matchupScoreI < worst[i])
         {
            worst[i] = matchupScoreI;
         }
         if (matchupScoreJ > best[j])
         {
            best[j] = matchupScoreJ;
         }
         if (matchupScoreJ < worst[j])
         {
            worst[j] = matchupScoreJ;
         }
         // cout << setw(20) << left << agentStr[i] << " " << setw(5) << right
              // << matchupScoreI << " ";
         // printHistory(histI);
         // cout << "\n";
         // cout << setw(20) << left << agentStr[j] << " " << setw(5) << right
              // << matchupScoreJ << " ";
         // printHistory(histJ);
         // cout << "\n\n";
      }
   }

   for (i = 0; i < numAgents; i += 1)
   {
      order[i] = i;
   }
   for (i = 0; i < numAgents - 1; i += 1)
   {
      for (j = i + 1; j < numAgents; j += 1)
      {
         if (totalScore[order[i]] < totalScore[order[j]] || (totalScore[order[i]] == totalScore[order[j]] &&
             agentStr[order[i]] > agentStr[order[j]]))
         {
            temp = order[i];
            order[i] = order[j];
            order[j] = temp;
         }
      }
   }
   cout << "\n"
        << "Overall standings:\n"
        << "                        total  W  T  L  best worst    DC    CC    CD    DD\n";
   for (i = 0; i < numAgents; i += 1)
   {
      cout << setw(20) << left << agentStr[order[i]]
           << " " << setw(8) << right << totalScore[order[i]]
           << " " << setw(2) << right << wins[order[i]]
           << " " << setw(2) << right << ties[order[i]]
           << " " << setw(2) << right << losses[order[i]]
           << " " << setw(5) << right << best[order[i]]
           << " " << setw(5) << right << worst[order[i]]
           << " " << setw(5) << right << countDC[order[i]]
           << " " << setw(5) << right << countCC[order[i]]
           << " " << setw(5) << right << countCD[order[i]]
           << " " << setw(5) << right << countDD[order[i]]
           << "\n";
   }
for (i = 0; i < numAgents; i += 1)
   {
      if(agentStr[i]=="Akira")
      {
         if(totalScore[i]>maxPoints);
         {
            maxPoints = totalScore[i];
            bestNum = getRounds();
            bestPercent = getPercent();
         if(getMax()<maxPoints)
         {
            setMax(maxPoints,getRounds(),getPercent());
         }
            cout<<"*****************************************************"<<maxPoints<<" - "<<getRounds()<<" - "<<getPercent()<<endl;
         }
      }
   }
}
 cout<<"*****************************************************"<<getMax()<<" - "<<getMRounds()<<" - "<<getMPercent()<<endl;
   return 0;
}

void printHistory(const vector<strategy> hist)
{
   int i;
   for (i = 0; i < static_cast<int>(hist.size()); i += 1)
   {
      cout << (hist.at(i) == playC ? 'C' : hist.at(i) == playD ? 'D' : '*');
   }
}
