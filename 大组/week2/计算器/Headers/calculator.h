#pragma once
typedef  struct StackNode
{
	double num;
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //栈顶指针
	int		 count;   //栈中元素个数
}LinkStack;
typedef enum {
	FAlSE = 0, SUCCESS = 1
} Status;
double beDouble(char* nums, int* i);//用来把字符串变为double的函数
Status pushStack(LinkStack* s, char data, double num);//压栈函数
Status popStack(LinkStack* s);//出栈函数
Status destroyStack(LinkStack* s);//销毁栈函数