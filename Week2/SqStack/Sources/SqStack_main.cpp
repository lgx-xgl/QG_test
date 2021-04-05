#include "SqStack.h"
int main()
{
	SqStack s;
	s.elem = NULL;
	ElemType node;
	int OPERASION, OPERASION2, er = 0, size;
	while (1) {
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.����һ��ջ" << endl
			<< "       2.ѹ��һ�����ݵ�ջ��" << endl
			<< "       3.����һ��ջ��������" << endl
			<< "       4.���ջ������" << endl
			<< "       5.���ջ�ĳ���" << endl
			<< "       6.���ջ" << endl
			<< "       7.����ջ" << endl
			<< "       8.�ж�ջΪ�Ƿ�Ϊ��" << endl;
		if (!scanf_s("%d", &OPERASION)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//��ջ�����
			++er;
			cout << "��Ĳ��������Ⱑ" << "   ��������������" << er << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << endl;
		if (OPERASION > 8 || OPERASION < 1) {
			++er;
			cout << "��Ĳ��������Ⱑ" << "   ��������������" << er << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OPERASION != 1 && s.elem == NULL) {
			cout << "���ȳ�ʼ������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (OPERASION)
		{
		case 1:
			cout << "������������Ҫ��������󳤶�" << endl;
			cin >> size;
			while (size <= 0) {
				cout << "���ȹ�С������������" << endl;
				cin >> size;
			}
			if (s.elem != NULL) {
				cout << "ԭ����ջ��δ���٣���ȷ��Ҫ��ԭ����ջ������";
				cout << endl << "1.ȷ��        2.�ܾ�";
				cin >> OPERASION2;
				if (OPERASION2 == 1) {
					destroyStack(&s);
					initStack(&s, size);
				}
				else break;
			}
			else initStack(&s, size);
			cout << "��ɹ�������һ���µĿ�ջ" << endl;
			break;
		case 2:
			cout << "��������Ҫѹ�������" << endl;
			cin >> node;
			if (pushStack(&s, node))cout << "ѹ��ɹ�";
			break;
		case 3:
			if (popStack(&s, &node)) {
				cout << "������ջ��Ԫ����" << node << endl;
			}
			else {
				cout << "����ʧ�ܣ������Ƿ�Ϊ��ջ" << endl;
			}
			break;
		case 4:
			if (getTopStack(&s, &node)) {
				cout << "ջ��Ԫ����" << node << endl;
			}
			else {
				cout << "����ջ��Ԫ��ʧ�ܣ������Ƿ�Ϊ��ջ" << endl;
			}
			break;
		case 5:
			int length;
			if (stackLength(&s, &length)) {
				cout << "ջ����" << length << "��Ԫ��";
			}
			else {
				cout << "����ջ�Ƿ񱻴���";
			}
			break;
		case 6:
			cout << "�������������� ���� 1 ������������򲻴���" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				clearStack(&s);
				cout << "��ճɹ�";
			}
			break;
		case 7:
			cout << "��������������� ���� 1 �������������򲻴���" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				destroyStack(&s);
				cout << "���ٳɹ�";
			}
			break;
		case 8:
			if (isEmptyStack(&s)) cout << "ջ����Ϊ��";
			else cout << "ջ��Ԫ��";
			cout << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}