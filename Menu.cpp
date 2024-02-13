#pragma once
#include "Functions.h"
#include "Hangman.h"
#include "Menu.h"
#include <iomanip> 
#include <iostream>
#include <string>

using namespace std;

string getLegoText4(bool isTrySuccessfull) {
    if (isTrySuccessfull) {
        legoText4 = "Nice job - what took you so long?";
    }
    else {
        legoText4 = "Bra.. That was not right if that wasnt clear yet thought!";
    }
    return legoText4;
}

void MainMenu() {
    // Header _-
    cout << tab << setfill('_') << setw(56) << '_' << endl << tab << mFSidebarL + mFHeader + mFSidebarR << endl << tab << setfill('-') << setw(56) << '-' << endl;
    
    // | Start new game: .....1 | How to play: .....3 |
    cout << tab << mFSidebarL << left << setfill('.') << setw(6) << "Start new game: " << right << setfill('.') << setw(6) << 1 << " " + mFSidebarL
    << left << setfill('.') << setw(10) << "How to play: " << right << setfill('.') << setw(11) << 3 << mFSidebarR << endl
    // | Options: ............2 | About: ...........4 |
    << tab << mFSidebarL << left << setfill('.') << setw(11) << "Options: " << right << setfill('.') << setw(11) << 2 << " " + mFSidebarL
    << left << setfill('.') << setw(12) << "About: " << right << setfill('.') << setw(12) << 4 << mFSidebarR << endl
    // |                        | Exit: ............6 |
    << tab << mFSidebarL << left << setfill(' ') << setw(11) << "  " << right << setfill(' ') << setw(11) << " " << " " + mFSidebarL
    << left << setfill('.') << setw(12) << "Exit: " << right << setfill('.') << setw(12) << 5 << mFSidebarR << endl

    << tab << setfill('-') << setw(56) << '-' << endl;
}

void PressNumber() {
    // Prompt to select a number 
    cout << tab << right << setfill(' ') << setw(35) << "PRESS NUMBER" << endl;
}

void GameEnding() {
    if (isGameOver) {
        // Game over
        cout << "You lost!\nDid you visualized that when you started this?" << endl;
    }
    if (isWordRevealed) {
        // Win
        cout << "You won! Real Chadman you are." << endl;
    }
}

void Disclaimer() {
    // Recursive msg w/ tried before
    cout << crlf << legoText1 + spoofedFruit + legoText2 << tryCounter << legoText3 << crlf << legoText4 << crlf << endl
        << "Letters you tried before: " << tryPond << endl;
}
