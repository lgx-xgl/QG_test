#include "sort.h"
void insertSort(int* a, int n)									//��������(��������)
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

void MergeArray(int* a, int begin, int mid, int end, int* temp)	//�鲢���򣨺ϲ����飩
{
	mid += 1;										//mid������������λ��
	int p = begin, q = mid,t=begin;
	while (p != mid && q != end + 1)
	{
		if (a[p] <= a[q]) {							//˭С˭����
			temp[t] = a[p];
			++p;
		}
		else {
			temp[t] = a[q];
			++q;
		}
		++t;
	}
	if (p == mid) {									//�����������ˣ�������ȫ��
		while (q != end + 1) {
			temp[t] = a[q];
			++q;
			++t;
		}
	}
	if (q == end + 1) {									//�����������ˣ�������ȫ��
		while (p != mid ) {
			temp[t] = a[p];
			++p;
			++t;
		}
	}
	for (int i = begin; i <= end; ++i) {			//������ԭ������
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)			//�鲢����
{

	if (begin >= end)return;					//�ֵ���С��,��һ��������
	int mid = (begin + end) / 2;				
	MergeSort(a, begin, mid, temp);				//ʹ������
	MergeSort(a, mid + 1, end, temp);			//ʹ������
	MergeArray(a, begin, mid, end, temp);
}

void QuickSort_Recursion(int* a, int begin, int end)			//��������(�ݹ��)
{
	if (begin >= end) return;
	int mid=Partition(a, begin, end);
	QuickSort_Recursion(a, begin, mid - 1);
	QuickSort_Recursion(a, mid + 1, end);
}

void QuickSort(int* a, int size)								//���ţ��ǵݹ�棩
{
	stack <int> s_q;											//��ջ���淶Χ
	s_q.push(0);
	s_q.push(size - 1);
	int begin, end;
	while (!s_q.empty()) {
		end = s_q.top();
		s_q.pop();
		begin = s_q.top();
		s_q.pop();
		int mid = Partition(a, begin, end);
		if (begin < mid - 1) {									//ֻ��begin<mid-1���������Ҫ��¼��Χ
			s_q.push(begin);
			s_q.push(mid - 1);
		}
		if (mid + 1 < end) {
			s_q.push(mid + 1);
			s_q.push(end);
		}
	}
}

int Partition(int* a, int begin, int end)						//������
{
	int t = a[begin],p=begin,q=end,k;
	while (p < q) {												//�����qһ����p���ұߣ��������м����a[begin]��λ��
		while (a[p] < t) ++p;									//���һ��ҪС����
		while (a[q] > t) --q;									//�ұߴ�����
		if (p == q) break;
		k = a[p];												//��������
		a[p] = a[q];
		a[q] = k;
		if (a[p] == a[q])++p;									//������Ϊ��������ȣ���������ѭ��
	}
	return q;													//�������λ��
}

int Find_Max(int* a,int size)
{
	int Max = -0xffffff;
	for (int i = 0; i < size; ++i) {
		Max = max(Max, a[i]);
	}
	return Max;
}

void CountSort(int* a, int size, int max)						//��������
{
	max++;
	int* temp1 = new int[max];
	memset(temp1, 0, max*sizeof(int));							//���˳�ʼ���Ŀ�
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

void RadixCountSort(int* a, int size)							//������������
{
	int Max = 0,Min=0xffffff;
	int* tong = new int[10];
	int* b = new int[size];
	for (int i = 0; i < size; ++i) {
		Min = min(Min, a[i]);
		Max = max(Max, a[i]);
	}
	if (Min < 0) {												//ͨ������һ����С������ʹ����������
		for (int i = 0; i < size; ++i) {
			a[i] -= Min;
		}
	}
	int ex = 1;
	while (Max) {
		Max /= 10;
		ex *= 10;
	}
	ex /= 10;													//ex��Max���λ
	int k;
	for (int i = 1; i <= ex; i*=10) {
		memset(tong, 0, 10 * sizeof(int));						//��ǰ��ʼ��
		for (int j = 0; j < size; ++j) {						//��ÿһ�����Ĵ�λȡ��
			k = a[j] / i % 10;
			++tong[k];
		}
		for (int j = 1; j < 10; ++j) tong[j] += tong[j - 1];	//���ü�����������
		for (int j = size-1; j >=0; --j) {
			k = a[j] / i % 10;
			tong[k]--;
			b[tong[k]] = a[j];
		}
		for (int j = 0; j < size; ++j) a[j] = b[j];
	}
	if (Min < 0) {												//ǰ�������һ����С���������ڼӻ���
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


void ColorSort(int* a, int size)								//��ɫ����
{
	int p = 0, q = size - 1, t,now;							//p��ǰ���0��q�ĺ����2
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
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
		cout << "��Ĳ��������Ⱑ,�����������" << endl;
	}
	return OP;
}

void COUT(int *a,int size)
{
	cout << "ת���������Ϊ" << endl;;
	for (int i = 0; i < size; ++i) {
		cout << a[i]<<" ";
	}
	cout << endl;
}

int QuickSort_Recursion(int* a, int begin, int end,int k)			//��������(���ذ�)
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