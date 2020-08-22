#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

LinkList InitLinkList()
{
	LinkList linklist;
	linklist.size = 0;
        linklist.head = (Node*)malloc(sizeof(Node));
	linklist.head->next = NULL;
	
	return linklist;
}

Status DestroyLinkList(LinkList *linklist)
{
	Node *p = (*linklist).head;
	Node *q;
	while(p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(linklist);
	return SUCCESS;
}

Status CleanLinkList(LinkList *linklist)
{
	Node *p = (*linklist).head->next;
	Node *q;
	while(p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;		
	}
	(*linklist).head->next = NULL;
	(*linklist).size = 0;
	return SUCCESS;	
}

LinkList CreateLinkList(int n)
{
	LinkList linklist;
	linklist.size = n;
        linklist.head = (Node*)malloc(sizeof(Node));
	linklist.head->next = NULL;
	
	Node *p = linklist.head;
	for(int i = 0; i < n; i++)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		scanf("%d",&node->data);
		node->next = p->next;
		p->next = node;
	}
	return linklist;
}

Status InsertLinkList(LinkList *linklist,ElementType data,int pos)
{
	Node *p = LocatePos(linklist,pos-1);
	if(!p)
	{
		return ERROR;
       	}
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = data;
	q->next = p->next;
	p->next = q;
	(*linklist).size++;
	return SUCCESS; 
}

Status DelLinkList(LinkList *linklist, int pos)
{
	Node *p = LocatePos(linklist,pos-1);
	if(!p)
	{
		return ERROR;
       	}
	Node *q = p->next;
	p->next = q->next;
	free(q);
	(*linklist).size--;
	return SUCCESS;
}

void TranverseLinkList(LinkList linklist)
{
	Node *p = linklist.head->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int LocateLinkList(LinkList linklist, ElementType data)
{
	Node *p = linklist.head->next;
	int j = 1;
	while(p && p->data != data)
	{
		p = p->next;
		j++;
	}
	if(!p)
		return 0;
	return j;
}

ElementType GetEleLinkList(LinkList linklist, int pos)
{
	Node *p = LocatePos(&linklist,pos);
	if(!p)
	{
		return NULL;
	}
	return p->data;
}

Status SetEleLinkList(LinkList *linklist,ElementType data, int pos)
{
	Node *p = LocatePos(linklist,pos);
	if(!p)
	{
		return ERROR;
	}
	p->data = data;
	return SUCCESS;
}

Node* LocatePos(LinkList *linklist,int pos)
{
	Node *p = (*linklist).head;
	int j = 0;
	while(p!=NULL && j<pos)
	{
		p = p->next;
		j++;
	}
	if(!p || j>pos)
	{
		return NULL;
	}
	return p;
}
	int main() 
	{
		LinkList linklist = CreateLinkList(4);
		TranverseLinkList(linklist);
		printf("\nsize=%d\n",linklist.size);
		InsertLinkList(&linklist,33,3);
		printf("第二个元素为：%d\n",GetEleLinkList(linklist,2));
		TranverseLinkList(linklist);
		printf("\nsize=%d\n",linklist.size);
		DelLinkList(&linklist,2);
		TranverseLinkList(linklist);
		printf("\nsize=%d\n",linklist.size);
		SetEleLinkList(&linklist,99,1);
		SetEleLinkList(&linklist,99,4);
		TranverseLinkList(linklist);
		printf("\nsize=%d\n",linklist.size);
		CleanLinkList(&linklist);
		TranverseLinkList(linklist);
		printf("\nsize=%d\n",linklist.size);
		Node *p = LocatePos(&linklist,0);
		printf("%d",p);	
	
		return 0;
	}
