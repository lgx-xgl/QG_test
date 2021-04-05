#include "SqStack.h"
int main()
{
	SqStack s;
	s.elem = NULL;
	ElemType node;
	int OPERASION, OPERASION2, er = 0, size;
	while (1) {
		cout << "=============   你想做啥：    =============" << endl
			<< "       1.制作一个栈" << endl
			<< "       2.压入一个数据到栈顶" << endl
			<< "       3.弹出一个栈顶的数据" << endl
			<< "       4.获得栈顶数据" << endl
			<< "       5.检测栈的长度" << endl
			<< "       6.清空栈" << endl
			<< "       7.销毁栈" << endl
			<< "       8.判断栈为是否为空" << endl;
		if (!scanf_s("%d", &OPERASION)) {
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');				//清空缓冲区
			++er;
			cout << "你的操作有问题啊" << "   恶意输入问题数" << er << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << endl;
		if (OPERASION > 8 || OPERASION < 1) {
			++er;
			cout << "你的操作有问题啊" << "   恶意输入问题数" << er << endl;
			system("pause");
			system("cls");
			continue;
		}
		if (OPERASION != 1 && s.elem == NULL) {
			cout << "请先初始化链表" << endl;
			system("pause");
			system("cls");
			continue;
		}
		switch (OPERASION)
		{
		case 1:
			cout << "请你输入你想要的链表最大长度" << endl;
			cin >> size;
			while (size <= 0) {
				cout << "长度过小，请重新输入" << endl;
				cin >> size;
			}
			if (s.elem != NULL) {
				cout << "原来链栈仍未销毁，你确定要将原来的栈销毁吗？";
				cout << endl << "1.确定        2.拒绝";
				cin >> OPERASION2;
				if (OPERASION2 == 1) {
					destroyStack(&s);
					initStack(&s, size);
				}
				else break;
			}
			else initStack(&s, size);
			cout << "你成功创建了一个新的空栈" << endl;
			break;
		case 2:
			cout << "请输入你要压入的数据" << endl;
			cin >> node;
			if (pushStack(&s, node))cout << "压入成功";
			break;
		case 3:
			if (popStack(&s, &node)) {
				cout << "弹出的栈顶元素是" << node << endl;
			}
			else {
				cout << "弹出失败，请检查是否为空栈" << endl;
			}
			break;
		case 4:
			if (getTopStack(&s, &node)) {
				cout << "栈顶元素是" << node << endl;
			}
			else {
				cout << "查找栈顶元素失败，请检查是否为空栈" << endl;
			}
			break;
		case 5:
			int length;
			if (stackLength(&s, &length)) {
				cout << "栈里有" << length << "个元素";
			}
			else {
				cout << "请检查栈是否被创建";
			}
			break;
		case 6:
			cout << "你真的想清空它吗？ 输入 1 则清空它，否则不处理" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				clearStack(&s);
				cout << "清空成功";
			}
			break;
		case 7:
			cout << "你真的想销毁它吗？ 输入 1 则销毁它，否则不处理" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				destroyStack(&s);
				cout << "销毁成功";
			}
			break;
		case 8:
			if (isEmptyStack(&s)) cout << "栈现在为空";
			else cout << "栈有元素";
			cout << endl;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}