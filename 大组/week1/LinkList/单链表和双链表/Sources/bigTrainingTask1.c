#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"bigTrainingTask.h"
singleNode* singleHead = NULL;
doubleNode* doubleHead = NULL;                      //������˫����ֻ����һ������,����Ԥ�ȹ��������ͷ
int cacheClean;                                     //��������������ĳн�����
int operationNum = 0;                               //������Ŵ��
char Menu[4][27] = {                                                                //�����˵�������
	"1.������",
	"2.˫������",
	"3.��������",
	"(������������)"
};
char Menu1[13][27] = {
	"1.����������",
	"2.����������",
	"3.���ٵ�����",
	"4.�����½ڵ�",
	"5.ɾ��ĳ�ڵ�",
	"6.��ѯĳ����",
	"7.�ڵ���ż�Ի�",
	"8.���������м�ڵ�",
	"9.�ж������Ƿ�ɻ�",
	"10.��ת����(�ǵݹ�)",
	"11.��ת����(�ݹ�)",
	"12.������һ��",
	"(������������)"
};
char Menu2[8][27] = {
	"1.����˫������",
	"2.����˫������",
	"3.����˫������",
	"4.�����µĽڵ�",
	"5.ɾ��ĳ���ڵ�",
	"6.����ĳ������",
	"7.������һ��",
	"(������������)"
};
int main() {
	while (1) {
		system("cls");
		displayMenu(Menu, 4);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //��ȡ�س��������������
		switch (operationNum) {
		case 1:
			singleLinkedList();                                       //���뵥��������
			break;
		case 2:
			doubleLinkedList();
			break;
		case 3:
			return 1;
		default:
			printf("�������!!!����������!!!");
			Sleep(800);
		}
	}
}
void displayMenu(char menu[][27], int size) {
	for (int i = 0; i < size; i++) {
		printf("%s\n", menu[i]);
	}
}
singleNode* singleNodeGeneration() {                                              //����������
	system("cls");
	if (singleHead != NULL) {
		printf("�������Ѿ���������,���������ٴ���(���س�������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //��ȡ�س��������������
		return NULL;

	}
	printf("������һ���ַ�(����#���������):\n");                       //���ù���������־
	singleNode* p1 = singleHead, * p2;
	p2 = (singleNode*)malloc(sizeof(singleNode));
	singleHead = p2;
	p2->data = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                        //����getchar�м�Ļس��ᱻ��ȡ,�����ô�������
	while (p2->data != '#') {
		printf("������һ���ַ�(����#���������):\n");
		p1 = p2;
		p2 = (singleNode*)malloc(sizeof(singleNode));
		p1->next = p2;
		p2->data = getchar();
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                   //����getchar�м�Ļس��ᱻ��ȡ,�����ô�������
	}
	free(p2);                                                          //�ͷ����һ���ַ�Ϊ#�Ľڵ�
	if (p1 != NULL)                                                    //���һ��ʼ������#��ôp1=NULL,��headΪnull,Ϊ������
		p1->next = NULL;
	else
		singleHead = NULL;
	printf("�����ɹ�\n");
	Sleep(800);
	return singleHead;
}
singleNode* singleNodeDestroy() {                                               //���������
	system("cls");
	if (singleHead == NULL) {
		printf("����Ϊ��!!!");
		Sleep(800);
		return NULL;
	}
	singleNode* p1 = singleHead, * p2 = singleHead;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	singleHead = NULL;
	printf("���ٳɹ�!!");
	Sleep(800);
	return singleHead;
}
int nodeDisplay(int flag) {                                         //�����ڱ�����������˫����,����һ�����ֱ�ʾ�����ڽڵ����
	int local = 0;                                                   //��¼�������λ��
	if (flag == 0) {
		singleNode* p1 = singleHead;
		if (singleHead == NULL) {
			printf("����Ϊ��\n");
			return 0;
		}
		printf("���\t����\n");
		while (p1 != NULL) {
			printf("%d\t%c\n", ++local, p1->data);
			p1 = p1->next;
		}
	}
	if (flag == 1) {
		doubleNode* p1 = doubleHead;
		if (doubleHead == NULL) {
			printf("����Ϊ��\n");
			return 0;
		}
		printf("���\t����\n");
		while (p1 != NULL) {
			printf("%d\t%c\n", ++local, p1->data);
			p1 = p1->next;
		}
	}
	return local;                                                      //���ؽڵ����
}
singleNode* singleNodeInsert() {                                                 //�ڵ�Ĳ���
	system("cls");
	if (singleHead == NULL) {
		printf("������δ����!!!!���ȴ�������!!!!");
		Sleep(1100);
		return NULL;
	}
	while (1) {
		system("cls");
		printf("1.ͷ������\n2.�м����\n3.β������\n��������뷽ʽ:\n");
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                      //��ȡ�س��������������
		if (operationNum == 1) {                                          //ͷ������
			singleNode* p1 = (singleNode*)malloc(sizeof(singleNode));
			p1->next = singleHead;
			singleHead = p1;
			printf("����������һ���ַ�:\n");
			p1->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //��ȡ�س��������������
			break;
		}
		else if (operationNum == 2) {                                     //�м����   
			system("cls");
			if (singleHead->next == NULL) {
				printf("������ֻ��һ���ڵ���ѡ��ͷ���������β������\n");
				Sleep(1500);
				continue;
			}
			int maxNum = nodeDisplay(0);                                    //��¼�ڵ�����Ա��ڹ�������ֵԽ������
			int low = 0, high = 0;
			while (1) {
				printf("���С���������������ڵ����(�ո����):\n");
				scanf("%d %d", &low, &high);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (high - low == 1 && high <= maxNum && low >= 1) {          //����ó�������
					singleNode* p1 = (singleNode*)malloc(sizeof(singleNode));
					singleNode* p2 = singleHead;
					int num = 0;
					while (++num != low) {                                   //ָ���Ƶ���Ӧλ��
						p2 = p2->next;
					}
					p1->next = p2->next;
					p2->next = p1;
					printf("����������һ���ַ�:\n");
					p1->data = getchar();
					while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //��ȡ�س��������������
					break;
				}
				else {
					printf("�������!!!!�����Ƿ���Ϲ���!!!!\n");
				}
			}
			break;
		}
		else if (operationNum == 3) {                                            //β������
			singleNode* p1 = singleHead, * p2;
			p2 = (singleNode*)malloc(sizeof(singleNode));
			while (p1->next != NULL) {
				p1 = p1->next;
			}
			printf("����������һ���ַ�:\n");
			p2->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //��ȡ�س��������������
			p1->next = p2;
			p2->next = NULL;
			break;
		}
		else {
			printf("�������!!!���������!!!");
			Sleep(800);
		}
	}

	printf("����ɹ�!!!");
	Sleep(600);
	return singleHead;
}
singleNode* singleNodeDelete() {                                                  //�ڵ�ɾ��
	system("cls");
	if (singleHead == NULL) {
		printf("����Ϊ��!!!!���ȴ�������!!!!");
		Sleep(1000);
		return NULL;
	}
	singleNode* p1 = singleHead;
	int num = 0;                                                      //���ڳн�����Ľڵ����
	int maxNum = nodeDisplay(0);                                     //��¼�ڵ�����Ա��ں�������
	while (1) {
		printf("������Ҫɾ���ڵ�����:\n");
		scanf("%d", &num);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (num == 1) {                                             //ɾ��ͷ�ڵ����⴦��
			singleHead = p1->next;
			free(p1);
			break;
		}
		else if (num > 1 && num <= maxNum) {
			int index = 0;
			singleNode* p2 = NULL;
			while (++index != num - 1) {                             //�������׷��Ŀ��ڵ�
				p1 = p1->next;
			}
			p2 = p1->next;
			p1->next = p2->next;
			free(p2);
			break;
		}
		else {
			printf("�������!!!!���������Ƿ�Ϲ�!!!\n");
		}
	}
	printf("ɾ���ɹ�!!!!");
	Sleep(1000);
	return singleHead;
}
singleNode* singleNodeSearch() {
	system("cls");
	int flag = 0;                                                      //�ж��Ƿ���ڽڵ��һ����־
	if (singleHead == NULL) {
		printf("Ϊ������!!!!");
		Sleep(1000);
		return NULL;
	}
	printf("������Ҫ��ѯ��һ���ַ�:\n");
	char OBJ = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	singleNode* p1 = singleHead;
	while (p1 != NULL) {
		if (p1->data == OBJ) {
			flag = 1;                                                 //���ڲ�ѯֵ��ı��־��ֵ
			break;
		}
		p1 = p1->next;
	}
	if (flag == 1) {
		printf("�������д��ַ�!!(���س���������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return p1;
	}
	else {
		printf("������û�д��ַ�!!!!(���س�������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return NULL;
	}
}
singleNode* parityExchange() {
	if (singleHead == NULL) {
		printf("Ϊ������!!!!���ȴ�������!!!");
		Sleep(1000);
		return NULL;
	}
	if (singleHead->next == NULL)                                         //������ֻ��һ������,��ֱ�ӷ���
		return singleHead;
	singleNode* p1 = singleHead, * p2 = p1->next, * p3 = singleHead->next;                  //������ָ��,p2,p3��������,p1����������һ��ָ��
	singleHead = p3;
	p1->next = p2->next;
	p2->next = p1;
	p2 = p1->next;
	if (p2 == NULL)
		return singleHead;
	p3 = p2->next;                                                           //���⴦��ǰ�����ĶԻ�
	while (p3 != NULL) {
		p1->next = p3;
		p2->next = p3->next;
		p3->next = p2;
		p1 = p2;
		p2 = p2->next;
		if (p2 == NULL)
			return singleHead;
		p3 = p2->next;
	}
	printf("��ż�Ի��ɹ�!!!!");
	Sleep(800);
	return singleHead;
}
singleNode* middleSearch() {                                               //����ָ��
	system("cls");
	if (singleHead == NULL) {
		printf("Ϊ������!!!!");
		Sleep(800);
		return singleHead;
	}
	singleNode* p1 = singleHead, * p2 = singleHead;
	while (p1 != NULL) {
		p1 = p1->next;
		if (p1 == NULL)
			break;
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("��Ϊ�м�ڵ������ӡ�Ľ��:\n");                            //���м�ڵ������ӡ�Ա����
	int num = 0;
	printf("���\t����\n");
	while (p2 != NULL) {
		printf("%d\t%c\n", ++num, p2->data);
		p2 = p2->next;
	}
	printf("(�س���������һ��)");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return p2;
}
void circleJudge() {                                              //����ָ������Ƿ�ΪNULL�����������ж��Ƿ�Ϊѭ��ָ��
	if (singleHead == NULL) {
		printf("Ϊ������!!!");
		Sleep(800);
	}
	singleNode* p1 = singleHead, * p2 = singleHead, * p3 = singleHead;
	while (1) {
		system("cls");
		printf("1.����β��ͷ,�����жϻ���(֮���ȥѭ����,�˽������ڲ��Եĸ���)\n2.ֱ���жϴ˵������Ƿ�Ϊѭ������\n������������:\n");//����һ�������������жϹ���
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (operationNum == 1) {
			if (singleHead->next == NULL) {
				printf("������ֻ��һ���ڵ㲻���ô˹���!!!!\n");
				Sleep(1000);
				continue;
			}
			while (p3->next != NULL) {
				p3 = p3->next;
			}
			p3->next = singleHead;                                       //β��ͷ
			break;
		}
		else if (operationNum == 2) {
			break;
		}
		else {
			printf("�������!!!���������Ƿ�Ϲ�!!!\n");
			Sleep(1000);
		}
	}
	while (p2 != NULL) {
		p2 = p2->next;
		if (p2 == NULL)
			break;
		p2 = p2->next;
		if (p1 == p2) {
			printf("��������ѭ������(�س�������һ��)");
			if (operationNum == 1) {
				p3->next = NULL;                                   //ȥ������
			}
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			return;
		}
	}
	printf("������Ϊѭ������(�س�������һ��)");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
}
singleNode* singleNodeReversal() {                                           //��ת����,�ǵݹ�
	system("cls");
	if (singleHead == NULL) {
		printf("Ϊ������!!");                                       //��������NULL
		Sleep(1000);
		return NULL;
	}
	if (singleHead->next == NULL) {
		printf("��ת�ɹ�");                                          //������ֻ��һ���ڵ�,ֱ�ӷ���ͷָ��
		Sleep(800);
		return singleHead;
	}
	singleNode* p1 = singleHead, * p2 = singleHead->next, * p3 = p2->next;
	p1->next = NULL;                                                  //������ָ��,�����⴦��ǰ����ָ��
	while (p3 != NULL) {
		p2->next = p1;
		p1 = p2;
		p2 = p3;                                                      //p2��������,p1��p3���������ƶ�
		p3 = p3->next;
	}
	p2->next = p1;
	singleHead = p2;
	printf("��ת�ɹ�!");
	Sleep(800);
	return singleHead;
}
singleNode* singleNodeReversalRecursion(singleNode* Head) {                         //�ݹ鷴ת
	if (Head == NULL || Head->next == NULL) {
		return Head;                                                //���õ�ȫ���ڵ�󷵻����һ���ڵ�
	}
	singleNode* p1 = Head->next;
	singleNode* p2 = singleNodeReversalRecursion(p1);
	p1->next = Head;                                                 //����ȫ���ڵ��,��ʼ������
	Head->next = NULL;
	return p2;                                                      //�õ����һ���ڵ㲻ͣ�ķ�����,��Ϊ��ת���ͷ�ڵ�
}
void singleLinkedList() {                                           //����������
	while (1) {
		system("cls");
		displayMenu(Menu1, 13);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //��ȡ�س��������������
		switch (operationNum) {
		case 1:
			singleNodeGeneration();
			break;
		case 2:
			system("cls");
			nodeDisplay(0);
			printf("���س�������һ��");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);            //��ȡ�س��������������
			break;
		case 3:
			singleNodeDestroy();
			break;
		case 4:
			singleNodeInsert();
			break;
		case 5:
			singleNodeDelete();
			break;
		case 6:
			singleNodeSearch();
			break;
		case 7:
			parityExchange();
			break;
		case 8:
			middleSearch();
			break;
		case 9:
			circleJudge();
			break;
		case 10:
			singleNodeReversal();
			break;
		case 11:
			singleHead = singleNodeReversalRecursion(singleHead);
			system("cls");
			printf("��ת�ɹ�");
			Sleep(800);
			break;
		case 12:
			return;
		default:
			printf("�������!!!����������!!!");
			Sleep(800);
		}
	}
}
doubleNode* doubleNodeGeneration() {
	system("cls");
	if (doubleHead != NULL) {
		printf("˫�������Ѿ���������,���������ٴ���(���س�������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //��ȡ�س��������������
		return NULL;

	}
	printf("������һ���ַ�(����#���������):\n");                       //���ù���������־
	doubleNode* p1 = doubleHead, * p2;
	p2 = (doubleNode*)malloc(sizeof(doubleNode));
	doubleHead = p2;
	p2->previous = NULL;
	p2->data = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                        //����getchar�м�Ļس��ᱻ��ȡ,�����ô�������
	while (p2->data != '#') {
		printf("������һ���ַ�(����#���������):\n");
		p1 = p2;
		p2 = (doubleNode*)malloc(sizeof(doubleNode));
		p1->next = p2;
		p2->previous = p1;
		p2->data = getchar();
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                   //����getchar�м�Ļس��ᱻ��ȡ,�����ô�������
	}
	free(p2);                                                          //�ͷ����һ���ַ�Ϊ#�Ľڵ�
	if (p1 != NULL)                                                    //���һ��ʼ������#��ôp1=NULL,��headΪnull,Ϊ������
		p1->next = NULL;
	else
		doubleHead = NULL;
	printf("�����ɹ�\n");
	Sleep(800);
	return doubleHead;
}
doubleNode* doubleNodeDestroy() {                                               //���������
	system("cls");
	if (doubleHead == NULL) {
		printf("����Ϊ��!!!");
		Sleep(800);
		return NULL;
	}
	doubleNode* p1 = doubleHead, * p2 = doubleHead;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);                                                      //ȫ���ͷ�
		p1 = p2;
	}
	doubleHead = NULL;
	printf("���ٳɹ�!!");
	Sleep(800);
	return doubleHead;
}
doubleNode* doubleNodeInsert() {
	system("cls");
	if (doubleHead == NULL) {
		printf("˫������δ����!!!!���ȴ�������!!!!");
		Sleep(1100);
		return NULL;
	}
	while (1) {
		system("cls");
		printf("1.ͷ������\n2.�м����\n3.β������\n��������뷽ʽ:\n");
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                      //��ȡ�س��������������
		if (operationNum == 1) {                                          //ͷ������
			doubleNode* p1 = (doubleNode*)malloc(sizeof(doubleNode));
			p1->next = doubleHead;
			doubleHead->previous = p1;
			p1->previous = NULL;
			doubleHead = p1;
			printf("����������һ���ַ�:\n");
			p1->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //��ȡ�س��������������
			break;
		}
		else if (operationNum == 2) {                                     //�м����   
			system("cls");
			if (doubleHead->next == NULL) {
				printf("������ֻ��һ���ڵ���ѡ��ͷ���������β������\n");
				Sleep(1500);
				continue;
			}
			int maxNum = nodeDisplay(1);                                    //��¼�ڵ�����Ա��ں�������
			int low = 0, high = 0;
			while (1) {
				printf("���С���������������ڵ����(�ո����):\n");
				scanf("%d %d", &low, &high);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (high - low == 1 && high <= maxNum && low >= 1) {          //����ó�������
					doubleNode* p1 = (doubleNode*)malloc(sizeof(doubleNode));
					doubleNode* p2 = doubleHead;
					int num = 0;
					while (++num != low) {                                   //ָ���Ƶ���Ӧλ��
						p2 = p2->next;
					}
					p1->next = p2->next;
					p2->next = p1;
					p1->previous = p2;
					p2 = p1->next;
					if (p2 != NULL)
						p2->previous = p1;
					printf("����������һ���ַ�:\n");
					p1->data = getchar();
					while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //��ȡ�س��������������
					break;
				}
				else {
					printf("�������!!!!�����Ƿ���Ϲ���!!!!\n");
				}
			}
			break;
		}
		else if (operationNum == 3) {                                            //β������
			doubleNode* p1 = doubleHead, * p2;
			p2 = (doubleNode*)malloc(sizeof(doubleNode));
			while (p1->next != NULL) {
				p1 = p1->next;
			}
			printf("����������һ���ַ�:\n");
			p2->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //��ȡ�س��������������
			p1->next = p2;
			p2->previous = p1;
			p2->next = NULL;
			break;
		}
		else {
			printf("�������!!!���������!!!");
			Sleep(800);
		}
	}

	printf("����ɹ�!!!");
	Sleep(600);
	return doubleHead;
}
doubleNode* doubleNodeDelete() {                                                  //�ڵ�ɾ��
	system("cls");
	if (doubleHead == NULL) {
		printf("����Ϊ��!!!!���ȴ�������!!!!");
		Sleep(1000);
		return NULL;
	}
	doubleNode* p1 = doubleHead;
	int num = 0;                                                      //���ڳн�����Ľڵ����
	int maxNum = nodeDisplay(1);                                     //��¼�ڵ�����Ա��ں�������
	while (1) {
		printf("������Ҫɾ���ڵ�����:\n");
		scanf("%d", &num);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (num == 1) {                                             //ɾ��ͷ�ڵ����⴦��
			doubleHead = p1->next;
			if (doubleHead != NULL)
				doubleHead->previous = NULL;
			free(p1);
			break;
		}
		else if (num > 1 && num <= maxNum) {
			int index = 0;
			doubleNode* p2 = NULL;
			while (++index != num - 1) {
				p1 = p1->next;
			}
			p2 = p1->next;
			if (p2->next != NULL) {
				p2 = p2->next;
				p2->previous = p1;
				p2 = p1->next;
			}
			p1->next = p2->next;
			free(p2);
			break;
		}
		else {
			printf("�������!!!!���������Ƿ�Ϲ�!!!\n");
		}
	}
	printf("ɾ���ɹ�!!!!");
	Sleep(1000);
	return doubleHead;
}
doubleNode* doubleNodeSearch() {
	system("cls");
	int flag = 0;                                                      //�ж��Ƿ���ڽڵ��һ����־
	if (doubleHead == NULL) {
		printf("Ϊ������!!!!");
		Sleep(1000);
		return NULL;
	}
	printf("������Ҫ��ѯ��һ���ַ�:\n");
	char OBJ = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	doubleNode* p1 = doubleHead;
	while (p1 != NULL) {
		if (p1->data == OBJ) {
			flag = 1;                                                 //���ڲ�ѯֵ��ı��־��ֵ
			break;
		}
		p1 = p1->next;
	}
	if (flag == 1) {
		printf("˫���������д��ַ�!!(���س���������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return p1;
	}
	else {
		printf("˫��������û�д��ַ�!!!!(���س�������һ��)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return NULL;
	}
}
void doubleLinkedList() {
	while (1) {
		system("cls");
		displayMenu(Menu2, 8);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //��ȡ�س��������������
		switch (operationNum) {
		case 1:
			doubleNodeGeneration();
			break;
		case 2:
			system("cls");
			nodeDisplay(1);
			printf("���س�������һ��");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);            //��ȡ�س��������������
			break;
		case 3:
			doubleNodeDestroy();
			break;
		case 4:
			doubleNodeInsert();
			break;
		case 5:
			doubleNodeDelete();
			break;
		case 6:
			doubleNodeSearch();
			break;
		case 7:
			return;
		default:
			printf("�������!!!����������!!!");
			Sleep(800);
		}
	}
}