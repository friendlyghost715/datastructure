#define ERROR -1;
#define SUCCESS 1;

typedef int Status;

typedef int ElementType;

typedef struct Node{
	ElementType data;
	struct Node *next;
}Node;

typedef struct{
	int size;
	Node *head;
	Node *tail;
}LinkList;

// 分配结点，并返回指针 
Node* MakeNode(ElementType e);
// 初始化带头节点的单链表
LinkList InitLinkList();
// 销毁链表
Status DestroyLinkList(LinkList *linklist);
// 清空链表
Status CleanLinkList(LinkList *linklist);
// 创建一个长度为n的链表，命令行输入元素
LinkList CreateLinkList(int n);
// 在链表的第pos个位置上插入data元素
Status InsertLinkList(LinkList *linklist, ElementType data, int pos);
// 删除链表的第pos个位置上的元素
Status DelLinkList(LinkList *linklist, int pos);
// 遍历链表
void TranverseLinkList(LinkList linklist);
// 返回数据元素data在链表中的位置
int LocateLinkList(LinkList linklist, ElementType data);
// 返回链表的第pos个位置上的元素
ElementType GetEleLinkList(LinkList linklist, int pos);
// 设置链表的第pos个位置上的元素为data
Status SetEleLinkList(LinkList *linklist,ElementType data, int pos);
// 获取指向第pos个元素的指针
Node* LocatePos(LinkList *linklist,int pos);
// 将b链表追加到a链表的尾部
void Append(LinkList *a, LinkList *b);
