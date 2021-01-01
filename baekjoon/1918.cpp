#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

stack<char> operators;

int priority[255];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority['('] = 10;

	priority['+'] = 3;
	priority['-'] = 3;
	priority['*'] = 4;
	priority['/'] = 4;

	priority[')'] = 1;

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		char ch = input[i];
		
		if ('A' <= ch && ch <= 'Z') {
			cout << ch;
		}
		else {
			while (!operators.empty()) {
				char next = operators.top();

				if (priority[ch] > priority[next]) break;

				if (next == '(' && ch != ')') break;

				if(next != '(' && next != ')') cout << next;

				operators.pop();
			}
			operators.push(ch);
		}
	}

	while (!operators.empty()) {
		char next = operators.top();
		if (next != '(' && next != ')') cout << next;
		operators.pop();
	}
}