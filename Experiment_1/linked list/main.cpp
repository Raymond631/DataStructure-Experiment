#include <iostream>
using namespace std;

struct Polynomial   //多项式
{
	double coefficient;   //系数
	int index;   //指数
	Polynomial* next = nullptr;
};

Polynomial *CreatPoly(int n)   //输入多项式
{
	Polynomial* head = NULL;   //头指针
	Polynomial* p = NULL, * q = NULL;  //p指向当前new的节点，q指向上一节点
	for (int i = 1; i <= n; i++)
	{
		p = new Polynomial;
		cout << "请输入您的第" << i << "项的系数：";
		cin >> p->coefficient;
		cout << "请输入您的第" << i << "项的指数：";
		cin >> p->index;

		if (i == 1)   //只做1次
		{
			head = p;   //固定头指针
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	return head;
}

void PrintPoly(Polynomial* poly)   //输出多项式
{
	while (poly->next != NULL)
	{
		cout << poly->coefficient << "  " << poly->index << endl;
		poly = poly->next;
	}
	cout << poly->coefficient << "  " << poly->index << endl;
}

Polynomial* AddPoly(Polynomial* h1, Polynomial* h2)   //定义加法函数，并返回结果的链表的头指针
{
	Polynomial* p, * q, * head, * r;          //定义结构体头指针head和标记指针p,q,r
	p = h1;
	q = h2;
	head = new Polynomial;    //为结果多项式分配头节点
	if (p->index > q->index) 
	{ 
		head = h1;
		p = p->next;
	}
	else
	{
		if (p->index < q->index) 
		{ 
			head = h2;
			q = q->next;
		}
		else
		{ 
			p->coefficient = p->coefficient + q->coefficient;
			head = p;
			p = p->next;
			q = q->next;
		}
	}
	r = head;
	while (p != NULL && q != NULL)   //节点是否为空 用 指针是否为空 来判断
	{
		if (p->index > q->index) 
		{ 
			r->next = p;
			p = p->next;
		}
		else
		{
			if (p->index < q->index) 
			{ 
				r->next = q;
				q = q->next;
			}
			else
			{ 
				p->coefficient = p->coefficient + q->coefficient; 
				r->next = p; 
				p = p->next; 
				q = q->next; 
			}
		}
		r = r->next;
	}
	if (p == NULL && q == NULL) 
		r->next = NULL;
	else
	{
		if (p == NULL) r->next = q;
		if (q == NULL) r->next = p;
	}
	return head;
}


int main()
{
	Polynomial* h1, * h2, * h3;

	cout << "请输入第一个多项式的项数：";
	int n1;
	cin >> n1;
	h1=CreatPoly(n1);

	cout << "请输入第二个多项式的项数：";
	int n2;
	cin >> n2;
	h2=CreatPoly(n2);

	h3=AddPoly(h1,h2);
	cout << "合并后的多项式为：" << endl;
	PrintPoly(h3);

	return 0;
}