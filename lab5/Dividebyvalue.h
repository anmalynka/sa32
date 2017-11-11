#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

struct node
{
	int data;
	node * next, *prev;
};

class List
{
	node * Head, *Tail, *HeadL, *TailL, *HeadR, *TailR;
	int Count;

public:
	List();
	List(const List&);
	int GetCount();
	void CopyLeft(int number);
	void CopyRight(int number);
	void AddTail(int n);
	void AddHead(int n);
	void Print();
	void PrintNewLeft();
	void PrintNewRight();
};
class CSV
{
public:
	void OpenFile(vector<int>&myValues, int numbers, int lines);
	void ShowArray(vector<int>&myValues, int numbers, int lines);

};

