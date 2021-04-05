#include "LinkStack.h"
int main()
{
	LinkStack s ;
	s.top = NULL;																	//��ջ��û��ջ�����𣺿�ջ��s.top
	ElemType node;
	int OPERASION,OPERASION2,er=0;
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
		switch (OPERASION)
		{
		case 1:
			if (s.top != NULL) {
				cout << "ԭ����ջ��δ���٣���ȷ��Ҫ��ԭ����ջ������";
				cout << endl << "1.ȷ��        2.�ܾ�";
				cin >> OPERASION2;
				if (OPERASION2 == 1) {
					destroyLStack(&s);
					initLStack(&s);
				}
				else break;
			} else initLStack(&s);
			cout << "��ɹ�������һ���µĿ�ջ"<<endl;
			break;
		case 2:
			if (s.top == NULL) {
				cout << "���ȴ�һ��ջ��" << endl;
				break;
			}
			cout << "��������Ҫѹ�������"<<endl;
			cin >> node;
			if (pushLStack(&s, node))cout << "ѹ��ɹ�";
			break;
		case 3:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			if (popLStack(&s, &node)) {
				cout << "������ջ��Ԫ����" << node << endl;
			}
			else {
				cout << "����ʧ�ܣ������Ƿ�Ϊ��ջ" << endl;
			}
			break;
		case 4:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			if (getTopLStack(&s, &node)) {
				cout << "ջ��Ԫ����" << node << endl;
			}
			else {
				cout << "����ջ��Ԫ��ʧ�ܣ������Ƿ�Ϊ��ջ" << endl;
			}
			break;
		case 5:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			int length;
			if (LStackLength(&s, &length)) {
				cout << "ջ����" << length << "��Ԫ��";
			}
			else {
				cout << "����ջ�Ƿ񱻴���";
			}
			break;
		case 6:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			cout << "�������������� ���� 1 ������������򲻴���" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				clearLStack(&s);
				cout << "��ճɹ�";
			}
			break;
		case 7:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			cout << "��������������� ���� 1 �������������򲻴���" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				destroyLStack(&s);
				cout << "���ٳɹ�";
			}
			break;
		case 8:
			if (s.top == NULL) { cout << "����ջ�Ƿ񱻴���" << endl; break; }
			if (isEmptyLStack(&s)) cout << "ջ����Ϊ��";
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
