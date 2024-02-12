#pragma once
#include <string>
#include "WordPool.h";

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
int getCounter(string fruitToFind, int fruitLength, int tryCounter) {
    tryCounter;
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
string getRefinedLetter(string userInputRaw, string userInputRefined) {
    if (!userInputRaw.empty()) {
        char firstChar = tolower(userInputRaw[0]);
        userInputRefined += firstChar;
    }
    return userInputRefined;
}

// Checks whether the user has already typed a letter by checking if it has already been added to spoodedFruit
bool checkIfTriedBefore(string spoofedFruit, int fruitLength, string userInputRefined, bool triedThatBefore) {
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
int findLetterPosition(string fruitToFind, string userInputRefined, int posHit) {
    posHit = -1;
    posHit = fruitToFind.find(userInputRefined);
    return posHit;
}

// Checks whether the guessed letter matches one in fruitToFind
bool checkIfIsTrySuccessfull(int posHit, bool isTrySuccessfull) {
    isTrySuccessfull = false;
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
string addToTryPond(string userInputRefined, bool isTrySuccessfull, string tryPond) {
    if (!isTrySuccessfull) {
        tryPond = tryPond.append(userInputRefined + " ");
    }
    return tryPond;
}

// Lowers -1 of tryCounter if try was unsuccessfull
string addToTryCounter(bool isTrySuccessfull, int tryCounter) {
    if (!isTrySuccessfull) {
        tryCounter = (tryCounter - 1);
    }
    return tryCounter;
}
