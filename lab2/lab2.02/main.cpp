#include "FindSameLengthWords.h"

int main() {
	int sameLength = 0, sizeValue = 0;
	int numLetters, numPages, fileSize = 0, openError=0;
	string line, nameIn, nameOut;
	FindSameLengthWords fileToRead;
	ifstream inFile;
	ofstream outFile;
	cout << "Input name of file to read *.txt: \t";
	cin >> nameIn;
	cout << "Input name of file to write in  *.txt: \t"; 
	cin >> nameOut;
	try
	{
		fileToRead.OpenFileIn(inFile, nameIn, openError);
		fileToRead.OpenFileOut(outFile, nameOut);
		cout << "File size: " << fileToRead.FileSize(inFile, fileSize) << " bt " << endl;
		sizeValue = fileToRead.FileSize(inFile, fileSize);
		if (sizeValue > 10000)
			cout << "File is way too big, you need to wait a little bit \n";
		//cout << fileToRead.CountWords(inFile) << " words in file" << endl;
		cout << fileToRead.CountLines(inFile) << " strings in file" << endl;
		cout << "S= "; cin >> numPages;
		cout << "N= "; cin >> numLetters;
		cout << fileToRead.ShowString(inFile, line, numPages) << endl;
		cout << fileToRead.StrLWord(inFile, line, numPages, numLetters) <<
			" words from string  " << numPages << "  contains  " << numLetters << "  letter" << endl;
		outFile << fileToRead.StrLWord(inFile, line, numPages, numLetters);


	}
	catch (int openError) {
		cout << "Cannot open file" << endl;
	
	}
	catch (string strl) {
		cout << "Cannot process file"<< endl;
	}
	finally:
	inFile.close();
	outFile.close();
	system("pause");
	return 0;
}