#include "calculation.h"

bool Calculation:: isOperation(char operationSymbol) 
{
	if (operationSymbol == 'S' || operationSymbol == 'C' || operationSymbol == 'T' || operationSymbol == 'G'
		|| operationSymbol == 'L' || operationSymbol == '+' || operationSymbol == '-' 
		|| operationSymbol == '*' || operationSymbol == '/' || operationSymbol == '^' 
		|| operationSymbol == '(' || operationSymbol == ')')
		return true;
	return false;
}
			
double Calculation::countFunction(double numberOne, double numberTwo, char operationSymbol)
{
	switch (operationSymbol) 
	{
		case 'S': return sin(numberOne);
		case 'C': return cos(numberOne);
		case 'T': return sin(numberOne)/cos(numberOne);
		case 'G': return cos(numberOne) / sin(numberOne);
		case 'L': return log(numberOne);
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
		case 'T':
		case 'G':
		case 'S':
		case 'C':
		case 'L': return 4; break;
		case '(':
		case ')': return 5; break;
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
			
			
float  Calculation::functionCalculate(string&  tmpline, bool isBracket)
{
	stack <char> stackSymbols;
	stack <double> stackNumbers;
	string function = "\0";
	double numberOne, numberTwo;
	int  size;
			
	for (int i = 0; i < tmpline.length(); i++)
	{
		if (tmpline[i] == ')')
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
		if (tmpline[i] == '(')
		{
			stackSymbols.push(tmpline[i]);
			continue;
		}
		if (tmpline[i] == 'S'|| tmpline[i] == 'C' || tmpline[i] == 'T' || tmpline[i] == 'G' || tmpline[i] == 'L')
		{
			if (!tmpline[i + 1] == '(')
			{
				throw 1;
			}
			else
				stackSymbols.push(tmpline[i]);

		}
		if (isdigit(tmpline[i])) 
			function += tmpline[i];
		else
		{
			if (!function.empty())
			{
				stackNumbers.push(stod(function));
				function = "\0";
			}
			if (stackSymbols.empty())
				stackSymbols.push(tmpline[i]);
			else if (stackSymbols.top() == 'S' || stackSymbols.top() == 'C'
				|| stackSymbols.top() == 'T' || stackSymbols.top() == 'G'
				|| stackSymbols.top() == 'L')
				continue;
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
					if (priorityOperation(tmpline[i]) <= priorityOperation(stackSymbols.top()) && !stackSymbols.empty())
					{
						numberOne = stackNumbers.top();
						stackNumbers.pop();
						numberTwo = stackNumbers.top();
						stackNumbers.pop();
						stackNumbers.push(countFunction(numberTwo, numberOne, stackSymbols.top()));
						stackSymbols.pop();
					}
				}
				stackSymbols.push(tmpline[i]);
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
		if (stackSymbols.top()=='S' || stackSymbols.top() == 'C' || stackSymbols.top() == 'T' ||
			stackSymbols.top() == 'G' || stackSymbols.top() == 'L')
		{
			numberOne = stackNumbers.top();
			stackNumbers.pop();
			stackNumbers.push(countFunction(numberOne, 0 , stackSymbols.top()));
			stackSymbols.pop();
		}
		else
		{
			numberOne = stackNumbers.top();
			stackNumbers.pop();
			numberTwo = stackNumbers.top();
			stackNumbers.pop();
			stackNumbers.push(countFunction(numberTwo, numberOne, stackSymbols.top()));
			stackSymbols.pop();
		}
	}
	
	return stackNumbers.top();
}
			
int Calculation:: WrongInput(string line, string character, int stringToInt)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (!isdigit(line[i]) && !isOperation(line[i])&&!line[i]=='x')
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

float Calculation::Recursion()
{
	return 0;
}

void  Calculation::FindAndChange(string line, string &tmpline, int &index)
{
	tmpline = line;
	for (int j = 0; j < tmpline.length(); j++)
	{
		if (tmpline[j] == 'x') {
			//tmpline[j] = NULL;
			tmpline[j] = index+48;
		}
	}
}
float Calculation::NonRecursion(string line, string &tmpline, int n, int m, int &index, bool isBracket, char symbol)
{ ///ready
	float result=0;
	switch (symbol) {
		case 'S':
		{
			for (index = n; index <= m; index++)
			{
				FindAndChange(line, tmpline, index);
				result += functionCalculate(tmpline, isBracket);
			}
			break;
		}
		case 'P': 
		{
			for (index = n; index <= m; index++)
			{
				FindAndChange(line, tmpline, index);
				result *= functionCalculate(tmpline, isBracket);
			}
			break;
		}
	}
	return result;
}

