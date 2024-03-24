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
Status initStack(LinkStack* s);//初始化
Status isEmptyStack(LinkStack* s);//判断是否为空
Status getTopStack(LinkStack* s, char* e);//拿栈顶元素
Status clearStack(LinkStack* s);//清除栈
Status destroyStack(LinkStack* s);//销毁栈
Status stackLength(LinkStack* s, int* length);//得到栈的长度
Status pushStack(LinkStack* s, char datas);//压栈
Status popStack(LinkStack* s, char* datas);//出栈
Status printAll(LinkStack* s);//打印全部元素
void displayMenu(char menu[][29]);//打印菜单