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

STATUS InsertLinkList(LinkList linklist,ElementType data, int pos)
{
	LinkList p = linklist;
	int j = 0;
	while(p!=NULL && j<pos-1)
	{
		p = p->next;
		j++;
	}
	if(p==NULL || j>pos-1)
	{
		return ERROR;	
	}
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = data;
	q->next = p->next;
	p->next = q;
	return SUCCESS; 
} 
	
	int main() 
	{
		LinkList linklist = InitLinkList(); 
		printf("%d",linklist->data); InsertLinkList(linklist,8,1);
		printf("%d",linklist->next->data);
		return 0;
	}
