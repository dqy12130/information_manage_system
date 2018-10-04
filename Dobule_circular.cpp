#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;
typedef  struct DLNode//双向链表结点类型
{
	ElemType data;
	DLNode *prior;
	DLNode *next;
}DLNode,*DLinkList;

void DCreateList(DLinkList &);//创建
void DInsertList(DLinkList &, int);//插入
void DTraver(DLinkList);//遍历
void DdeleteList(DLinkList &,int);//删除指定位置的元素
int  Destroy(DLinkList &);//销毁双向链表


void DCreateList(DLinkList &DL)//创建双向链表结点
{ 
	//DLinkList DL;
	DL = new DLNode;
	DL->data = -1;
	DL->next = NULL;
	DL->prior = NULL;
}

void DInsertList(DLinkList &DL,int n)
{
	DLinkList p = DL;//操作指针 
	if (DL)
	{
		int i = 0;
		while (i < n)//尾插法
		{
			DLinkList s;
			s = new DLNode;
			s->data = i+1 ;
			s->prior = p;
			p->next = s;
			s->next = NULL;
			p = s;//结点移动，使之使用指向为链表的尾部
			i++;//趋于结束
		}
	}
}

void DTraver(DLinkList DL)
{
	DLinkList p=DL;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}	
}

void DdeleteList(DLinkList &DL,int n)
{
	DLinkList p = DL->next;
	if (p==NULL)
	{
		cout << "双向链表为空，删除无效" << endl;
	}
	else
	{
		for (int i = 0; i < n-1; i++)
		{
			p = p->next;
		}
		DLinkList s;
		s = p;//保存要删除结点的地址
		p->next->prior = p->prior;//下一个结点的前驱指向要删除结点的前驱
		p->prior->next = p->next;//当前结点的后继指向要删除结点的后继
		p = p->next;//结点移动，保证链表的完整性
		delete s;//删除结点
	}
}

int  Destroy(DLinkList &DL)
{

	delete DL;//销毁双向链表
	if (DL)
	{
		return 1;
	}
	else 
	    return 0;
	

}

void DLink()
{   
	DLinkList head;
	DCreateList(head);//初始化双向链表
	DInsertList(head, 10);
	DTraver(head);
	DdeleteList(head, 5);
	cout << Destroy(head);
	system("pause");
}