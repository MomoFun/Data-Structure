#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	struct SNode *Next;
};

//Initial stack
Stack CreateStack()
{//������ջ��ͷ��㣬����ָ��
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

//�ж�S�Ƿ�Ϊ��
int IsEmpty(Stack S)
{//��Ϊ�գ���������1�����򷵻�0
	return(S->Next == NULL);
}

void Push(ElementType item, Stack S)
{
	struct SNode *TmpCell;
	TmpCell 
}