#pragma once
#include <string>
#include <iostream>
#include "Menu.h"
#include "Hangman.h"
#include "Functions.h"

using namespace std;

// Style elements
string mFHeader = "----->   FREECALRADIAs BORING HANGMAN CPP   <-----";
string mFSidebarL = "|  ";
string mFSidebarR = "  |";
string crlf = "\n";
string tab = "\t";

// 7 times CRLF
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

string getLegoText4(bool isTrySuccessfull) {
    if (isTrySuccessfull) {
        legoText4 = "Nice job - what took you so long?";
    }
    else {
        legoText4 = "Bra.. That was not right if that wasnt clear yet thought!";
    }
    return legoText4;
}

// Header _-
cout << tab << setfill('_') << setw(56) << '_' << endl
<< tab << mFSidebarL + mFHeader + mFSidebarR << endl
<< tab << setfill('-') << setw(56) << '-' << endl;

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

// Prompt to select a number 
cout << tab << right << setfill(' ') << setw(35) << "PRESS NUMBER" << endl;

//"You have to guess a fruit by guessing what letters the word may contain while you have still attempts left."
