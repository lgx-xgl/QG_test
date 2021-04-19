#include "sort.h"
int main()
{
	clock_t star, end;
	int OP, size, k, pp = 0, OK, OKK;
	int* a,* temp,* b;
	a = new int;
	b = new int;
	temp = new int;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.自己做一个数列" << endl
			<< "       2.随机生成一个数列" << endl
			<< "       3.随机生成一个特殊数列（只含0.1.2）来测试颜色排列" << endl << endl;
		OP=CIN();
		pp = 1;
		while (OP < 1 || OP > 3 ) {
			cout << "请重新输入"<<endl;
			OP = CIN();
		}
		cout << "请输入你想要的数列的长度"<<endl;
		size = CIN(); 
		while (size <= 0) {
			cout << "请重新输入" << endl;
			size = CIN();
		}
		a = new int[size];
		b = new int[size];
		if (OP == 1) {
			cout << "请输入你的数组"<<endl;
			for (int i = 0; i < size; ++i) {
				k = CIN();
				a[i] = k;
			}
		}
		if (OP == 2) {
			for (int i = 0; i < size; ++i) {
				k = rand();
				a[i] = k;
			}
			cout << "你是否想看生成的数组？ 1.看 2.不看" << endl;
			OKK = CIN();
			while (OKK != 1 && OKK != 2) {
				cout << "请重新输入" << endl;
				OKK = CIN();
			}
			if (OKK == 1)COUT(a, size);
		}
		if (OP == 3) {
			for (int i = 0; i < size; ++i) {
				k = rand()%3;
				a[i] = k;
			}
			cout << "你是否想看生成的数组？ 1.看 2.不看" << endl;
			OKK = CIN();
			while (OKK != 1 && OKK != 2) {
				cout << "请重新输入" << endl;
				OKK = CIN();
			}
			if (OKK == 1)COUT(a, size);
		}
		memcpy(b, a, size*sizeof(int));
		while (pp) {
			system("pause");
			system("cls");
			for (int i = 1; i <= 10; ++i) cout << endl;
			cout << "=============   你已经得到了一个数组了，你还想做什么：    =============" << endl
				<< "       1.插入排序" << endl
				<< "       2.归并排序" << endl
				<< "       3.快速排序（递归）" << endl
				<< "       4.快速排序（非递归）" << endl
				<< "       5.计数排序" << endl
				<< "       6.基数排序" << endl
				<< "       7.数组回朔（到有序前）" << endl
				<< "       8.重做数组" << endl
				<< "       9.颜色排列" << endl 
				<< "       10.查看是否为递增序列" << endl 
				<< "       11.选做：查看第k小的数" << endl << endl;
			OP = CIN();
			while (OP < 1 || OP > 11) {
				cout << "请重新输入" << endl;
				OP = CIN();
			}
			temp = new int[size];
			star = clock();
			switch (OP)
			{
			case 1:
				insertSort(a, size);
				break;
			case 2:
				MergeSort(a, 0, size-1, temp);
				break;
			case 3:
				QuickSort_Recursion(a, 0, size-1);
				break;
			case 4:
				QuickSort(a, size);
				break;
			case 5:
				CountSort(a, size, Find_Max(a, size));
				break;
			case 6:
				RadixCountSort(a, size);
				break;
			case 7:
				memcpy(a, b, size * sizeof(int));
				cout << "回溯成功" << endl;
				break;
			case 8:
				cout << "确定不要这个数组请再按1+回车,否则输入0"<<endl;
				OK = CIN();
				if (OK==1)
				pp = 0;
				system("pause");
				system("cls");
				break;
			case 9:
				if (!is_color(a, size)) {
					cout << "这个数组不是一个可以用颜色排序进行排序的数组" << endl;
					OP = 8;
					break;
				}
				ColorSort(a, size);
				break;
			case 10:
				for (int j = 1; j < size; ++j) {
					if (a[j] < a[j - 1]) {
						cout << "这不是个递增序列" << endl;
						break;
					}
					if (j == size - 1) cout << "这是个递增序列" << endl;
				}
				break;
			case 11:
				cout << "你想要第几小？" << endl;
				cin >> k;
				cout << "第" << k << "小的数是：";
				cout<<Find_k(a, size, k)<<endl;
				break;
			default:
				break;
			}
			end = clock();
			if (OP != 7 && OP != 8 && OP != 10 && OP != 11) {
				cout << "你是否想看转换后的数组？ 1.看 2.不看" << endl;
				OKK = CIN();
				while (OKK != 1 && OKK != 2) {
					cout << "请重新输入" << endl;
					OKK = CIN();
				}
				if (OKK == 1)COUT(a, size);
				cout << "所用时间为" << end - star << "ms" << endl;							#计时用末时间减去初时间 
			}
		}
	}
}
