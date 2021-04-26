#include "tree.h"

int main()
{
	int OP,e;
	BinarySortTree BST;
	BST_init(&BST);
	while (1)
	{
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.插入数字" << endl
			<< "       2.查找数字" << endl
			<< "       3.删除数字" << endl
			<< "       4.递归前序遍历" << endl
			<< "       5.递归中序遍历" << endl
			<< "       6.递归后序遍历" << endl
			<< "       7.迭代前序遍历" << endl
			<< "       8.迭代中序遍历" << endl
			<< "       9.迭代后序遍历" << endl
			<< "       10.层序遍历" << endl
			<< "       11.退出程序" << endl<<endl;
		OP = CIN();
		cout << endl;
		while (OP > 11 || OP < 1) {
			cout << "你的输入有问题，请重新输入"<<endl;
			OP = CIN();
		}
		switch (OP)
		{
		case 1:
			cout << "请输入你想插入的数:  ";
			e = CIN();
			if(BST_insert(&BST, e))cout<<"插入成功，此时树中有"<<BST.count<<"个元素"<<endl;
			break;
		case 2:
			cout << "请输入你想查找的数   ";
			e = CIN();
			if (BST_Search(&BST, e)) cout << "树中有此数" << endl;
			else cout << "树中无此树" << endl;
			break;
		case 3:
			cout << "请输入你想删除的数   ";
			e = CIN();
			if (!BST_Search(&BST, e)) cout << "找不到此数，无法删除"<<endl;
			else if (BST_delete(&BST, e)) cout<<"成功删除此数,此时树中有"<<BST.count<<"个元素"<<endl;
			break;
		case 4:
			cout << "树的前序遍历为：";
			BST_preorderI(&BST, COUT);
			cout << endl;
			break;
		case 5:
			cout << "树的中序遍历为：";
			BST_inorderI(&BST, COUT);
			cout << endl;
			break;
		case 6:
			cout << "树的后序遍历为：";
			BST_postorderI(&BST, COUT);
			cout << endl;
			break;
		case 7:
			cout << "树的前序遍历为：";
			BST_preorderR(&BST, COUT);
			cout << endl;
			break;
		case 8:
			cout << "树的中序遍历为：";
			BST_inorderR(&BST, COUT);
			cout << endl;
			break;
		case 9:
			cout << "树的后序遍历为：";
			BST_postorderR(&BST, COUT);
			cout << endl;
			break;
		case 10:
			cout << "树的层序遍历为：";
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