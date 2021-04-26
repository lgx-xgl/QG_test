#include "tree.h"

int main()
{
	int OP,e;
	BinarySortTree BST;
	BST_init(&BST);
	while (1)
	{
		cout << "=============   ������ɶ��    =============" << endl
			<< "       1.��������" << endl
			<< "       2.��������" << endl
			<< "       3.ɾ������" << endl
			<< "       4.�ݹ�ǰ�����" << endl
			<< "       5.�ݹ��������" << endl
			<< "       6.�ݹ�������" << endl
			<< "       7.����ǰ�����" << endl
			<< "       8.�����������" << endl
			<< "       9.�����������" << endl
			<< "       10.�������" << endl
			<< "       11.�˳�����" << endl<<endl;
		OP = CIN();
		cout << endl;
		while (OP > 11 || OP < 1) {
			cout << "������������⣬����������"<<endl;
			OP = CIN();
		}
		switch (OP)
		{
		case 1:
			cout << "����������������:  ";
			e = CIN();
			if(BST_insert(&BST, e))cout<<"����ɹ�����ʱ������"<<BST.count<<"��Ԫ��"<<endl;
			break;
		case 2:
			cout << "������������ҵ���   ";
			e = CIN();
			if (BST_Search(&BST, e)) cout << "�����д���" << endl;
			else cout << "�����޴���" << endl;
			break;
		case 3:
			cout << "����������ɾ������   ";
			e = CIN();
			if (!BST_Search(&BST, e)) cout << "�Ҳ����������޷�ɾ��"<<endl;
			else if (BST_delete(&BST, e)) cout<<"�ɹ�ɾ������,��ʱ������"<<BST.count<<"��Ԫ��"<<endl;
			break;
		case 4:
			cout << "����ǰ�����Ϊ��";
			BST_preorderI(&BST, COUT);
			cout << endl;
			break;
		case 5:
			cout << "�����������Ϊ��";
			BST_inorderI(&BST, COUT);
			cout << endl;
			break;
		case 6:
			cout << "���ĺ������Ϊ��";
			BST_postorderI(&BST, COUT);
			cout << endl;
			break;
		case 7:
			cout << "����ǰ�����Ϊ��";
			BST_preorderR(&BST, COUT);
			cout << endl;
			break;
		case 8:
			cout << "�����������Ϊ��";
			BST_inorderR(&BST, COUT);
			cout << endl;
			break;
		case 9:
			cout << "���ĺ������Ϊ��";
			BST_postorderR(&BST, COUT);
			cout << endl;
			break;
		case 10:
			cout << "���Ĳ������Ϊ��";
			BST_levelOrder(&BST, COUT);
			cout << endl;
			break;
		case 11:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}