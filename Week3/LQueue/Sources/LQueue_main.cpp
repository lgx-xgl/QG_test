#include "LQueue.h"
int main()								//主函数
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
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.初始化队列" << endl
			<< "       2.插入一个元素" << endl
			<< "       3.弹出头元素" << endl
			<< "       4.查看头元素" << endl
			<< "       5.遍历一次队列（可将队列元素输出）" << endl
			<< "       6.清空链表" << endl
			<< "       7.删除链表" << endl
			<< "       8.查看链表状态（空，未初始化,长度）" << endl << endl;
		if (!scanf_s("%d", &OP)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
			cout << "你的操作有问题啊" << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OP > 8 || OP < 1) {
			cout << "你的操作有问题啊" << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OP != 1 && Q.front == NULL) {
			cout << "请先初始化队列" << endl;
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
			cout << "请你输入元素的类型" << endl
				<< "       1.数字" << endl
				<< "       2.字符串" << endl
				<< "       3.浮点数" << endl;
			while (!scanf_s("%d", &type) || type <= 0 || type > 3) {
				cout << "你的操作有问题啊,请输入一个正常值" << endl;
			}
			switch (type)
			{
			case 1:
				cout << "请输入一个数字" << endl;
				num = new int;
				while (!scanf_s("%d", num)) {
					cout << "你的操作有问题啊,请输入一个数字" << endl;
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
				}
				if (!EnLQueue(&Q, num, 1)) p = 1;
				break;
			case 2:
				cout << "请输入一个字符串（字符）" << endl;
				STR = new string;
				cin >> *STR;
				if (!EnLQueue(&Q, STR, 2)) p = 1;
				break;
			case 3:
				cout << "请输入一个浮点数" << endl;
				DOU = new double;
				while (!scanf_s("%lf", DOU) ) {
					cout << "你的操作有问题啊,请输入一个正常浮点数" << endl;
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
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
			if (IsEmptyLQueue(&Q)) cout << "此队列已空";
			else cout << "队列长度为" << LengthLQueue(&Q);
		default:
			break;
		}
		cout << endl;
		if (p == 0) cout << "操作成功";
		else cout << "操作失败";
		cout << endl;
		system("pause");
		system("cls");
	}
}