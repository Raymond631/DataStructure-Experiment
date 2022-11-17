#include <iostream>
using namespace std;

struct Polynomial   //����ʽ
{
	double coefficient;   //ϵ��
	int index;   //ָ��
	bool isEmpty = false;   //�ж��Ƿ�Ϊ��
};

void CreatPoly(Polynomial* p, int n)   //�������ʽ
{
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].coefficient;
		cin >> p[i].index;
		p[i].isEmpty = true;
	}
}

void PrintPoly(Polynomial* p)   //�������ʽ
{
	int i = 0;
	while (p[i].isEmpty)
	{
		cout << p[i].coefficient << " " << p[i].index << endl;
		i++;
	}
}

void AddPoly(Polynomial* p, Polynomial* q, Polynomial* r, int n, int m)   //����ʽ���
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

	cout << "�������һ������ʽ��������";
	int n1;
	cin >> n1;
	cout << "���������ĵ�һ������ʽ���밴����˳�����룬��ϵ������ָ������" << endl;
	CreatPoly(poly_1, n1);


	cout << "������ڶ�������ʽ��������";
	int n2;
	cin >> n2;
	cout << "���������ĵڶ�������ʽ���밴����˳�����룬��ϵ������ָ������" << endl;
	CreatPoly(poly_2, n2);

	AddPoly(poly_1, poly_2, poly_3, n1, n2);
	cout << "�ϲ���Ķ���ʽΪ��" << endl;
	PrintPoly(poly_3);

	return 0;
}