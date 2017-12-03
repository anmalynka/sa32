#pragma once
#include  <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <stack>
#include <math.h>
#include "vectoroperations.h"
using namespace std;

class Calculation 
{
	private:
	public:
		bool isOperation(char operationSymbol);
		double countFunction(double numberOne, double numberTwo, char operationSymbol);
		int priorityOperation(char operationSymbol);
		bool isPrime(int number);
		int bracketRight(char operationSymbol);
		int bracketLeft(char operationSymbol);
		int Brackets(string line);
		float functionCalculate(string& tmpline, bool isBracket);
		int WrongInput(string line, string character, int stringToInt);
		float Calculation::Recursion();
		void  Calculation::FindAndChange(string line, string &tmpline, int &index);
		float Calculation::NonRecursion(string line,string &tmpline, int n, int m, int &index, bool isBracket, char symbol);
};


