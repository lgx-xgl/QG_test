#include "LinkStack.h"
string al, al_change;
int JUDGE = 1;									//��Ϊ0����������
LinkStack s;
const int list_size = 10000;
ElemType num_list[list_size];							//��һ�����ǵ�һ��#
const int PR[] = { 0,0,1,1,2 };						//�ֱ��Ӧ+-*/(�����ȼ�
const char CH[] = { '+','-','*','/' };				 //������ת���ַ�
void  Case(int Symbol, int Pr)
{
	ElemType top_num;
	if (Symbol <= 3) {
		if (isEmptyLStack(&s)) {					//ջΪ��
			pushLStack(&s, Symbol);
			return;
		}
		getTopLStack(&s, &top_num);
		while (PR[int (top_num)] >= Pr) {					//һֱ������ֱ��ջ�����ȼ�<Pr
			if (top_num == 4) break;				//����'('������
			al_change += CH[int(top_num)];
			popLStack(&s, &top_num);
			if (isEmptyLStack(&s)) break;			//������Ϊ��ջ
			getTopLStack(&s, &top_num);
		}
		pushLStack(&s, Symbol);
		return;
	}
	if (Symbol == 4) {								//'('ֱ�ӷž�ok
		pushLStack(&s, Symbol);
		return;
	}
	if (Symbol == 5) {
		getTopLStack(&s, &top_num);
		while (top_num != 4) {						//'('ǰ��ȫ������
			if (isEmptyLStack) {
				cout << "������������⣬����";
				JUDGE = 0;
				return;
			}
			al_change += CH[int(top_num)];
			popLStack(&s, &top_num);
			getTopLStack(&s, &top_num);
		}
		popLStack(&s, &top_num);					//��'('����
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
		if (al[i] >= '0' && al[i] <= '9') {						//����ֱ�ӵ���
			t = 1;
			num = 0;
			while (al[i] <= '9' && al[i] >= '0') {
				if (al[i] == '0') {									//���λΪ0��Ҫ����
					++last_zero;
				}
				else last_zero = 0;
				num += t * (al[i] - '0');
				t *= 10;
				++i;
			}
			num=down(num);											//��num���ҵ�
			for (int j = 1; j <= last_zero; ++j) num *= 10;
			++k;
			num_list[k] = num;
			al_change += '#';									//������#����,���������������	
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
		case '��':
			Case(2, PR[2]);
			break;
		case '��':
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
	while (!isEmptyLStack(&s)) {								//��ʣ��ĵ���
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
			pushLStack(&s, num_list[k]);					//�������ӽ�ȥ
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
	cout << "������������ʽ" << endl;
	cin >> al;
	change();
	if (!JUDGE) return 0;
	OUT();
}
