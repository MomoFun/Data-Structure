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
{//构建堆栈的头结点，返回指针
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

//判断S是否为空
int IsEmpty(Stack S)
{//若为空，函数返回1，否则返回0
	return(S->Next == NULL);
}

void Push(ElementType item, Stack S)
{
	struct SNode *TmpCell;
	TmpCell 
}