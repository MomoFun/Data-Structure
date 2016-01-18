#ifndef MYQUEUE_H
#define MYQUEUE_H

/*******************************/
/*      ���ζ���C++ʵ��        */
/*******************************/

class MyQueue
{
public:
	MyQueue(int queueCapacity);     //��������   InitQueue(&Q)
	virtual ~MyQueue();				//���ٶ���   DestroyQueue(&Q)
	void ClearQueue();				//��ն���   ClearQueue(&Q)
	bool QueueEmpty() const;		//�ж϶���   QueueEmpty(Q)
	bool QueueFull() const;			//�ж϶���   QueueFull(Q)
	int QueueLength() const;		//���г���   QueueLength(Q)
	bool EnQueue(int element);		//��Ԫ����� EnQueue(&Q, element)
	bool DeQueue(int &element);		//��Ԫ�س��� DeQueue(&Q, &element)
	void QueueTraverse();			//��������   QueueTraverse(Q,visit())
private:
	int *m_pQueue;					//��������ָ��
	int m_iQueueLen;				//����Ԫ�ظ���
	int m_iQueueCapacity;			//������������
	int m_iHead;					//��ͷ
	int m_iTail;					//��β
};

#endif