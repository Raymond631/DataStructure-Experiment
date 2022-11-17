#include <iostream>
using namespace std;

struct Polynomial   //多项式
{
	double coefficient;   //系数
	int index;   //指数
	bool isEmpty = false;   //判断是否为空
};

void CreatPoly(Polynomial* p, int n)   //输入多项式
{
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].coefficient;
		cin >> p[i].index;
		p[i].isEmpty = true;
	}
}

void PrintPoly(Polynomial* p)   //输出多项式
{
	int i = 0;
	while (p[i].isEmpty)
	{
		cout << p[i].coefficient << " " << p[i].index << endl;
		i++;
	}
}

void AddPoly(Polynomial* p, Polynomial* q, Polynomial* r, int n, int m)   //多项式相加
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (p[i].isEmpty && q[j].isEmpty)
	{
		if (p[i].index == q[j].index)
		{
			r[k].index = p[i].index;
			r[k].coefficient = p[i].coefficient + q[j].coefficient;
			r[k].isEmpty = true;
			i++;
			j++;
			k++;
		}
		if (p[i].index > q[j].index)
		{
			r[k].index = p[i].index;
			r[k].coefficient = p[i].coefficient;
			r[k].isEmpty = true;
			i++;
			k++;
		}
		if (p[i].index < q[j].index)
		{
			r[k].index = q[j].index;
			r[k].coefficient = q[j].coefficient;
			r[k].isEmpty = true;
			j++;
			k++;
		}
	}
	while (p[i].isEmpty)
	{
		r[k].index = p[i].index;
		r[k].coefficient = p[i].coefficient;
		r[k].isEmpty = true;
		i++;
		k++;
	}
	while (q[j].isEmpty)
	{
		r[k].index = q[j].index;
		r[k].coefficient = q[j].coefficient;
		r[k].isEmpty = true;
		j++;
		k++;
	}
}

int main()
{
	Polynomial poly_1[30], poly_2[30], poly_3[60];

	cout << "请输入第一个多项式的项数：";
	int n1;
	cin >> n1;
	cout << "请输入您的第一个多项式（请按降幂顺序输入，先系数，后指数）：" << endl;
	CreatPoly(poly_1, n1);


	cout << "请输入第二个多项式的项数：";
	int n2;
	cin >> n2;
	cout << "请输入您的第二个多项式（请按降幂顺序输入，先系数，后指数）：" << endl;
	CreatPoly(poly_2, n2);

	AddPoly(poly_1, poly_2, poly_3, n1, n2);
	cout << "合并后的多项式为：" << endl;
	PrintPoly(poly_3);

	return 0;
}