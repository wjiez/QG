#pragma once
void QuickSort(int nums[], int low, int high);//快速排序
void MergeSort(int nums[], int temp[], int low, int high);//归并排序
void InsertSort(int nums[], int size);//插入排序
void CountSort(int nums[], int size);//计数排序
void RadixCountSort(int nums[], int size);//基数排序
void displayMenu(char menu[][200], int size);//显示菜单
void ColorSort();//颜色排序
void LargeAmountTestOne();//随机生成10000数据
void LargeAmountTestTwo();//随机生成50000数据
void LargeAmountTestThree();//随机生成200000数据
void LargeTimesTest();//随机生成数据存放在[100000][100]的二维数组
void SaveDatas();//保存数据
void GetData(int option);//从文件获取数据
void RankSearchRandom();//随机生成数据供选择算法使用
int RankSearch(int nums[], int low, int high, int rank);//快速选择
void QuickSortNonR(int nums[], int low, int high);//非递归快速排序,网上说用栈,但又要重写栈,要不停调用函数,所以我干脆用数组,思路是用一个大数组来存需要排序的两个端点,用-1来标记是否排序完
void BetterBubbleSort(int nums[], int size);//三种优化的冒泡排序
void RandomQuickSort(int nums[], int low, int high);//随机的快速排序
void TriQuickSort(int nums[], int low, int high);//三枢轴的快速排序