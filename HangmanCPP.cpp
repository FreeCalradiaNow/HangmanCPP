#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

#pragma region Textblocks/ Style

// Style elements
string mFHeader = "                               ----->   This is Hangman Fruity Shores  <-----                              ";
string mFLong = "==================================================================================================================";
string mFSidebarL = "\n||  ";
string mFSidebarR = "  ||";
string crlf = "\n";
string tab = "\t";

void gap() {
    for (int i = 0; i < 8; i++)
    {
      cout << "\n";
    }
}

// Reuseable textblocks
string legoText1 = "Guess the word: ";
string legoText2 = " You still have ";
string legoText3 = " failed attempts left.";
string legoText4 = "";


#pragma endregion

int main()
{
#pragma region Properties

    // Properties
    string fruitToFind;
    string spoofedFruit;
    string userInputRaw;
    string tryPond;
    int tryCounter;

    bool wordRevealed = false;
    bool gameOver = false;

#pragma endregion

#pragma region Start Message

    // Welcome/ Introduction
    cout << mFLong << mFSidebarL + mFHeader + mFSidebarR << endl
         << mFSidebarL + "You have to guess a fruit by guessing what letters the word may contain while you have still attempts left." + mFSidebarR << "\n" + mFLong + "\n\n\n" << endl;

#pragma endregion

#pragma region Menu

    // Menu
    system("Color 0B");
        //Color(Background)(Foreground)
        //0 = Black       8 = Gray
        //1 = Blue        9 = Light Blue
        //2 = Green       A = Light Green
        //3 = Aqua        B = Light Aqua
        //4 = Red         C = Light Red
        //5 = Purple      D = Light Purple
        //6 = Yellow      E = Light Yellow
        //7 = White       F = Bright White

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
            cout << crlf << "Get your shit together - you already hit that damn letter before!" << endl;
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
                legoText4 = "Nice job - what took you so long?";
            }
            if (!trySuccess) {
                tryCounter = tryCounter - 1;
                tryPond = tryPond.append(userInputRefined + " ");
                legoText4 = "Bra.. That was not right if that wasnt clear yet thought!";
                if (tryCounter < 1) {
                    gameOver = true;
                }
            }
            if (spoofedFruit.find("_") == string::npos) {
                wordRevealed = true;
            }
            cout << crlf << legoText1 + spoofedFruit + legoText2 << tryCounter << legoText3 << crlf << legoText4 << crlf << endl
                 << "Letters you tried before: " << tryPond << endl;

        }
    }
    
    if (gameOver) {
        gap();
        cout << "You lost!\nDid you visualized that when you started this?" << endl;
        gap();
    }
    if (wordRevealed) {
        gap();
        cout << "You won! Real Chadman you are." << endl;
        gap();
    }
    
#pragma endregion

    return 0;
}
