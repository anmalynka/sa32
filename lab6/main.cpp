#include "calculation.h"
//#include "vectoroperations.cpp"

int main()
{
	Calculation calc;
	string line, tmpline, character = "\0";
	bool isBracket = 0;
	int stringToInt = 0, moreValue = 1, n=0, m=0, index=0;
	char symbol;
	cout << "S - sum, P- product \t";
	cin >> symbol;
	cout << "Input range for x \t ";
	cin >> n;
	cin >> m;

		while (moreValue == 1)
		{
			cout << "S - sin, C- cos, T-tg, G-ctg, L-log";
			cout << "Input expression:  ";
			cin >> line;
			if (calc.WrongInput(line, character, stringToInt) == 1)
			{
				cout << "Invalid character " << endl;
				continue;
			}
			else if (calc.WrongInput(line, character, stringToInt) == 2)
			{
				cout << "Invalid brackets " << endl;
				continue;
			}
			else if (calc.WrongInput(line, character, stringToInt) == 3)
			{
				cout << "Illegal numbers (not prime)" << endl;
				continue;
			}
			else
				cout << calc.NonRecursion(line, tmpline, n, m, index, isBracket, symbol);
			cout << "\nOne more? 1/0  ";
			cin >> moreValue;
		}
	

	
	return 0;
}