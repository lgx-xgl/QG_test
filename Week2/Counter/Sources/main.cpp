#include "LinkStack.h"
string al, al_change;
int JUDGE = 1;									//若为0，即有问题
LinkStack s;
const int list_size = 10000;
ElemType num_list[list_size];							//第一个数是第一个#
const int PR[] = { 0,0,1,1,2 };						//分别对应+-*/(的优先级
const char CH[] = { '+','-','*','/' };				 //将数字转回字符
void  Case(int Symbol, int Pr)
{
	ElemType top_num;
	if (Symbol <= 3) {
		if (isEmptyLStack(&s)) {					//栈为空
			pushLStack(&s, Symbol);
			return;
		}
		getTopLStack(&s, &top_num);
		while (PR[int (top_num)] >= Pr) {					//一直弹出，直到栈顶优先级<Pr
			if (top_num == 4) break;				//遇到'('就算了
			al_change += CH[int(top_num)];
			popLStack(&s, &top_num);
			if (isEmptyLStack(&s)) break;			//弹出后为空栈
			getTopLStack(&s, &top_num);
		}
		pushLStack(&s, Symbol);
		return;
	}
	if (Symbol == 4) {								//'('直接放就ok
		pushLStack(&s, Symbol);
		return;
	}
	if (Symbol == 5) {
		getTopLStack(&s, &top_num);
		while (top_num != 4) {						//'('前，全部弹出
			if (isEmptyLStack) {
				cout << "你的输入有问题，请检查";
				JUDGE = 0;
				return;
			}
			al_change += CH[int(top_num)];
			popLStack(&s, &top_num);
			getTopLStack(&s, &top_num);
		}
		popLStack(&s, &top_num);					//将'('弹出
		return;
	}
	return;
}
int down(int x)
{
	int t = 0;
	while (x) {
		t *= 10;
		t += (x % 10);
		x /= 10;
	}
	return t;
}
void change()
{
	ElemType  t, num,last_zero=0;
	int l, k=0;
	l = al.length();
	for (int i = 0; i < l; ++i) {
		if (JUDGE == 0) return;
		if (al[i] >= '0' && al[i] <= '9') {						//数字直接弹出
			t = 1;
			num = 0;
			while (al[i] <= '9' && al[i] >= '0') {
				if (al[i] == '0') {									//最后位为0需要特判
					++last_zero;
				}
				else last_zero = 0;
				num += t * (al[i] - '0');
				t *= 10;
				++i;
			}
			num=down(num);											//将num左右倒
			for (int j = 1; j <= last_zero; ++j) num *= 10;
			++k;
			num_list[k] = num;
			al_change += '#';									//数字用#代替,具体的数放数组里	
		}
		switch (al[i])
		{
		case '+':
			Case(0, PR[0]);
			break;
		case '-':
			Case(1, PR[1]);
			break;
		case '*':
			Case(2, PR[2]);
			break;
		case '/':
			Case(3, PR[3]);
			break;
		case '×':
			Case(2, PR[2]);
			break;
		case '÷':
			Case(3, PR[3]);
			break;
		case '(':
			Case(4, PR[4]);
			break;
		case ')':
			Case(5, -1);
			break;
		case' ':
			continue;
		default:
			break;
		}
	}
	ElemType Symbol;
	while (!isEmptyLStack(&s)) {								//将剩余的弹出
		popLStack(&s, &Symbol);
		al_change += CH[int(Symbol)];
	}
}
void OUT()
{
	destroyLStack(&s);
	initLStack(&s);
	ElemType l = al_change.length(), a1, a2;
	int k=0;
	for (int i = 0; i < l; ++i) {
		if (al_change[i] =='#') {
			++k;
			pushLStack(&s, num_list[k]);					//把数字扔进去
		}
		else {
			popLStack(&s, &a1);
			popLStack(&s, &a2);
			if (al_change[i] == '+') pushLStack(&s, a2 + a1);
			if (al_change[i] == '-') pushLStack(&s, a2 - a1);
			if (al_change[i] == '*') pushLStack(&s, a2 * a1);
			if (al_change[i] == '/') pushLStack(&s, a2 / a1);
		}
	}
	popLStack(&s, &a1);
	cout << a1 << endl;
}
int main()
{
	s.top = NULL;
	initLStack(&s);
	cout << "请输入运算表达式" << endl;
	cin >> al;
	change();
	if (!JUDGE) return 0;
	OUT();
}
