#pragma once
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
//int Choice = 0;
class Graph
{
	
public:
	int **CreateArray(size_t row, size_t culloms);
	void AddArray(int **Arr, size_t row, size_t culloms);
	void ShowArray(int**Arr, size_t row, size_t culloms);
	int *CreateValueArray(size_t row);
	void FillValueArray(int *Arr, size_t row);
	int IncidencyFind(int**Arr, int *Val, size_t row, size_t culloms, int value);
	int AdjacencyFind(int**Arr, int*Val, size_t row, size_t culloms, int value);
	void TestIncidency();
	void TestAdjacency();
 

};