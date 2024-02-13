#pragma once
#include <string>

using namespace std;

static string userInputRaw;
static string userInputRefined;
static string spoofedFruit;
static string tryPond;
static int tryCounter;
static int posHit = -1;

static bool triedThatBefore = false;
static bool isTrySuccessfull = false;
static bool isWordRevealed = false;
static bool isGameOver = false;
static bool isGameGoingOn = false;

string spoofFruit(string fruitToFind, string spoofedFruit);

int getFruitLength(string fruitToFind, int fruitLength);

int getCounter(string fruitToFind, int fruitLength);

string getRefinedLetter(string userInputRaw);

bool checkIftriedThatBefore(string spoofedFruit, int fruitLength, string userInputRefined);

int findLetterPosition(string fruitToFind, string userInputRefined);

bool checkIfIsTrySuccessfull(int posHit);

string updateSpoofedFruit(string fruitToFind, int fruitLength, string spoofedFruit, string userInputRefined);

string addToTryPond(string userInputRefined, bool isTrySuccessfull);

int addToTryCounter(bool isTrySuccessfull);

bool checkIfIsWordRevealed(string spoofedFruit);

bool checkIfIsGameOver(int tryCounter);

bool checkIfIsGameGoingOn(bool isWordRevealed, bool isGameOver);