#include "calculation.h"

bool Calculation:: isOperation(char operationSymbol) 
{
	if (operationSymbol == '+' || operationSymbol == '-' || operationSymbol == '*' 
		|| operationSymbol == '/' || operationSymbol == '^' 
		|| operationSymbol == '(' || operationSymbol == ')')
		return true;
	return false;
}
			
double Calculation::countFunction(double numberOne, double numberTwo, char operationSymbol)
{
	switch (operationSymbol) 
	{
		case '+': return numberOne + numberTwo;
		case '-': return numberOne - numberTwo;
		case '*': return numberOne * numberTwo;
		case '/': return numberOne / numberTwo;
		case '^': return pow(numberOne, numberTwo);	
	}
}
			
int Calculation:: priorityOperation(char operationSymbol)
{
	switch (operationSymbol) 
	{
		case '(':
		case ')': return 4; break;
		case '^': return 3; break;
		case '/':
		case '*': return 2; break;
		case '+':
		case '-': return 1; break;
			
		default:  return 0;
	}
}
			
bool Calculation:: isPrime(int number)
{
	if (number == 1|| number==0) return false;
		for (int i = 2; i <= sqrt(number); i++) 
		{
			if  (number%i == 0) 
				return false;
		}
		return true;
}
			
int Calculation::bracketRight(char operationSymbol)
{
	if (operationSymbol == '(')
		return 1;
	return 0;
}
			
int Calculation::bracketLeft(char operationSymbol)
{
	if (operationSymbol == ')')
		return 1;
	return 0;
}
			
int Calculation::Brackets(string line)
{
	int bracket;
	int i;
	for (i = 0, bracket = 0; i < line.length(); i++)
	{
		if (line[i] == '(')
			bracket++;
		else
		{
			if (line[i] == ')')
				bracket--;
		}
	}
	return bracket;
}
			
			
int Calculation::functionCalculate(string line, bool isBracket, int result)
{

	stack <char> stackSymbols;
	stack <double> stackNumbers;
	string function = "\0";
	double numberOne, numberTwo;
	int size;
			
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ')')
		{
			isBracket = 0;
			if (!function.empty())
			{
				stackNumbers.push(stod(function));
				function = "\0";
			}
			while (stackSymbols.top() != '(')
			{
				numberOne = stackNumbers.top();
				stackNumbers.pop();
				numberTwo = stackNumbers.top();
				stackNumbers.pop();
				stackNumbers.push(countFunction(numberTwo, numberOne, stackSymbols.top()));
				stackSymbols.pop();
			}
			stackSymbols.pop();
			continue;
		}
		if (line[i] == '(')
		{
			stackSymbols.push(line[i]);
			continue;
		}
		if (isdigit(line[i])) 
			function += line[i];
		else
		{
			if (!function.empty())
			{
				stackNumbers.push(stod(function));
				function = "\0";
			}
			if (stackSymbols.empty())
				stackSymbols.push(line[i]);
			else
			{
				size = stackSymbols.size();
				for (int j = 0; j < size; j++)
				{
					if (stackSymbols.top() == '(')
					{
						isBracket = 1;
						break;
					}
					if (priorityOperation(line[i]) <= priorityOperation(stackSymbols.top()) && !stackSymbols.empty())
					{
						numberOne = stackNumbers.top();
						stackNumbers.pop();
						numberTwo = stackNumbers.top();
						stackNumbers.pop();
						stackNumbers.push(countFunction(numberTwo, numberOne, stackSymbols.top()));
						stackSymbols.pop();
					}
				}
				stackSymbols.push(line[i]);
			}
		}
	}
	if (!function.empty())
	{
		stackNumbers.push(stod(function));
		function = "\0";
	}
	while (!stackSymbols.empty() && !stackNumbers.empty())
	{
		numberOne = stackNumbers.top();
		stackNumbers.pop();
		numberTwo = stackNumbers.top();
		stackNumbers.pop();
		stackNumbers.push(countFunction(numberTwo, numberOne, stackSymbols.top()));
		stackSymbols.pop();
	}
	result = stackNumbers.top();
	return result;
}
			
int Calculation:: WrongInput(string line, string character, int stringToInt)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (!isdigit(line[i]) && !isOperation(line[i]))
			for (i = 0; i < line.length(); i++)
				return 1;
			if (Brackets(line) != 0)
				return 2;
	}
	for (int i = 0; i <= line.length(); i++)
	{
		if (isdigit(line[i])) 
		{
			character += line[i];
		}
		else
		{
			if (!character.empty())
			{
				stringToInt = stoi(character);
				character = "\0";
				if (!isPrime(stringToInt))
					return 3;
			}
		}
	}
}

