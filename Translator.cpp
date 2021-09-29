/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Implementation file for the Translator class.
Translator class holds the model for translation between american english consonants and tut sounds on a word by word basis

Sources:
https://www.programiz.com/cpp-programming/library-function/cctype/ispunct (ispunct() method) (assignment 1)
*/

#include <iostream>
#include <exception>
#include "Translator.h"
#include "Model.h"
using namespace std;

// constructor
Translator::Translator(){
  Model mod;
}

// destructor
Translator::~Translator(){
}

string Translator::translateEnglishWord(string w){
  cout << "Translating english to tut: " << w << endl;
  string newWord = "";
  string sTemp;
  for (int indexer = 0; indexer < w.length(); ++indexer){
    if (indexer >= w.length()){ // redundant check to make sure a double letter at the end of the word did not push indexer past length of word (see below)
      break;
    }
    // check for vowel
    cout << "checking letter: " << w.at(indexer) << endl;
    if (w.at(indexer) != 'a' && w.at(indexer) != 'e' && w.at(indexer) != 'i' && w.at(indexer) != 'o' && w.at(indexer) != 'u' && w.at(indexer) != 'A' && w.at(indexer) != 'E' && w.at(indexer) != 'I' && w.at(indexer) != 'O' && w.at(indexer) != 'U'){
      cout << "did not find double letter!" << w.at(indexer) << endl;
      // checks if char is punctuation
      if (ispunct(w.at(indexer))){
        char __c = w.at(indexer);
        newWord += __c;
      }
      else if (w.at(indexer) == '\n'){
        char __c = w.at(indexer);
        newWord += __c;
      }
      // if not punctuation, must be a consonant
      else {
        // check for a double letter
        if (checkDoubleLetter(w, indexer)){
          cout << "Found double letter! " << w.at(indexer) << endl;
          newWord += "" + mod.translateDoubleCharacter(w.at(indexer));
          indexer += 1; // puts the indexer one step ahead, thereby skipping the second of the double letters (potential out of bounds errors avoided by indexer check above)
        }
        // if it is only a single character non vowel, non punctuation character
        else {
          newWord += mod.translateSingleCharacter(w.at(indexer));
        }
      }
    }
    else {
      if (checkDoubleLetter(w, indexer)){
        cout << "Found double letter! " << w.at(indexer) << endl;
        newWord += "" + mod.translateDoubleCharacter(w.at(indexer));
        indexer += 1; // puts the indexer one step ahead, thereby skipping the second of the double letters (potential out of bounds errors avoided by indexer check above)
      }
      else {
        // add vowel to newWord
        char __c = w.at(indexer);
        newWord += __c;
      }
    }
  }
  return newWord;
}

string Translator::translateEnglishSentence(string s){
  string newSentence = "";
  string tempWord = "";
  // iterates over chars in text
  for (int i = 0; i < s.length(); ++i){
    // checks if char is a whitespace
    if (s.at(i) == ' ' || s.at(i) == '\n' || i == s.length()){
      // translates word created, adds a space, and resets for next word
      newSentence += translateEnglishWord(tempWord) + " ";
      // cout << "New sentence: " << newSentence << endl;
      tempWord = "";
    }
    else {
      // collects chars to form words
      tempWord += s.at(i);

      // grabs the last word on the line, otherwise would be ignored
      if (i == s.length() - 1){
        newSentence += translateEnglishWord(tempWord) + " ";
        tempWord = "";
      }
    }
  }
  return newSentence;
}

string Translator::translateTutWord(string w){
  // define pertinent vars
  string newWord = "";
  int newWordLen = 0;
  string sTemp = "";

  // iterate over tut word
  for (int indexer = 0; indexer < w.length(); ++indexer){
    // failsafe - in case indexer is past where it should be
    if (indexer >= w.length()){
      break;
    }

    // add chars to holding var
    char _c = w.at(indexer);
    sTemp += _c;

    // check if is punctuation
    if (ispunct(_c)){
      newWordLen = 0;
      newWord += _c;
      sTemp = "";
    }

    // check if is double letter
    if (!sTemp.compare("squa") || !sTemp.compare("Squa")){
      // get double letter translation
      string _temp = mod.translateTutDoubleCharSyllable(w, sTemp, indexer);
      // use this to tell if it was a double consonant or vowel
      char _ctemp = _temp.at(0);
      // check if it was a double consonant
      if (_ctemp != 'a' && _ctemp != 'e' && _ctemp != 'i' && _ctemp != 'o' && _ctemp != 'u' && _ctemp != 'A' && _ctemp != 'E' && _ctemp != 'I' && _ctemp != 'O' && _ctemp != 'U'){
        // increment indexer by the length of the letter's tutnese translation
        indexer += mod.translateSingleCharacter(_ctemp).length();
      }
      else {
        // all double vowels increment indexer by 2
        indexer += 2;
      }
      // add to newWord
      newWord += _temp;
    }
    else {
      // special case for translation from 'ex' to 'x'
      // it is the only translation that starts with a vowel, and thus
      // it can be confused
      if (!sTemp.compare("e")){
        if (indexer != w.length() - 1){
          char c = w.at(indexer + 1);
          if (c == 'x' || c == 'X'){
            sTemp += c;
            ++indexer;
          }
        }
      }
      // add regular syllable translation to newWord
      newWord += mod.translateTutSingleCharSyllable(sTemp);
    }
    // check if translation was made
    if (newWordLen < newWord.length()){
      // if so, reset sTemp and update newWordLen
      sTemp = "";
      newWordLen = newWord.length();
    }
  }
  return newWord;
}

string Translator::translateTutSentence(string s){
  string newSentence = "";
  string tempWord = "";
  // iterates over chars in text
  for (int i = 0; i < s.length(); ++i){
    // checks if char is a whitespace
    if (s.at(i) == ' ' || s.at(i) == '\n' || i == s.length()){
      // translates word created, adds a space, and resets for next word
      newSentence += translateTutWord(tempWord) + " ";
      tempWord = "";
    }
    else {
      // collects chars to form words
      tempWord += s.at(i);

      // grabs the last word on the line, otherwise would be ignored
      if (i == s.length() - 1){
        newSentence += translateTutWord(tempWord) + " ";
        tempWord = "";
      }
    }
  }
  return newSentence;
}

bool Translator::checkDoubleLetter(string w, int index){
  // try-catch to avoid a checking a double letter at the end of the line (rare case)
  try{
    if (w.at(index) == w.at(index + 1)){
      cout << "Found double letter: " << w.at(index) << endl;
      return true;
    }
    else{
      return false;
    }
  }
  catch(...){
    return false;
  }
}
