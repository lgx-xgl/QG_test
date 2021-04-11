#include "AQueue.h"

char type;
char datatype[MAXQUEUE];



int main()								//������
{
	int OP,size,p;
	int* num;
	string* STR;
	double* DOU;
	Aqueue Q;
	Q.data[0] = NULL;
	void* el=new int;
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
			<< "       8.�鿴����״̬���գ�����δ��ʼ��,���ȣ�" << endl << endl;
		if (!scanf_s("%d", &OP)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
			cout << "��Ĳ��������Ⱑ"<<endl;
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
		if (OP != 1 && Q.data[0] == NULL) {
			cout << "���ȳ�ʼ������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		p = 0;
		switch (OP)
		{
		case 1:
			cout << "��������г���(0<=len<=10)" << endl;
			while (!scanf_s("%d", &size) || size <= 0 || size>10) {
				cout << "��Ĳ��������Ⱑ,������һ������ֵ" << endl;
			}
			Q.length = size+1;
			InitAQueue(&Q);
			break;
		case 2:
			cout << "��������Ԫ�ص�����" << endl
				<< "       1.����" << endl
				<< "       2.�ַ���" << endl
				<< "       3.������" << endl;
			cin >> type;
			switch (type)
			{
			case '1':
				cout << "������һ������"<<endl;
				num = new int;
				cin >> *num;
				datatype[Q.rear] = type;
				if (!EnAQueue(&Q, num)) p = 1;
				break;
			case '2':
				cout << "������һ���ַ������ַ���"<<endl;
				STR = new string;
				cin >> *STR;
				datatype[Q.rear] = type;
				if (!EnAQueue(&Q, STR)) p=1;
				break;
			case '3':
				cout << "������һ��������"<<endl;
				DOU = new double;
				cin >> *DOU;
				datatype[Q.rear] = type;
				if (!EnAQueue(&Q, DOU)) p=1;
				break;
			default:
				break;
			}
			break;
		case 3:
			if (!DeAQueue(&Q)) p=1;
			break;
		case 4:
			if (!GetHeadAQueue(&Q, &el)) {
				p = 1;
				break;
			}
			switch (datatype[Q.front])
			{
			case '1':
				cout << *(int*)el;
				break;
			case '2':
				cout << *(string*)el;
				break;
			case '3':
				cout << *(double*)el;
				break;
			default:
				break;
			}
			break;
		case 5:
			if (!TraverseAQueue(&Q, APrint))p=1;
			break;
		case 6:
			ClearAQueue(&Q);
			break;
		case 7:
			DestoryAQueue(&Q);
			break;
		case 8:
			if (IsFullAQueue(&Q)) cout << "�˶���Ϊ��";
			else if (IsEmptyAQueue(&Q)) cout << "�˶����ѿ�";
			else cout<<"����Ϊ"<<LengthAQueue(&Q);
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


void APrint(void* q,int step)                        //��������
{
	switch (datatype[step])
	{
	case '1':
		cout << *(int*)q;
		break;
	case '2':
		cout << *(string*)q;
		break;
	case '3':
		cout << *(double*)q;
		break;
	default:
		break;
	}
	cout << "  ";
	return;
}