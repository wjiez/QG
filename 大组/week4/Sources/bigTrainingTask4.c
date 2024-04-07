#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include"bigTrainingTask4.h"
int cacheClean;                                     //用于清除缓存区的承接数据
int operationNum = 0;                               //操作序号存放
char Menu[9][100] = {                                                                //各个菜单的内容
	"1.初始化二叉树",
	"2.插入数据",
	"3.查找数据",
	"4.删除数据",
	"5.三序遍历(递归)",
	"6.三序遍历(非递归)",
	"7.层序遍历",
	"8.结束程序",
	"(请输入操作序号)"
};
int main() {
	int flag = 0, num = 0, judge = 0;//flag用于判断二叉树是否初始化,num用于数据承接,judge判断是否读取到数据
	srand((unsigned)time(NULL));
	BinarySortTree test;
	while (1) {
		system("cls");
		displayMenu(Menu, 9);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
		switch (operationNum)
		{
		case 1:
			if (flag == 0) {
				BST_init(&test);
				printf("初始化成功!!\n");
				flag = 1;
			}
			else
				printf("已初始化过\n");
			Sleep(800);
			break;
		case 2:
			if (flag == 0)
				printf("请先初始化\n");
			else {
				printf("请输入插入数据:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_insert(&test, num);
				else
					printf("输入数据有误,请检查!!!\n");
			}
			Sleep(800);
			break;
		case 3:
			if (flag == 0)
				printf("请先初始化\n");
			else if (test.root == NULL)
				printf("二叉树为空\n");
			else {
				printf("请输入查询数据:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_search(&test, num);
				else
					printf("输入数据有误,请检查!!!\n");
			}
			Sleep(800);
			break;
		case 4:
			if (flag == 0)
				printf("请先初始化\n");
			else if (test.root == NULL)
				printf("二叉树为空\n");
			else {
				printf("请输入删除数据:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_delete(&test, num);
				else
					printf("输入数据有误,请检查!!!\n");
			}
			Sleep(800);
			break;
		case 5:
			system("cls");
			if (flag == 0)
				printf("请先初始化\n");
			else if (test.root == NULL)
				printf("二叉树为空!!!\n");
			else {
				printf("先序遍历:\n");
				BST_preorderR(test.root);
				printf("\n中序遍历:\n");
				BST_inorderR(test.root);
				printf("\n后序遍历:\n");
				BST_postorderR(test.root);
			}
			printf("\n回车返回菜单\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 6:
			system("cls");
			if (flag == 0)
				printf("请先初始化\n");
			else if (test.root == NULL)
				printf("二叉树为空!!!\n");
			else {
				printf("先序遍历:\n");
				BST_preorderI(test.root);
				printf("\n中序遍历:\n");
				BST_inorderI(test.root);
				printf("\n后序遍历:\n");
				BST_postorderI(test.root);
			}
			printf("\n回车返回菜单\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 7:
			system("cls");
			if (flag == 0)
				printf("请先初始化\n");
			else if (test.root == NULL)
				printf("二叉树为空!!!\n");
			else {
				printf("层序遍历:\n");
				BST_levelOrder(test.root);
			}
			printf("\n回车返回菜单\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 8:
			system("pause");
			return 1;
			break;
		default:
			break;
		}
	}
}
Status BST_init(BinarySortTreePtr P) {
	P->root = NULL;
	return SUCCESS;
}
Status BST_insert(BinarySortTreePtr P, int data) {
	if (P->root == NULL) {
		NodePtr nodeptr = (NodePtr)malloc(sizeof(Node));
		P->root = nodeptr;
		P->root->data = data;
		P->root->left = NULL;
		P->root->right = NULL;
		return SUCCESS;
	}
	NodePtr nodeptr = (NodePtr)malloc(sizeof(Node));
	nodeptr->data = data;
	nodeptr->left = NULL;
	nodeptr->right = NULL;
	NodePtr moveptr = P->root;
	while (1) {
		if (moveptr->data > data) {
			if (moveptr->left == NULL) {
				moveptr->left = nodeptr;
				printf("插入成功\n");
				break;
			}
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				moveptr->right = nodeptr;
				printf("插入成功\n");
				break;
			}
			moveptr = moveptr->right;
		}
		else {
			printf("已有此元素,插入失败!!\n");
			free(nodeptr);
			break;
		}
	}
	return SUCCESS;
}
Status BST_delete(BinarySortTreePtr P, int data) {
	NodePtr moveptr = P->root, preptr = NULL, deptr = P->root;//moveptr找寻要删除节点,preptr记录上一个节点,deptr为删除节点
	while (1) {
		if (moveptr->data > data) {//与节点比较决定右节点还是左节点
			if (moveptr->left == NULL) {
				printf("没有此数据\n");
				break;
			}
			preptr = moveptr;
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				printf("没有此数据\n");
				break;
			}
			preptr = moveptr;
			moveptr = moveptr->right;
		}
		else {//找到了要删除节点
			deptr = moveptr;
			if (deptr->left == NULL || deptr->right == NULL) {    //只有一个后节点或则没有后节点
				if (preptr == NULL) {          //如果为删除节点为根节点
					if (deptr->left == NULL)
						P->root = deptr->right;
					else
						P->root = deptr->left;
				}
				else if (deptr->left == NULL) {
					if (preptr->left != NULL && preptr->left->data == data)
						preptr->left = deptr->right;
					else
						preptr->right = deptr->right;
				}
				else {
					if (preptr->left != NULL && preptr->left->data == data)
						preptr->left = deptr->left;
					else
						preptr->right = deptr->left;
				}
			}
			else {                          //有两个后节点
				NodePtr preinheritptr = NULL;  //后继节点的前一个结点
				moveptr = moveptr->right;
				while (1) {                  //找后继节点
					if (moveptr->left == NULL)
						break;
					preinheritptr = moveptr;
					moveptr = moveptr->left;
				}
				if (preptr == NULL)           //如果删除节点为根节点
					P->root = moveptr;
				else {//删除节点不为根节点
					if (preptr->left != NULL && preptr->left == deptr)
						preptr->left = moveptr;
					else
						preptr->right = moveptr;
				}
				moveptr->left = deptr->left;
				if (preinheritptr != NULL) {//如果后继节点不为删除节点右节点第一个
					preinheritptr->left = moveptr->right;
					moveptr->right = deptr->right;
				}
			}
			free(deptr);
			printf("删除成功!!!!\n");
			break;
		}
	}
	return SUCCESS;
}
Status BST_search(BinarySortTreePtr P, int data) {
	NodePtr moveptr = P->root;
	while (1) {
		if (moveptr->data > data) {//左右对比
			if (moveptr->left == NULL) {
				printf("没有此数据\n");
				break;
			}
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				printf("没有此数据\n");
				break;
			}
			moveptr = moveptr->right;
		}
		else {
			printf("存在此数据\n");
			break;
		}
	}
	return SUCCESS;
}
Status BST_preorderI(NodePtr P) {
	LinkStack Top;
	NodePtr temp = NULL;
	initStack(&Top);
	pushStack(&Top, P);
	while (1) {
		if (Top.top == NULL)
			break;
		printf("%d\t", Top.top->moveptr->data);
		temp = Top.top->moveptr;
		popStack(&Top.top);
		if (temp->right != NULL)
			pushStack(&Top.top, temp->right);
		if (temp->left != NULL)
			pushStack(&Top.top, temp->left);
	}
	return SUCCESS;
}
Status BST_preorderR(NodePtr P) {
	if (P == NULL)return SUCCESS;
	printf("%d\t", P->data);
	BST_preorderR(P->left);
	BST_preorderR(P->right);
}
Status BST_inorderI(NodePtr P) {
	LinkStack Top;
	NodePtr judgeptr = P;
	initStack(&Top);
	while (1) {
		if (judgeptr == NULL && Top.top == NULL)
			break;
		if (judgeptr == NULL) {            //为空则输出
			printf("%d\t", Top.top->moveptr->data);
			judgeptr = Top.top->moveptr->right;
			popStack(&Top.top);
		}
		else {                  //不为空则压栈
			pushStack(&Top.top, judgeptr);
			judgeptr = judgeptr->left;
		}
	}
	return SUCCESS;
}
Status BST_inorderR(NodePtr P) {
	if (P == NULL)
		return SUCCESS;
	BST_inorderR(P->left);
	printf("%d\t", P->data);
	BST_inorderR(P->right);
}
Status BST_postorderI(NodePtr P) {
	LinkStack Top;          
	NodePtr judgeptr = NULL, moveptr = P; 
	initStack(&Top);
	while (1) {
		if (moveptr == NULL && Top.top == NULL)        
			break;
		if (moveptr != NULL) {
			pushStack(&Top.top, moveptr);          
			moveptr = moveptr->left;         //向左指
		}
		else {
			moveptr = Top.top->moveptr;           
			if (moveptr->right != NULL && moveptr->right != judgeptr) {         //向右指
				moveptr = moveptr->right;
				pushStack(&Top.top, moveptr);
				moveptr = moveptr->left;
			}
			else {
				printf("%d\t", Top.top->moveptr->data);            
				popStack(&Top.top);
				judgeptr = moveptr;
				moveptr = NULL;     //重置
			}
		}
	}
	return SUCCESS;
}
Status BST_postorderR(NodePtr P) {
	if (P == NULL)
		return SUCCESS;
	BST_postorderR(P->left);
	BST_postorderR(P->right);
	printf("%d\t", P->data);
}
Status BST_levelOrder(NodePtr P) {//层序遍历
	LinkQueue Top;
	NodePtr temp = NULL, moveptr = P;  //暂存指针,移动遍历指针
	initLQueue(&Top);
	EnLQueue(&Top, P);
	while (1) {
		if (Top.head == NULL)
			break;
		printf("%d\t", Top.head->moveptr->data);  //输出
		temp = Top.head->moveptr;                  
		if (temp->left != NULL)                  //先入左孩子
			EnLQueue(&Top,temp->left);
		if (temp->right != NULL)                  //后入右孩子
			EnLQueue(&Top, temp->right);
		DeLQueue(&Top);                          //出队
	}
	return SUCCESS;
}
Status initStack(LinkStack* s) {//初始化
	s->top = NULL;
	return SUCCESS;
}
Status popStack(LinkStack* s) {//出栈
	LinkStackPtr p1 = s->top;
	s->top = p1->next;
	free(p1);
	return SUCCESS;
}
Status pushStack(LinkStack* s, NodePtr moveptr) {//入栈
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->moveptr = moveptr;
	return SUCCESS;
}
Status initLQueue(LinkQueue* s) {//初始化
	s->head = NULL;
	s->tail = NULL;
	return SUCCESS;
}
Status DeLQueue(LinkQueue* s) {//出队
	if (s->head == s->tail)
		s->tail = NULL;
	QueuePtr p1 = s->head;
	s->head = p1->next;
	free(p1);
	return SUCCESS;
}
Status EnLQueue(LinkQueue* s, NodePtr moveptr) {//入队
	QueuePtr p1 = (QueuePtr)malloc(sizeof(QNode));
	if (s->tail != NULL) {
		s->tail->next = p1;
	}
	else {
		s->head = p1;
	}
	s->tail = p1;
	p1->next = NULL;
	p1->moveptr = moveptr;
	return SUCCESS;
}
void displayMenu(char menu[][100]) {//打印菜单
	for (int i = 0; i < 9; i++) {
		printf("%s\n", menu[i]);
	}
}