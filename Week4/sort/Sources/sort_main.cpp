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
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.�Լ���һ������" << endl
			<< "       2.�������һ������" << endl
			<< "       3.�������һ���������У�ֻ��0.1.2����������ɫ����" << endl << endl;
		OP=CIN();
		pp = 1;
		while (OP < 1 || OP > 3 ) {
			cout << "����������"<<endl;
			OP = CIN();
		}
		cout << "����������Ҫ�����еĳ���"<<endl;
		size = CIN(); 
		while (size <= 0) {
			cout << "����������" << endl;
			size = CIN();
		}
		a = new int[size];
		b = new int[size];
		if (OP == 1) {
			cout << "�������������"<<endl;
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
			cout << "���Ƿ��뿴���ɵ����飿 1.�� 2.����" << endl;
			OKK = CIN();
			while (OKK != 1 && OKK != 2) {
				cout << "����������" << endl;
				OKK = CIN();
			}
			if (OKK == 1)COUT(a, size);
		}
		if (OP == 3) {
			for (int i = 0; i < size; ++i) {
				k = rand()%3;
				a[i] = k;
			}
			cout << "���Ƿ��뿴���ɵ����飿 1.�� 2.����" << endl;
			OKK = CIN();
			while (OKK != 1 && OKK != 2) {
				cout << "����������" << endl;
				OKK = CIN();
			}
			if (OKK == 1)COUT(a, size);
		}
		memcpy(b, a, size*sizeof(int));
		while (pp) {
			system("pause");
			system("cls");
			for (int i = 1; i <= 10; ++i) cout << endl;
			cout << "=============   ���Ѿ��õ���һ�������ˣ��㻹����ʲô��    =============" << endl
				<< "       1.��������" << endl
				<< "       2.�鲢����" << endl
				<< "       3.�������򣨵ݹ飩" << endl
				<< "       4.�������򣨷ǵݹ飩" << endl
				<< "       5.��������" << endl
				<< "       6.��������" << endl
				<< "       7.�����˷��������ǰ��" << endl
				<< "       8.��������" << endl
				<< "       9.��ɫ����" << endl 
				<< "       10.�鿴�Ƿ�Ϊ��������" << endl 
				<< "       11.ѡ�����鿴��kС����" << endl << endl;
			OP = CIN();
			while (OP < 1 || OP > 11) {
				cout << "����������" << endl;
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
				cout << "���ݳɹ�" << endl;
				break;
			case 8:
				cout << "ȷ����Ҫ����������ٰ�1+�س�,��������0"<<endl;
				OK = CIN();
				if (OK==1)
				pp = 0;
				system("pause");
				system("cls");
				break;
			case 9:
				if (!is_color(a, size)) {
					cout << "������鲻��һ����������ɫ����������������" << endl;
					OP = 8;
					break;
				}
				ColorSort(a, size);
				break;
			case 10:
				for (int j = 1; j < size; ++j) {
					if (a[j] < a[j - 1]) {
						cout << "�ⲻ�Ǹ���������" << endl;
						break;
					}
					if (j == size - 1) cout << "���Ǹ���������" << endl;
				}
				break;
			case 11:
				cout << "����Ҫ�ڼ�С��" << endl;
				cin >> k;
				cout << "��" << k << "С�����ǣ�";
				cout<<Find_k(a, size, k)<<endl;
				break;
			default:
				break;
			}
			end = clock();
			if (OP != 7 && OP != 8 && OP != 10 && OP != 11) {
				cout << "���Ƿ��뿴ת��������飿 1.�� 2.����" << endl;
				OKK = CIN();
				while (OKK != 1 && OKK != 2) {
					cout << "����������" << endl;
					OKK = CIN();
				}
				if (OKK == 1)COUT(a, size);
				cout << "����ʱ��Ϊ" << end - star << "ms" << endl;							#��ʱ��ĩʱ���ȥ��ʱ�� 
			}
		}
	}
}
