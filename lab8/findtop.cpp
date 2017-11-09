#include "findtop.h"
int **Graph:: CreateArray(size_t row, size_t culloms)
{
	int ** Arr = new int *[row];
	for (size_t i = 0; i < culloms; ++i) {
		Arr[i] = new int[culloms];
	}
	return Arr;
}
void Graph::AddArray(int **Arr, size_t row, size_t culloms)
{
	cout << endl;
	for (size_t i = 0; i < row; ++i) {
		for (size_t j = 0; j < culloms; ++j) {
			cout << "Input array: " << i << " " << j << " =  ";
			if (!(cin >> Arr[i][j]))
				throw 2;
		}
	}
}

void Graph::ShowArray(int**Arr, size_t row, size_t culloms)
{
	for (size_t i = 0; i < row; ++i)
	{
		for (size_t j = 0; j < culloms; ++j)
		{
			cout << "\t" << Arr[i][j] << ' ';
		}
		cout << endl;
	}
}
int *Graph:: CreateValueArray(size_t row)
{
	int  *Arr = new int[row];
	return Arr;

}
void Graph:: FillValueArray(int *Arr, size_t row)
{
	for (size_t i = 0; i < row; ++i) {
		cout << "Input array: ";
		if (!(cin >> Arr[i]))
			throw 2;
	}
	for (size_t i = 0; i < row; ++i)
	{
		cout << "\t" << Arr[i] << ' ';
	}
	cout << endl;
}
int Graph::IncidencyFind(int**Arr, int *Val, size_t row, size_t culloms, int value)
{

	for (int i = 0; i < row; i) {
		for (int j = 0; j < culloms; j++) {
			if (Arr[i][j] == 1) {
				cout << "-" << j + 1;
				Arr[i][j] = 0;
				for (int l = 0; l < row; l++) {
					if (Arr[l][j] == 1) {
						Arr[l][j] = 0;
						if (Val[l - 1] == value)
						{
							//cout << "\nfound, it's  " << l << " point" << endl;
							return l;
							i = row;
							j = culloms;
							break;
						}
						i = l;
						break;
					}
				}
			}

		}
	}
}

int Graph::AdjacencyFind(int**Arr, int*Val, size_t row, size_t culloms, int value)
{
	cout << "Steps:   1";
	for (int i = 0; i < row; i) {
		for (int j = 0; j < row; j++) {
			if (Arr[i][j] == 1) {
				Arr[i][j] = 0;
				Arr[j][i] = 0;
				cout << "-" << j + 1;
				if (Val[j - 1] == value)
				{
					return j;
					i = row;
					break;
				}
				i = j;
				break;
			}

		}
	}

}
void Graph::TestIncidency() {
	const int n = 7, m = 11, k = 4;
	int Val[n][1] = { 5, 6, 7, 4, 2, 1, 9 };
	int In[n][m] =
	{
		{ 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 } };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cout << In[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << Val[i - 1][1] << ' ';
	}
	cout << "way:  0";
	for (int i = 0; i < n; i) {
		for (int j = 0; j < m; j++) {
			if (In[i][j] == 1) {
				cout << "-" << j + 1;
				In[i][j] = 0;
				for (int l = 0; l < n; l++) {
					if (In[l][j] == 1) {
						In[l][j] = 0;
						if (Val[l - 1][1] == k)
						{
							cout << "\nfound, it's  " << l + 1 << " point" << endl;
							i = n;
							j = m;
							break;
						}
						i = l;
						break;
					}
				}
			}
		}
	}
}
void Graph::TestAdjacency()
{
	const int n = 7, m = 11, k = 4;// число вершин
	int s = 0; // стартовая вершина (вершины везде нумеруются с нуля)
			   // чтение графа
	int Adj[n][n] =
	{ { 0, 1, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 0, 1, 1, 0 },
	{ 1, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1 },
	{ 1, 1, 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 1, 0, 0, 1 },
	{ 0, 0, 1, 1, 0, 1, 0 } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Adj[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	int Val[n][1] = { 5, 6, 7, 4, 2, 1, 9 };
	for (int i = 0; i < n; i++)
	{
		cout << Val[i - 1][1] << ' ';
	}
	cout << "\nSteps:   1";
	for (int i = 0; i < n; i) {
		for (int j = 0; j < n; j++) {
			if (Adj[i][j] == 1) {
				Adj[i][j] = 0;
				Adj[j][i] = 0;
				cout << "-" << j + 1;
				if (Val[j - 1][1] == k)
				{
					cout << "\nfound, it's  " << j + 1 << " point" << endl;
					i = n;
					break;
				}
				i = j;
				break;
			}

		}
	}
	cout << endl;

}
