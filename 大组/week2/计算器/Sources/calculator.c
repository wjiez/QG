#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include"calculator.h"
char Calculationexpression[200] = "";//����������׺���ʽ
int cacheClean;                                     //��������������ĳн�����
int main() {
	while (1) {
		system("cls");
		printf("�������׼������ʽ(���õȺ�ֱ�ӻس�,��������������,�ݲ�֧�ֱ��ʽ��ǰ����������Ŵ���,ֱ�ӻس���������):\n");
		gets(Calculationexpression);//������׺���ʽ
		LinkStack test = { NULL,0 };//��ʼ����ջ
		char temp[200] = "";//������ź�׺���ʽ
		int i = 0, j = 0, status = 1,judge=1;//��������ı����ƶ�,status��������Ƿ���Ҫ���еڶ�����,judge�������С�����Ƿ�����һ�������ظ�����
		int rnum = 0, lnum = 0;//��������������¼,������򱨴�
		double result = 0; //���ڼ��������ֵ�ļ�¼
		if (Calculationexpression[0] == '\0')
			return 1;
		while (Calculationexpression[i] != '\0') {
			if (Calculationexpression[0] == '*' || Calculationexpression[0] == '/'||Calculationexpression[0]=='+'||Calculationexpression[0]=='-') {
				printf("���ʽ����,����!!!\n");
				status = 0;
				break;
			}
			if (Calculationexpression[i] == '-' || Calculationexpression[i] == '+') {//�ԼӼ��ŵĴ���
				judge = 1;//����С����״̬
				if (test.top == NULL)
					pushStack(&test, Calculationexpression[i], 0);
				else if (Calculationexpression[i - 1] == '+' || Calculationexpression[i - 1] == '-' || Calculationexpression[i - 1] == '*' || Calculationexpression[i - 1] == '/') {//���������򱨴�
					printf("���ʽ����,����!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				else if (test.top->data == '*' || test.top->data == '/') {//���ȼ��Ա�
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
			else if (Calculationexpression[i] == '*' || Calculationexpression[i] == '/') {//�Գ˳��Ŵ���
				judge = 1;
				if (test.top == NULL)
					pushStack(&test, Calculationexpression[i], 0);
				else if (Calculationexpression[i - 1] == '+' || Calculationexpression[i - 1] == '-' || Calculationexpression[i - 1] == '*' || Calculationexpression[i - 1] == '/') {//���������򱨴�
					printf("���ʽ����,����!!!\n");
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
				if (i != 0 && Calculationexpression[i - 1] != '+' && Calculationexpression[i - 1] != '-' && Calculationexpression[i - 1] != '*' && Calculationexpression[i - 1] != '/'&&Calculationexpression[i-1]!='(') {//�����Ϊ��Ԫ��,������ǰ����߲�����������򱨴�
					printf("����������ǰ�Ƿ��������!!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				if (Calculationexpression[i + 1] == '/' || Calculationexpression[i + 1] == '*' ) {
					printf("���ʽ����,����!!!\n");
					status = 0;
					destroyStack(&test);
					break;
				}
				if (Calculationexpression[i + 1] == '-' || Calculationexpression[i + 1] == '+') {//��������Ԫ��Ϊ�Ӽ���Դ����ֽ����������
					temp[j++] = ',';
					temp[j++] = Calculationexpression[++i];
					i++;
					while ((Calculationexpression[i] >= '0' && Calculationexpression[i] <= '9') || Calculationexpression[i] == '.') {
						temp[j++] = Calculationexpression[i++];
					}
					if (Calculationexpression[i] != ')') {//�����ڳ�����������,�����⻹���������ݱ���
						printf("���ʽ����,����!!!\n");
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
			else if (Calculationexpression[i] == ')' && rnum < lnum) {//�����Ŵ���
				if (Calculationexpression[i - 1] > '9' || Calculationexpression[i - 1] < '0') {
					printf("���ʽ����,����!!!\n");
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
			else if ((Calculationexpression[i] >= '0' && Calculationexpression[i] <= '9') || Calculationexpression[i] == '.') {//���ִ���
				if (Calculationexpression[i] == '.') {
					if (i == 0 || Calculationexpression[i - 1] > '9' || Calculationexpression[i - 1] < '0'||Calculationexpression[i+1]>'9'||Calculationexpression[i+1]<'0' || judge == 0) {//С����ǰ�����������,��һ�������ַ���С���㲻���ظ�����,���򱨴�,
						printf("���ʽ����,����!!!\n");
						destroyStack(&test);
						status = 0;
						break;
					}
					else {
						temp[j++] = '.';
						judge = 0;                  //�����־���������Ѿ�������һ��С����
					}		
				}
				else if (i != 0 && ((Calculationexpression[i - 1] >= '0' && Calculationexpression[i - 1] <= '9') || Calculationexpression[i - 1] == '.'))//�����һ���ַ�Ϊ���ֻ�С�������ֱ�Ӵ���,�����ö��Ÿ���
					temp[j++] = Calculationexpression[i];
				else {
					temp[j++] = ',';//��ͬ�ַ�������֮����һ�����Ÿ���,
					temp[j++] = Calculationexpression[i];
				}
			}
			else {//�����Ϊ�������еķ����򱨴�
				destroyStack(&test);
				printf("������δ֪���Ż����Ų�ƥ��,����!!!!\n");
				status = 0;
				break;
			}
			i++;
		}
		if ( status == 1&&i-1>=0&&(Calculationexpression[i-1] == '*' || Calculationexpression[i-1] == '/' || Calculationexpression[i-1] == '+' || Calculationexpression[i-1] == '-')) {//����ʽβ���м�����ű���
			printf("���ʽ����,����!!!\n");
			destroyStack(&test);
			status = 0;
		}
		if (status==1&&rnum != lnum) {//�������Ų�ƥ�䱨��
			destroyStack(&test);
			printf("����������ƥ��,����!!!\n");
			status = 0;
		}
		while (status) {//�������ȫ�������׺���ʽ
			if (test.top == NULL)
				break;
			temp[j++] = test.top->data;
			popStack(&test);
		}
		i = 0;
		while (status) {//״̬��ȷ����к�׺���ʽ����
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
					printf("0������Ϊ����!!!!\n");
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
		popStack(&test);//�ͷ����һ�����ݱ�Ϊ��ջ
		printf("�س�������....");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);

	}
}
Status pushStack(LinkStack* s, char data, double num) {//ѹջ
	LinkStackPtr p1 = (LinkStackPtr)malloc(sizeof(StackNode));
	p1->next = s->top;
	s->top = p1;
	p1->data = data;
	p1->num = num;
	s->count++;
	return SUCCESS;
}
Status popStack(LinkStack* s) {//��ջ
	if (s->top == NULL)
		return SUCCESS;
	s->count--;
	LinkStackPtr p1 = s->top;
	char temp = p1->data;
	s->top = s->top->next;
	free(p1);
	return SUCCESS;
}
Status destroyStack(LinkStack* s) {//����
	while (s->top != NULL)
		popStack(s);
	return SUCCESS;
}
double beDouble(char* nums, int* i) {//�������ַ�����Ϊdouble�ĺ���
	int flag = 1, symbol = 0;//flag�����ж�������,symbol�����ָ�С����
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