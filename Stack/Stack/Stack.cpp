// Stack.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <cctype>

using namespace std;

#define SIZE 27

class stack {
	char stck[SIZE];
	int tos;
public:
	stack();
	void push(char ch);
	char pop();
};

//スタック初期化
stack::stack() {
	cout << "スタックを初期化\n";
	tos = 0;
}

//文字をプッシュする
void stack::push(char ch) {
	if (tos == SIZE) {
		cout << "スタックが一杯です\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char stack::pop() {
	if (tos == 0) {
		cout << "スタックは空です\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

void showstack(stack o);
stack loadstack();
stack loadstack(int x);

int main()
{
	stack s1, s2,s3;
	int i;

	s1 = loadstack();
	showstack(s1);

	//大文字を格納する
	s2 = loadstack(1);
	showstack(s2);

	//小文字を格納する
	s3 = loadstack(0);
	showstack(s3);

	cin >> i;

	return 0;
}

void showstack(stack o) {
	char c;

	while (c = o.pop())cout << c << "\n";
	cout << "\n";
}

stack loadstack() {
	stack t;
	char c;

	for (c = 'a'; c <= 'z'; c++) {
		t.push(c);
	}
	return t;
}

/* スタックにアルファベット文字を格納する
upperが1の場合は大文字、それ以外は小文字を格納
*/
stack loadstack(int upper) {
	stack t;
	char c;

	if (upper == 1) {
		c = 'A';
	}
	else {
		c = 'a';
	}

	for (; toupper(c) <= 'Z'; c++) {
		t.push(c);
	}

	return t;
}