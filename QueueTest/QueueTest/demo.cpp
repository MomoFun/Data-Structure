#include "MyQueue.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	MyQueue *p = new MyQueue(4);
	p->EnQueue(10);
	p->EnQueue(2);
	p->EnQueue(13);
	p->EnQueue(5);
	p->QueueTraverse();

	cout << "delete element" << endl;
	int e = 0;
	p->DeQueue(e);
	cout << e << endl;
	p->DeQueue(e);
	cout << e << endl;

	cout << "Queue:" << endl;
	p->QueueTraverse();

	p->ClearQueue();
	p->QueueTraverse();

	p->EnQueue(1);
	p->QueueTraverse();

	delete p;
	p = NULL;
	system("pause");
	return 0;
}
