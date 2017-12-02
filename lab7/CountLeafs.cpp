#include "CountLeafs.h"



void Tree::Push(int a, node **t)
{
	if ((*t) == NULL)
	{
		(*t) = new node;
		(*t)->info = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}
	if (a>(*t)->info) Push(a, &(*t)->r);
	else Push(a, &(*t)->l);
}

void Tree::Countsum(node *t)
{
	if (t == NULL) return;
	else
	{
		cout << t->info << endl;
		if (t->l)
			Countsum(t->l);
		if (t->r)
			Countsum(t->r);
	}
}
void Tree::Print(node *t, int u)
{
	if (t == NULL) return;
	else
	{
		Print(t->r, ++u);
		for (int i = 0; i<u; ++i) cout << "| \t";
		cout << t->info << endl;
		u--;
	}
	Print(t->l, ++u);
}

int **TableTree::CreateArray(int culloms, int row)
{
	int ** Arr = new int *[row];
	for (int i = 0; i < culloms; i++) {
		Arr[i] = new int[culloms];
	}
	return Arr;
}
void TableTree::AddArray0(int **Arr, int culloms, int row)
{
	//cout << endl;
	for (int i = 0; i < culloms; i++) {
		for (int j = 0; j < row; j++) {
			Arr[i][j] = 0;
		}
	}
}
void TableTree::ShowArray(int**Arr, int  culloms, int row)
{
	for (int i = 0; i < culloms; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << "\t" << Arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void TableTree::CreateArrayBorders(int **Arr, int *Ar, int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		Arr[i][0] = Ar[i];
		Arr[0][i] = Ar[i];
	}
}
bool TableTree::CompareWithRoot(int *Ar, int culloms, int index)
{
	if (Ar[index] > Ar[1])
		return true;
	else
		return false;
}
bool TableTree::CompareLeft(int *Ar, int culloms, int index, vector <int>& L_buff)
{
	if (!L_buff.empty())
	{
		if (L_buff.back() >= Ar[index])
			return true; /// push down
		else
			return false; /// push up or right
	}
}
bool TableTree::CompareRight(int *Ar, int culloms, int index, vector <int>& R_buff)
{
	if (!R_buff.empty())
	{
		if (R_buff.back() <= Ar[index])
			return true;/// push down
		else
			return false;/// push up or right
	}
}
int TableTree::FindValue(int *Ar, int culloms, int index)
{
	for (int i = 1; i<culloms; i++)
		if (Ar[i] == index)
		{
			return i;
		}
}
int TableTree::LeftBufferIndex(int *Ar, int culloms, int index, vector <int> L_buff)
{
	for (int j = L_buff.size() - 1; j >= 0; j--)
	{
		if (L_buff[j] >= Ar[index])
			return j + 1;
	}
}

int TableTree::RightBufferIndex(int *Ar, int culloms, int index, vector <int> R_buff)
{
	for (int j = R_buff.size() - 1; j >= 0; j--)
	{
		if (R_buff[j] <= Ar[index])
			return j + 1;
	}
}

void TableTree::TreeTable(int **Arr, int *Ar, int culloms, /*int index,*/ vector <int>& L_buff, vector <int>& R_buff)
{
	int buff, tmp, temp;
	L_buff.push_back(Ar[1]);
	R_buff.push_back(Ar[1]);
	for (int i = 2; i < culloms; i++)
	{
		if (CompareWithRoot(Ar, culloms, i))
		{
			if (CompareRight(Ar, culloms, i, R_buff))/////ready and works
			{
				buff = R_buff.back();
				tmp = FindValue(Ar, culloms, buff);
				Arr[tmp][i] = 1;
				R_buff.push_back(Ar[i]);
			}
			else
			{
				temp = RightBufferIndex(Ar, culloms, i, R_buff);
				tmp = FindValue(Ar, culloms, R_buff[temp]);
				Arr[tmp][i] = 1;
				/// maybe insert has to be corrected
				R_buff.insert(R_buff.begin() + temp, Ar[i]);
			}
		}
		else
		{
			if (CompareLeft(Ar, culloms, i, L_buff))
			{
				buff = L_buff.back();
				tmp = FindValue(Ar, culloms, buff);
				Arr[tmp][i] = 1;
				L_buff.push_back(Ar[i]);
			}
			else
			{
				temp = LeftBufferIndex(Ar, culloms, i, L_buff);
				tmp = FindValue(Ar, culloms, L_buff[temp]);
				Arr[tmp][i] = 1;
				/// maybe insert has to be corrected
				L_buff.insert(L_buff.begin() + temp, Ar[i]);
			}

		}
		//test
		/*for (int k = 0; k < L_buff.size(); k++)
		cout << L_buff[k] << ' ';
		cout << endl;
		for (int k = 0; k < R_buff.size(); k++)
		cout << R_buff[k] << ' ';
		cout << endl;*/
		//test
	}
}

int TableTree::CountLeafs(int **Arr, int culloms, int index)
{
	int result = 0;
	for (int i = 1; i < culloms; i++)
	{
		if (Arr[index][i] == 1)
		{
			result = result + Arr[0][i];
		}
	}
	return result;
}
int TableTree::FindMaxSum(int *Ar, int n, int &maxSum)
{
	int tmp;
	maxSum = Ar[0];
	for (int i = 0; i < n + 1; i++)
	{
		if (maxSum < Ar[i]) {
			maxSum = Ar[i];
			tmp = i;
		}
	}
	return tmp;
}
