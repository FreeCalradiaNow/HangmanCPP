#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
#pragma region Textblocks/ Style

    //Style elements
    string mFHeader = "                               ----->   This is Hangman Fruity Shores  <-----                              ";
    string mFLong = "==================================================================================================================";
    string mFSidebarL = "\n||  ";
    string mFSidebarR = "  ||";
    string crlf = "\n";
    string tab = "\t";

    //Reuseable textblocks
    string legoText1 = "Guess the word: ";
    string legoText2 = "You still have ";
    string legoText3 = " failed attempts left.";
    string legoText4 = "";

#pragma endregion

#pragma region Properties

    //Properties
    string fruitToFind;
    string spoofedFruit;

    bool wordRevealed = false;
    bool gameOver = false;

#pragma endregion

#pragma region Start Message

    //Welcome/ Introduction
    cout << mFLong << mFSidebarL + mFHeader + mFSidebarR << endl;
    cout << mFSidebarL + "You have to guess a fruit by guessing what letters the word may contain while you have still attempts left." + mFSidebarR << "\n" + mFLong + "\n\n\n" << endl;

#pragma endregion

#pragma region Random word/ spoofing

    //Fruit array fruits
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
    
    //spoofedFruit gets \"_\" for each letter in fruitToFind. Whitespaces are excluded
    for (char c : fruitToFind) {
        if (c != ' ') {
            spoofedFruit += '_';
        }
        else {
            spoofedFruit += ' ';
        }
    }

#pragma endregion

#pragma region DEBUG INFOBOX

    //? This infos are just for development - comment out ir #ifdebig them before use
    // 
    cout << "DEBUG INFO" << endl;
    //fruitToFind
    cout << "Variable:" + tab + "fruitToFind" + crlf << "Actual value:" + tab + fruitToFind + crlf << "Description:" + tab + 
        "Variable gets randomized value from array." + crlf<< endl;
    //spoofedFruit
    cout << "Variable:" + tab + "spoofedFruit" + crlf << "Actual value:" + tab + spoofedFruit + crlf << "Description:" + tab + 
        "Variable gets \"_\" for each letter in fruitToFind. Whitespaces are excluded" + crlf << endl;


#pragma endregion






    return 0;
}
