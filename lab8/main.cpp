#include "findtop.h"
void main()
{
	int Choice = 0;
	Graph graph;
	size_t row, culloms;
	int k = 0;
	int n = 1;
	cout << "(1)-Add insidence matrix, (2)-add adjacency matrix,  (3)-test insidence, (4)-test adjacency\n";
	cin >> Choice;
	try {
		switch (Choice) {
		case 1: {
			cout << "Let's add an insidence matrix for graph \nInput number of tops  ";
			cin >> row;
			cout << "Input number of ways"; cin >> culloms;
			cout << "\nInput values for graph tops\n ";
			int *Val1 = graph.CreateValueArray(row);
			graph.FillValueArray(Val1, row);
			int ** Arr1 = graph.CreateArray(row, culloms);
			graph.AddArray(Arr1, row, culloms);
			graph.ShowArray(Arr1, row, culloms);

			cout << "Value of top to find "; cin >> k;
			cout << "\nFound, it's  " << graph.IncidencyFind(Arr1, Val1, row, culloms, k) << " point" << endl;
			break;
		}
		case 2:
		{
			cout << "Let's add an adjacency matrix for graph /n Input number of tops  ";
			cin >> row;
			culloms = row;
			cout << "Input values for graph tops\n ";
			int *Val2 = graph.CreateValueArray(row);
			graph.FillValueArray(Val2, row);
			int **Arr2 = graph.CreateArray(row, culloms);
			graph.AddArray(Arr2, row, culloms);
			graph.ShowArray(Arr2, row, culloms);

			cout << "Value of top to find "; cin >> k;
			cout << "\nFound, it's  " << graph.AdjacencyFind(Arr2, Val2, row, culloms, k) << " point" << endl;
			break;
		}
		case 3:
		{
			cout << "Here is the test insidence matrix for graph\n";
			graph.TestIncidency();
			break;
		}
		case 4:
		{
			cout << "Here is the test adjacency matrix for graph\n";
			graph.TestAdjacency();
			break;
		}
		}
	}
	catch (int error)
	{
		cout << "Illegal data for matrix\n";
	}
	system("pause");
}