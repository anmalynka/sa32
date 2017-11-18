#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;


#define CMP_EQUIL(a, b) ((a) == (b))
#define CMP_LESST(a, b) ((a) < (b))
#define CMP_GREAT(a, b) ((a) > (b))

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

class Tree {
public:
	void insert(Node **head, int value);
	void removeNodeByPtr(Node *target);
	void deleteValue(Node *root, int value);
	void printTree(Node *root, const char *dir, int level);
	void Display(Node *current, int indent);
};

class CSV {
public:
	void OpenFile(vector<int>&myValues, int numbers, int lines);
	void ShowArray(vector<int>&myValues, int numbers, int lines);

};




