#include "calculation.h"

class OperationsVectors
{
	public:
		double **CreateArray(size_t row, size_t culloms)
		{
			double ** Arr = new double *[row];
			for (size_t i = 0; i < culloms; ++i) {
				Arr[i] = new double[culloms];
			}
			return Arr;
		}

		void Free(double** Arr, size_t row, size_t culloms) {
			for (size_t i = 0; i < row; ++i) {
				for (size_t j = 0; j < culloms; ++j)
				{
					delete[] Arr[i];
				}
			}
			delete[] Arr;
		}

		void AddArray(double **Arr, size_t row, size_t culloms)
		{
			cout << endl;
			for (size_t i = 0; i < row; ++i) {
				for (size_t j = 0; j < culloms; ++j) {
					cout << "Input array: " << i << " " << j << " =  ";
					cin >> Arr[i][j];
				}
			}
		}

		void ShowArray(double**Arr, size_t row, size_t culloms)
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

		void SumArrays(double**Arr1, double **Arr2, size_t row)
		{
			int arrayElementSize;
			double ** sum = new double *[row];
			for (size_t i = 0; i < row; ++i)
			{
				sum[i] = new double[row];
				for (size_t j = 0; j < row; ++j)
					sum[i][j] = Arr1[i][j] + Arr2[i][j];
			}
			ShowArray(sum, row, row);
		}

		void  DifArrays(double **Arr1, double **Arr2, size_t row)
		{
			double ** dif = new double *[row];
			for (size_t i = 0; i < row; ++i)
			{
				dif[i] = new double[row];
				for (size_t j = 0; j < row; ++j)
					dif[i][j] = Arr1[i][j] - Arr2[i][j];
			}
			ShowArray(dif, row, row);
		}

		void ProdArrays(double **Arr1, double **Arr2, size_t row)
		{
			double ** prod = new double *[row];
			for (size_t i = 0; i < row; ++i)
			{
				prod[i] = new double[row];
				for (size_t j = 0; j < row; ++j)
				{
					prod[i][j] = 0;
					for (size_t k = 0; k < row; ++k)
						prod[i][j] = prod[i][j] + (Arr1[i][k] * Arr2[k][j]);
				}
			}
			ShowArray(prod, row, row);
		}

		bool  DivArrays(double **Arr1, double **Arr2, size_t row)
		{
			double ** div = new double *[row];
			for (size_t i = 0; i < row; ++i) {
				div[i] = new double[row];

				for (size_t j = 0; j < row; ++j) if (Arr2[i][j] == 0) return 0;
			}
			for (size_t i = 0; i < row; ++i) {
				for (size_t j = 0; j < row; ++j)
				{
					div[i][j] = 0;
					for (size_t k = 0; k < row; ++k)
						div[i][j] = div[i][j] + (Arr1[i][k] / Arr2[k][j]);

				}
				ShowArray(div, row, row);
				return 1;
			}
		}

		//void findandchange(double **Arr1, double **Arr3, size_t n, size_t m)
		//			{
		//				for (size_t i = 0; i < n; i++) {
		//					for (size_t j = 0; j < n; j++) {
		//						Arr3[i][j] = Arr1[i][j];
		//					}
		//				}
		//				int k = 0; double tmp;
		//				for (size_t i = 0; i < n; i++) {
		//
		//					for (size_t j = 0; j < n; j++) {
		//						for (int k = 0; k <= n; k++) {
		//
		//							if (Arr3[i][j] == 0)
		//							{
		//								tmp = Arr3[i][j];
		//								Arr3[i][j] = Arr3[2][k];
		//								Arr3[2][k] = tmp;
		//								
		//							}
		//							if (k == n - 1) break;
		//							if (i == 2)
		//								break;
		//
		//
		//						}
		//					}
		//				}
		//				showarray(Arr3, n, m);
		//			}
		////////////////////////

		bool TinyArray(double **Arr1, vector <double> &archiveVector, size_t row, size_t culloms)
		{
			int tmp, null = 0;
			vector<double>::iterator it;
			double *s_array = new double[row*culloms];
			if (row < 3)
				return 0;
			else
			{
				for (size_t i = 0, k = 0; i < row; ++i)
				{
					for (size_t j = 0; j < row; ++j)
						s_array[k++] = Arr1[i][j];
				}
				copy(s_array, s_array + row*culloms, back_inserter(archiveVector));
				for (int i = 0; i < archiveVector.size(); i++)
				{
					if (archiveVector[i] == 0)
					{
						tmp = i;
						archiveVector.erase(archiveVector.begin() + tmp);
						i--;
					}
				}
				ShowVector(archiveVector, it);
				delete[] s_array;
			}
			return 1;
		}

		void ShowVector(vector <double>& archiveVector, vector <double>::iterator& it)
		{
			for (it = archiveVector.begin(); it < archiveVector.end(); it++)
				cout << ' ' << *it;
		}

		int OLdArraySize(size_t row)
		{
			int OldSize = pow(row, 2) * sizeof(double);
			return OldSize;
		}

		int NewArraySize(vector <double> &archivedVector)
		{
			int NewSize = archivedVector.size() * sizeof(double);
			return NewSize;
		}

		void  NormalArray(double **Arr1, vector <double> &archiveVector, size_t row)
		{
			vector<double>::iterator it;
			int commonCharacters;	commonCharacters = row * 2;
			int underLength;	underLength = row / 3;
			int again = 0;
			double *l_array = new double[row*row];
			while (again < underLength)
			{
				for (int i = 0; i < row; i++)
					archiveVector.emplace(archiveVector.begin() + commonCharacters, 0);
				again++; commonCharacters = commonCharacters + row * 3;
			}
			ShowVector(archiveVector, it);
		}

};