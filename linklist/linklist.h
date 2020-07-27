#define ERROR -1;
#define SUCCESS 1;

typedef int STATUS;


typedef int ElementType;

typedef struct Node{
	ElementType data;
	struct Node *next;
}Node, *LinkList;

LinkList InitLinkList();

ElementType InsertLinkList(LinkList linklist, ElementType data, int pos);
