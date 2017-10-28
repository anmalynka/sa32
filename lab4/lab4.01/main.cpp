#include "PriorityQueue.h"

void main()
{
	Priority_Queue queue;
	oQueue *head, *tail;
	int number, count = 0, add_number=0;
	int Choice, ChoiceC = 1;
	double res = 0, element=0;
	QUEUE *q = new QUEUE;
	QUEUE *qout = new QUEUE;
	q->first = NULL;
	q->end = &(q->first);
	qout->first = NULL;
	qout->end = &(qout->first);
	cout << "CREATE PRIORITY QUEUE" << endl;
	cout << "Number of elements: "; cin >> number;
	try
	{
		queue.CreatePriorityQueue(q, number);
		queue.CopyQueue(q, qout, res, number);
		if (q->first == NULL)
			cout << "Can't get the value ";
		while (ChoiceC != 0) 
		{
			cout << "(1)-add element, (2)-read queue" << endl;
			cin >> Choice;
			switch (Choice) 
			{
			case 2:
				cout << "Prioritized queue: ";
				while (count < number + add_number)
				{
					res = queue.MinPriority(qout, q, res);
					queue.CreateOutputQueue(head, tail, q, res);
					queue.ShowOutputQueue(head, tail);
					count++;
				}
				count = 0;
				cout << "\nContinue YES(1)/NO(0)  ";
				cin >> ChoiceC;
				break;
			case 1:
				cout << "How many elements? "; cin >> add_number;
				queue.AddNewQueueElement(q, add_number);
				cout << "Element(s) added";
				queue.CopyQueue(q, qout, res, number);
				cout << "\nContinue YES(1)/NO(0)  ";
				cin >> ChoiceC;
				break;
			}
		}
	}
	catch (const exception& e)
	{
			cout << " a standard exception was caught, with message '"
				<< e.what() << "'\n";
	}
	catch (int x)
	{
		cout << "Error: You may input just digits";
	}
	cout << endl;
	system("pause");
}