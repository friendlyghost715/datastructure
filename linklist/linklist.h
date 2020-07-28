#define ERROR -1;
#define SUCCESS 1;

typedef int Status;


typedef int ElementType;

typedef struct Node{
	ElementType data;
	struct Node *next;
}Node, *LinkList;

LinkList InitLinkList();

Status InsertLinkList(LinkList linklist, ElementType data, int pos);

Status DelLinkList(LinkList linklist, int pos);

void TranverseLinkList(LinkList linklist);

int LocateLinkList(LinkList linklist, ElementType data);
