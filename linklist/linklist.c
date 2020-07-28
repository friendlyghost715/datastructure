#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

LinkList InitLinkList()
{
	LinkList linklist = (LinkList)malloc(sizeof(Node));
	linklist->data = 0;
	linklist->next = NULL;
	
	return linklist;
}

Status InsertLinkList(LinkList linklist,ElementType data, int pos)
{
	LinkList p = linklist;
	int j = 0;
	while(p && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j>pos-1)
	{
		return ERROR;	
	}
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = data;
	q->next = p->next;
	p->next = q;
	return SUCCESS; 
}

LinkList CreateLinkList(int n)
{
	LinkList linklist = (LinkList)malloc(sizeof(Node));
	linklist->next = NULL;
	for(int i = 0; i < n; i++)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		scanf("%d",&node->data);
		node->next = linklist->next;
		linklist->next = node;
	}
	return linklist;
}

Status DelLinkList(LinkList linklist, int pos)
{
	Node *p = linklist;
	int j = 0;
	while(p && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if(!p || j>pos-1)
	{
		return ERROR;
	}
	Node *q = p->next;
	p->next = q->next;
	free(q);
	return SUCCESS;
}

void TranverseLinkList(LinkList linklist)
{
	Node *p = linklist->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
}

int LocateLinkList(LinkList linklist, ElementType data)
{
	Node *p = linklist->next;
	int j = 1;
	while(p && p->data != data)
	{
		p = p->next;
		j++;
	}
	if(!p)
		return -1;
	return j;
}
	int main() 
	{
		LinkList linklist = CreateLinkList(4);
		TranverseLinkList(linklist);
		// DelLinkList(linklist,3);
		// TranverseLinkList(linklist);
		int pos = LocateLinkList(linklist, 3);
		printf("%d", pos);
		return 0;
	}
