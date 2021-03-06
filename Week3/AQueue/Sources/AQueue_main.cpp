#include "AQueue.h"

char type;
char datatype[MAXQUEUE];



int main()								//主函数
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
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.初始化队列" << endl
			<< "       2.插入一个元素" << endl
			<< "       3.弹出头元素" << endl
			<< "       4.查看头元素" << endl
			<< "       5.遍历一次队列（可将队列元素输出）" << endl
			<< "       6.清空链表" << endl
			<< "       7.删除链表" << endl
			<< "       8.查看链表状态（空，满，未初始化,长度）" << endl << endl;
		if (!scanf_s("%d", &OP)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
			cout << "你的操作有问题啊"<<endl;
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
		if (OP != 1 && Q.data[0] == NULL) {
			cout << "请先初始化队列" << endl;
			system("pause");
			system("cls");
			continue;
		}
		p = 0;
		switch (OP)
		{
		case 1:
			cout << "请输入队列长度(0<=len<=10)" << endl;
			while (!scanf_s("%d", &size) || size <= 0 || size>10) {
				cout << "你的操作有问题啊,请输入一个正常值" << endl;
			}
			Q.length = size+1;
			InitAQueue(&Q);
			break;
		case 2:
			cout << "请你输入元素的类型" << endl
				<< "       1.数字" << endl
				<< "       2.字符串" << endl
				<< "       3.浮点数" << endl;
			cin >> type;
			switch (type)
			{
			case '1':
				cout << "请输入一个数字"<<endl;
				num = new int;
				cin >> *num;
				datatype[Q.rear] = type;
				if (!EnAQueue(&Q, num)) p = 1;
				break;
			case '2':
				cout << "请输入一个字符串（字符）"<<endl;
				STR = new string;
				cin >> *STR;
				datatype[Q.rear] = type;
				if (!EnAQueue(&Q, STR)) p=1;
				break;
			case '3':
				cout << "请输入一个浮点数"<<endl;
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
			if (IsFullAQueue(&Q)) cout << "此队列为满";
			else if (IsEmptyAQueue(&Q)) cout << "此队列已空";
			else cout<<"长度为"<<LengthAQueue(&Q);
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


void APrint(void* q,int step)                        //操作函数
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