#pragma once
typedef enum Status
{
	FAlSE = 0,
	SUCCESS = 1
} Status;
typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;
Status initStack(LinkStack* s);//��ʼ��
Status isEmptyStack(LinkStack* s);//�ж��Ƿ�Ϊ��
Status getTopStack(LinkStack* s, char* e);//��ջ��Ԫ��
Status clearStack(LinkStack* s);//���ջ
Status destroyStack(LinkStack* s);//����ջ
Status stackLength(LinkStack* s, int* length);//�õ�ջ�ĳ���
Status pushStack(LinkStack* s, char datas);//ѹջ
Status popStack(LinkStack* s, char* datas);//��ջ
Status printAll(LinkStack* s);//��ӡȫ��Ԫ��
void displayMenu(char menu[][29]);//��ӡ�˵�