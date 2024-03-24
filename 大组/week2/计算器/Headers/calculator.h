#pragma once
typedef  struct StackNode
{
	double num;
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //ջ��ָ��
	int		 count;   //ջ��Ԫ�ظ���
}LinkStack;
typedef enum {
	FAlSE = 0, SUCCESS = 1
} Status;
double beDouble(char* nums, int* i);//�������ַ�����Ϊdouble�ĺ���
Status pushStack(LinkStack* s, char data, double num);//ѹջ����
Status popStack(LinkStack* s);//��ջ����
Status destroyStack(LinkStack* s);//����ջ����