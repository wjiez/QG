#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include"LinkStack.h"
int cacheClean;                                     //��������������ĳн�����
int operationNum = 0;                               //������Ŵ��
char Menu[11][29] = {                                                                //�����˵�������
	"1.��ʼ��ջ",
	"2.�ж�ջ�Ƿ��",
	"3.�õ�ջ��Ԫ��",
	"4.���ջ",
	"5.����ջ",
	"6.���ջ�Ĵ�С",
	"7.��ջ",
	"8.��ջ",
	"9.������ջ(ȫ����ջ)",
	"10.�˳�����",
	"(������������)"
};
int main() {
	LinkStack test;
	int flag = 0, num = 0;//flag�ж��Ƿ��ʼ����,num������¼ջ����
	char i = 0;//�����������ַ�����ʾ��ջ�Ȳ���
	while (1) {
		system("cls");
		displayMenu(Menu);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //��ȡ�س��������������
		switch (operationNum) {
		case 1:
			if (initStack(&test) && flag == 0) {
				printf("��ʼ���ɹ�!!!\n");
				flag = 1;
				Sleep(1000);
			}
			else {
				printf("�ѳ�ʼ����,������ջ�Ѵ�����������!!!\n");
				Sleep(1000);
			}
			break;
		case 2:
			if (flag == 1) {//��ʼ�����ı�־
				isEmptyStack(&test);
				Sleep(1000);
			}
			else {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			break;
		case 3:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {//Ϊ�����ܽ��з���
				printf("��ջΪ��!!!\n");
				Sleep(1000);
			}
			else if (getTopStack(&test, &i)) {
				printf("ջ��Ԫ��Ϊ:\n%c", i);
				Sleep(1000);
			}
			break;
		case 4:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (clearStack(&test)) {
				printf("��ճɹ�\n");
				Sleep(1000);
			}
			break;
		case 5:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (destroyStack(&test)) {
				printf("���ٳɹ�!!!\n");
				flag = 0;
				Sleep(1000);
			}
			break;
		case 6:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (stackLength(&test, &num)) {
				printf("Ŀǰջ�ĳ���Ϊ:\n%d", num);
				Sleep(1000);
			}
			break;
		case 7:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else {
				printf("������һ���ַ���ջ:\n");
				scanf("%c", &i);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				pushStack(&test, i);
				printf("��ջ�ɹ�\n");
				Sleep(1000);
			}
			break;
		case 8:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {
				printf("��ջΪ��!!!\n");
				Sleep(1000);
			}
			else {
				popStack(&test, &i);
				printf("����%c��ջ�ɹ�\n", i);
				Sleep(1000);
			}
			break;
		case 9:
			if (flag == 0) {
				printf("��ջ��δ��ʼ����!!!");
				Sleep(1000);
			}
			else
				printAll(&test);
			break;
		case 10:
			return 1;
		default:
			printf("�������!!!����������!!!");
			Sleep(800);
		}
	}
}
Status initStack(LinkStack* s) {//��ʼ��
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyStack(LinkStack* s) {//�ж��Ƿ�Ϊ��
	if (s->top == NULL) {
		printf("��ջΪ��\n");
		return FAlSE;
	}
	else
		printf("��ջ��Ϊ��\n");
	return SUCCESS;
}
Status getTopStack(LinkStack* s, char* data) {//��ջ��
	*data = s->top->data;
	return SUCCESS;
}
Status clearStack(LinkStack* s) {//���ջ
	char i = 0, * p = &i;
	while (s->top != NULL)
		popStack(s, p);
	return SUCCESS;
}
Status popStack(LinkStack* s, char* data) {//��ջ
	LinkStackPtr p1 = s->top;
	*data = p1->data;
	s->top = p1->next;
	free(p1);
	(s->count)--;
	return SUCCESS;
}
Status pushStack(LinkStack* s, char data) {//��ջ
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->data = data;
	(s->count)++;
	return SUCCESS;
}
Status stackLength(LinkStack* s, int* length) {//ջ����
	*length = s->count;
	return SUCCESS;
}
Status destroyStack(LinkStack* s) {//����
	char i = 0, * p = &i;
	while (s->top != NULL)
		popStack(s, p);
	return SUCCESS;
}
Status printAll(LinkStack* s) {//��ӡȫ��ջ
	system("cls");
	if (s->count == 0) {
		printf("Ϊ��ջ!!!!\n");
	}
	else {
		char p = 0;
		while (s->count != 0) {
			popStack(s, &p);
			printf("%c\n", p);
		}
	}
	printf("�س�����!!!");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return SUCCESS;
}
void displayMenu(char menu[][29]) {//��ӡ�˵�
	for (int i = 0; i < 11; i++) {
		printf("%s\n", menu[i]);
	}
}