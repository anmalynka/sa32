#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
struct node
{
	int info;
	node *l, *r;
};


class Tree
{
public:
	void Push(int a, node *t);
	void Countsum(node *t);
	void Print(node *t, int u);
};

class TableTree
{
public:
	int **CreateArray(int culloms, int row);
	void AddArray0(int **Arr, int culloms, int row);
	void ShowArray(int**Arr, int  culloms, int row);
	void CreateArrayBorders(int **Arr, int *Ar, int n);
	bool CompareWithRoot(int *Ar, int culloms, int index);
	bool CompareLeft(int *Ar, int culloms, int index, vector <int>& L_buff);
	bool CompareRight(int *Ar, int culloms, int index, vector <int>& R_buff);
	int FindValue(int *Ar, int culloms, int index);
	int LeftBufferIndex(int *Ar, int culloms, int index, vector <int> L_buff);
	int RightBufferIndex(int *Ar, int culloms, int index, vector <int> R_buff);
	void TreeTable(int **Arr, int *Ar, int culloms, vector <int>& L_buff, vector <int>& R_buff);
	int CountLeafs(int **Arr, int culloms, int index);
	int FindMaxSum(int *Ar, int n, int &maxSum);
};
