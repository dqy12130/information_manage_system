#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;
typedef  struct DLNode//双向循环链表结点类型
{
	ElemType data;
	DLNode *prior;
	DLNode *next;
}DLNode, *DCLinkList;

void DCCreateList(DCLinkList &);//创建
void DCInsertList(DCLinkList &, int);//插入
void DCTraver(DCLinkList);//遍历
void DCdeleteList(DCLinkList &, int);//删除指定位置的元素
int  DCDestroy(DCLinkList &);//销毁双向循环链表


void DCCreateList(DCLinkList &DL)//创建双向循环链表结点
{
	//DCLinkList DL;
	DL = new DLNode;
	DL->data = -1;
	DL->next = DL;
	DL->prior = DL;
}


void DCInsertList(DCLinkList &DL, int n)
{
	DCLinkList p = DL;//操作指针 
	if (DL)
	{
		int i = 0;
		while (i <=n)//尾插法
		{
			DCLinkList s;
			s = new DLNode;
			s->data = i + 1;
			s->prior = p;
			p->next = s;
			s->next = NULL;
			DL->prior = s;//头结点前驱始终指向末尾结点
			p = s;//结点移动，使之使用指向为链表的尾部
			i++;//趋于结束
		}
		p->next = DL;//末尾结点后继指向头结点
		//cout << "测试:  " << p->next->data << endl;
	}
}

void DCTraver(DCLinkList DL)
{
	DCLinkList p = DL;
	while (p->next!=DL)//遍历终止条件
	{
		cout << p->data << endl;
		p = p->next;
	}
}

void DCdeleteList(DCLinkList &DL, int n)
{
	DCLinkList p = DL->next;
	if (p==NULL)
	{
		cout << "双向循环链表为空，删除无效" << endl;
	}
	else 
	{
		for (int i = 0; i < n - 1; i++)
		{
			p = p->next;
		}
		DCLinkList s;
		s = p;//保存要删除结点的地址
		p->next->prior = p->prior;//下一个结点的前驱指向要删除结点的前驱
		p->prior->next = p->next;//当前结点的后继指向要删除结点的后继
		p = p->next;//结点移动，保证链表的完整性
		delete s;//删除结点
	}
}

int  DCDestroy(DCLinkList &DL)
{

	delete DL;//销毁双向循环链表
	if (DL)
	{
		return 1;
	}
	else
		return 0;
}

void main()
{
	DCLinkList head;
	DCCreateList(head);//初始化双向循环链表
	DCInsertList(head, 10);
	DCTraver(head);
	DCdeleteList(head, 5);
	DCTraver(head);
	cout << DCDestroy(head);
	system("pause");
}