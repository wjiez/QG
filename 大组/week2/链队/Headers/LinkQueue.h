#pragma once
typedef enum{
	FAlSE = 0, SUCCESS = 1
} Status;
typedef struct QNode {
	void* data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr   head;
	QueuePtr   tail;
	int count;
}LinkQueue;
Status initLQueue(LinkQueue* s);//初始化
Status isEmptyLQueue(LinkQueue* s);//判断是否为空
Status getHeadLQueue(LinkQueue* s, void** data);//拿队头
Status clearLQueue(LinkQueue* s);//清除队列
Status DestroyLQueue(LinkQueue* s);//销毁队列
Status LQueueLength(LinkQueue* s, int* length);//询问队列长度
Status EnLQueue(LinkQueue* s, void** data);//入队
Status DeLQueue(LinkQueue* s, void** data);//出队
Status PrintAll(LinkQueue* s);//全部打印
void displayMenu(char menu[][29]);//打印菜单
