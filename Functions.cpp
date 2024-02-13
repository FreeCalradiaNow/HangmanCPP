#pragma once
#include "Functions.h"
#include "WordPool.h";
#include <string>

using namespace std;

// Returns string spoofedFruit with a "_" for each non whitespace char in fruitToFind
string spoofFruit(string fruitToFind, string spoofedFruit) {
    spoofedFruit = "";
    for (char c : fruitToFind) {
        if (c != ' ') {
            spoofedFruit += '_';
        }

        else {
            spoofedFruit += ' ';
        }
    }
    return spoofedFruit;
}

// Returns int fruitLength based on fruitToFind
int getFruitLength(string fruitToFind, int fruitLength) {
    fruitLength = fruitToFind.length();
    return fruitLength;
}

// Returns a int tryCounter based on fruitLength
int getCounter(string fruitToFind, int fruitLength) {
    if (fruitLength > 8 && fruitLength < 14) {
        tryCounter = fruitLength + 1;
    }
    else if (fruitLength <= 8) {
        tryCounter = 7;
    }
    else {
        tryCounter = 15;
    }
    return tryCounter;
}

// Returns string userInputRefined from string userInputRaw
string getRefinedLetter(string userInputRaw) {
    if (!userInputRaw.empty()) {
        char firstChar = tolower(userInputRaw[0]);
        userInputRefined += firstChar;
    }
    return userInputRefined;
}

// Checks whether the user has already typed a letter by checking if it has already been added to spoodedFruit
bool checkIftriedThatBefore(string spoofedFruit, int fruitLength, string userInputRefined) {
    triedThatBefore = false;
    for (string::size_type i = 0; i < fruitLength; ++i) {
        if (spoofedFruit[i] == userInputRefined[0]) {
            triedThatBefore = true;
            break;
        }
    }
    return triedThatBefore;
}

// Returns int posHit from string fruitToFind, string userInputRefined - position where letter matches string or npos
int findLetterPosition(string fruitToFind, string userInputRefined) {
    posHit = fruitToFind.find(userInputRefined);
    return posHit;
}

// Checks whether the guessed letter matches one in fruitToFind
bool checkIfIsTrySuccessfull(int posHit) {
    if (posHit != string::npos) {
        isTrySuccessfull = true;
    }
    return isTrySuccessfull;
}

// Returns spoofedFruit with letters instead of "_" where guessed letter matched position in fruitToFind
string updateSpoofedFruit(string fruitToFind, int fruitLength, string spoofedFruit, string userInputRefined) {
    for (string::size_type i = 0; i < fruitLength; ++i) {
        if (fruitToFind[i] == userInputRefined[0]) {
            spoofedFruit[i] = userInputRefined[0];
        }
    }
    return spoofedFruit;
}

// Adds unsuccessfull guess to tryPond
string addToTryPond(string userInputRefined, bool isTrySuccessfull) {
    if (!isTrySuccessfull) {
        tryPond = tryPond.append(userInputRefined + " ");
    }
    return tryPond;
}

// Lowers -1 of tryCounter if try was unsuccessfull
int addToTryCounter(bool isTrySuccessfull) {
    if (!isTrySuccessfull) {
        tryCounter = (tryCounter - 1);
    }
    return tryCounter;
}

// Checks if word has been revealed by checking for npos
bool checkIfIsWordRevealed(string spoofedFruit) {
    if (spoofedFruit.find("_") == string::npos) {
        isWordRevealed = true;
    }
    return isWordRevealed;
}

// Checks if game has been lost by checking the tryCounter
bool checkIfIsGameOver(int tryCounter) {
    if (tryCounter < 1) {
        isGameOver = true;
    }
    return isGameOver;
}

// Checks if game is going on by checking for win/lose conditions
bool checkIfIsGameGoingOn(bool isWordRevealed, bool isGameOver) {
    if (!isWordRevealed && !isGameOver) {
        isGameGoingOn = true;
    }
    return isGameGoingOn;
}