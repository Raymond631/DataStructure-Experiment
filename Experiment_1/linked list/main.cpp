#include <iostream>
using namespace std;

struct Polynomial   //����ʽ
{
	double coefficient;   //ϵ��
	int index;   //ָ��
	Polynomial* next = nullptr;
};

Polynomial *CreatPoly(int n)   //�������ʽ
{
	Polynomial* head = NULL;   //ͷָ��
	Polynomial* p = NULL, * q = NULL;  //pָ��ǰnew�Ľڵ㣬qָ����һ�ڵ�
	for (int i = 1; i <= n; i++)
	{
		p = new Polynomial;
		cout << "���������ĵ�" << i << "���ϵ����";
		cin >> p->coefficient;
		cout << "���������ĵ�" << i << "���ָ����";
		cin >> p->index;

		if (i == 1)   //ֻ��1��
		{
			head = p;   //�̶�ͷָ��
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

void PrintPoly(Polynomial* poly)   //�������ʽ
{
	while (poly->next != NULL)
	{
		cout << poly->coefficient << "  " << poly->index << endl;
		poly = poly->next;
	}
	cout << poly->coefficient << "  " << poly->index << endl;
}

Polynomial* AddPoly(Polynomial* h1, Polynomial* h2)   //����ӷ������������ؽ���������ͷָ��
{
	Polynomial* p, * q, * head, * r;          //����ṹ��ͷָ��head�ͱ��ָ��p,q,r
	p = h1;
	q = h2;
	head = new Polynomial;    //Ϊ�������ʽ����ͷ�ڵ�
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
	while (p != NULL && q != NULL)   //�ڵ��Ƿ�Ϊ�� �� ָ���Ƿ�Ϊ�� ���ж�
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

	cout << "�������һ������ʽ��������";
	int n1;
	cin >> n1;
	h1=CreatPoly(n1);

	cout << "������ڶ�������ʽ��������";
	int n2;
	cin >> n2;
	h2=CreatPoly(n2);

	h3=AddPoly(h1,h2);
	cout << "�ϲ���Ķ���ʽΪ��" << endl;
	PrintPoly(h3);

	return 0;
}