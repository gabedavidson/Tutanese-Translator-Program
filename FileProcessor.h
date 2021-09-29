/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Header file for the FileProcessor class.
FileProcessor class holds the model for reading from and writing to files

Sources:
https://stackoverflow.com/questions/13123892/how-to-stop-redefinition-of-a-class (header guards) (assignment 1)
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include "Translator.h"
using namespace std;

class FileProcessor{
  private:
    Translator t;
  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inFile, string outFile, string method);

};

#endif
