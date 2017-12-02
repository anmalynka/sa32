#include "CountLeafs.h"
node * tree = NULL;
void main() 
{
	priority_queue<int> q;
	int count = 0;
	Tree t;
	TableTree tT;
	int n, maxSum=0;
	vector <int> L_buff;
	vector <int> R_buff;
	// n elements
	cout << "Number:\n";  
	if (!(cin >> n))
			throw 1;
	int culloms = n + 1;
	int *Ad = new int[culloms]; // base
	int *Ad2 = new int[culloms]; // results
	int ** Ad1 = tT.CreateArray(culloms, culloms); /// table
	tT.AddArray0(Ad1, culloms, culloms);
	
	try {	
		Ad[0] = 0;
		for (int i = 1; i < culloms; i++)
		{
			if (!(cin >> Ad[i]))
				throw 1;
			t.Push(Ad[i], &tree);
		}
		cout << "\tTree\n";
		t.Print(tree, 0);
		cout << endl;
		while (!q.empty())
		{
			cout << q.top() << ' ';
			q.pop();
		}
		tT.CreateArrayBorders(Ad1, Ad, n);
		tT.TreeTable(Ad1, Ad, culloms, L_buff, R_buff);
		// test
		tT.ShowArray(Ad1, culloms, culloms);
		// test

		for (int i = 1; i < culloms; i++)
			Ad2[i] = tT.CountLeafs(Ad1, culloms, i);
		cout << "\nNode with max leafs sum is " << Ad[tT.FindMaxSum(Ad2, n, maxSum)] << " with sum = " << Ad2[tT.FindMaxSum(Ad2, n, maxSum)] << endl;
	}
	catch (int error)
	{
		cout << "You have to input just numbers\n";
	}
	
	
	system("pause");
}