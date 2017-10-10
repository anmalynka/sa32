#include  "FindSameLengthWords.h"

void FindSameLengthWords :: toStart(ifstream &inFile)
{
	inFile.clear();
	inFile.seekg(0);
}

void FindSameLengthWords :: OpenFileIn(ifstream &inFile, string nameIn)
{
	inFile.open(nameIn);
	if (!inFile.is_open())
	{
		cout << "File can't be opened\n";
		exit(1);
	}
}

int FindSameLengthWords :: FileSize(ifstream& inFile, int fileSize)
{
	inFile.seekg(0, ios::end);
	fileSize = inFile.tellg();
	toStart(inFile);
	return fileSize;
}

void FindSameLengthWords :: OpenFileOut(ofstream &outFile, string nameOut)
{
	outFile.open(nameOut);
}

int FindSameLengthWords :: CountWords(ifstream &inFile)
{
	string item;
	int count = 0;
	while (!inFile.eof())
	{
		inFile >> item;
		count++;
	}
	toStart(inFile);
	return count;
}

int FindSameLengthWords :: CountLines(ifstream &inFile)
{
	char c;
	int line_count = 0;
	while (!inFile.eof())
	{
		c = inFile.get();
		if (c == '\n')
		{
			line_count++;
		}
	}
	toStart(inFile);
	return line_count;
}

string FindSameLengthWords :: ShowString(ifstream& inFile, string line, int numPages)
{
	for (int i = 1; i <= numPages; i++)
		getline(inFile, line);
	if (line.empty()) {
		toStart(inFile);
		return "String is empty, try another one. ";
	}
	else
		return  line;
}

int FindSameLengthWords :: FindInString(ifstream &inFile, string line, int numPages, int numLetters)
{
	char letter;
	for (int i = 1; i <= numPages; i++)
		getline(inFile, line);
	int size = line.length();
	string word;
	int same_length = 0;

	for (int i = 0; i < size; i++)
	{
		if (!isspace(line[i]) && isalpha(line[i]) && !isdigit(line[i]))
		{
			letter = line.at(i);
			word += letter;
		}
		if (isspace(line[i]) || line[i] == '\0')
		{
			if (word.length() == numLetters)
			{
				word = "";
				same_length++;
			}
			word = "";
		}
	}
	return same_length;
}

