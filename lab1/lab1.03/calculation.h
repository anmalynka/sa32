#pragma once
#include  <iostream>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <string>
#include <stack>
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
		int functionCalculate(string line, bool isBracket, int result);
		int WrongInput(string line, string character, int stringToInt);
};


