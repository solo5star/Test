#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, operand;
	cin >> n;
	string command;

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command == "push") {
			cin >> operand;
			q.push(operand);
		}
		else if (command == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << "\n";
		}
		else if (command == "empty") {
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (command == "front") {
			cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else if (command == "back") {
			cout << (q.empty() ? -1 : q.back()) << "\n";
		}
	}
}