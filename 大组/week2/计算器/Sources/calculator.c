#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"calculator.h"
char Calculationexpression[200] = "";//用于输入中缀表达式
int cacheClean;                                     //用于清除缓存区的承接数据
int main() {
	while (1) {
		system("cls");
		printf("请输入标准计算表达式(不用等号直接回车,负数单独括起来,暂不支持表达式的前面加正负符号处理,直接回车结束程序):\n");
		gets(Calculationexpression);//输入中缀表达式
		LinkStack test = { NULL,0 };//初始化链栈
		char temp[200] = "";//用来存放后缀表达式
		int i = 0, j = 0, status = 1,judge=1;//用于数组的遍历移动,status用来标记是否需要进行第二步骤,judge用来标记小数点是否有在一个数内重复出现
		int rnum = 0, lnum = 0;//左右括号数量记录,不相等则报错
		double result = 0; //用于计算过程中值的记录
		if (Calculationexpression[0] == '\0')
			return 1;
		while (Calculationexpression[i] != '\0') {
			if (Calculationexpression[0] == '*' || Calculationexpression[0] == '/'||Calculationexpression[0]=='+'||Calculationexpression[0]=='-') {
				printf("表达式有误,请检查!!!\n");
				status = 0;
				break;
			}
			if (Calculationexpression[i] == '-' || Calculationexpression[i] == '+') {//对加减号的处理
				judge = 1;//重置小数点状态
				if (test.top == NULL)
					pushStack(&test, Calculationexpression[i], 0);
				else if (Calculationexpression[i - 1] == '+' || Calculationexpression[i - 1] == '-' || Calculationexpression[i - 1] == '*' || Calculationexpression[i - 1] == '/') {//符号相连则报错
					printf("表达式有误,请检查!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				else if (test.top->data == '*' || test.top->data == '/') {//优先级对比
					while (test.top != NULL && test.top->data != '(') {
						temp[j++] = test.top->data;
						popStack(&test);
					}
					pushStack(&test, Calculationexpression[i], 0);
				}
				else {
					while (test.top != NULL && test.top->data != '(') {
						temp[j++] = test.top->data;
						popStack(&test);
					}
					pushStack(&test, Calculationexpression[i], 0);
				}

			}
			else if (Calculationexpression[i] == '*' || Calculationexpression[i] == '/') {//对乘除号处理
				judge = 1;
				if (test.top == NULL)
					pushStack(&test, Calculationexpression[i], 0);
				else if (Calculationexpression[i - 1] == '+' || Calculationexpression[i - 1] == '-' || Calculationexpression[i - 1] == '*' || Calculationexpression[i - 1] == '/') {//符号相连则报错
					printf("表达式有误,请检查!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				else if (test.top->data == '+' || test.top->data == '-' || test.top->data == '(') {
					pushStack(&test, Calculationexpression[i], 0);
				}
				else {
					temp[j++] = test.top->data;
					popStack(&test);
					pushStack(&test, Calculationexpression[i], 0);
				}
			}
			else if (Calculationexpression[i] == '(') {
				if (i != 0 && Calculationexpression[i - 1] != '+' && Calculationexpression[i - 1] != '-' && Calculationexpression[i - 1] != '*' && Calculationexpression[i - 1] != '/'&&Calculationexpression[i-1]!='(') {//如果不为首元素,左括号前面左边不是运算符号则报错
					printf("请检查左括号前是否有运算符!!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				if (Calculationexpression[i + 1] == '/' || Calculationexpression[i + 1] == '*' ) {
					printf("表达式有误,请检查!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				if (Calculationexpression[i + 1] == '-' || Calculationexpression[i + 1] == '+') {//括号内首元素为加减则对此数字进行正负标记
					temp[j++] = ',';
					temp[j++] = Calculationexpression[++i];
					i++;
					while ((Calculationexpression[i] >= '0' && Calculationexpression[i] <= '9') || Calculationexpression[i] == '.') {
						temp[j++] = Calculationexpression[i++];
					}
					if (Calculationexpression[i] != ')') {//括号内除了正负符号,数字外还有其他内容报错
						printf("表达式有误,请检查!!!\n");
						status = 0;
						destroyStack(&test);
						break;
					}
				}
				else {
					pushStack(&test, Calculationexpression[i], 0);
					lnum++;
				}
			}
			else if (Calculationexpression[i] == ')' && rnum < lnum) {//右括号处理
				if (Calculationexpression[i - 1] > '9' || Calculationexpression[i - 1] < '0') {
					printf("表达式有误,请检查!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				while (1) {
					char temp1 = test.top->data;
					popStack(&test);
					if (temp1 == '(')
						break;
					temp[j++] = temp1;
				}
				rnum++;
			}
			else if ((Calculationexpression[i] >= '0' && Calculationexpression[i] <= '9') || Calculationexpression[i] == '.') {//数字处理
				if (Calculationexpression[i] == '.') {
					if (i == 0 || Calculationexpression[i - 1] > '9' || Calculationexpression[i - 1] < '0'||Calculationexpression[i+1]>'9'||Calculationexpression[i+1]<'0' || judge == 0) {//小数点前面必须是数字,且一个数字字符串小数点不能重复出现,否则报错,
						printf("表达式有误,请检查!!!\n");
						destroyStack(&test);
						status = 0;
						break;
					}
					else {
						temp[j++] = '.';
						judge = 0;                  //这里标志着数字内已经存在了一个小数点
					}		
				}
				else if (i != 0 && ((Calculationexpression[i - 1] >= '0' && Calculationexpression[i - 1] <= '9') || Calculationexpression[i - 1] == '.'))//如果上一个字符为数字或小数点则可直接存入,否则用逗号隔开
					temp[j++] = Calculationexpression[i];
				else {
					temp[j++] = ',';//不同字符串数字之间用一个逗号隔开,
					temp[j++] = Calculationexpression[i];
				}
			}
			else {//如果不为上面所有的符号则报错
				destroyStack(&test);
				printf("输入了未知符号或括号不匹配,请检查!!!!\n");
				status = 0;
				break;
			}
			i++;
		}
		if ( status == 1&&i-1>=0&&(Calculationexpression[i-1] == '*' || Calculationexpression[i-1] == '/' || Calculationexpression[i-1] == '+' || Calculationexpression[i-1] == '-')) {//计算式尾部有计算符号报错
			printf("表达式有误,请检查!!!\n");
			destroyStack(&test);
			status = 0;
		}
		if (status==1&&rnum != lnum) {//左右括号不匹配报错
			destroyStack(&test);
			printf("括号数量不匹配,请检查!!!\n");
			status = 0;
		}
		while (status) {//把运算符全部放入后缀表达式
			if (test.top == NULL)
				break;
			temp[j++] = test.top->data;
			popStack(&test);
		}
		i = 0;
		while (status) {//状态正确则进行后缀表达式运算
			if (temp[i] == ',') {
				if (temp[i + 1] == '+' || temp[i + 1] == '-' || (temp[i + 1] >= '0' && temp[i + 1] <= '9')) {
					i++;
					pushStack(&test, 0, beDouble(&temp[0], &i));
				}
			}
			else if (temp[i] == '+') {
				result = test.top->num;
				popStack(&test);
				result = result + test.top->num;
				popStack(&test);
				pushStack(&test, 0, result);
				i++;
			}
			else if (temp[i] == '-') {
				result = test.top->num;
				popStack(&test);
				result = test.top->num - result;
				popStack(&test);
				pushStack(&test, 0, result);
				i++;
			}
			else if (temp[i] == '*') {
				result = test.top->num;
				popStack(&test);
				result = result * test.top->num;
				popStack(&test);
				pushStack(&test, 0, result);
				i++;
			}
			else if (temp[i] == '/') {
				result = test.top->num;
				if (result == 0) {
					printf("0不能作为除数!!!!\n");
					destroyStack(&test);
					break;
				}
				popStack(&test);
				result = test.top->num / result;
				popStack(&test);
				pushStack(&test, 0, result);
				i++;
			}
			else if (temp[i] == '\0') {
				printf("%lf\n", test.top->num);
				popStack(&test);
				break;
			}
		}
		popStack(&test);//释放最后一个数据变为空栈
		printf("回车键继续....");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);

	}
}
Status pushStack(LinkStack* s, char data, double num) {//压栈
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->data = data;
	p1->num = num;
	s->count++;
	return SUCCESS;
}
Status popStack(LinkStack* s) {//出栈
	if (s->top == NULL)
		return SUCCESS;
	s->count--;
	LinkStackPtr p1 = s->top;
	char temp = p1->data;
	s->top = s->top->next;
	free(p1);
	return SUCCESS;
}
Status destroyStack(LinkStack* s) {//销毁
	while (s->top != NULL)
		popStack(s);
	return SUCCESS;
}
double beDouble(char* nums, int* i) {//用来把字符串变为double的函数
	int flag = 1, symbol = 0;//flag用来判断正负号,symbol用来分隔小数点
	double result = 0;
	if (nums[*i] == '-') {
		(*i)++;
		flag = 0;
	}
	if (nums[*i] == '+') {
		(*i)++;
		flag = 1;
	}
	int k = 10;
	while (1) {
		if (nums[*i] == '+' || nums[*i] == '-' || nums[*i] == '*' || nums[*i] == '/' || nums[*i] == ',' || nums[*i] == '\0')
			break;
		else if (nums[*i] == '.') {
			symbol = 1;
			(*i)++;
		}
		else {
			if (symbol == 0)
				result = result * 10 + (double)(nums[(*i)++] - '0');
			else {
				result = result + ((double)(nums[(*i)++] - '0') / k);
				k *= 10;
			}
		}
	}
	if (flag == 0)
		return -result;
	else
		return result;
}