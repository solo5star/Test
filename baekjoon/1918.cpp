#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

stack<char> operators;

int priority[255];

void pop() {
	if(operators.top() != '(') cout << operators.top();
	operators.pop();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority['*'] = 2;
	priority['/'] = 2;
	priority['+'] = 1;
	priority['-'] = 1;

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		char ch = input[i];
		
		if ('A' <= ch && ch <= 'Z') {
			cout << ch;
		}
		else if (ch == '(') {
			operators.push(ch);
		}
		else if (ch == ')') {
			while (operators.top() != '(') pop();
			pop();
		}
		else {
			while (!operators.empty() && operators.top() != '(' && priority[ch] <= priority[operators.top()]) pop();

			operators.push(ch);
		}
	}

	while (!operators.empty()) pop();
}