#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
#pragma region Textblocks/ Style

    // Style elements
    string mFHeader = "                               ----->   This is Hangman Fruity Shores  <-----                              ";
    string mFLong = "==================================================================================================================";
    string mFSidebarL = "\n||  ";
    string mFSidebarR = "  ||";
    string crlf = "\n";
    string tab = "\t";

    // Reuseable textblocks
    string legoText1 = "Guess the word: ";
    string legoText2 = " You still have ";
    string legoText3 = " failed attempts left.";
    string legoText4 = "";

#pragma endregion

#pragma region Properties

    // Properties
    string fruitToFind;
    string spoofedFruit;
    string userInputRaw;
    int tryCounter;

    bool wordRevealed = false;
    bool gameOver = false;

#pragma endregion

#pragma region Start Message

    // Welcome/ Introduction
    cout << mFLong << mFSidebarL + mFHeader + mFSidebarR << endl;
    cout << mFSidebarL + "You have to guess a fruit by guessing what letters the word may contain while you have still attempts left." + mFSidebarR << "\n" + mFLong + "\n\n\n" << endl;

#pragma endregion

#pragma region Random word/ spoofing

    // Fruit array fruits
    string fruits[] = {
        "apple", "apricot", "avocado", "banana", "bilberry", "blackberry", "blackcurrant", "blood orange", "blueberry", "boysenberry", "breadfruit", "cantaloupe", "cherimoya", "cherry", 
        "chico fruit", "cloudberry", "coconut", "cranberry", "cucumber", "currant", "custard apple", "damson", "date", "dragonfruit", "durian", "grape", "grapefruit", "guava", "honeydew", 
        "huckleberry", "jackfruit", "jambul", "jujube", "kiwano", "kiwi", "kumquat", "lemon", "lime", "loquat", "longan", "lychee", "mandarine", "mango", "mangosteen", "marionberry",
        "melon", "mulberry", "nectarine", "nance", "orange", "papaya", "passionfruit", "peach", "pear", "persimmon",  "physalis", "pineapple", "plum", "pomegranate", "pomelo",
        "purple mangosteen", "quince", "raisin", "rambutan", "raspberry", "redcurrant", "rock melon", "salal berry", "satsuma", "star fruit", "strawberry", "tamarillo", "tangerine", 
        "ugli fruit", "watermelon", "white currant", "white sapote", "yuzu", "zucchini", "acai" 
    };

    int size = sizeof(fruits) / sizeof(fruits[0]);
    // Seed the random number generator
    srand(time(NULL));
    // Pick a random index from the array
    int randomIndex = rand() % size;

    fruitToFind = fruits[randomIndex];
    
    // SpoofedFruit gets \"_\" for each letter in fruitToFind. Whitespaces are excluded
    for (char c : fruitToFind) {
        if (c != ' ') {
            spoofedFruit += '_';
        }
        else {
            spoofedFruit += ' ';
        }
    }

    // Defined counter
    int fruitLength = fruitToFind.length();
    if (fruitLength > 8 && fruitLength < 14) {
        tryCounter = fruitLength + 1;
    }
    if (fruitLength <= 8) {
        tryCounter = 7;
    }
    else {
        tryCounter = 15;
    }

#pragma endregion

#pragma region Game

    while (!wordRevealed && !gameOver) {
        cin >> userInputRaw;
        string userInputRefined;
        bool triedThatBefore = false;
        if (!userInputRaw.empty()) {
            char firstChar = tolower(userInputRaw[0]);
            userInputRefined += firstChar;
            for (string::size_type i = 0; i < fruitLength; ++i) {
                if (spoofedFruit[i] == userInputRefined[0]) {
                    triedThatBefore = true;
                    break;
                }
            }
        }
        if (triedThatBefore) {
            cout << "Get your shit together - you already hit that damn letter before!" << endl;
        }
        else {
            bool trySuccess = false;
            int posHit = fruitToFind.find(userInputRefined);
            if (posHit != string::npos) {
                trySuccess = true;
                for (string::size_type i = 0; i < fruitLength; ++i) {
                    if (fruitToFind[i] == userInputRefined[0]) {
                        spoofedFruit[i] = userInputRefined[0];
                    }
                }
                legoText4 = "\nNice job - what took you so long?\n";
            }
            if (!trySuccess) {
                tryCounter = tryCounter - 1;
                legoText4 = "\nBra..\nThat was not right if that wasnt clear yet thought!\n";
                if (tryCounter < 1) {
                    gameOver = true;
                }
            }
            if (spoofedFruit.find("_") == string::npos) {
                wordRevealed = true;
            }
            cout << legoText1 + spoofedFruit + legoText2 << tryCounter << legoText3 << legoText4 << endl;
        }
    }

    if (gameOver) {
        cout << "You lost!\nDid you visualized that when you started this?\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    }
    if (wordRevealed) {
        cout << "You won! Real Chadman you are.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    }

#pragma endregion

#pragma region DEBUG INFOBOX

    //? This infos are just for development - comment out ir #ifdebig them before use
    // 
    cout << "DEBUG INFO" << endl;
    // fruitToFind
    cout << "Variable:" + tab + "fruitToFind" + crlf << "Actual value:" + tab + fruitToFind + crlf << "Description:" + tab + 
        "Variable gets randomized value from array." + crlf<< endl;
    // spoofedFruit
    cout << "Variable:" + tab + "spoofedFruit" + crlf << "Actual value:" + tab + spoofedFruit + crlf << "Description:" + tab + 
        "Variable gets \"_\" for each letter in fruitToFind. Whitespaces are excluded" + crlf << endl;

#pragma endregion

    return 0;
}
