#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

int stack[100000];

char history[100000];

int historyIndex = 0;

int top = 0;

int current = 1;

inline int peek() {
	if (top == 0) return -1;
	return stack[top - 1];
}

inline void push() {
	history[historyIndex++] = '+';
	stack[top++] = current++;
}

inline int pop() {
	history[historyIndex++] = '-';
	return stack[--top];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, number;
	bool incomplete = false;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number;

		if (i == 0) {
			while (current <= number) push();

			pop();
		}
		else if (current <= number) {
			while (current <= number) push();

			pop();
		}
		else if (number < current) {
			if (peek() != number) {
				incomplete = true;
				break;
			}
			else {
				pop();
			}
		}
	}

	if (incomplete) {
		cout << "NO" << "\n";
	}
	else {
		for (int i = 0; i < historyIndex; i++) {
			cout << history[i] << "\n";
		}
	}
}