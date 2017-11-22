#include "CSV.h"
void main()
{
	CSV c;
	vector <vector<char>> line;
	vector<char> newline;
	line.push_back(vector<char>());
	int n = 0, lineNumber, startPoint, Choice, continueOp=1, saveExit;
	string newLine, findLine, editLine, changeElement;
	char section;
	try {
		c.CreateVector(line, n);
		c.DelDelimiters(line, n);
		c.ShowArray(line, n);
		cout << endl;
		cout << "Find line by name. Input name from line" << endl;
		cin >> findLine;
		c.ShowSearch(line, n, findLine);

		while (continueOp == 1) {
			cout << "\nAlphabet sort (1), Numeric sort (2), Add line (3), Edit line (4),  Edit element (5) " << endl;
			cin >> Choice;
			switch (Choice)
			{
			case 1:
				c.SortAlphabet(line, n);
				cout << endl << "Alphabetic" << endl;
				system("CLS");
				c.ShowArray(line, n);
				break;
			case 2:
				cout << endl << "Numberic" << endl;
				c.SortNumbers(line, n);
				system("CLS");
				c.ShowArray(line, n);
				break;
			case 3:
				cout << "Input new line (with delimiters)" << endl;
				cin >> newLine;
				c.AddExtraLine(line, newLine, n);
				system("CLS");
				c.ShowArray(line, n);
				break;
			case 4:
				cout << "Input line number" << endl;
				if (!(cin >> lineNumber))
					throw 4;
				cout << "Input new line (with delimiters" << endl;
				cin >> editLine;
				c.EditLine(line, n, lineNumber, editLine);
				system("CLS");
				c.ShowArray(line, n);
				break;
			case 5:
				cout << "Input line number" << endl;
				if (!(cin >> lineNumber))
					throw 4;
				cout << "Input field (n)-name, (l)-land, (r)-rock, (a)-area, (d)-density" << endl;
				cin >> section;
				cout << "Input new element to change" << endl;
				cin >> changeElement;
				c.EditElement(line, n, lineNumber, section, changeElement, startPoint);
				system("CLS");
				c.ShowArray(line, n); 
				break;
			default:
				throw 3;
			}
			cout << "\nContinue? (1)-Yes/(0)-No  ";
			cin >> continueOp;
		}
		cout << "(1)-Save editings, (0)-Exit ";
		cin >> saveExit;
		if (saveExit == 1)
			c.SaveChanges(line, n);
		else if (saveExit == 0)
			exit(1);
		else
			throw 3;
	}
	catch (int error)
	{
		if (error == 1)
			cout << "Couldn;t open the file";
		if (error == 2)
			cout << "No such field";
		if (error == 3)
			cout << "You didn't choose any posible value";
		if (error == 4)
			cout << "Illegal data";
	}
	system("pause");
}
