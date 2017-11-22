#include "CSV.h"

void CSV::CreateVector(vector<vector<char>>& line, int &n)
{
	char nameIn[] = "foresty.csv ";
	char el;
	FILE *fileread;
	if ((fileread = fopen(nameIn, "r")) == NULL) {
		throw 1;
	}
	el = getc(fileread);
	while (el != EOF) {
		if (el == '\n') {
			n++;
			line.push_back(vector<char>());
		}
		else
			line[n].push_back(el);
		el = getc(fileread);
	}
	fclose(fileread);
}
void  CSV::DelDelimiters(vector<vector<char>>& line, int &n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			if (line[i][j] == ';')
				line[i][j] = ' ';
		}
	}
}

bool CSV::CheckAlphabet(vector<vector<char>>& line, int &n, int &k)
{
	int count = 0;
	if ((line[k][count] != ';') && line[k + 1][count] != ';') {
		if (line[k][count] > line[k + 1][count])
			return true;
		else if (line[k][count] == line[k + 1][count])
		{
			if (line[k][count + 1] > line[k + 1][count + 1])
				return true;
			else
				return false;
		}
		else
			return false;
	}
}

int CSV::NumberPosition(vector<vector<char>>& line, int &m)
{
	int countNumbers = 0;
	for (int j = 0; j < line[m].size(); j++) {
		if (line[m][j] == ';')
			countNumbers++;
		if (countNumbers == 4)
			return j;
	}
}
bool CSV::CheckNumbers(vector<vector<char>>& line, int &n, int &k, int &t, int &z)
{
	if ((line[k][t-1]!=NULL) && (line[k + 1][z-1]!=NULL))
	{
		if (line[k][t-1] > line[k + 1][z-1])
			return true;
		else
			return false;
	}
}
void CSV::SwipeLines(vector<vector<char>>&line, int &n, int &k)
{
	int firstlenght = line[k].size();
	int secondlenght = line[k + 1].size();
	char tmpArray[2][100];
	for (int i = 0; i < firstlenght; i++)
	{
		tmpArray[1][i] = line[k][i];
	}
	line[k].clear();
	for (int j = 0; j < secondlenght; j++)
	{
		tmpArray[0][j] = line[k + 1][j];
	}
	line[k + 1].clear();
	for (int i = 0; i < secondlenght; i++)
	{
		line[k].push_back(tmpArray[0][i]);
	}
	for (int i = 0; i < firstlenght; i++)
	{
		line[k + 1].push_back(tmpArray[1][i]);
	}
}
void  CSV::SortAlphabet(vector<vector<char>>&line, int &n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1; k++)
		{
			if (CheckAlphabet(line, n, k))
				SwipeLines(line, n, k);

		}
	}
}

void  CSV::SortNumbers(vector<vector<char>>&line, int &n)
{
	int z = 0, t = 0, tmp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n - 1; k++)
		{
			tmp = k + 1;
			t = NumberPosition(line, k);
			z = NumberPosition(line, tmp);
			if (CheckNumbers(line, n, k, t, z))
				SwipeLines(line, n, k);
		}
	}
}

void  CSV::AddExtraLine(vector<vector<char>>& line, string &newLine, int &n)
{
	n++;
	vector<char> newline(newLine.begin(), newLine.end());
	line.push_back(vector<char>());
	for (int i = 0; i < newline.size(); i++)
	{
		line[n - 1].push_back(newline[i]);
	}
}
void  CSV::EditLine(vector<vector<char>> &line, int &n, int &lineNumber, string &editLine)
{
	lineNumber--;
	line[lineNumber].clear();
	vector<char> newline(editLine.begin(), editLine.end());
	for (int i = 0; i < newline.size(); i++)
	{
		line[lineNumber].push_back(newline[i]);
	}
}
int  CSV::FindLine(vector<vector<char>> &line, int &n, string &findLine)
{
	bool check = false;
	int i = 0, k = 0, j = 1;
	vector<char> findline(findLine.begin(), findLine.end());
	for (i = 0; i < n; i++)
	{
		if (line[i][k] == findline[0])
		{
			for (k = 0, j = 0; k < line[i].size(), j < findline.size(); k++, j++)
			{
				if (line[i][k] == findline[j]) {
					if (j == findline.size() - 1)
						return i;
					continue;
				}
				else {
					k = 0;
					break;
				}
			}
		}
	}
	return 0;
}
void CSV::ShowSearch(vector<vector<char>>& line, int &n, string &findLine)
{
	int foundLine = FindLine(line, n, findLine);
	if (foundLine == 0)
		cout << "No such name in any line \n";
	else
	{
		for (int i = 0; i < line[foundLine].size(); i++)
		{
			cout << line[foundLine][i];
		}
		cout << endl;
	}
}
int CSV::FindEditElement(vector<vector<char>>&line, int &n, int lineNumber, char section, int &startPoint)
{
	int semicolom = 0, countNumbers = 0, count = 0, index;
	switch (section) {
	case 'n':
		semicolom = 0; break;
	case 'l':
		semicolom = 1; break;
	case 'r':
		semicolom = 2; break;
	case 'a':
		semicolom = 3; break;
	case 'd':
		semicolom = 4; break;
	default:
		throw 2;
	}
	for (int j = 0; j < line[lineNumber].size(); j++) {
		if (line[lineNumber][j] == ';')
		{
			countNumbers++;

			if (countNumbers == semicolom)
			{
				startPoint = j + 1;
				index = j + 1;
				while (line[lineNumber][index] != ';') {
					count++;
					index++;
				}
				break;
			}
		}
	}
	return  count;
}
void CSV::EditElement(vector<vector<char>>& line, int &n, int lineNumber, char section, string changeElement, int &startPoint)
{
	lineNumber--;
	int eraseTill = FindEditElement(line, n, lineNumber, section, startPoint);
	vector<char> editElement(changeElement.begin(), changeElement.end());
	int count = 0;
	char tmp[100];
	int k = line[lineNumber].size();
	for (int i = startPoint + eraseTill, j = 0; i < k, j < 100; i++, j++) {
		tmp[j] = line[lineNumber][i];
		count++;
		if (i == k - 1) break;
	}
	for (int i = 0; i < count + eraseTill; i++)
		line[lineNumber].pop_back();
	for (int i = startPoint, j = 0; i < editElement.size(), j<editElement.size(); i++, j++)
	{
		line[lineNumber].push_back(editElement[j]);
	}
	for (int i = 0; i < count; i++)
	{
		line[lineNumber].push_back(tmp[i]);
	}

}
void CSV::ShowArray(vector<vector<char>>& line, int &n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < line[i].size(); j++) {
			cout << line[i][j];
		}
		cout << endl;
	}
}
void CSV::SaveChanges(vector<vector<char>>&line, int &n)
{
	ofstream changed;
	changed.open("foresty.csv");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < line[i].size(); j++)
			changed << line[i][j];
		changed << '\n';
	}
	changed.close();
}
