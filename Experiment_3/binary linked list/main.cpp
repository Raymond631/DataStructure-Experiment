#include<iostream>
using namespace std;

struct BiTNode  //二叉链表节点
{
	char data;
	struct BiTNode* lchild, * rchild;
};
void CreateBiTree(BiTNode*& T)  //创建二叉链表
{
	char c = getchar();
	if (c == '#')
		T = NULL;
	else if(c=='/n')
	{
		return;  //返回main()函数
	}
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PrintElement(char e)  //遍历中的Visit函数
{
	cout << e;
}
bool PreOrderTraverse(BiTNode* T)  //先序遍历（递归）
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
bool InOrderTraverse(BiTNode* T)  //中序遍历（递归）
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
bool PostOrderTraverse(BiTNode* T)  //后序遍历（递归）
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

struct Stack  //节点栈
{
	BiTNode* T;
	Stack* next;
};
Stack* InitStack()  //创建空栈
{
	Stack* top;
	top = new Stack;
	top->next = NULL;
	top->T = NULL;
	return top;
}
void Push(BiTNode* e, Stack*& top, Stack*& p)  //入栈
{
	top->T = e;
	p = top;
	top = new Stack;
	top->next = p;
	top->T = NULL;
}
BiTNode* Pop(Stack* top, Stack*& p)  //出栈
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
void PreOrderTraverse(BiTNode* T,int a)  //先序遍历（非递归）
{
	Stack* top = InitStack();
	Stack* q;	//指向栈顶指针下面一个节点
	BiTNode* p = T;

	char maxnum = 0;	//最大节点值
	char minnum = 0;	//最小节点值
	int node = 0;	//节点总数
	int node0 = 0;	//叶子节点数
	int node1 = 0;	//度为1的节点数
	int node2 = 0;	//度为2的节点数

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
	cout << "最大节点值:" << maxnum << endl;
	cout << "最小节点值:" << minnum << endl;
	cout << "节点总数:" << node << endl;
	cout << "叶子节点数:" << node0 << endl;
	cout << "度为1的节点数:" << node1 << endl;
	cout << "度为2的节点数:" << node2 << endl;
}

int main()
{
	cout << "请按照先序次序输入二叉树中节点的值,#表示空树，回车表示输入结束：" << endl;
	BiTNode* head = NULL;
	CreateBiTree(head);

	cout << "先序遍历结果为：";
	PreOrderTraverse(head);
	cout << endl;

	cout << "中序遍历结果为：";
	InOrderTraverse(head);
	cout << endl;

	cout << "后序遍历结果为：";
	PostOrderTraverse(head);
	cout << endl;

	PreOrderTraverse(head,1);  //非递归遍历

	return 0;
}