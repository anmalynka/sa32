#include "CountLeafs.h"
node * tree = NULL;
void main() 
{
	priority_queue<int> q;
	int count = 0;
	Tree t;
	TableTree tT;
	int n, maxSum=0;
	// n elements
	cout << "Number:\n";  cin >> n;
	int culloms = n + 1;
	int *Ad = new int[culloms]; // base
	int *Ad2 = new int[culloms]; // results
	vector <int> L_buff;
	vector <int> R_buff;
	//vector <int> ::iterator  it;
	Ad[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> Ad[i];
		t.Push(Ad[i], &tree);
	}
	int ** Ad1 = tT.CreateArray(culloms, culloms); /// table
	tT.AddArray0(Ad1, culloms, culloms);

	cout << "tree\n";
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
		Ad2[i]=tT.CountLeafs(Ad1, culloms, i);
	cout << "\nNode with max leafs sum is " << Ad[tT.FindMaxSum(Ad2, n, maxSum) ] << " with sum = " << Ad2[tT.FindMaxSum(Ad2, n, maxSum)] << endl;
	system("pause");
}