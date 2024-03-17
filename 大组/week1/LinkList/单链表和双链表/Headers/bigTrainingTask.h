#pragma once
typedef struct singleNode {
	char data;
	struct singleNode* next;
}singleNode;       //单链表结构
typedef struct doubleNode {
	char data;
	struct doubleNode* next;
	struct doubleNode* previous;
}doubleNode;       //双链表结构
void displayMenu(char menu[][27], int size);        //用于打印菜单的函数,size用于确定打印几行
singleNode* singleNodeGeneration();                 //用于构建单链表的函数
singleNode* singleNodeDestroy();					//用于销毁单链表的函数
int nodeDisplay(int flag);							//用于打印链表内容的函数,flag用于决定打印单链表或双链表,返回节点个数
singleNode* singleNodeInsert();						//用于插入结点的函数,可选择中间插入,尾部插入,头部插入
singleNode* singleNodeDelete();						//用于删除单链表某节点
singleNode* singleNodeSearch();						//用于单链表查找是否存在某数据的函数
singleNode* parityExchange();						//用于奇偶节点对换的函数
singleNode* middleSearch();							//用于找寻中间节点,且打印中间节点往后的函数
void circleJudge();                                 //用于判断是否为循环链表的函数,内有尾连头供测试(测试完会解除连接)
singleNode* singleNodeReversal();                   //用于单链表反转(非递归)
singleNode* singleNodeReversalRecursion(singleNode* Head); //用于单链表反转(递归)
void singleLinkedList();                            //用于单链表菜单操作函数
doubleNode* doubleNodeGeneration();                 //用于双向链表构建函数
doubleNode* doubleNodeDestroy();                    //用于双向链表销毁
doubleNode* doubleNodeInsert();						//用于双向链表插入
doubleNode* doubleNodeDelete();						//用于双向链表节点删除
doubleNode* doubleNodeSearch();						//用于双向链表的节点查询
void doubleLinkedList();							//用于双向链表菜单操作函数