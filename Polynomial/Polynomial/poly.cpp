#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct PolyNode{			 //多项式每一项的结点结构体
	int coef;				 //系数
	int expon;				 //指数
	struct PolyNode *link;	 //指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;	//指向结点的指针
Polynomial P1,P2;

int Compare(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else if (a < b)
	{
		return -1;
	}
	else
	{
		return 0; 
	}
}
void Attach(int c, int e, Polynomial *pRear)
{
	Polynomial P;

	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

//读入多项式
Polynomial ReadPoly()
{
	Polynomial P,Rear,t;
	int c,e,N;

	cin >> N;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(N--){
		cin >> c >> e;
		Attach(c,e,&Rear);
	}
	t = P; P = P->link; free(t);
	return P;
}

//多项式乘法
Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;

	if (!P1||!P2)
	{
		return NULL;
	}

	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(t2){//用P1的第一项乘以P2，得到P
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while(t1)
	{
		t2 = P2;
		Rear = P;
		while(t2){
			e = t1->expon + t2->expon;
			c = t1->coef + t2->coef;
			while (Rear->link && Rear->link->expon > e)
			{
				Rear = Rear->link;
			}
			if (Rear->link && Rear->link->expon == e)
			{
				if (Rear->link->coef + c)
				{
					Rear->link->coef += c;
				}
				else
				{//删除操作
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else
			{//插入操作
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	return P;
}


//多项式加法
Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;

	while(P1&&P2)
	{
		switch(Compare(P1->expon,P2->expon)){
		case 1:
			Attach(P1->coef,P1->expon,&rear);
			P1 = P1->link;
			break;
		case -1:
			Attach(P2->coef,P2->expon,&rear);
			P2 = P2->link;
			break;
		case 0:
			sum = P1->coef + P2->coef;
			if(sum){
				Attach(sum,P1->expon,&rear);
				P1 = P1->link;
				P2 = P2->link;
				break;
			}
		}
	}

	for (;P1;P1=P1->link)
	{
		Attach(P1->coef,P1->expon,&rear);
	}

	for (;P2;P2=P2->link)
	{
		Attach(P2->coef,P2->expon,&rear);
	}
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}

//输出多项式
void PrintPoly(Polynomial P)
{
	int flag = 0;//辅助调整输出格式

	if (!P)
	{
		cout << "0 0" << endl;
		return;
	}
	while (P)
	{
		if (!flag)
		{
			flag = 1;
		}
		else
		{
			cout << " ";
		}
		cout << P->coef << P->expon;
		P = P->link;
	}
	cout << endl;
}

int main()
{
	Polynomial P1, P2, PP, PS;//定义变量

	//读入多项式
	P1 = ReadPoly();
	P2 = ReadPoly();

	PP = Mult(P1,P2);
	PrintPoly(PP);
	PS = PolyAdd(P1,P2);
	PrintPoly(PS);

	return 0;
}

