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
Status initLQueue(LinkQueue* s);//��ʼ��
Status isEmptyLQueue(LinkQueue* s);//�ж��Ƿ�Ϊ��
Status getHeadLQueue(LinkQueue* s, void** data);//�ö�ͷ
Status clearLQueue(LinkQueue* s);//�������
Status DestroyLQueue(LinkQueue* s);//���ٶ���
Status LQueueLength(LinkQueue* s, int* length);//ѯ�ʶ��г���
Status EnLQueue(LinkQueue* s, void** data);//���
Status DeLQueue(LinkQueue* s, void** data);//����
Status PrintAll(LinkQueue* s);//ȫ����ӡ
void displayMenu(char menu[][29]);//��ӡ�˵�
