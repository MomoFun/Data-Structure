#include <iostream>
using namespace std;

#define MaxSize 100

typedef int ElementType;
typedef struct SNode *Stack;
struct SNode{
	ElementType Data[MaxSize];
	int Top;
};

void Push(Stack PtrS, ElementType item)
{
	if (PtrS->Top == MaxSize -1)
	{
		cout << "the stack is full" << endl;
	}else{
		PtrS->Data[++(PtrS->Top)] = item;
	}
}

ElementType Pop(Stack PtrS)
{
	if (PtrS->Top == -1)
	{
		cout << "stack is empty" << endl;
	}else{
		return(PtrS->Data[(PtrS->Top)--]);
	}
}


//用一个数组实现两个栈的结构体
typedef struct DSNode *DStack;
struct DSNode{
	ElementType Data[MaxSize];
	int Top1;  //堆栈1的栈顶指针
	int Top2;  //堆栈2的栈顶指针
}S;
S.Top1 = -1;
S.Top2 = MaxSize;

void Push(DStack PtrS, ElementType item, int Tag)
{
	if(PtrS->Top2 - PtrS->Top1 == 1){
		cout << "stack is full" << endl;
	}
	if(Tag == 1)
	{
		PtrS->Data[++(PtrS->Top1)] = item;
	}else{
		PtrS->Data[--(PtrS->Top2)] = item;
	}
}

ElementType Pop(DStack PtrS, int Tag)
{
	if (Tag == 1)
	{
		if (PtrS->Top1 == -1)
		{
			cout << "stack1 is empty" << endl;
			return NULL;
		}else {
			return PtrS->Data[(PtrS->Top1)--];
		}
	}else{
		if (PtrS->Top2 == MaxSize)
		{
			cout << "stack2 is empty" <<endl;
			return NULL;
		}else{
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
}
