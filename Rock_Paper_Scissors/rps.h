// CS 4318, spring 2017
// Agent Challenge 1: Rock, paper, scissors
//
// Here are the #includes and definitions available to each agent.

#ifndef RPS_H
#define RPS_H

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// The handsigns available for the agents to play.
enum handsign {rock, paper, scissors};

// Returns the focal player's outcome given the two handsigns.
int outcome(handsign focal, handsign opponent);

// Returns a random integer between 0 and n - 1.
int randomInt(int n);

#endif // #ifndef RPS_H
