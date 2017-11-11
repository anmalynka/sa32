#include "Dividebyvalue.h"

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::List(const List & L)
{
	Head = Tail = NULL;
	Count = 0;
	node * temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

void List::AddHead(int n)
{
	node * temp = new node;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}

void List::AddTail(int n)
{
	node * temp = new node;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}
void List::CopyLeft(int number)
{
	node * temp = new node;
	temp = Head;
	node *m; int a = 0;
	while (temp != NULL)
	{
		a++;
		if (temp->data <= number)
		{
			m = temp;
			node *newlist = new node;
			newlist->next = NULL;
			newlist->data = m->data;

			if (HeadL != NULL)
			{
				newlist->prev = TailL;
				TailL->next = newlist;
				TailL = newlist;
			}
			else
			{
				newlist->prev = NULL;
				HeadL = TailL = newlist;
			}
		}
		temp = temp->next;
	}

}
void List::CopyRight(int number)
{
	node * temp = new node;
	temp = Head;
	node *m; int a = 0;
	while (temp != NULL)
	{
		a++;
		if (temp->data > number)
		{
			m = temp;
			node *newlist = new node;
			newlist->next = NULL;
			newlist->data = m->data;

			if (HeadR != NULL)
			{
				newlist->prev = TailR;
				TailR->next = newlist;
				TailR = newlist;
			}
			else
			{
				newlist->prev = NULL;
				HeadR = TailR = newlist;
			}

		}
		temp = temp->next;
	}

}

void List::Print()
{
	if (Count != 0)
	{
		node * temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}
void List::PrintNewLeft()
{
	if (Count != 0)
	{
		node * temp = HeadL;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}
void List::PrintNewRight()
{
	if (Count != 0)
	{
		node * temp = HeadR;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

int List::GetCount()
{
	return Count;
}

void CSV::OpenFile(vector<int>&myValues, int numbers, int lines)
{
	int x = 0;     // a variable that will contain a value from the file
	ifstream ifs("numbers.csv");
	if (ifs.fail())
	{
		throw 1;
		ifs.close();
	}
	char tmp;
	for (int i = 0; i < lines; ++i) {
		for (int i = 0; i < numbers; ++i) {
			ifs >> x;
			myValues.push_back(x);
			if (i < (numbers - 1))
				ifs >> tmp;
		}
	}

}
void CSV::ShowArray(vector<int>&myValues, int numbers, int lines)
{
	for (int i = 0; i < lines; ++i) {
		for (int i = 0; i < numbers; ++i) {
			cout << myValues[i] << ' ';
		}
	}

}
