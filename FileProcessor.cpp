/*
Gabe Davidson
2338642
gadavidson@chapman.edu
CPSC 350-3
Assignment 2

Implementation file for the FileProcessor class.
FileProcessor class holds the model for reading from and writing to files

Sources:
https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html (read from file) (was encountering error with my original method) (assignment 1)
*/

#include "FileProcessor.h"
#include "Translator.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// constructor
FileProcessor::FileProcessor(){
  Translator t;
}

// destructor
FileProcessor::~FileProcessor(){
}

void FileProcessor::processFile(const string inFile, const string outFile, const string method){
  // defining and opening reader/writer objects
  ofstream WriterFile;
  WriterFile.open(outFile);
  ifstream ReadFile;
  ReadFile.open(inFile);

  string text;

  cout << "About to process file" << endl;

  while (!ReadFile.eof()){
    getline(ReadFile, text);
    cout << text << endl;
    if (!method.compare("E2T")){
      text = t.translateEnglishSentence(text);
    }
    else if (!method.compare("T2E")){
      text = t.translateTutSentence(text);
    }
    else {
      cout << "Translation method unknown. Use either 'E2T' or 'T2E'" << endl;
      exit(0);
    }

    // cout << text << endl;
    WriterFile << text << '\n';
  }



  WriterFile.close();
  cout << "WriterFile is closed." << endl;
  ReadFile.close();
  cout << "ReadFile is closed." << endl;

  cout << "Finished processing file." << endl;
}
