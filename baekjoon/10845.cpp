#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string instruction;
	int operand;
	queue<int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> instruction;
		if (instruction == "push") {
			cin >> operand;
			q.push(operand);
		}
		else if (instruction == "pop") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (instruction == "size") {
			cout << q.size() << "\n";
		}
		else if (instruction == "empty") {
			cout << (q.size() == 0) << "\n";
		}
		else if (instruction == "front") {
			cout << (q.size() == 0 ? -1 : q.front()) << "\n";
		}
		else if (instruction == "back") {
			cout << (q.size() == 0 ? -1 : q.back()) << "\n";
		}
	}
}