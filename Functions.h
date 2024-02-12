#pragma once
#include <string>

using namespace std;

string userInputRaw;
string userInputRefined;
string spoofedFruit;
int tryCounter;
string tryPond;

bool isTrySuccessfull;
bool wordRevealed = false;
bool gameOver = false;

string spoofFruit(string fruitToFind);
int getFruitLength(string fruitToFind);
int getCounter(string fruitToFind);
string getRefinedLetter(string userInputRaw);
bool checkIfTriedBefore(string spoofedFruit, int fruitLength, string userInputRefined);
int findLetterPosition(string fruitToFind, string userInputRefined);
bool checkIfIsTrySuccessfull(int posHit);
string updateSpoofedFruit(string fruitToFind, int fruitLength, string spoofedFruit, string userInputRefined);