/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Header file for the Translator class.
Translator class holds the model for translation between american english consonants and tut sounds on a word by word basis

Sources:
https://stackoverflow.com/questions/13123892/how-to-stop-redefinition-of-a-class (header guards) (assignment 1)
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include "Model.h"
using namespace std;

class Translator{
  private:
    Model mod;
    bool checkDoubleLetter(string w, int index);
  public:
    Translator();  // constructor
    ~Translator();  // destructor
    string translateEnglishWord(string w);
    string translateEnglishSentence(string s);
    string translateTutWord(string w);
    string translateTutSentence(string w);
};

#endif
