#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<math.h>
#include<time.h>
#include"bigTraining3.h"
int cacheClean;                                     //用于清除缓存区的承接数据
int TestOne[10000] = { 0 }, TestTwo[50000] = { 0 }, TestThree[200000] = { 0 }, TestFour[100000][100] = { 0 }, temp[200000] = { 0 };//大数据存放地方
int operationNum = 0;                               //操作序号存放
int Amount = 0;                                     //用于记录提供文件的数据量
char Menu[17][200] = {                                                                //各个菜单的内容
	"1.生成随机数并保存到文件(data.txt)",
	"2.生成随机数据但不保存",
	"3.再次从文件读取已经随机生成的数据",
	"4.读取外部文件数据供排序(最多只会读取文件中200000个数据,之后的测试会优先使用此数据,不会改变文件数据)",
	"5.测试快速排序时间",
	"6.测试归并排序时间",
	"7.测试插入排序时间",
	"8.测试计数排序时间",
	"9.测试基数排序时间",
	"10.颜色排序",
	"11.找到第k小的数",
	"12.测试快速排序(非递归)",
	"13.测试优化的冒泡排序",
	"14.测试随机枢轴的快速排序",
	"15.测试三枢轴的快速排序",
	"16.结束程序",
	"(请输入操作序号)"
};
int main() {
	int flag = 0, judge = 0;//flag用于判断是否有数据可供排序,且判断是何种数据形式,judge用来判断是否生成过随机数
	srand((unsigned)time(NULL));
	while (1) {
		system("cls");
		displayMenu(Menu, 17);
		scanf("%d", &operationNum);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
		switch (operationNum)
		{
		case 1://生成随机数并保存到文件
			printf("保存26万数据中请稍等.....\n");
			LargeAmountTestOne();
			LargeAmountTestTwo();
			LargeAmountTestThree();
			LargeTimesTest();
			SaveDatas();
			printf("生成数据成功并保存成功!!!");
			Sleep(500);
			flag = 1;
			judge = 1;
			break;
		case 2:
			LargeAmountTestOne();
			LargeAmountTestTwo();
			LargeAmountTestThree();
			LargeTimesTest();
			printf("生成数据成功!!!");
			Sleep(600);
			flag = 1;
			break;
		case 3://再次读取保存到文件的数据到数组中
			if (judge == 0) {
				printf("请先生成随机数!!!\n");
			}
			else {
				printf("读取数据中请稍等!!!\n");
				GetData(0);
				flag = 1;
			}
			Sleep(500);
			break;
		case 4://从外部文件获取数据
			GetData(1);
			flag = 2;
			break;
		case 5://快速排序的测试
			if (flag == 0) {//没有生成数据,不允许排序
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");       //小数据测试并打印
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				QuickSort(test, 0, 99);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();//分别进行测试计时
				QuickSort(TestOne, 0, 9999);                    //10000数据量测试            
				clock_t diff = clock() - start;                           
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				QuickSort(TestTwo, 0, 49999);                     //50000数据量测试
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				QuickSort(TestThree, 0, 199999);                    //200000数据量测试
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					QuickSort(TestFour[i], 0, 99);                                //少量多次,100000次100数据量
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {//外部文件的数据测试路径
				clock_t start = clock();
				QuickSort(TestThree, 0, Amount - 1);                                           
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 6:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				MergeSort(test, temp,0, 100);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				MergeSort(TestOne, temp, 0,10000);             //10000数据量测试
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				MergeSort(TestTwo, temp, 0, 50000); //50000数据量测试
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				MergeSort(TestThree, temp, 0, 200000); //200000数据量测试
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					MergeSort(TestFour[i], temp, 0, 100);              //少量多次,100000次100数据量
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				MergeSort(TestThree, temp, 0, Amount);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 7:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				InsertSort(test,100);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				InsertSort(TestOne, 10000);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				InsertSort(TestTwo, 50000);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				InsertSort(TestThree, 200000);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					InsertSort(TestFour[i], 100);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				InsertSort(TestThree, Amount);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 8:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				CountSort(test,100);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				CountSort(TestOne, 10000);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				CountSort(TestTwo, 50000);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				CountSort(TestThree, 200000);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					CountSort(TestFour[i], 100);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				CountSort(TestThree, Amount);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 9:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				RadixCountSort(test,100);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				RadixCountSort(TestOne, 10000);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				RadixCountSort(TestTwo, 50000);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				RadixCountSort(TestThree, 200000);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					RadixCountSort(TestFour[i], 100);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				RadixCountSort(TestThree, Amount);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 10:
			system("cls");
			ColorSort();
			printf("\n回车返回菜单\n");
			while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			break;
		case 11:
			RankSearchRandom();
			break;
		case 12:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				QuickSortNonR(test, 0,99);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				QuickSortNonR(TestOne, 0, 9999);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				QuickSortNonR(TestTwo, 0, 49999);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				QuickSortNonR(TestThree, 0, 199999);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					QuickSortNonR(TestFour[i],0, 99);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				QuickSortNonR(TestThree, 0, Amount-1);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 13:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				BetterBubbleSort(test,100);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				BetterBubbleSort(TestOne,10000);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				BetterBubbleSort(TestTwo, 50000);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				BetterBubbleSort(TestThree, 200000);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					BetterBubbleSort(TestFour[i],100);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				BetterBubbleSort(TestThree,Amount );
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 14:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				RandomQuickSort(test, 0, 99);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				RandomQuickSort(TestOne, 0, 9999);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				RandomQuickSort(TestTwo, 0, 49999);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				RandomQuickSort(TestThree, 0, 199999);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					RandomQuickSort(TestFour[i], 0, 99);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				RandomQuickSort(TestThree, 0, Amount - 1);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 15:
			if (flag == 0) {
				printf("没有数据可用,请先选择'1'或'2'或'3'或'4'生成数据\n");
				Sleep(1300);
			}
			else if (flag == 1) {
				system("cls");
				int test[100] = { 0 };
				printf("测试:\n随机生成100个数据:\n");
				for (int i = 0; i < 100; i++) {
					test[i] = rand() % 100;
					printf("%d ", test[i]);
				}
				TriQuickSort(test, 0, 99);
				printf("\n排序后:\n");
				for (int i = 0; i < 100; i++) {
					printf("%d ", test[i]);
				}
				clock_t start = clock();
				TriQuickSort(TestOne, 0, 9999);
				clock_t diff = clock() - start;
				printf("\n排序10000个数据用时:%d ms\n", diff);
				start = clock();
				TriQuickSort(TestTwo, 0, 49999);
				diff = clock() - start;
				printf("排序50000个数据用时:%d ms\n", diff);
				start = clock();
				TriQuickSort(TestThree, 0, 199999);
				diff = clock() - start;
				printf("排序200000个数据用时:%d ms\n", diff);
				start = clock();
				for (int i = 0; i < 100000; i++) {
					TriQuickSort(TestFour[i], 0, 99);
				}
				diff = clock() - start;
				printf("排序100000次100个数据用时:%d ms\n", diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);                    //读取回车键并清除缓存区
			}
			else {
				clock_t start = clock();
				TriQuickSort(TestThree, 0, Amount - 1);
				clock_t diff = clock() - start;
				printf("排序%d个数据用时:%d ms\n", Amount, diff);
				flag = 0;
				printf("回车返回菜单\n");
				while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
			}
			break;
		case 16:
			system("pause");
			return 1;
			break;
		default:
			break;
		}
	}
}
void GetData(int option) {//选择获取数据方式
	FILE* p = NULL;
	if (option == 0) {//读取从此程序保存的文件数据
		p = fopen("data.txt", "r");
		for (int i = 0; i < 10000; i++)
			fscanf(p, "%d", &TestOne[i]);
		for (int i = 0; i < 50000; i++)
			fscanf(p, "%d", &TestTwo[i]);
		for (int i = 0; i < 200000; i++)
			fscanf(p, "%d", &TestThree[i]);
		for (int i = 0; i < 100000; i++) {
			for (int j = 0; j < 100; j++) {
				fscanf(p, "%d", &TestFour[i][j]);
			}
		}
	}
	if (option == 1) {//从外部文件读取数据
		Amount = 0;
		printf("请输入读取文件名(带上.txt后缀):\n");
		char FileName[100] = "";
		scanf("%s", FileName);
		p = fopen(FileName, "r");
		if (p == NULL) {
			printf("找不到文件!!!!!\n");
			Sleep(1200);
			return;
		}
		while (!feof(p) && Amount < 200000)
			fscanf(p, "%d", &TestThree[Amount++]);
	}
	printf("读取成功!!!!");
	Sleep(1000);
	if (p != NULL)
		fclose(p);

}
void SaveDatas() {//保存数据
	FILE* p;
	p = fopen("data.txt", "w");
	for (int i = 0; i < 10000; i++)
		fprintf(p, "%d ", TestOne[i]);
	for (int i = 0; i < 50000; i++)
		fprintf(p, "%d ", TestTwo[i]);
	for (int i = 0; i < 200000; i++)
		fprintf(p, "%d ", TestThree[i]);
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100; j++) {
			fprintf(p, "%d ", TestFour[i][j]);
		}
	}
	fclose(p);
}
void displayMenu(char menu[][200], int size) {
	for (int i = 0; i < size; i++) {
		printf("%s\n", menu[i]);
	}
}
void MergeSort(int nums[], int temp[], int low, int high) {
	if (high <= low + 1)return;            //归
	int mid = low + ((high - low) >> 1);
	MergeSort(nums, temp, low, mid);         //分
	MergeSort(nums, temp, mid, high);        
	int i = low, j = mid, k = low;
	while (i < mid && j <high) {               //合
		temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	}
	while (i < mid) {                        //加上剩下的
		temp[k++] = nums[i++];
	}
	while (j <high) {                       //加上剩下的
		temp[k++] = nums[j++];
	}
	for (int i = low; i < high; ++i) {    //复制
		nums[i] = temp[i];
	}
}
void InsertSort(int nums[], int size) {
	for (int movingNum = 1, i, temp; movingNum < size; movingNum++) {  //移动数据从前往后
		temp = nums[movingNum];                                
		for (i = movingNum - 1; i >= 0; i--) {                
			if (temp < nums[i])                       //遇到大的覆盖到后面一位
				nums[i + 1] = nums[i];
			else                                      //遇到小的移动停止循环,数据插入
				break;
		}
		nums[i + 1] = temp;
	}
}
void CountSort(int nums[], int size) {
	int max = nums[0], min = nums[0];
	for (int i = 0; i < size; i++) {     //得到最大最小值
		if (nums[i] > max)
			max = nums[i];
		if (nums[i] < min)
			min = nums[i];
	}
	int* countNum = (int*)calloc(max - min + 1, sizeof(int));   //计数和统计数组
	int* temp = (int*)malloc(size * sizeof(int));               //暂存数组
	for (int i = 0; i < size; i++) {
		countNum[nums[i] - min]++;
	}
	for (int i = 1; i <= max - min; i++)
		countNum[i] = countNum[i] + countNum[i - 1];            
	for (int i = size - 1; i >= 0; i--) {
		int index = nums[i] - min;
		temp[countNum[index] - 1] = index + min;             //根据统计数组放元素
		countNum[index]--;
	}
	for (int i = 0; i < size; i++)
		nums[i] = temp[i];                                  //复制
	free(countNum);
}
void RadixCountSort(int nums[], int size)
{
	int max = nums[0], opnum = 0;             
	for (int i = 0; i < size; i++) {                 //得到最大数
		if (nums[i] > max)
			max = nums[i];
	}
	while (max != 0) {                        //计算最大位数
		max /= 10;                          
		opnum++;
	}
	int index, base = 1, i, j, n;                   
	int* temp = (int*)calloc(size, sizeof(int));    //暂存数组
	int* counts = (int*)calloc(10, sizeof(int));    //计数统计数组
	for (n = 0; n < opnum; n++)                     //n为记录需要排序趟数,趟数根据最高位数决定
	{
		for (i = 0; i < 10; i++)                    //每一趟计数数组都要重置为0
			counts[i] = 0;
		for (j = 0; j < size; j++)                  //计数数组
		{
			index = (int)(nums[j] / base) % 10;        
			counts[index]++;
		}
		for (i = 1; i < 10; i++)
			counts[i] = counts[i] + counts[i - 1];     //统计数组
		for (j = size - 1; j >= 0; j--)
		{
			index = (int)(nums[j] / base) % 10;         //根据统计数组进行排位
			temp[counts[index] - 1] = nums[j];
			counts[index]--;
		}
		base *= 10;                                   //base每次*10以取得不同位数的数据
		for (int i = 0; i < size; i++) {
			nums[i] = temp[i];                           //复制数组
		}
	}
	free(counts);
	free(temp);
}
void LargeAmountTestOne() {   //随机生成数据存放数组内
	srand((unsigned)time(NULL));                          
	for (int i = 0; i < 10000; i++) {
		TestOne[i] = rand() % 1000;
	}
}
void LargeAmountTestTwo() {//随机生成数据存放数组内
	srand((unsigned)time(NULL));
	for (int i = 0; i < 50000; i++) {
		TestTwo[i] = rand() % 1000;
	}
}
void LargeAmountTestThree() {//随机生成数据存放数组内
	srand((unsigned)time(NULL));
	for (int i = 0; i < 200000; i++) {
		TestThree[i] = rand() % 1000;
	}
}
void LargeTimesTest() {//随机生成数据存放数组内
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100; j++) {
			TestFour[i][j] = rand() % 1000;
		}
	}
}
void ColorSort() {
	srand((unsigned)time(NULL));
	int test[50] = { 0 };
	printf("排序前随机生成数据:\n");
	for (int i = 0; i < 50; i++) {
		test[i] = rand() % 3;         //随机获得0,1,2的数据
		printf("%d ", test[i]);
	}
	int zero = 0, one = 0, two = 49, tempNum = 0;  //共三个指标指向数据
	for (; one <= two; one++) {
		if (test[one] == 0) {                      //一指标指向0则与零指标换
			tempNum = test[one];
			test[one] = test[zero];
			test[zero] = tempNum;
			zero++;
		}
		else if (test[one] == 2) {                 //一指标指向2则与二指标换
			tempNum = test[two];
			test[two] = test[one];
			test[one] = tempNum;
			two--;
			one--;
		}
	}
	printf("\n排序后的数据:\n");
	for (int i = 0; i < 50; i++) {
		printf("%d ", test[i]);
	}
}
void RankSearchRandom() {
	system("cls");
	srand((unsigned)time(NULL));
	int test[100] = { 0 }, rank = 0;
	printf("随机生成100个数据:\n");
	for (int i = 0; i < 100; i++) {
		test[i] = rand() % 100;            //随机生成100以内数据
		printf("%d ", test[i]);
	}
	while (1) {
		printf("\n请输入要查询第几小的数据(1-100)(输入-1返回菜单):\n");
		scanf("%d", &rank);
		while ((cacheClean = getchar()) != '\n' && cacheClean != EOF);
		if (rank == -1) {                     //设置返回菜单条件
			return;
		}
		else if (rank <= 100 && rank >= 1) {	
			RankSearch(test, 0, 99, rank);     //进行选择
			printf("\n第%d小的数据为:%d\n", rank, test[rank - 1]);   
			rank = 0;
		}
		else {
			printf("输入错误!!!!");
		}
	}
}
int RankSearch(int nums[], int low, int high, int rank) {
	if (low >= high)return -1;
	int High = high, Low = low;
	while (1) {
		while (++low < High) {
			if (nums[low] > nums[Low])
				break;
		}
		while (high > Low) {
			if (nums[high] < nums[Low])
				break;
			high--;
		}
		if (high <= low)
			break;
		int temp = nums[low];
		nums[low] = nums[high];
		nums[high] = temp;
	}
	int temp = nums[high];
	nums[high] = nums[Low];
	nums[Low] = temp;
	if (high < rank - 1)    //判断最后值位置是否为所需排位位置,不是则只需要再排序一边
		RankSearch(nums, high + 1, High, rank);
	if (high > rank - 1)
		RankSearch(nums, Low, high - 1, rank);
	if (high == rank - 1)
		return nums[high];
	return -1;    //让所有路径都有返回值
}
void QuickSort(int nums[], int low, int high) {
	if (low >= high)return;      //归
	int High = high, Low = low;
	while (1) {
		while (++low < High) {    //低位向高位找
			if (nums[low] > nums[Low])
				break;
		}
		while (high > Low) {      //高位向低位找
			if (nums[high] < nums[Low])
				break;
			high--;
		}
		if (high <= low)          //高低位指标相遇
			break;
		int temp = nums[low];     //交换
		nums[low] = nums[high];
		nums[high] = temp;
	}
	int temp = nums[high];       //交换中枢值
	nums[high] = nums[Low];
	nums[Low] = temp;
	QuickSort(nums, Low, high - 1);      //左右分别继续
	QuickSort(nums, high + 1, High);
}
void QuickSortNonR(int nums[],int low, int high) {//网上说用栈,但又要重写栈,要不停调用函数,所以我干脆用数组,思路是用一个大数组来存需要排序的两个端点,用-1来标记是否排序完
	memset(temp, -1, sizeof(temp));//全局变量数组借用,全部重置为-1
	int index = -1;
	temp[++index] = low;
	temp[++index] = high;
	while (1) {
		if (temp[0] == -1)//第一个元素为0,标志排序全部完成
			break;
		high = temp[index--];
		temp[index + 1] = -1;
		low = temp[index--];
		temp[index + 1] = -1;
		if (low >= high)continue;      //归
		int High = high, Low = low;
		while (1) {
			while (++low < High) {    //低位向高位找
				if (nums[low] > nums[Low])
					break;
			}
			while (high > Low) {      //高位向低位找
				if (nums[high] < nums[Low])
					break;
				high--;
			}
			if (high <= low)          //高低位指标相遇
				break;
			int temp = nums[low];     //交换
			nums[low] = nums[high];
			nums[high] = temp;
		}
		int tempNum = nums[high];       //交换中枢值
		nums[high] = nums[Low];
		nums[Low] = tempNum;
		temp[++index] = Low;       //存放端点
		temp[++index] = high-1;
		temp[++index] = high + 1;
		temp[++index] = High;
	}
}
void BetterBubbleSort(int nums[],int size) {
	int flag = 0,HBoundary=size-1,LBoundary=0,high=size-1,low=0;
	while (low < high) {
		flag = 0;                     //交换标记每次循环开始设为0
		for (int i = low; i <high; i++) {   //从低位到高位的一次排序
			if (nums[i] > nums[i + 1]) {
				int temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
				HBoundary = i;            //记录最后交换边界值
				flag = 1;                //交换过后标志变为1
			}
		}
		high = HBoundary;              //设置边界值
		if (flag == 0)      //没交换过就停止循环
			break;
		flag = 0;                     //交换标记每次循环开始设为0
		for (int i = high; i > low; i--) {
			if (nums[i] < nums[i - 1]) {
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
				LBoundary = i;            //记录最后交换边界值
				flag = 1;
			}
		}
		
		low = LBoundary;               //设置边界值
		if (flag == 0)      //没交换过就停止循环
			break;
	}
}
void RandomQuickSort(int nums[],int low,int high) {
	if (low >= high)return;      //归
	srand((unsigned)time(NULL));
	int High = high, Low = low,MainNum=0,temp;
	MainNum = (rand()%(high-low+1))+low;        //生成范围内随机数
	temp = nums[MainNum];                        //交换随机数位置
	nums[MainNum] = nums[low];                     
	nums[low] = temp;
	while (1) {
		while (++low < High) {    //低位向高位找
			if (nums[low] > nums[Low])
				break;
		}
		while (high > Low) {      //高位向低位找
			if (nums[high] < nums[Low])
				break;
			high--;
		}
		if (high <= low)          //高低位指标相遇
			break;
		int temp = nums[low];     //交换
		nums[low] = nums[high];
		nums[high] = temp;
	}
	temp = nums[high];       //交换中枢值
	nums[high] = nums[Low];
	nums[Low] = temp;
	RandomQuickSort(nums, Low, high - 1);      //左右分别继续
	RandomQuickSort(nums, high + 1, High);
}
void TriQuickSort(int nums[],int low,int high) {
	if (low >= high)return;      //归
	int High = high, Low = low;
	int mid = (low + high) >> 1,MainNum=0,temp;
	if (nums[low] >= nums[high] && nums[high] >= nums[mid])   //找中间值
		MainNum = high;
	else if (nums[low] >= nums[high] && nums[low] <= nums[mid])
		MainNum = low;
	else
		MainNum = mid;
	temp = nums[MainNum];                        //交换位置
	nums[MainNum] = nums[low];
	nums[low] = temp;
	while (1) {
		while (++low < High) {    //低位向高位找
			if (nums[low] > nums[Low])
				break;
		}
		while (high > Low) {      //高位向低位找
			if (nums[high] < nums[Low])
				break;
			high--;
		}
		if (high <= low)          //高低位指标相遇
			break;
		int temp = nums[low];     //交换
		nums[low] = nums[high];
		nums[high] = temp;
	}
	temp = nums[high];       //交换中枢值
	nums[high] = nums[Low];
	nums[Low] = temp;
	TriQuickSort(nums, Low, high - 1);      //左右分别继续
	TriQuickSort(nums, high + 1, High);
}