/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Implementation file for the Model class.
Model class holds the model for translation between american english consonants and tut sounds on a letter by letter basis

Sources:
https://www.techiedelight.com/convert-char-to-string-cpp/ (string constructor) (assignment 1)
*/

#include <iostream>
#include <string>
#include "Model.h"
using namespace std;

// constructor
Model::Model(){
  isVowel = false;
  c = 'a';
}

// destructor
Model::~Model(){
}

string Model::translateSingleCharacter(char c){
  string translation;

  // cross referencing between param c and consonants
  if (c == 'b'){
    translation = "bub";
  }
  else if (c == 'B'){
    translation = "Bub";
  }
  else if (c == 'c'){
    translation = "cash";
  }
  else if (c == 'C'){
    translation = "Cash";
  }
  else if (c == 'd'){
    translation = "dud";
  }
  else if (c == 'D'){
    translation = "Dud";
  }
  else if (c == 'f'){
    translation = "fuf";
  }
  else if (c == 'F'){
    translation = "Fuf";
  }
  else if (c == 'g'){
    translation = "gug";
  }
  else if (c == 'G'){
    translation = "Gug";
  }
  else if (c == 'h'){
    translation = "hash";
  }
  else if (c == 'H'){
    translation = "Hash";
  }
  else if (c == 'j'){
    translation = "jay";
  }
  else if (c == 'J'){
    translation = "Jay";
  }
  else if (c == 'k'){
    translation = "kuck";
  }
  else if (c == 'K'){
    translation = "Kuck";
  }
  else if (c == 'l'){
    translation = "lul";
  }
  else if (c == 'L'){
    translation = "Lul";
  }
  else if (c == 'm'){
    translation = "mum";
  }
  else if (c == 'M'){
    translation = "Mum";
  }
  else if (c == 'n'){
    translation = "nun";
  }
  else if (c == 'N'){
    translation = "Nun";
  }
  else if (c == 'p'){
    translation = "pub";
  }
  else if (c == 'P'){
    translation = "Pub";
  }
  else if (c == 'q'){
    translation = "quack";
  }
  else if (c == 'Q'){
    translation = "Quack";
  }
  else if (c == 'r'){
    translation = "rug";
  }
  else if (c == 'R'){
    translation = "Rug";
  }
  else if (c == 's'){
    translation = "sus";
  }
  else if (c == 'S'){
    translation = "Sus";
  }
  else if (c == 't'){
    translation = "tut";
  }
  else if (c == 'T'){
    translation = "Tut";
  }
  else if (c == 'v'){
    translation = "vuv";
  }
  else if (c == 'V'){
    translation = "Vuv";
  }
  else if (c == 'w'){
    translation = "wack";
  }
  else if (c == 'W'){
    translation = "Wack";
  }
  else if (c == 'x'){
    translation = "ex";
  }
  else if (c == 'X'){
    translation = "Ex";
  }
  else if (c == 'y'){
    translation = "yub";
  }
  else if (c == 'Y'){
    translation = "Yub";
  }
  else if (c == 'z'){
    translation = "zub";
  }
  else if (c == 'Z'){
    translation = "Zub";
  }
  else{ // default case, returns original parameter
    return "" + c;
  }

  return translation;

}

string Model::translateDoubleCharacter(char c){
  string s (1, c);

  // check double vowel
  if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
    if (isupper(s[0])){
      // begin editied section (editied on assignment 1 content to fix incorrect translations)
      return "Squa" + translateSingleCharacter(c);
    }
    else {
      return "squa" + translateSingleCharacter(c);
    }
    // end editied section
  }
  else {
    if (isupper(s[0])){
      return "Squat" + s;
    }
    else {
      return "squat" + s;
    }
  }
}

string Model::translateTutSingleCharSyllable(string w){
  if (w.compare("bub") == 0){
    return "b";
  }
  else if (w.compare("Bub") == 0){
    return "B";
  }
  else if (w.compare("cash") == 0){
    return "c";
  }
  else if (w.compare("Cash") == 0){
    return "C";
  }
  else if (w.compare("dud") == 0){
    return "d";
  }
  else if (w.compare("Dud") == 0){
    return "D";
  }
  else if (w.compare("fuf") == 0){
    return "f";
  }
  else if (w.compare("Fuf") == 0){
    return "F";
  }
  else if (w.compare("gug") == 0){
    return "g";
  }
  else if (w.compare("Gug") == 0){
    return "G";
  }
  else if (w.compare("hash") == 0){
    return "h";
  }
  else if (w.compare("Hash") == 0){
    return "H";
  }
  else if (w.compare("jay") == 0){
    return "j";
  }
  else if (w.compare("Jay") == 0){
    return "J";
  }
  else if (w.compare("kuck") == 0){
    return "k";
  }
  else if (w.compare("Kuck") == 0){
    return "K";
  }
  else if (w.compare("lul") == 0){
    return "l";
  }
  else if (w.compare("Lul") == 0){
    return "L";
  }
  else if (w.compare("mum") == 0){
    return "m";
  }
  else if (w.compare("Mum") == 0){
    return "M";
  }
  else if (w.compare("nun") == 0){
    return "n";
  }
  else if (w.compare("Nun") == 0){
    return "N";
  }
  else if (w.compare("pub") == 0){
    return "p";
  }
  else if (w.compare("Pub") == 0){
    return "P";
  }
  else if (w.compare("quack") == 0){
    return "q";
  }
  else if (w.compare("Quack") == 0){
    return "Q";
  }
  else if (w.compare("rug") == 0){
    return "r";
  }
  else if (w.compare("Rug") == 0){
    return "R";
  }
  else if (w.compare("sus") == 0){
    return "s";
  }
  else if (w.compare("Sus") == 0){
    return "S";
  }
  else if (w.compare("tut") == 0){
    return "t";
  }
  else if (w.compare("Tut") == 0){
    return "T";
  }
  else if (w.compare("vuv") == 0){
    return "v";
  }
  else if (w.compare("Vuv") == 0){
    return "V";
  }
  else if (w.compare("wack") == 0){
    return "w";
  }
  else if (w.compare("Wack") == 0){
    return "W";
  }
  else if (w.compare("ex") == 0){
    return "x";
  }
  else if (w.compare("Ex") == 0){
    return "X";
  }
  else if (w.compare("yub") == 0){
    return "y";
  }
  else if (w.compare("Yub") == 0){
    return "Y";
  }
  else if (w.compare("zub") == 0){
    return "z";
  }
  else if (w.compare("Zub") == 0){
    return "Z";
  }
  else if (w == "a" || w == "e" || w == "i" || w == "o" || w == "u" || w == "A" || w == "E" || w == "I" || w == "O" || w == "U"){
    return w;
  }
  else {
    return "";
  }
}

string Model::translateTutDoubleCharSyllable(string w, string sTemp, int indexer){
  string _sTemp = "";
  // double consonant case
  if (!sTemp.compare("squa") || !sTemp.compare("Squa")){
    // string hold = sTemp + w.at(indexer + 1);
    string _temp = "";
    try{
      for (int k = indexer + 1; k < indexer + 6; ++k){
        _temp += w.at(k);
        // if returns a translation, return that translation
        // otherwise, keep iterating. same concept as in translator.cpp
        if (translateTutSingleCharSyllable(_temp).length() > 0){
          return translateTutSingleCharSyllable(_temp) + translateTutSingleCharSyllable(_temp);
        }
      }
    }
    // no translation was found within 5 characters (or there were too few characters
    // and an error was thrown) -> same result!
    catch(exception& e){
      cout << "The following error is utilized in double character checking: ";
      cerr << e.what() << endl;
    }
  }
  // double vowel case
  if (w.at(indexer + 1) == 't'){
    char c = w.at(indexer + 2);
    // failsafe
    if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'){
      char __c = w.at(indexer + 1);
      _sTemp += __c;
      _sTemp += __c;
    }
    // add double vowel
    else {
      _sTemp += c;
      _sTemp += c;
    }
  }
  return _sTemp;
}
