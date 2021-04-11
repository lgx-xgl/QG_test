#include "LQueue.h"
int main()								//������
{
	int OP, size, p, type;
	int* num;
	string* STR;
	double* DOU;
	Lqueue Q;
	Q.front = NULL;
	void* el = new int;
	while (1) {
		for (int i = 1; i <= 10; ++i) cout << endl;
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.��ʼ������" << endl
			<< "       2.����һ��Ԫ��" << endl
			<< "       3.����ͷԪ��" << endl
			<< "       4.�鿴ͷԪ��" << endl
			<< "       5.����һ�ζ��У��ɽ�����Ԫ�������" << endl
			<< "       6.�������" << endl
			<< "       7.ɾ������" << endl
			<< "       8.�鿴����״̬���գ�δ��ʼ��,���ȣ�" << endl << endl;
		if (!scanf_s("%d", &OP)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
			cout << "��Ĳ��������Ⱑ" << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OP > 8 || OP < 1) {
			cout << "��Ĳ��������Ⱑ" << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OP != 1 && Q.front == NULL) {
			cout << "���ȳ�ʼ������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		p = 0;
		switch (OP)
		{
		case 1:
			InitLQueue(&Q);
			break;
		case 2:
			cout << "��������Ԫ�ص�����" << endl
				<< "       1.����" << endl
				<< "       2.�ַ���" << endl
				<< "       3.������" << endl;
			while (!scanf_s("%d", &type) || type <= 0 || type > 3) {
				cout << "��Ĳ��������Ⱑ,������һ������ֵ" << endl;
			}
			switch (type)
			{
			case 1:
				cout << "������һ������" << endl;
				num = new int;
				while (!scanf_s("%d", num)) {
					cout << "��Ĳ��������Ⱑ,������һ������" << endl;
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
				}
				if (!EnLQueue(&Q, num, 1)) p = 1;
				break;
			case 2:
				cout << "������һ���ַ������ַ���" << endl;
				STR = new string;
				cin >> *STR;
				if (!EnLQueue(&Q, STR, 2)) p = 1;
				break;
			case 3:
				cout << "������һ��������" << endl;
				DOU = new double;
				while (!scanf_s("%lf", DOU) ) {
					cout << "��Ĳ��������Ⱑ,������һ������������" << endl;
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
				}
				if (!EnLQueue(&Q, DOU,3)) p = 1;
				break;
			default:
				break;
			}
			break;
		case 3:
			if (!DeLQueue(&Q)) p = 1;
			break;
		case 4:
			if (!GetHeadLQueue(&Q, &el)) {
				p = 1;
				break;
			}
			switch (((Node*)el)->type)
			{
			case 1:
				cout << *((int*)((Node*)el)->data);
				break;
			case 2:
				cout << *((string*)((Node*)el)->data);
				break;
			case 3:
				cout << *((double*)((Node*)el)->data);
				break;
			default:
				break;
			}
			break;
		case 5:
			if (!TraverseLQueue(&Q, LPrint))p = 1;
			break;
		case 6:
			ClearLQueue(&Q);
			break;
		case 7:
			DestoryLQueue(&Q);
			break;
		case 8:
			if (IsEmptyLQueue(&Q)) cout << "�˶����ѿ�";
			else cout << "���г���Ϊ" << LengthLQueue(&Q);
		default:
			break;
		}
		cout << endl;
		if (p == 0) cout << "�����ɹ�";
		else cout << "����ʧ��";
		cout << endl;
		system("pause");
		system("cls");
	}
}