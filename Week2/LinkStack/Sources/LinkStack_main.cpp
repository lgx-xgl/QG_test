#include "LinkStack.h"
int main()
{
	LinkStack s ;
	s.top = NULL;																	//空栈和没有栈的区别：空栈有s.top
	ElemType node;
	int OPERASION,OPERASION2,er=0;
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
		switch (OPERASION)
		{
		case 1:
			if (s.top != NULL) {
				cout << "原来链栈仍未销毁，你确定要将原来的栈销毁吗？";
				cout << endl << "1.确定        2.拒绝";
				cin >> OPERASION2;
				if (OPERASION2 == 1) {
					destroyLStack(&s);
					initLStack(&s);
				}
				else break;
			} else initLStack(&s);
			cout << "你成功创建了一个新的空栈"<<endl;
			break;
		case 2:
			if (s.top == NULL) {
				cout << "请先创一个栈吧" << endl;
				break;
			}
			cout << "请输入你要压入的数据"<<endl;
			cin >> node;
			if (pushLStack(&s, node))cout << "压入成功";
			break;
		case 3:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			if (popLStack(&s, &node)) {
				cout << "弹出的栈顶元素是" << node << endl;
			}
			else {
				cout << "弹出失败，请检查是否为空栈" << endl;
			}
			break;
		case 4:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			if (getTopLStack(&s, &node)) {
				cout << "栈顶元素是" << node << endl;
			}
			else {
				cout << "查找栈顶元素失败，请检查是否为空栈" << endl;
			}
			break;
		case 5:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			int length;
			if (LStackLength(&s, &length)) {
				cout << "栈里有" << length << "个元素";
			}
			else {
				cout << "请检查栈是否被创建";
			}
			break;
		case 6:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			cout << "你真的想清空它吗？ 输入 1 则清空它，否则不处理" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				clearLStack(&s);
				cout << "清空成功";
			}
			break;
		case 7:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			cout << "你真的想销毁它吗？ 输入 1 则销毁它，否则不处理" << endl;
			cin >> OPERASION2;
			if (OPERASION2 == 1) {
				destroyLStack(&s);
				cout << "销毁成功";
			}
			break;
		case 8:
			if (s.top == NULL) { cout << "请检查栈是否被创建" << endl; break; }
			if (isEmptyLStack(&s)) cout << "栈现在为空";
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
