/*
Andrew Crandall
CSC 160
12/4/2021
Title: Declarations file for myFunctions
Summary: Declare functions contained within myFunctions.cpp
*/

#ifndef MYFUNCTS_H // start of myFuncts.h
#define MYFUNCTS_H

#include <string> // includes string
#include <cctype> // allows for toupper and tolower functions
#include <iostream> // allows for input/output to console
#include <string.h>


#define PLAY 1
#define STOP 0
#define ERROR -1


/*
Declare Functions
-----------------
int promptYn, needs string input
string strToUpper, needs string input
string strToLower, needs string input
string drawBoards, needs int input
char charToUpper, needs char input
bool letterCheck, needs char and string input
*/

int promptYN(std::string reply);
std::string strToUpper(std::string str);
std::string strToLower(std::string str);
std::string drawBoards(int wrongGuesses);
char charToUpper(char letter);
bool letterCheck(char letter, std::string word);
int binarySearch(char usedLetters[], char letterToGuess, int used);
void bubbleSort(char nums[], int used);


#endif // end of myFuncts.h