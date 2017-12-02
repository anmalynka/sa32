#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iterator>
using namespace std;

class CSV
{
public:
	void CreateVector(vector<vector<char>>& line, int &n);
	void DelDelimiters(vector<vector<char>>& line, int &n);
	bool CheckAlphabet(vector<vector<char>>& line, int &n, int &k);
	int NumberPosition(vector<vector<char>>& line, int &m);
	bool CheckNumbers(vector<vector<char>>& line, int &n, int &k, int &t, int &z);
	void SwipeLines(vector<vector<char>>&line, int &n, int &k);
	void SortAlphabet(vector<vector<char>>&line, int &n);
	void SortNumbers(vector<vector<char>>&line, int &n);
	void AddExtraLine(vector<vector<char>>& line, string &newLine, int &n);
	void EditLine(vector<vector<char>> &line, int &n, int &lineNumber, string &editLine);
	int FindLine(vector<vector<char>> &line, int &n, string &findLine);
	void ShowSearch(vector<vector<char>>& line, int &n, string &findLine);
	int FindEditElement(vector<vector<char>>&line, int &n, int lineNumber, char section, int &startPoint);
	void EditElement(vector<vector<char>>& line, int &n, int lineNumber, char section, string changeElement, int &startPoint);
	void ShowArray(vector<vector<char>>& line, int &n);
	void SaveChanges(vector<vector<char>>&line, int &n);
};