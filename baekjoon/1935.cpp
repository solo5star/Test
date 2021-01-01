#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

int mapper[255];
stack<double> operands;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string postfix;
	cin >> postfix;

	for (int i = 0; i < n; i++) {
		cin >> mapper['A' + i];
	}

	for (int i = 0; i < postfix.length(); i++) {
		char ch = postfix[i];

		if ('A' <= ch && ch <= 'Z') {
			operands.push(mapper[ch]);
		}
		else {
			double op2 = operands.top();
			operands.pop();
			double op1 = operands.top();
			operands.pop();

			switch (ch) {
			case '+':
				operands.push(op1 + op2);
				break;
			case '-':
				operands.push(op1 - op2);
				break;
			case '*':
				operands.push(op1 * op2);
				break;
			case '/':
				operands.push(op1 / op2);
				break;
			}
		}
	}

	cout.precision(2);
	cout << fixed;
	cout << operands.top();
}