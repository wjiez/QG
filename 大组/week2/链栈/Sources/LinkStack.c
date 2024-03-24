#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include"LinkStack.h"
int cacheClean;                                     //用于清除缓存区的承接数据
int operationNum = 0;                               //操作序号存放
char Menu[11][29] = {                                                                //各个菜单的内容
	"1.初始化栈",
	"2.判断栈是否空",
	"3.得到栈顶元素",
	"4.清空栈",
	"5.销毁栈",
	"6.检测栈的大小",
	"7.入栈",
	"8.出栈",
	"9.遍历链栈(全部出栈)",
	"10.退出程序",
	"(请输入操作序号)"
};
int main() {
	LinkStack test;
	int flag = 0, num = 0;//flag判断是否初始化过,num用来记录栈长度
	char i = 0;//本代码用来字符来演示出栈等操作
	while (1) {
		system("cls");
		displayMenu(Menu);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //读取回车键并清除缓存区
		switch (operationNum) {
		case 1:
			if (initStack(&test) && flag == 0) {
				printf("初始化成功!!!\n");
				flag = 1;
				Sleep(1000);
			}
			else {
				printf("已初始化过,或则链栈已存在请先销毁!!!\n");
				Sleep(1000);
			}
			break;
		case 2:
			if (flag == 1) {//初始化过的标志
				isEmptyStack(&test);
				Sleep(1000);
			}
			else {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			break;
		case 3:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {//为空则不能进行访问
				printf("链栈为空!!!\n");
				Sleep(1000);
			}
			else if (getTopStack(&test, &i)) {
				printf("栈顶元素为:\n%c", i);
				Sleep(1000);
			}
			break;
		case 4:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else if (clearStack(&test)) {
				printf("清空成功\n");
				Sleep(1000);
			}
			break;
		case 5:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else if (destroyStack(&test)) {
				printf("销毁成功!!!\n");
				flag = 0;
				Sleep(1000);
			}
			break;
		case 6:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else if (stackLength(&test, &num)) {
				printf("目前栈的长度为:\n%d", num);
				Sleep(1000);
			}
			break;
		case 7:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else {
				printf("请输入一个字符入栈:\n");
				scanf("%c", &i);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				pushStack(&test, i);
				printf("入栈成功\n");
				Sleep(1000);
			}
			break;
		case 8:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {
				printf("链栈为空!!!\n");
				Sleep(1000);
			}
			else {
				popStack(&test, &i);
				printf("数据%c出栈成功\n", i);
				Sleep(1000);
			}
			break;
		case 9:
			if (flag == 0) {
				printf("链栈还未初始化过!!!");
				Sleep(1000);
			}
			else
				printAll(&test);
			break;
		case 10:
			return 1;
		default:
			printf("输入错误!!!请重新输入!!!");
			Sleep(800);
		}
	}
}
Status initStack(LinkStack* s) {//初始化
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyStack(LinkStack* s) {//判断是否为空
	if (s->top == NULL) {
		printf("链栈为空\n");
		return FAlSE;
	}
	else
		printf("链栈不为空\n");
	return SUCCESS;
}
Status getTopStack(LinkStack* s, char* data) {//拿栈顶
	*data = s->top->data;
	return SUCCESS;
}
Status clearStack(LinkStack* s) {//清除栈
	char i = 0, * p = &i;
	while (s->top != NULL)
		popStack(s, p);
	return SUCCESS;
}
Status popStack(LinkStack* s, char* data) {//出栈
	LinkStackPtr p1 = s->top;
	*data = p1->data;
	s->top = p1->next;
	free(p1);
	(s->count)--;
	return SUCCESS;
}
Status pushStack(LinkStack* s, char data) {//入栈
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->data = data;
	(s->count)++;
	return SUCCESS;
}
Status stackLength(LinkStack* s, int* length) {//栈长度
	*length = s->count;
	return SUCCESS;
}
Status destroyStack(LinkStack* s) {//销毁
	char i = 0, * p = &i;
	while (s->top != NULL)
		popStack(s, p);
	return SUCCESS;
}
Status printAll(LinkStack* s) {//打印全部栈
	system("cls");
	if (s->count == 0) {
		printf("为空栈!!!!\n");
	}
	else {
		char p = 0;
		while (s->count != 0) {
			popStack(s, &p);
			printf("%c\n", p);
		}
	}
	printf("回车返回!!!");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return SUCCESS;
}
void displayMenu(char menu[][29]) {//打印菜单
	for (int i = 0; i < 11; i++) {
		printf("%s\n", menu[i]);
	}
}