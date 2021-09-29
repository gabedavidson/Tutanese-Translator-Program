/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Header file for the Model class.
Model class holds the model for translation between american english consonants and tut sounds on a letter by letter basis

Sources:
https://stackoverflow.com/questions/13123892/how-to-stop-redefinition-of-a-class (header guards) (assignment 1)
*/

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
using namespace std;

class Model{
  public:
    Model();
    ~Model();
    string translateSingleCharacter(char c);
    string translateDoubleCharacter(char c);
    string translateTutSingleCharSyllable(string w);
    string translateTutDoubleCharSyllable(string w, string sTemp, int indexer);
  private:
    bool shouldTranslateInput(char c);
    bool isVowel;
    char c;
};

#endif
