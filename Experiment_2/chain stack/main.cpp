#include<iostream>
using namespace std;

struct Stack1  //�����ջ
{
	char operators;
	Stack1* next;
}optr;
struct Stack2  //������ջ
{
	double nums;
	Stack2* next;
}opnd;

Stack1 *InitStack1(Stack1& optr)  //������ջ
{
	Stack1* top;
	top = new Stack1;
	return top;
}
Stack2 *InitStack2(Stack2& opnd)
{
	Stack2* top;
	top = new Stack2;
	return top;
}

void Push1(Stack1& optr, char e, Stack1* &top, Stack1* &p)  //��ջ
{
	top->operators = e;
	p = top;
	top = new Stack1;
	top->next = p;
}
void Push2(Stack2& opnd, char e,Stack2* &top, Stack2* &q)
{
	 top->nums=double(e - 48);
	 q = top;
	 top = new Stack2;
	 top->next = q;
}
void Push2(Stack2& opnd, double e, Stack2* &top, Stack2* &q)
{
	top->nums = double(e);
	q = top;
	top = new Stack2;
	top->next = q;
}

char Pop1(Stack1 *top, Stack1 *&p)  //��ջ
{
	char temp= p->operators;
	top->next = p->next;
	p = p->next;
	return temp;
}
double Pop2(Stack2 *top, Stack2 *&q)
{
	double temp = q->nums;
	top->next = q->next;
	q = q->next;
	return temp;
}

char GetTop1(Stack1 *p)  //ȡջ��
{
	return p->operators;
}
double GetTop2(Stack2 *q)
{
	return q->nums;
}

bool isNum(char c)  //�ж��Ƿ�Ϊ����
{
	if (c >= 48 && c <= 57)
		return true;
	else
		return false;
}

char Precede(char a, char b)  //���ȼ��Ƚ�
{
	if (a == '+' || a == '-')
	{
		if (b == '+' || b == '-' || b == ')' || b == '#')
			return'>';
		if (b == '*' || b == '/' || b == '(' || b == '%' || b == '^')
			return'<';
	}
	if (a == '*' || a == '/' || a == '%')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == '%' || b == ')' || b == '#')
			return'>';
		if (b == '(' || b == '^')
			return'<';
	}
	if (a == '^' || a == ')')
	{
		return'>';
	}
	if (a == '(')
	{
		if (b == ')')
			return'=';
		else
			return'<';
	}
	if (a == '#')
	{
		if (b == '#')
			return'=';
		else
			return'<';
	}
}

double Operate(double a, char theta, double b)  //��������
{
	switch (theta)
	{
	case'+':
		return(a + b);
	case'-':
		return(a - b);
	case'*':
		return(a * b);
	case'/':
		return(a / b);
	case'%':
		return((int)a % (int)b);
	case'^':
		return(pow(a, b));
	}
}

int main()
{
	Stack1* top1 = InitStack1(optr);
	Stack1* p = top1;
	Push1(optr, '#', top1, p);

	Stack2* top2 = InitStack2(opnd);
	Stack2* q = top2;
	char c;
	cout << "�������λ�����ʽ����#������";
	c = getchar();

	double a = 0, b = 0;
	char x = NULL, theta = NULL;

	while (c != '#' || GetTop1(p) != '#')
	{
		if (isNum(c))
		{
			Push2(opnd, c, top2, q);
			c = getchar();
		}
		else
		{
			switch (Precede(GetTop1(p), c))
			{
			case'<':
				Push1(optr, c, top1, p);
				c = getchar();
				break;
			case'=':
				Pop1(top1,p);
				c = getchar();
				break;
			case'>':
				theta = Pop1(top1,p);
				b = Pop2(top2,q);
				a = Pop2(top2,q);
				Push2(opnd, Operate(a, theta, b), top2, q);
				break;
			}
		}
	}
	cout << "���Ϊ" << GetTop2(q) << endl;
	return 0;
}