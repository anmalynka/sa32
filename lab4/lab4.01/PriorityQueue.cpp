#include "PriorityQueue.h"

void Priority_Queue:: CreatePriorityQueue(QUEUE*&q, int number)
{
	int prio, val, count = 0;
	while (count < number)
	{
		NODE* nd = new NODE;
		cout << "prioriry: "; 
		if (!(cin >> prio))
			throw 2;
		cout << "value:    "; 
		if (!(cin >> val))
			throw 3;
		nd->next = *(q->end);
		nd->prio = prio;
		nd->value = val;
		*(q->end) = nd;
		q->end = &(nd->next);
		count++;

	}
}

void Priority_Queue::AddNewQueueElement(QUEUE*&q, int addnumber) {
	int prio, val, count = 0;
	while (count < addnumber) {
		NODE* node = new NODE;
		cout << "prioriry: ";
		if (!(cin >> prio))
			throw 2;
		cout << "value:    ";
		if (!(cin >> val))
			throw 3;
		node->next = *(q->end);
		node->prio = prio;
		node->value = val;
		*(q->end) = node;
		q->end = &(node->next);
		count++;
	}
}

void Priority_Queue::CreateOutputQueue(oQueue *&head, oQueue*&tail, QUEUE *&q, double res)
{
	head = new oQueue;
	tail = new oQueue;
	head->nextO = tail;
	tail->predO = head;
	oQueue *oQ = new oQueue;
	oQ->info = res;
	oQ->nextO = tail;
	oQ->predO = tail->predO;
	tail->predO = oQ;
	oQ->predO->nextO = oQ;
}

void Priority_Queue::ShowOutputQueue(oQueue *&head, oQueue*&tail)
{
	oQueue *output = head;
	while (output != tail->predO)
	{
		cout << output->nextO->info << " ";
		output = output->nextO;
	}
	cout << " ";
}

void Priority_Queue::CopyQueue(QUEUE*&q, QUEUE*&qout, double res, int n)
{
	int count = 0;
	NODE**curnode = (&q->first);
	while (*curnode != NULL) {
		//elemnode = curnode;

		NODE* nd = new NODE;
		nd->next = *(qout->end);
		nd->prio = (*curnode)->prio;
		nd->value = (*curnode)->value;
		*(qout->end) = nd;
		qout->end = &(nd->next);
		curnode = &((*curnode)->next);
	}
}

double Priority_Queue::MinPriority(QUEUE *&qout, QUEUE*&q, double res) {
	NODE**curnode = &(qout->first);
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
		qout->end = minnode;
	return res;
}
