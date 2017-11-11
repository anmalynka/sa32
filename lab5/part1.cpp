#include "Dividebyvalue.h"
void main()
{
	STARTUPINFO sif;
	PROCESS_INFORMATION pif;
	TCHAR CommandLine[] = TEXT("lab5.02.exe");

	ZeroMemory(&sif, sizeof(sif));
	sif.cb = sizeof(sif);
	ZeroMemory(&pif, sizeof(pif));

	cout << "Work of the first process\n";

	List L;
	CSV C;
	int n = 0;
	vector <int> myValues;
	int number, numbers = 1000, lines = 1;
	try {
		C.OpenFile(myValues, numbers, lines);
		C.ShowArray(myValues, numbers, lines);


		for (int i = 0; i < lines; i++) {
			for (int i = 0; i < numbers; i++) {
				L.AddTail(myValues[i]);
			}
		}
		//cout << "\nList L:\n";
		//L.Print();
		cout << "\nInput number to separate" << endl;
		if (!(cin >> number) || number < 1 || number>1000)
		{
			throw 2;
		}
		L.CopyLeft(number);
		L.CopyRight(number);
		cout << "\nFist part\n";
		L.PrintNewLeft();
		cout << "\nSecond part\n";
		L.PrintNewRight();
	}
	catch (int error)  {
		if (error == 1)
			cout << "Couldn't open a file\n";
		if (error == 2)
			cout << " Value have to be JUST digit from 1 to 1000\n";

	}
	if (!CreateProcess(NULL, CommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &sif, &pif))
		cout << "CreateProcess failed.\n";

	WaitForSingleObject(pif.hProcess, INFINITE);
	cout << "End of child process.\n";


	CloseHandle(pif.hProcess);
	CloseHandle(pif.hThread);


	system("pause");
}