#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

LinkList InitLinkList()
{
	LinkList linklist = (LinkList)malloc(sizeof(Node));
	linklist->element = 0;
	linklist->next = NULL;
	
	return linklist;
}

int main()
{
	LinkList linklist = InitLinkList();
	printf("%d",linklist->element);
	return 0;
}
