#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <deque>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string instruction;
	int operand;
	deque<int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> instruction;
		if (instruction == "push_front") {
			cin >> operand;
			q.push_front(operand);
		}
		else if (instruction == "push_back") {
			cin >> operand;
			q.push_back(operand);
		}
		else if (instruction == "pop_front") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (instruction == "pop_back") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
				q.pop_back();
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