#pragma once
#include <string>
#include <random>
#include <ctime>cvg
#include <iostream>
#include "Functions.h"

using namespace std;

// Fruit array fruits
string fruits[] = {
    "apple", "apricot", "avocado", "banana", "bilberry", "blackberry", "blackcurrant", "blood orange", "blueberry", "boysenberry", "breadfruit", "cantaloupe", "cherimoya", "cherry",
    "chico fruit", "cloudberry", "coconut", "cranberry", "cucumber", "currant", "custard apple", "damson", "date", "dragonfruit", "durian", "grape", "grapefruit", "guava", "honeydew",
    "huckleberry", "jackfruit", "jambul", "jujube", "kiwano", "kiwi", "kumquat", "lemon", "lime", "loquat", "longan", "lychee", "mandarine", "mango", "mangosteen", "marionberry",
    "melon", "mulberry", "nectarine", "nance", "orange", "papaya", "passionfruit", "peach", "pear", "persimmon",  "physalis", "pineapple", "plum", "pomegranate", "pomelo",
    "purple mangosteen", "quince", "raisin", "rambutan", "raspberry", "redcurrant", "rock melon", "salal berry", "satsuma", "star fruit", "strawberry", "tamarillo", "tangerine",
    "ugli fruit", "watermelon", "white currant", "white sapote", "yuzu", "zucchini", "acai"
};

// Returns a random word from fruits[] as fruitToFind
string pickAWord(string fruits[]) {
    string fruitToFind = "";
    int arraySize = (sizeof(fruits) / sizeof(fruits[0]));  // Get the size of the array  
    mt19937 engine(random_device{}());  // Create a random number engine and seed it with a random device
    uniform_int_distribution<int> dist(0, arraySize - 1);  // Create a uniform integer distribution from 0 to size - 1
    int randomIndex = dist(engine);  // Pick a random index from the distribution
    string fruitToFind = fruits[randomIndex];
    return fruitToFind;
}