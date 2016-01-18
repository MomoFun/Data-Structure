#ifndef MYQUEUE_H
#define MYQUEUE_H

/*******************************/
/*      环形队列C++实现        */
/*******************************/

class MyQueue
{
public:
	MyQueue(int queueCapacity);     //创建队列   InitQueue(&Q)
	virtual ~MyQueue();				//销毁队列   DestroyQueue(&Q)
	void ClearQueue();				//清空队列   ClearQueue(&Q)
	bool QueueEmpty() const;		//判断队列   QueueEmpty(Q)
	bool QueueFull() const;			//判断队列   QueueFull(Q)
	int QueueLength() const;		//队列长度   QueueLength(Q)
	bool EnQueue(int element);		//新元素入队 EnQueue(&Q, element)
	bool DeQueue(int &element);		//首元素出队 DeQueue(&Q, &element)
	void QueueTraverse();			//遍历队列   QueueTraverse(Q,visit())
private:
	int *m_pQueue;					//队列数组指针
	int m_iQueueLen;				//队列元素个数
	int m_iQueueCapacity;			//队列数组容量
	int m_iHead;					//队头
	int m_iTail;					//队尾
};

#endif