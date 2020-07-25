typedef int ElementType;

typedef struct Node{
	ElementType element;
	struct Node *next;
}Node, *LinkList;

LinkList InitLinkList();
