#include "Deletenode.h"
void main() {
	cout << "\n\n\nStart of second program\n";
	Tree T;
	CSV C;
	Node *root = NULL;
	vector <int> myValues;
	int number, numbers = 10, lines = 1, value;;
	try {
		C.OpenFile(myValues, numbers, lines);
		C.ShowArray(myValues, numbers, lines);
		for (int i = 0; i < lines; i++) {
			for (int i = 0; i < numbers; i++) {
				T.insert(&root, myValues[i]);
			}
		}
		T.printTree(root, "root",0);
		T.Display(root, 0);
		cout << "------------------\n Input value to delete  ";
		cin >> value;
		if (value < 1 || value > 1000)
			throw 3;

		T.deleteValue(root, value);
		T.printTree(root, "root", 0);
	cout << "------------------\n";
	}
	catch (int error)
	{
		if (error == 1)
			cout << "Couldn't open file ";
		if (error == 2)
			cout << "File is empty, can't read";
		if (error == 3)
			cout << "No such element in tree";
	}
	
	
	


	system("pause");
}