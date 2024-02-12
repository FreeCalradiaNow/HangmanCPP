#pragma once
#include <string>
#include <iomanip> 
#include "Menu.h"
#include "WordPool.h"
#include "Functions.h"

using namespace std;

int main()
{
    // Properties
    string userInputRaw;
 
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



    while (!wordRevealed && !gameOver) {
        //bool triedThatBefore = false;
        //if (!userInputRaw.empty()) {
        //    char firstChar = tolower(userInputRaw[0]);
        //    userInputRefined += firstChar;
        //    for (string::size_type i = 0; i < fruitLength; ++i) {
        //        if (spoofedFruit[i] == userInputRefined[0]) {
        //            triedThatBefore = true;
        //            break;
        //        }
        //    }
        //}
        //if (triedThatBefore) {
        //    cout << crlf << "Get your shit together - you already hit that damn letter before!" << endl;
        //}
        else {/*
            bool trySuccess = false;*/
      /*      int posHit = fruitToFind.find(userInputRefined);
            if (posHit != string::npos) {*/
               /* trySuccess = true;*/
           /*     for (string::size_type i = 0; i < fruitLength; ++i) {
                    if (fruitToFind[i] == userInputRefined[0]) {
                        spoofedFruit[i] = userInputRefined[0];
                    }
                }*/
           /*     legoText4 = "Nice job - what took you so long?";*/
            }
            if (!trySuccess) {
                tryCounter = tryCounter - 1;
                /*tryPond = tryPond.append(userInputRefined + " ");*/
               /* legoText4 = "Bra.. That was not right if that wasnt clear yet thought!";*/
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
    
    return 0;
}
