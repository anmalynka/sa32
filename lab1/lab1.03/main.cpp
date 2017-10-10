#include "calculation.h"
#include "vectoroperations.cpp"

int main()
{
	vector < double> archiveVector;
	Calculation calc;
	OperationsVectors opv;
	size_t row = 0, culloms = 0;
	string line, character = "\0";
	char choiceMenu, choiceArchive, choiceMatrix;
	bool isBracket = 0;
	int stringToInt = 0, moreValue = 1, result=0;
	cout << "(1)-calculation, (2)-operations with arrays" << endl;
	cin >> choiceMenu;
	switch (choiceMenu)
	{
	case '1':
	{
		while (moreValue == 1)
		{
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
				cout << calc.functionCalculate(line, isBracket, result);
			cout << "\nOne more? 1/0  ";
			cin >> moreValue;
		}
	}
	break;
	case '2':
	{
		cout << "Input squared array size [][] \nn = ";
		cin >> row; culloms = row;
		cout << "\nFill in array [" << row << "][" << culloms << "]";
		double ** Arr1 = opv.CreateArray(row, culloms);
		opv.AddArray(Arr1, row, culloms);
		system("cls");
		cout << "A= ";
		opv.ShowArray(Arr1, row, culloms);
		cout << "Do you want to archive array? Y/N ";
		cin >> choiceArchive;
		switch (choiceArchive)
		{
		case 'Y':
		{
			cout << "Archived array: ";
			if (opv.TinyArray(Arr1, archiveVector, row, culloms) != 1)
			{
				cout << "Error, array isn't big enough " << endl;
				break;
			}
			cout << "\nOld array size: " << opv.OLdArraySize(row) << endl;
			cout << "New array size: " << opv.NewArraySize(archiveVector) << endl;
			cout << "Normal size:  ";
			opv.NormalArray(Arr1, archiveVector, row);
		}
		break;
		case 'N':
			break;
		}
		cout << "\nInput second array: size [" << row << "][" << culloms << "]";
		double ** Arr2 = opv.CreateArray(row, culloms);
		opv.AddArray(Arr2, row, culloms);
		system("cls");
		cout << "A= ";  opv.ShowArray(Arr1, row, culloms); cout << endl;
		cout << "B= ";  opv.ShowArray(Arr2, row, culloms); cout << endl << endl;
		cout << "What you want to do? " << endl <<
			"(a) -addition, (b)-subtraction, (c)-multiplication, (d)-division, (e)-delete arrays " << endl;
		cin >> choiceMatrix;
		switch (choiceMatrix)
		{
		case 'a':
		{
			cout << "S= "; opv.SumArrays(Arr1, Arr2, row);
			_getch();
		}
		break;
		case 'b':
		{
			cout << "D= "; opv.DifArrays(Arr1, Arr2, row);
			_getch();
		}
		break;
		case 'c':
		{
			cout << "P= "; opv.ProdArrays(Arr1, Arr2, row);
			_getch();
		}
		break;
		case 'd':
		{
			cout << "V= ";
			if (opv.DivArrays(Arr1, Arr2, row) != 1)
			{
				cout << " Error: Division by zero";
				break;
			}
			_getch();
		}
		break;
		case 'e':
		{
			opv.Free(Arr1, row, culloms);
			opv.Free(Arr2, row, culloms);
		}
		break;
		}
	} break;
	}
	
	return 0;
}