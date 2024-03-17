#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"bigTrainingTask.h"
singleNode* singleHead = NULL;
doubleNode* doubleHead = NULL;                      //本程序单双链表都只各用一个链表,所以预先构建链表的头
int cacheClean;                                     //用于清除缓存区的承接数据
int operationNum = 0;                               //操作序号存放
char Menu[4][27] = {                                                                //各个菜单的内容
	"1.单链表",
	"2.双向链表",
	"3.结束程序",
	"(请输入操作序号)"
};
char Menu1[13][27] = {
	"1.创建单链表",
	"2.遍历单链表",
	"3.销毁单链表",
	"4.插入新节点",
	"5.删除某节点",
	"6.查询某数据",
	"7.节点奇偶对换",
	"8.查找链表中间节点",
	"9.判断链表是否成环",
	"10.反转链表(非递归)",
	"11.反转链表(递归)",
	"12.返回上一步",
	"(请输入操作序号)"
};
char Menu2[8][27] = {
	"1.创建双向链表",
	"2.遍历双向链表",
	"3.销毁双向链表",
	"4.插入新的节点",
	"5.删除某个节点",
	"6.查找某个内容",
	"7.返回上一步",
	"(请输入操作序号)"
};
int main() {
	while (1) {
		system("cls");
		displayMenu(Menu, 4);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //读取回车键并清除缓存区
		switch (operationNum) {
		case 1:
			singleLinkedList();                                       //进入单链表内容
			break;
		case 2:
			doubleLinkedList();
			break;
		case 3:
			return 1;
		default:
			printf("输入错误!!!请重新输入!!!");
			Sleep(800);
		}
	}
}
void displayMenu(char menu[][27], int size) {
	for (int i = 0; i < size; i++) {
		printf("%s\n", menu[i]);
	}
}
singleNode* singleNodeGeneration() {                                              //构建单链表
	system("cls");
	if (singleHead != NULL) {
		printf("单链表已经创建过了,可先销毁再创建(按回车返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
		return NULL;

	}
	printf("请输入一个字符(输入#则结束构建):\n");                       //设置构建结束标志
	singleNode* p1 = singleHead, * p2;
	p2 = (singleNode*)malloc(sizeof(singleNode));
	singleHead = p2;
	p2->data = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                        //两个getchar中间的回车会被读取,所以用此来过渡
	while (p2->data != '#') {
		printf("请输入一个字符(输入#则结束构建):\n");
		p1 = p2;
		p2 = (singleNode*)malloc(sizeof(singleNode));
		p1->next = p2;
		p2->data = getchar();
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                   //两个getchar中间的回车会被读取,所以用此来过渡
	}
	free(p2);                                                          //释放最后一个字符为#的节点
	if (p1 != NULL)                                                    //如果一开始就输入#那么p1=NULL,即head为null,为空链表
		p1->next = NULL;
	else
		singleHead = NULL;
	printf("构建成功\n");
	Sleep(800);
	return singleHead;
}
singleNode* singleNodeDestroy() {                                               //链表的销毁
	system("cls");
	if (singleHead == NULL) {
		printf("链表为空!!!");
		Sleep(800);
		return NULL;
	}
	singleNode* p1 = singleHead, * p2 = singleHead;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	singleHead = NULL;
	printf("销毁成功!!");
	Sleep(800);
	return singleHead;
}
int nodeDisplay(int flag) {                                         //决定于遍历单链表还是双链表,返回一个数字表示链表内节点个数
	int local = 0;                                                   //记录数据相对位置
	if (flag == 0) {
		singleNode* p1 = singleHead;
		if (singleHead == NULL) {
			printf("链表为空\n");
			return 0;
		}
		printf("序号\t内容\n");
		while (p1 != NULL) {
			printf("%d\t%c\n", ++local, p1->data);
			p1 = p1->next;
		}
	}
	if (flag == 1) {
		doubleNode* p1 = doubleHead;
		if (doubleHead == NULL) {
			printf("链表为空\n");
			return 0;
		}
		printf("序号\t内容\n");
		while (p1 != NULL) {
			printf("%d\t%c\n", ++local, p1->data);
			p1 = p1->next;
		}
	}
	return local;                                                      //返回节点个数
}
singleNode* singleNodeInsert() {                                                 //节点的插入
	system("cls");
	if (singleHead == NULL) {
		printf("单链表还未创建!!!!请先创建链表!!!!");
		Sleep(1100);
		return NULL;
	}
	while (1) {
		system("cls");
		printf("1.头部插入\n2.中间插入\n3.尾部插入\n请输入插入方式:\n");
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                      //读取回车键并清除缓存区
		if (operationNum == 1) {                                          //头部插入
			singleNode* p1 = (singleNode*)malloc(sizeof(singleNode));
			p1->next = singleHead;
			singleHead = p1;
			printf("请输入插入的一个字符:\n");
			p1->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //读取回车键并清除缓存区
			break;
		}
		else if (operationNum == 2) {                                     //中间插入   
			system("cls");
			if (singleHead->next == NULL) {
				printf("链表中只有一个节点请选择头部插入或者尾部插入\n");
				Sleep(1500);
				continue;
			}
			int maxNum = nodeDisplay(0);                                    //记录节点个数以便于管理输入值越界问题
			int low = 0, high = 0;
			while (1) {
				printf("请从小到大输入两个相邻的序号(空格隔开):\n");
				scanf("%d %d", &low, &high);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (high - low == 1 && high <= maxNum && low >= 1) {          //处理好超界问题
					singleNode* p1 = (singleNode*)malloc(sizeof(singleNode));
					singleNode* p2 = singleHead;
					int num = 0;
					while (++num != low) {                                   //指针移到对应位置
						p2 = p2->next;
					}
					p1->next = p2->next;
					p2->next = p1;
					printf("请输入插入的一个字符:\n");
					p1->data = getchar();
					while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //读取回车键并清除缓存区
					break;
				}
				else {
					printf("输入错误!!!!请检查是否符合规则!!!!\n");
				}
			}
			break;
		}
		else if (operationNum == 3) {                                            //尾部插入
			singleNode* p1 = singleHead, * p2;
			p2 = (singleNode*)malloc(sizeof(singleNode));
			while (p1->next != NULL) {
				p1 = p1->next;
			}
			printf("请输入插入的一个字符:\n");
			p2->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			p1->next = p2;
			p2->next = NULL;
			break;
		}
		else {
			printf("输入错误!!!请从新输入!!!");
			Sleep(800);
		}
	}

	printf("插入成功!!!");
	Sleep(600);
	return singleHead;
}
singleNode* singleNodeDelete() {                                                  //节点删除
	system("cls");
	if (singleHead == NULL) {
		printf("链表为空!!!!请先创造链表!!!!");
		Sleep(1000);
		return NULL;
	}
	singleNode* p1 = singleHead;
	int num = 0;                                                      //用于承接输入的节点序号
	int maxNum = nodeDisplay(0);                                     //记录节点个数以便于后续操作
	while (1) {
		printf("请输入要删除节点的序号:\n");
		scanf("%d", &num);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (num == 1) {                                             //删除头节点特殊处理
			singleHead = p1->next;
			free(p1);
			break;
		}
		else if (num > 1 && num <= maxNum) {
			int index = 0;
			singleNode* p2 = NULL;
			while (++index != num - 1) {                             //用序号来追踪目标节点
				p1 = p1->next;
			}
			p2 = p1->next;
			p1->next = p2->next;
			free(p2);
			break;
		}
		else {
			printf("输入错误!!!!请检查输入是否合规!!!\n");
		}
	}
	printf("删除成功!!!!");
	Sleep(1000);
	return singleHead;
}
singleNode* singleNodeSearch() {
	system("cls");
	int flag = 0;                                                      //判断是否存在节点的一个标志
	if (singleHead == NULL) {
		printf("为空链表!!!!");
		Sleep(1000);
		return NULL;
	}
	printf("请输入要查询的一个字符:\n");
	char OBJ = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	singleNode* p1 = singleHead;
	while (p1 != NULL) {
		if (p1->data == OBJ) {
			flag = 1;                                                 //存在查询值则改变标志的值
			break;
		}
		p1 = p1->next;
	}
	if (flag == 1) {
		printf("链表中有此字符!!(按回车键返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return p1;
	}
	else {
		printf("链表中没有此字符!!!!(按回车返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return NULL;
	}
}
singleNode* parityExchange() {
	if (singleHead == NULL) {
		printf("为空链表!!!!请先创建链表!!!");
		Sleep(1000);
		return NULL;
	}
	if (singleHead->next == NULL)                                         //链表中只有一个内容,可直接返回
		return singleHead;
	singleNode* p1 = singleHead, * p2 = p1->next, * p3 = singleHead->next;                  //用三个指针,p2,p3用来交换,p1用来保存上一个指针
	singleHead = p3;
	p1->next = p2->next;
	p2->next = p1;
	p2 = p1->next;
	if (p2 == NULL)
		return singleHead;
	p3 = p2->next;                                                           //特殊处理前两个的对换
	while (p3 != NULL) {
		p1->next = p3;
		p2->next = p3->next;
		p3->next = p2;
		p1 = p2;
		p2 = p2->next;
		if (p2 == NULL)
			return singleHead;
		p3 = p2->next;
	}
	printf("奇偶对换成功!!!!");
	Sleep(800);
	return singleHead;
}
singleNode* middleSearch() {                                               //快慢指针
	system("cls");
	if (singleHead == NULL) {
		printf("为空链表!!!!");
		Sleep(800);
		return singleHead;
	}
	singleNode* p1 = singleHead, * p2 = singleHead;
	while (p1 != NULL) {
		p1 = p1->next;
		if (p1 == NULL)
			break;
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("此为中间节点往后打印的结果:\n");                            //从中间节点往后打印以便检验
	int num = 0;
	printf("序号\t内容\n");
	while (p2 != NULL) {
		printf("%d\t%c\n", ++num, p2->data);
		p2 = p2->next;
	}
	printf("(回车键返回上一步)");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	return p2;
}
void circleJudge() {                                              //快慢指针最后是否为NULL或者相遇来判断是否为循环指针
	if (singleHead == NULL) {
		printf("为空链表!!!");
		Sleep(800);
	}
	singleNode* p1 = singleHead, * p2 = singleHead, * p3 = singleHead;
	while (1) {
		system("cls");
		printf("1.链表尾连头,测试判断机制(之后会去循环化,此仅仅用于测试的个例)\n2.直接判断此单链表是否为循环链表\n请输入操作序号:\n");//设置一个例子来测试判断功能
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (operationNum == 1) {
			if (singleHead->next == NULL) {
				printf("链表中只有一个节点不可用此功能!!!!\n");
				Sleep(1000);
				continue;
			}
			while (p3->next != NULL) {
				p3 = p3->next;
			}
			p3->next = singleHead;                                       //尾连头
			break;
		}
		else if (operationNum == 2) {
			break;
		}
		else {
			printf("输入错误!!!请检查输入是否合规!!!\n");
			Sleep(1000);
		}
	}
	while (p2 != NULL) {
		p2 = p2->next;
		if (p2 == NULL)
			break;
		p2 = p2->next;
		if (p1 == p2) {
			printf("此链表是循环链表(回车返回上一步)");
			if (operationNum == 1) {
				p3->next = NULL;                                   //去除连接
			}
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			return;
		}
	}
	printf("此链表不为循环链表(回车返回上一步)");
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
}
singleNode* singleNodeReversal() {                                           //反转链表,非递归
	system("cls");
	if (singleHead == NULL) {
		printf("为空链表!!");                                       //空链表返回NULL
		Sleep(1000);
		return NULL;
	}
	if (singleHead->next == NULL) {
		printf("反转成功");                                          //链表中只有一个节点,直接返回头指针
		Sleep(800);
		return singleHead;
	}
	singleNode* p1 = singleHead, * p2 = singleHead->next, * p3 = p2->next;
	p1->next = NULL;                                                  //用三个指针,先特殊处理前两个指针
	while (p3 != NULL) {
		p2->next = p1;
		p1 = p2;
		p2 = p3;                                                      //p2用于连接,p1和p3作桥梁供移动
		p3 = p3->next;
	}
	p2->next = p1;
	singleHead = p2;
	printf("反转成功!");
	Sleep(800);
	return singleHead;
}
singleNode* singleNodeReversalRecursion(singleNode* Head) {                         //递归反转
	if (Head == NULL || Head->next == NULL) {
		return Head;                                                //在拿到全部节点后返回最后一个节点
	}
	singleNode* p1 = Head->next;
	singleNode* p2 = singleNodeReversalRecursion(p1);
	p1->next = Head;                                                 //拿完全部节点后,开始逐步连接
	Head->next = NULL;
	return p2;                                                      //拿到最后一个节点不停的返回它,作为反转后的头节点
}
void singleLinkedList() {                                           //单链表内容
	while (1) {
		system("cls");
		displayMenu(Menu1, 13);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //读取回车键并清除缓存区
		switch (operationNum) {
		case 1:
			singleNodeGeneration();
			break;
		case 2:
			system("cls");
			nodeDisplay(0);
			printf("按回车返回上一步");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);            //读取回车键并清除缓存区
			break;
		case 3:
			singleNodeDestroy();
			break;
		case 4:
			singleNodeInsert();
			break;
		case 5:
			singleNodeDelete();
			break;
		case 6:
			singleNodeSearch();
			break;
		case 7:
			parityExchange();
			break;
		case 8:
			middleSearch();
			break;
		case 9:
			circleJudge();
			break;
		case 10:
			singleNodeReversal();
			break;
		case 11:
			singleHead = singleNodeReversalRecursion(singleHead);
			system("cls");
			printf("反转成功");
			Sleep(800);
			break;
		case 12:
			return;
		default:
			printf("输入错误!!!请重新输入!!!");
			Sleep(800);
		}
	}
}
doubleNode* doubleNodeGeneration() {
	system("cls");
	if (doubleHead != NULL) {
		printf("双向链表已经创建过了,可先销毁再创建(按回车返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
		return NULL;

	}
	printf("请输入一个字符(输入#则结束构建):\n");                       //设置构建结束标志
	doubleNode* p1 = doubleHead, * p2;
	p2 = (doubleNode*)malloc(sizeof(doubleNode));
	doubleHead = p2;
	p2->previous = NULL;
	p2->data = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                        //两个getchar中间的回车会被读取,所以用此来过渡
	while (p2->data != '#') {
		printf("请输入一个字符(输入#则结束构建):\n");
		p1 = p2;
		p2 = (doubleNode*)malloc(sizeof(doubleNode));
		p1->next = p2;
		p2->previous = p1;
		p2->data = getchar();
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                   //两个getchar中间的回车会被读取,所以用此来过渡
	}
	free(p2);                                                          //释放最后一个字符为#的节点
	if (p1 != NULL)                                                    //如果一开始就输入#那么p1=NULL,即head为null,为空链表
		p1->next = NULL;
	else
		doubleHead = NULL;
	printf("构建成功\n");
	Sleep(800);
	return doubleHead;
}
doubleNode* doubleNodeDestroy() {                                               //链表的销毁
	system("cls");
	if (doubleHead == NULL) {
		printf("链表为空!!!");
		Sleep(800);
		return NULL;
	}
	doubleNode* p1 = doubleHead, * p2 = doubleHead;
	while (p1 != NULL) {
		p2 = p1->next;
		free(p1);                                                      //全部释放
		p1 = p2;
	}
	doubleHead = NULL;
	printf("销毁成功!!");
	Sleep(800);
	return doubleHead;
}
doubleNode* doubleNodeInsert() {
	system("cls");
	if (doubleHead == NULL) {
		printf("双向链表还未创建!!!!请先创建链表!!!!");
		Sleep(1100);
		return NULL;
	}
	while (1) {
		system("cls");
		printf("1.头部插入\n2.中间插入\n3.尾部插入\n请输入插入方式:\n");
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                      //读取回车键并清除缓存区
		if (operationNum == 1) {                                          //头部插入
			doubleNode* p1 = (doubleNode*)malloc(sizeof(doubleNode));
			p1->next = doubleHead;
			doubleHead->previous = p1;
			p1->previous = NULL;
			doubleHead = p1;
			printf("请输入插入的一个字符:\n");
			p1->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                  //读取回车键并清除缓存区
			break;
		}
		else if (operationNum == 2) {                                     //中间插入   
			system("cls");
			if (doubleHead->next == NULL) {
				printf("链表中只有一个节点请选择头部插入或者尾部插入\n");
				Sleep(1500);
				continue;
			}
			int maxNum = nodeDisplay(1);                                    //记录节点个数以便于后续操作
			int low = 0, high = 0;
			while (1) {
				printf("请从小到大输入两个相邻的序号(空格隔开):\n");
				scanf("%d %d", &low, &high);
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
				if (high - low == 1 && high <= maxNum && low >= 1) {          //处理好超界问题
					doubleNode* p1 = (doubleNode*)malloc(sizeof(doubleNode));
					doubleNode* p2 = doubleHead;
					int num = 0;
					while (++num != low) {                                   //指针移到对应位置
						p2 = p2->next;
					}
					p1->next = p2->next;
					p2->next = p1;
					p1->previous = p2;
					p2 = p1->next;
					if (p2 != NULL)
						p2->previous = p1;
					printf("请输入插入的一个字符:\n");
					p1->data = getchar();
					while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //读取回车键并清除缓存区
					break;
				}
				else {
					printf("输入错误!!!!请检查是否符合规则!!!!\n");
				}
			}
			break;
		}
		else if (operationNum == 3) {                                            //尾部插入
			doubleNode* p1 = doubleHead, * p2;
			p2 = (doubleNode*)malloc(sizeof(doubleNode));
			while (p1->next != NULL) {
				p1 = p1->next;
			}
			printf("请输入插入的一个字符:\n");
			p2->data = getchar();
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			p1->next = p2;
			p2->previous = p1;
			p2->next = NULL;
			break;
		}
		else {
			printf("输入错误!!!请从新输入!!!");
			Sleep(800);
		}
	}

	printf("插入成功!!!");
	Sleep(600);
	return doubleHead;
}
doubleNode* doubleNodeDelete() {                                                  //节点删除
	system("cls");
	if (doubleHead == NULL) {
		printf("链表为空!!!!请先创造链表!!!!");
		Sleep(1000);
		return NULL;
	}
	doubleNode* p1 = doubleHead;
	int num = 0;                                                      //用于承接输入的节点序号
	int maxNum = nodeDisplay(1);                                     //记录节点个数以便于后续操作
	while (1) {
		printf("请输入要删除节点的序号:\n");
		scanf("%d", &num);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (num == 1) {                                             //删除头节点特殊处理
			doubleHead = p1->next;
			if (doubleHead != NULL)
				doubleHead->previous = NULL;
			free(p1);
			break;
		}
		else if (num > 1 && num <= maxNum) {
			int index = 0;
			doubleNode* p2 = NULL;
			while (++index != num - 1) {
				p1 = p1->next;
			}
			p2 = p1->next;
			if (p2->next != NULL) {
				p2 = p2->next;
				p2->previous = p1;
				p2 = p1->next;
			}
			p1->next = p2->next;
			free(p2);
			break;
		}
		else {
			printf("输入错误!!!!请检查输入是否合规!!!\n");
		}
	}
	printf("删除成功!!!!");
	Sleep(1000);
	return doubleHead;
}
doubleNode* doubleNodeSearch() {
	system("cls");
	int flag = 0;                                                      //判断是否存在节点的一个标志
	if (doubleHead == NULL) {
		printf("为空链表!!!!");
		Sleep(1000);
		return NULL;
	}
	printf("请输入要查询的一个字符:\n");
	char OBJ = getchar();
	while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
	doubleNode* p1 = doubleHead;
	while (p1 != NULL) {
		if (p1->data == OBJ) {
			flag = 1;                                                 //存在查询值则改变标志的值
			break;
		}
		p1 = p1->next;
	}
	if (flag == 1) {
		printf("双向链表中有此字符!!(按回车键返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return p1;
	}
	else {
		printf("双向链表中没有此字符!!!!(按回车返回上一步)");
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		return NULL;
	}
}
void doubleLinkedList() {
	while (1) {
		system("cls");
		displayMenu(Menu2, 8);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                //读取回车键并清除缓存区
		switch (operationNum) {
		case 1:
			doubleNodeGeneration();
			break;
		case 2:
			system("cls");
			nodeDisplay(1);
			printf("按回车返回上一步");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);            //读取回车键并清除缓存区
			break;
		case 3:
			doubleNodeDestroy();
			break;
		case 4:
			doubleNodeInsert();
			break;
		case 5:
			doubleNodeDelete();
			break;
		case 6:
			doubleNodeSearch();
			break;
		case 7:
			return;
		default:
			printf("输入错误!!!请重新输入!!!");
			Sleep(800);
		}
	}
}