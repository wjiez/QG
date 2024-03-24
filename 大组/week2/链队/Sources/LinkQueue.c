#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"LinkQueue.h"
int cacheClean;                                     //��������������ĳн�����
int operationNum = 0;                               //������Ŵ��
char Menu[11][29] = {                                                                //�����˵�������
	"1.��ʼ������",
	"2.�ж϶����Ƿ��",
	"3.�õ���ͷԪ��",
	"4.��ն���",
	"5.���ٶ���",
	"6.�����еĴ�С",
	"7.���",
	"8.����",
	"9.��������(ȫ������)",
	"10.�˳�����",
	"(������������)"
};
int main() {
	LinkQueue test;
	int flag = 0, num = 0;//flag�����ж��Ƿ��ʼ����,num������¼���г��ȴӶ����
	char* i = NULL;//���������ַ�������������ӵȲ���
	while (1) {
		system("cls");
		displayMenu(Menu);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //��ȡ�س��������������
		switch (operationNum) {//����ָ���ж�
		case 1:
			if (initLQueue(&test) && flag == 0) {
				printf("��ʼ���ɹ�!!!\n");
				flag = 1;
				Sleep(1000);
			}
			else {
				printf("�ѳ�ʼ����,���������Ѵ�����������!!!\n");
				Sleep(1000);
			}
			break;
		case 2:
			if (flag == 1) {//�����ʼ����
				isEmptyLQueue(&test);
				Sleep(1000);
			}
			else {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			break;
		case 3:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {//Ϊ�յ���ʾ
				printf("����Ϊ��!!!\n");
				Sleep(1000);
			}
			else if (getHeadLQueue(&test, &i)) {
				printf("��ͷԪ��Ϊ:\n%c", *i);
				Sleep(1000);
			}
			break;
		case 4:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (clearLQueue(&test)) {
				printf("��ճɹ�\n");
				Sleep(1000);
			}
			break;
		case 5:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (DestroyLQueue(&test)) {
				printf("���ٳɹ�!!!\n");
				flag = 0;
				Sleep(1000);
			}
			break;
		case 6:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (LQueueLength(&test, &num)) {
				printf("Ŀǰ���еĳ���Ϊ:\n%d", num);
				Sleep(1000);
			}
			break;
		case 7:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else {
				printf("������һ���ַ����:\n");
				i = (char*)malloc(sizeof(char));
				scanf("%c", i);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);//��������
				EnLQueue(&test, &i);
				printf("��ӳɹ�\n");
				Sleep(1000);
			}
			break;
		case 8:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {
				printf("����Ϊ��!!!\n");
				Sleep(1000);
			}
			else {
				getHeadLQueue(&test, &i);
				printf("����%c���ӳɹ�\n", *i);//���õ������ٳ���,void*��free��
				DeLQueue(&test, &i);
				Sleep(1000);
			}
			break;
		case 9:
			if (flag == 0) {
				printf("���ӻ�δ��ʼ����!!!");
				Sleep(1000);
			}
			else
				PrintAll(&test);
			break;
		case 10:
			return 1;
		default:
			printf("�������!!!����������!!!");
			Sleep(800);
		}
	}
}
Status initLQueue(LinkQueue* s) {//��ʼ��
	s->head = NULL;
	s->tail = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyLQueue(LinkQueue* s) {//�ж��Ƿ�Ϊ��
	if (s->head == NULL && s->tail == NULL)
		printf("����Ϊ��\n");
	else
		printf("���Ӳ�Ϊ��\n");
	return SUCCESS;
}
Status getHeadLQueue(LinkQueue* s, void** data) {//�ö�ͷ
	*data = s->head->data;
	return SUCCESS;
}
Status clearLQueue(LinkQueue* s) {//�������
	int i = 0;
	void* p = &i;
	while (s->head != NULL)
		DeLQueue(s, &p);
	return SUCCESS;
}
Status DeLQueue(LinkQueue* s, void** data) {//����
	if (s->head == s->tail)
		s->tail = NULL;
	free(s->head->data);
	QueuePtr p1 = s->head;
	*data = p1->data;
	s->head = p1->next;
	free(p1);
	(s->count)--;
	return SUCCESS;
}
Status EnLQueue(LinkQueue* s, void** data) {//���
	QueuePtr p1 = (QueuePtr)malloc(sizeof(QNode));
	if (s->tail != NULL) {
		s->tail->next = p1;
	}
	else {
		s->head = p1;
	}
	s->tail = p1;
	p1->next = NULL;
	p1->data = *data;
	(s->count)++;
	return SUCCESS;
}
Status LQueueLength(LinkQueue* s, int* length) {//�õ����г���
	*length = s->count;
	return SUCCESS;
}
Status DestroyLQueue(LinkQueue* s) {//���ٶ���
	int i = 0;
	void* p = &i;
	while (s->head != NULL) {
		DeLQueue(s, &p);
	}
	return SUCCESS;
}
Status PrintAll(LinkQueue* s) {//ȫ����ӡ
	system("cls");
	if (s->count == 0) {
		printf("Ϊ�ն���!!!\n");
	}
	else {
		char* p = NULL;
		while (s->head != NULL) {
			getHeadLQueue(s, &p);
			printf("%c\n", *p);
			DeLQueue(s, &p);
		}
	}
	printf("�س�����!!!!");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return SUCCESS;
}
void displayMenu(char menu[][29]) {//��ӡ�˵�
	for (int i = 0; i < 11; i++) {
		printf("%s\n", menu[i]);
	}
}