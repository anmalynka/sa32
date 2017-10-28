#include <iostream>
#include <list>
#include <iomanip>
#include <string>

using namespace std;

typedef struct node
{
	struct node *next, *pred;
	int prio;
	//string value;
	double value;
} NODE;

typedef struct queue
{
	NODE *first;
	NODE **end; 
} QUEUE;

typedef struct oQueue
{
	int info;
	oQueue *nextO, *predO;
};

void makequeue(QUEUE*&q, int n)
{
	int b, c, k=0;
	while (k < n)
	{
		NODE* nd = new NODE;
		cin >> b;
		cin >> c;
		nd->next = *(q->end);
		nd->prio = b;
		nd->value = c;
		*(q->end) = nd;
		q->end = &(nd->next);
		k++;
	}
}

double minprio(QUEUE *&q,  double res) {
	NODE**curnode = &(q->first);
	NODE** minnode = curnode;
	
		while (*curnode != NULL)
		{
			if ((*curnode)->prio <= (*minnode)->prio)
				minnode = curnode;
			curnode = &((*curnode)->next);
		}
		
		res = (*minnode)->value;
		NODE *tmp = *minnode;
		*minnode = tmp->next;
		free(tmp);
		if (*minnode == NULL)
			q->end = minnode;
		return res;
}

void makeoutputQueue(oQueue *&head, oQueue*&tail, QUEUE *&q,  double res)
{
	
	head = new oQueue;
	tail = new oQueue;
	head->nextO = tail;
	tail->predO = head;

	res = minprio(q, res);
	oQueue *oQ = new oQueue;
	oQ->info = res;
	oQ->nextO = tail;
	oQ->predO = tail->predO;
	tail->predO = oQ;
	oQ->predO->nextO = oQ;
}
void showoutputQueue(oQueue *&head, oQueue*&tail)
{
	oQueue *output = head;
	while (output != tail->predO)
	{
		cout << output->nextO->info << " ";
		output = output->nextO;
	}
	cout << " ";
}

void main(){
	oQueue *head, *tail;
	int n, k = 0;
	
	double res = 0;
QUEUE *q = new QUEUE;
q->first = NULL;
q->end = &(q->first);
cout << "Number of elements: ";
cin >> n;
makequeue(q, n);

if (q->first == NULL)
cout << "Can't get the value ";
cout << "Prioritized queue: ";
while (k < n)
{
	makeoutputQueue(head, tail, q, res);
	showoutputQueue(head, tail);
	k++;
}

system("pause");
}