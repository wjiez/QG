#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include"bigTrainingTask4.h"
int cacheClean;                                     //��������������ĳн�����
int operationNum = 0;                               //������Ŵ��
char Menu[9][100] = {                                                                //�����˵�������
	"1.��ʼ��������",
	"2.��������",
	"3.��������",
	"4.ɾ������",
	"5.�������(�ݹ�)",
	"6.�������(�ǵݹ�)",
	"7.�������",
	"8.��������",
	"(������������)"
};
int main() {
	int flag = 0, num = 0, judge = 0;//flag�����ж϶������Ƿ��ʼ��,num�������ݳн�,judge�ж��Ƿ��ȡ������
	srand((unsigned)time(NULL));
	BinarySortTree test;
	while (1) {
		system("cls");
		displayMenu(Menu, 9);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //��ȡ�س��������������
		switch (operationNum)
		{
		case 1:
			if (flag == 0) {
				BST_init(&test);
				printf("��ʼ���ɹ�!!\n");
				flag = 1;
			}
			else
				printf("�ѳ�ʼ����\n");
			Sleep(800);
			break;
		case 2:
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else {
				printf("�������������:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_insert(&test, num);
				else
					printf("������������,����!!!\n");
			}
			Sleep(800);
			break;
		case 3:
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else if (test.root == NULL)
				printf("������Ϊ��\n");
			else {
				printf("�������ѯ����:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_search(&test, num);
				else
					printf("������������,����!!!\n");
			}
			Sleep(800);
			break;
		case 4:
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else if (test.root == NULL)
				printf("������Ϊ��\n");
			else {
				printf("������ɾ������:\n");
				judge = scanf("%d", &num);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (judge != 0)
					BST_delete(&test, num);
				else
					printf("������������,����!!!\n");
			}
			Sleep(800);
			break;
		case 5:
			system("cls");
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else if (test.root == NULL)
				printf("������Ϊ��!!!\n");
			else {
				printf("�������:\n");
				BST_preorderR(test.root);
				printf("\n�������:\n");
				BST_inorderR(test.root);
				printf("\n�������:\n");
				BST_postorderR(test.root);
			}
			printf("\n�س����ز˵�\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 6:
			system("cls");
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else if (test.root == NULL)
				printf("������Ϊ��!!!\n");
			else {
				printf("�������:\n");
				BST_preorderI(test.root);
				printf("\n�������:\n");
				BST_inorderI(test.root);
				printf("\n�������:\n");
				BST_postorderI(test.root);
			}
			printf("\n�س����ز˵�\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 7:
			system("cls");
			if (flag == 0)
				printf("���ȳ�ʼ��\n");
			else if (test.root == NULL)
				printf("������Ϊ��!!!\n");
			else {
				printf("�������:\n");
				BST_levelOrder(test.root);
			}
			printf("\n�س����ز˵�\n");
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
				printf("����ɹ�\n");
				break;
			}
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				moveptr->right = nodeptr;
				printf("����ɹ�\n");
				break;
			}
			moveptr = moveptr->right;
		}
		else {
			printf("���д�Ԫ��,����ʧ��!!\n");
			free(nodeptr);
			break;
		}
	}
	return SUCCESS;
}
Status BST_delete(BinarySortTreePtr P, int data) {
	NodePtr moveptr = P->root, preptr = NULL, deptr = P->root;//moveptr��ѰҪɾ���ڵ�,preptr��¼��һ���ڵ�,deptrΪɾ���ڵ�
	while (1) {
		if (moveptr->data > data) {//��ڵ�ȽϾ����ҽڵ㻹����ڵ�
			if (moveptr->left == NULL) {
				printf("û�д�����\n");
				break;
			}
			preptr = moveptr;
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				printf("û�д�����\n");
				break;
			}
			preptr = moveptr;
			moveptr = moveptr->right;
		}
		else {//�ҵ���Ҫɾ���ڵ�
			deptr = moveptr;
			if (deptr->left == NULL || deptr->right == NULL) {    //ֻ��һ����ڵ����û�к�ڵ�
				if (preptr == NULL) {          //���Ϊɾ���ڵ�Ϊ���ڵ�
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
			else {                          //��������ڵ�
				NodePtr preinheritptr = NULL;  //��̽ڵ��ǰһ�����
				moveptr = moveptr->right;
				while (1) {                  //�Һ�̽ڵ�
					if (moveptr->left == NULL)
						break;
					preinheritptr = moveptr;
					moveptr = moveptr->left;
				}
				if (preptr == NULL)           //���ɾ���ڵ�Ϊ���ڵ�
					P->root = moveptr;
				else {//ɾ���ڵ㲻Ϊ���ڵ�
					if (preptr->left != NULL && preptr->left == deptr)
						preptr->left = moveptr;
					else
						preptr->right = moveptr;
				}
				moveptr->left = deptr->left;
				if (preinheritptr != NULL) {//�����̽ڵ㲻Ϊɾ���ڵ��ҽڵ��һ��
					preinheritptr->left = moveptr->right;
					moveptr->right = deptr->right;
				}
			}
			free(deptr);
			printf("ɾ���ɹ�!!!!\n");
			break;
		}
	}
	return SUCCESS;
}
Status BST_search(BinarySortTreePtr P, int data) {
	NodePtr moveptr = P->root;
	while (1) {
		if (moveptr->data > data) {//���ҶԱ�
			if (moveptr->left == NULL) {
				printf("û�д�����\n");
				break;
			}
			moveptr = moveptr->left;
		}
		else if (moveptr->data < data) {
			if (moveptr->right == NULL) {
				printf("û�д�����\n");
				break;
			}
			moveptr = moveptr->right;
		}
		else {
			printf("���ڴ�����\n");
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
		if (judgeptr == NULL) {            //Ϊ�������
			printf("%d\t", Top.top->moveptr->data);
			judgeptr = Top.top->moveptr->right;
			popStack(&Top.top);
		}
		else {                  //��Ϊ����ѹջ
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
			moveptr = moveptr->left;         //����ָ
		}
		else {
			moveptr = Top.top->moveptr;           
			if (moveptr->right != NULL && moveptr->right != judgeptr) {         //����ָ
				moveptr = moveptr->right;
				pushStack(&Top.top, moveptr);
				moveptr = moveptr->left;
			}
			else {
				printf("%d\t", Top.top->moveptr->data);            
				popStack(&Top.top);
				judgeptr = moveptr;
				moveptr = NULL;     //����
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
Status BST_levelOrder(NodePtr P) {//�������
	LinkQueue Top;
	NodePtr temp = NULL, moveptr = P;  //�ݴ�ָ��,�ƶ�����ָ��
	initLQueue(&Top);
	EnLQueue(&Top, P);
	while (1) {
		if (Top.head == NULL)
			break;
		printf("%d\t", Top.head->moveptr->data);  //���
		temp = Top.head->moveptr;                  
		if (temp->left != NULL)                  //��������
			EnLQueue(&Top,temp->left);
		if (temp->right != NULL)                  //�����Һ���
			EnLQueue(&Top, temp->right);
		DeLQueue(&Top);                          //����
	}
	return SUCCESS;
}
Status initStack(LinkStack* s) {//��ʼ��
	s->top = NULL;
	return SUCCESS;
}
Status popStack(LinkStack* s) {//��ջ
	LinkStackPtr p1 = s->top;
	s->top = p1->next;
	free(p1);
	return SUCCESS;
}
Status pushStack(LinkStack* s, NodePtr moveptr) {//��ջ
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->moveptr = moveptr;
	return SUCCESS;
}
Status initLQueue(LinkQueue* s) {//��ʼ��
	s->head = NULL;
	s->tail = NULL;
	return SUCCESS;
}
Status DeLQueue(LinkQueue* s) {//����
	if (s->head == s->tail)
		s->tail = NULL;
	QueuePtr p1 = s->head;
	s->head = p1->next;
	free(p1);
	return SUCCESS;
}
Status EnLQueue(LinkQueue* s, NodePtr moveptr) {//���
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
void displayMenu(char menu[][100]) {//��ӡ�˵�
	for (int i = 0; i < 9; i++) {
		printf("%s\n", menu[i]);
	}
}