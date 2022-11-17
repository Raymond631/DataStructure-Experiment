#include<iostream>
using namespace std;

struct BiTNode  //��������ڵ�
{
	char data;
	struct BiTNode* lchild, * rchild;
};
void CreateBiTree(BiTNode*& T)  //������������
{
	char c = getchar();
	if (c == '#')
		T = NULL;
	else if(c=='/n')
	{
		return;  //����main()����
	}
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PrintElement(char e)  //�����е�Visit����
{
	cout << e;
}
bool PreOrderTraverse(BiTNode* T)  //����������ݹ飩
{
	if (T)
	{
		PrintElement(T->data);

		if (PreOrderTraverse(T->lchild))
		{
			if (PreOrderTraverse(T->rchild))
				return true;
		}
	}
	else
		return true;
}
bool InOrderTraverse(BiTNode* T)  //����������ݹ飩
{
	if (T)
	{
		if (InOrderTraverse(T->lchild))
		{
			PrintElement(T->data);
			if (InOrderTraverse(T->rchild))
				return true;
		}
	}
	else
		return true;
}
bool PostOrderTraverse(BiTNode* T)  //����������ݹ飩
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild))
		{
			if (PostOrderTraverse(T->rchild))
			{
				PrintElement(T->data);
				return true;
			}	
		}
	}
	else
		return true;
}

struct Stack  //�ڵ�ջ
{
	BiTNode* T;
	Stack* next;
};
Stack* InitStack()  //������ջ
{
	Stack* top;
	top = new Stack;
	top->next = NULL;
	top->T = NULL;
	return top;
}
void Push(BiTNode* e, Stack*& top, Stack*& p)  //��ջ
{
	top->T = e;
	p = top;
	top = new Stack;
	top->next = p;
	top->T = NULL;
}
BiTNode* Pop(Stack* top, Stack*& p)  //��ջ
{
	BiTNode* q = top->next->T;
	top->next = p->next;
	p = p->next;
	return q;
}

void visit(BiTNode* T, int& node, int& node0, int& node1, int& node2, char& maxnum, char& minnum)
{
	node++;
	if (T->lchild == NULL && T->rchild == NULL)
		node0++;
	if ((T->lchild == NULL || T->rchild == NULL) && !(T->lchild == NULL && T->rchild == NULL))
		node1++;
	if (T->lchild != NULL && T->rchild != NULL)
		node2++;

	if (node == 1)
		maxnum = T->data;
	if (node == 2 && maxnum >= T->data)
		minnum = T->data;
	if (node == 2 && maxnum < T->data)
	{
		minnum = maxnum;
		maxnum = T->data;
	}

	if (T->data < minnum)
		minnum = T->data;
	if (T->data > maxnum)
		maxnum = T->data;
}
void PreOrderTraverse(BiTNode* T,int a)  //����������ǵݹ飩
{
	Stack* top = InitStack();
	Stack* q;	//ָ��ջ��ָ������һ���ڵ�
	BiTNode* p = T;

	char maxnum = 0;	//���ڵ�ֵ
	char minnum = 0;	//��С�ڵ�ֵ
	int node = 0;	//�ڵ�����
	int node0 = 0;	//Ҷ�ӽڵ���
	int node1 = 0;	//��Ϊ1�Ľڵ���
	int node2 = 0;	//��Ϊ2�Ľڵ���

	while (p || top->next)
	{
		if (p)
		{
			Push(p, top, q);
			visit(p, node, node0, node1, node2, maxnum, minnum);
			p = p->lchild;
		}
		else
		{
			p = Pop(top, q);
			p = p->rchild;
		}
	}
	cout << "���ڵ�ֵ:" << maxnum << endl;
	cout << "��С�ڵ�ֵ:" << minnum << endl;
	cout << "�ڵ�����:" << node << endl;
	cout << "Ҷ�ӽڵ���:" << node0 << endl;
	cout << "��Ϊ1�Ľڵ���:" << node1 << endl;
	cout << "��Ϊ2�Ľڵ���:" << node2 << endl;
}

int main()
{
	cout << "�밴�������������������нڵ��ֵ,#��ʾ�������س���ʾ���������" << endl;
	BiTNode* head = NULL;
	CreateBiTree(head);

	cout << "����������Ϊ��";
	PreOrderTraverse(head);
	cout << endl;

	cout << "����������Ϊ��";
	InOrderTraverse(head);
	cout << endl;

	cout << "����������Ϊ��";
	PostOrderTraverse(head);
	cout << endl;

	PreOrderTraverse(head,1);  //�ǵݹ����

	return 0;
}