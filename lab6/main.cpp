#include "calculation.h"


int main()
{
	Calculation calc;
	string line, tmpline, character = "\0";
	bool isBracket = 0;
	int stringToInt = 0, moreValue = 1, n=0, m=0, index=0, value=1, result=0, Choice=0;
	char symbol;
	cout << "S - sum, P- product \t";
	cin >> symbol;
	cout << "Input range for x \t ";
	cin >> n;
	cin >> m;
	
		while (moreValue == 1)
		{
			cout << "\n(1) - Recursion, (2) NonRecursion \n";
			cin >> Choice;
			try {
				cout << "S - sin, C- cos, T-tg, G-ctg, L-log\n";
				cout << "Input expression:  ";
				cin >> line;
				switch (Choice) {
					
				case 1:
				{
					if (symbol == 'S')
						cout << calc.RecursionSum(line, tmpline, n, m, isBracket, result);
					else if (symbol == 'P')
						cout << calc.RecursionProduct(line, tmpline, n, m, isBracket, value);
					else
						throw 5;
					break;
				}
				case 2:
					cout << calc.NonRecursion(line, tmpline, n, m, index, isBracket, symbol);	
					break;
				}

				cout << "\nOne more? 1/0  ";
				cin >> moreValue;
			}
			catch (int error)
			{
				if(error==1)
					cout << "Invalid character \n";
				if(error==2)
					cout << "Invalid brackets \n";
				if(error==3)
					cout << "Illegal numbers (not prime)\n";
				if(error==4)
					cout << "Invalid operation\n";
				if (error == 5)
					cout << "Illegal symbol, use just S or P";
			}

		}
			

	
	
	return 0;
}