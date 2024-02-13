#pragma once
#include <string>

using namespace std;

static string mFHeader = "----->   FREECALRADIAs BORING HANGMAN CPP   <-----";
static string mFSidebarL = "|  ";
static string mFSidebarR = "  |";
static string crlf = "\n";
static string tab = "\t";

static string legoText1 = "Guess the word: ";
static string legoText2 = " You still have ";
static string legoText3 = " failed attempts left.";
static string legoText4;

//void gap();
static void MainMenu();
static void PressNumber();
static void GameEnding();
static void Disclaimer();