#pragma once
typedef struct Node {
	int data;
	struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree{
	NodePtr root;
} BinarySortTree, * BinarySortTreePtr;
typedef enum Status
{
	FAILURE = 0,
	SUCCESS = 1
} Status;
Status BST_init(BinarySortTreePtr);
Status BST_insert(BinarySortTreePtr, int);
Status BST_delete(BinarySortTreePtr, int);
Status BST_search(BinarySortTreePtr, int);
Status BST_preorderI(NodePtr);
Status BST_preorderR(NodePtr);
Status BST_inorderI(NodePtr);
Status BST_inorderR(NodePtr);
Status BST_postorderI(NodePtr);
Status BST_postorderR(NodePtr);
Status BST_levelOrder(NodePtr);
typedef  struct StackNode
{
	NodePtr moveptr;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;
}LinkStack;
typedef struct QNode {
	NodePtr moveptr;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr   head;
	QueuePtr   tail;
}LinkQueue;
void displayMenu(char menu[][100],int size);//打印菜单
Status initStack(LinkStack* s);//初始化
Status pushStack(LinkStack* s, NodePtr moveptr);//压栈
Status popStack(LinkStack* s);//出栈
Status initLQueue(LinkQueue* s);//初始化
Status EnLQueue(LinkQueue* s, NodePtr);//入队
Status DeLQueue(LinkQueue* s);//出队