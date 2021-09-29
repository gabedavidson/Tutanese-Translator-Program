/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Implementation file for main
Main is where the program starts the translation and finishes once translation is complete.
*/

#include "FileProcessor.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  FileProcessor processor;

  if (argc < 2){
    cout << "Please input a command line paramater (use either 'E2T' or 'T2E').";
    return 0;
  }
  else {
    cout << argv[1] << endl;
    processor.processFile("infile.txt", "outfile.txt", argv[1]);
  }

  return 0;
}
