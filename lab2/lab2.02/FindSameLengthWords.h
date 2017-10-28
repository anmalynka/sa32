#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

class FindSameLengthWords 
{
	private:
		char letter;
		string in, s;
	public:
		void toStart(ifstream &inFile);
		void  OpenFileIn(ifstream &inFile, string nameIn, int openError);
		int FileSize(ifstream& inFile, int fileSize);
		void OpenFileOut(ofstream &outFile, string nameOut);
		int CountWords(ifstream &inFile);
		int CountLines(ifstream &inFile);
		string ShowString(ifstream& inFile, string line, int numPages);
		int StrLWord(ifstream &inFile, string line, int numPages, int numLetters);
		
};