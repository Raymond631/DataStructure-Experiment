#include<iostream>
using namespace std;

struct Stack1  //运算符栈
{
	char* base;
	char* top;
}optr;
struct Stack2  //操作数栈
{
	double* base;
	double* top;
}opnd;

void InitStack1(Stack1 &optr)  //创建空栈
{
	optr.base = new char[100];
	optr.top = optr.base;
}
void InitStack2(Stack2 &opnd)
{
	opnd.base = new double[100];
	opnd.top = opnd.base;
}

void Push1(Stack1& optr, char e)  //入栈
{
	*(optr.top++) = e;
}
void Push2(Stack2& opnd, char e)
{
	*(opnd.top++) = double(e-48);
}
void Push2(Stack2& opnd, double e)
{
	*(opnd.top++) = double(e);
}

char Pop1(Stack1& optr)  //出栈
{
	return *(--optr.top);
}
double Pop2(Stack2& opnd)
{
	return *(--opnd.top);
}

char GetTop1(Stack1& optr)  //取栈顶
{
	return *(optr.top - 1);
}
double GetTop2(Stack2& opnd)
{
	return *(opnd.top - 1);
}

bool isNum(char c)  //判断是否为数字
{
	if (c >= 48 && c <= 57)
		return true;
	else
		return false;
}

char Precede(char a, char b)  //优先级比较
{
	if (a == '+' || a == '-')
	{
		if (b == '+' || b == '-' || b == ')'|| b == '#')
			return'>';
		if (b == '*' || b == '/' || b == '(' || b == '%' || b == '^')
			return'<';
	}
	if (a == '*' || a == '/'||a=='%')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == '%' || b == ')' || b == '#')
			return'>';
		if (b == '(' ||  b == '^')
			return'<';
	}
	if (a == '^'||a==')')
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

double Operate(double a, char theta, double b)  //单次运算
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
	InitStack1(optr);
	Push1(optr, '#');

	InitStack2(opnd);
	char c;
	cout << "请输入个位数表达式并以#结束：";
	c = getchar();

	double a = 0, b = 0;
	char x = NULL, theta = NULL;

	while (c != '#' || GetTop1(optr) != '#')
	{
		if (isNum(c))
		{
			Push2(opnd, c);
			c = getchar();
		}
		else
		{
			switch (Precede(GetTop1(optr), c))
			{
			case'<':
				Push1(optr, c);
				c = getchar();
				break;
			case'=':
				Pop1(optr);
				c = getchar();
				break;
			case'>':
				theta = Pop1(optr);
				b = Pop2(opnd);
				a = Pop2(opnd);
				Push2(opnd, Operate(a, theta, b));
				break;
			}
		}
	}
	cout << "结果为" << GetTop2(opnd) << endl;
	return 0;
}