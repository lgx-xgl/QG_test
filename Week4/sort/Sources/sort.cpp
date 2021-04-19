#include "sort.h"
void insertSort(int* a, int n)									//插入排序(都做升序)
{
	for (int i = 1; i < n; ++i) {
		int j = i,t;
		while (j>0&&a[j] < a[j - 1]) {
			t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;
			--j;
		}
	}
	return;
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)	//归并排序（合并数组）
{
	mid += 1;										//mid变成右数组的首位了
	int p = begin, q = mid,t=begin;
	while (p != mid && q != end + 1)
	{
		if (a[p] <= a[q]) {							//谁小谁先上
			temp[t] = a[p];
			++p;
		}
		else {
			temp[t] = a[q];
			++q;
		}
		++t;
	}
	if (p == mid) {									//左数组上完了，右数组全上
		while (q != end + 1) {
			temp[t] = a[q];
			++q;
			++t;
		}
	}
	if (q == end + 1) {									//右数组上完了，左数组全上
		while (p != mid ) {
			temp[t] = a[p];
			++p;
			++t;
		}
	}
	for (int i = begin; i <= end; ++i) {			//拷贝到原数组中
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)			//归并排序
{

	if (begin >= end)return;					//分到最小了,就一定有序了
	int mid = (begin + end) / 2;				
	MergeSort(a, begin, mid, temp);				//使左有序
	MergeSort(a, mid + 1, end, temp);			//使右有序
	MergeArray(a, begin, mid, end, temp);
}

void QuickSort_Recursion(int* a, int begin, int end)			//快速排序(递归版)
{
	if (begin >= end) return;
	int mid=Partition(a, begin, end);
	QuickSort_Recursion(a, begin, mid - 1);
	QuickSort_Recursion(a, mid + 1, end);
}

void QuickSort(int* a, int size)								//快排（非递归版）
{
	stack <int> s_q;											//用栈来存范围
	s_q.push(0);
	s_q.push(size - 1);
	int begin, end;
	while (!s_q.empty()) {
		end = s_q.top();
		s_q.pop();
		begin = s_q.top();
		s_q.pop();
		int mid = Partition(a, begin, end);
		if (begin < mid - 1) {									//只有begin<mid-1的情况才需要记录范围
			s_q.push(begin);
			s_q.push(mid - 1);
		}
		if (mid + 1 < end) {
			s_q.push(mid + 1);
			s_q.push(end);
		}
	}
}

int Partition(int* a, int begin, int end)						//枢轴存放
{
	int t = a[begin],p=begin,q=end,k;
	while (p < q) {												//到最后q一定在p的右边，它们两中间就是a[begin]的位置
		while (a[p] < t) ++p;									//左边一定要小于轴
		while (a[q] > t) --q;									//右边大于轴
		if (p == q) break;
		k = a[p];												//交换左右
		a[p] = a[q];
		a[q] = k;
		if (a[p] == a[q])++p;									//可能因为两个数相等，发生无限循环
	}
	return q;													//返回轴的位置
}

int Find_Max(int* a,int size)
{
	int Max = -0xffffff;
	for (int i = 0; i < size; ++i) {
		Max = max(Max, a[i]);
	}
	return Max;
}

void CountSort(int* a, int size, int max)						//计数排序
{
	max++;
	int* temp1 = new int[max];
	memset(temp1, 0, max*sizeof(int));							//吃了初始化的亏
	int* b = new int[size];
	for (int i = 0; i < size; ++i) temp1[a[i]]++;
	for (int i = 1; i < max; ++i) {
		temp1[i] += temp1[i - 1];
	}
	for (int i = 0; i < size; ++i) {
		temp1[a[i]]--;
		b[temp1[a[i]]] = a[i];
	}
	for (int i = 0; i < size; ++i) {
		a[i] = b[i];
	}
	return;
}

void RadixCountSort(int* a, int size)							//基数计数排序
{
	int Max = 0,Min=0xffffff;
	int* tong = new int[10];
	int* b = new int[size];
	for (int i = 0; i < size; ++i) {
		Min = min(Min, a[i]);
		Max = max(Max, a[i]);
	}
	if (Min < 0) {												//通过减掉一个最小负数，使所有数变正
		for (int i = 0; i < size; ++i) {
			a[i] -= Min;
		}
	}
	int ex = 1;
	while (Max) {
		Max /= 10;
		ex *= 10;
	}
	ex /= 10;													//ex是Max最高位
	int k;
	for (int i = 1; i <= ex; i*=10) {
		memset(tong, 0, 10 * sizeof(int));						//用前初始化
		for (int j = 0; j < size; ++j) {						//将每一个数的此位取出
			k = a[j] / i % 10;
			++tong[k];
		}
		for (int j = 1; j < 10; ++j) tong[j] += tong[j - 1];	//利用计数排序排序
		for (int j = size-1; j >=0; --j) {
			k = a[j] / i % 10;
			tong[k]--;
			b[tong[k]] = a[j];
		}
		for (int j = 0; j < size; ++j) a[j] = b[j];
	}
	if (Min < 0) {												//前面减掉了一个最小负数，现在加回来
		for (int i = 0; i < size; ++i) {
			a[i] += Min;
		}
	}
	return;
}

bool is_color(int* a, int size)
{
	for (int i = 0; i < size; ++i) {
		if (a[i] >= 3 || a[i] < 0) return false;
	}
	return true;
}


void ColorSort(int* a, int size)								//颜色排序
{
	int p = 0, q = size - 1, t,now;							//p的前面存0，q的后面存2
	while (a[p] == 0) ++p;
	now = p;
	while (now <= q) {
		while (a[p] == 0) ++p;
		while (a[q] == 2) --q;
		while (a[now] == 1) ++now;
		if (now > q) break;
		if (a[now] == 0) {
			t = a[p];
			a[p] = a[now];
			a[now] = t;
		}
		if (a[now] == 2) {
			t = a[q];
			a[q] = a[now];
			a[now] = t;
		}
		//COUT(a, size);
	}
	return;
}

int CIN()
{
	int OP;
	while (!scanf_s("%d", &OP)) {
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
		cout << "你的操作有问题啊,请重新输入吧" << endl;
	}
	return OP;
}

void COUT(int *a,int size)
{
	cout << "转换后的数组为" << endl;;
	for (int i = 0; i < size; ++i) {
		cout << a[i]<<" ";
	}
	cout << endl;
}

int QuickSort_Recursion(int* a, int begin, int end,int k)			//快速排序(重载版)
{
	if (begin >= end) if (begin == end && begin == k) return a[k]; else return 0;
	int mid = Partition(a, begin, end);
	if (mid == k) return a[k];
	int ok = 0;
	if (ok = QuickSort_Recursion(a, begin, mid - 1, k)) return ok;
	if (ok = QuickSort_Recursion(a, mid + 1, end, k)) return ok;
	return 0;
}

int Find_k(int* a, int size, int k)
{
	int* c = new int[size];
	memcpy(c, a, size * sizeof(int));
	return QuickSort_Recursion(c, 0, size - 1, k-1);
}