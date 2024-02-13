#pragma once
#include "Functions.h"
#include "Hangman.h"
#include "Menu.h"
#include "WordPool.h"
#include <iomanip> 
#include <iostream>
#include <string>

using namespace std;

int main()
{
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

    while (isGameGoingOn) {

        //TODO: ENTER BODY FOR PLAY SECTION

        checkIfIsGameGoingOn(isWordRevealed, isGameOver);
    }

    //// Main menu
// show menu
////
/// Play
// demand input
// while (!wordRevealed && !gameOver) {
// get input
// is intput success?
//     yes - insert input in spoofed - trigger msg 
//     no - add to tryPond - trigger msg - subt from counter 
// set wordRevealed || gameOver if needed
// }
// msg back to menu

    return 0;
}
