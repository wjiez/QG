#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"LinkQueue.h"
int cacheClean;                                     //用于清除缓存区的承接数据
int operationNum = 0;                               //操作序号存放
char Menu[11][29] = {                                                                //各个菜单的内容
	"1.初始化队列",
	"2.判断队列是否空",
	"3.得到队头元素",
	"4.清空队列",
	"5.销毁队列",
	"6.检测队列的大小",
	"7.入队",
	"8.出队",
	"9.遍历队列(全部出队)",
	"10.退出程序",
	"(请输入操作序号)"
};
int main() {
	LinkQueue test;
	int flag = 0, num = 0;//flag用来判断是否初始化过,num用来记录队列长度从而输出
	char* i = NULL;//本代码用字符类型来呈现入队等操作
	while (1) {
		system("cls");
		displayMenu(Menu);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //读取回车键并清除缓存区
		switch (operationNum) {//操作指令判断
		case 1:
			if (initLQueue(&test) && flag == 0) {
				printf("初始化成功!!!\n");
				flag = 1;
				Sleep(1000);
			}
			else {
				printf("已初始化过,或则链队已存在请先销毁!!!\n");
				Sleep(1000);
			}
			break;
		case 2:
			if (flag == 1) {//代表初始化过
				isEmptyLQueue(&test);
				Sleep(1000);
			}
			else {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			break;
		case 3:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {//为空的提示
				printf("链队为空!!!\n");
				Sleep(1000);
			}
			else if (getHeadLQueue(&test, &i)) {
				printf("队头元素为:\n%c", *i);
				Sleep(1000);
			}
			break;
		case 4:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else if (clearLQueue(&test)) {
				printf("清空成功\n");
				Sleep(1000);
			}
			break;
		case 5:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else if (DestroyLQueue(&test)) {
				printf("销毁成功!!!\n");
				flag = 0;
				Sleep(1000);
			}
			break;
		case 6:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else if (LQueueLength(&test, &num)) {
				printf("目前队列的长度为:\n%d", num);
				Sleep(1000);
			}
			break;
		case 7:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else {
				printf("请输入一个字符入队:\n");
				i = (char*)malloc(sizeof(char));
				scanf("%c", i);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);//清理缓存区
				EnLQueue(&test, &i);
				printf("入队成功\n");
				Sleep(1000);
			}
			break;
		case 8:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else if (test.count == 0) {
				printf("链队为空!!!\n");
				Sleep(1000);
			}
			else {
				getHeadLQueue(&test, &i);
				printf("数据%c出队成功\n", *i);//先拿到数据再出队,void*会free掉
				DeLQueue(&test, &i);
				Sleep(1000);
			}
			break;
		case 9:
			if (flag == 0) {
				printf("链队还未初始化过!!!");
				Sleep(1000);
			}
			else
				PrintAll(&test);
			break;
		case 10:
			return 1;
		default:
			printf("输入错误!!!请重新输入!!!");
			Sleep(800);
		}
	}
}
Status initLQueue(LinkQueue* s) {//初始化
	s->head = NULL;
	s->tail = NULL;
	s->count = 0;
	return SUCCESS;
}
Status isEmptyLQueue(LinkQueue* s) {//判断是否为空
	if (s->head == NULL && s->tail == NULL)
		printf("链队为空\n");
	else
		printf("链队不为空\n");
	return SUCCESS;
}
Status getHeadLQueue(LinkQueue* s, void** data) {//拿队头
	*data = s->head->data;
	return SUCCESS;
}
Status clearLQueue(LinkQueue* s) {//清楚队列
	int i = 0;
	void* p = &i;
	while (s->head != NULL)
		DeLQueue(s, &p);
	return SUCCESS;
}
Status DeLQueue(LinkQueue* s, void** data) {//出队
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
Status EnLQueue(LinkQueue* s, void** data) {//入队
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
Status LQueueLength(LinkQueue* s, int* length) {//得到队列长度
	*length = s->count;
	return SUCCESS;
}
Status DestroyLQueue(LinkQueue* s) {//销毁队列
	int i = 0;
	void* p = &i;
	while (s->head != NULL) {
		DeLQueue(s, &p);
	}
	return SUCCESS;
}
Status PrintAll(LinkQueue* s) {//全部打印
	system("cls");
	if (s->count == 0) {
		printf("为空队列!!!\n");
	}
	else {
		char* p = NULL;
		while (s->head != NULL) {
			getHeadLQueue(s, &p);
			printf("%c\n", *p);
			DeLQueue(s, &p);
		}
	}
	printf("回车返回!!!!");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return SUCCESS;
}
void displayMenu(char menu[][29]) {//打印菜单
	for (int i = 0; i < 11; i++) {
		printf("%s\n", menu[i]);
	}
}