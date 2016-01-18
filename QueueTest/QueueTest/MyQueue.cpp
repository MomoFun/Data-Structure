#include "MyQueue.h"
#include <iostream>
using namespace std;

//创建环形队列
MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new int[m_iQueueCapacity];
	ClearQueue();
}

MyQueue::~MyQueue()
{
	delete[] m_pQueue;
	m_pQueue =NULL;
}

void MyQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty() const
{
	return m_iQueueLen == 0 ? true: false;
}

bool MyQueue::QueueFull() const
{
	return m_iQueueLen == m_iQueueCapacity? true: false;
}

int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

bool MyQueue::EnQueue(int element)	
{
	if(QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail = (m_iTail+1) % m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}

bool MyQueue::DeQueue(int &element)
{
	if (QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead = (m_iHead+1) % m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}

void MyQueue::QueueTraverse()
{
	for (int i = m_iHead; i < m_iHead + m_iQueueLen; i++)
	{
		cout << m_pQueue[i%m_iQueueCapacity] << endl;
	}
	cout << endl;
}