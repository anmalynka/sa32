#pragma once
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
class Priority_Queue
{
public:
	
	void CreatePriorityQueue(QUEUE*&q, int number);
	void AddNewQueueElement(QUEUE*&q, int addnumber);
	void CreateOutputQueue(oQueue *&head, oQueue*&tail, QUEUE *&q, double res);
	void ShowOutputQueue(oQueue *&head, oQueue*&tail);
	void CopyQueue(QUEUE*&q, QUEUE*&qout, double res, int n);
	double MinPriority(QUEUE *&qout, QUEUE*&q, double res);
};