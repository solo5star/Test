#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> passwords;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int set = 0;

	int n;
	string instruction;
	int operand;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> instruction;

		if (instruction == "add") {
			cin >> operand;
			set |= 1 << operand;
		}
		else if (instruction == "remove") {
			cin >> operand;
			set &= ~0 ^ (1 << operand);
		}
		else if (instruction == "check") {
			cin >> operand;
			cout << ((set & (1 << operand)) != 0) << "\n";
		}
		else if (instruction == "toggle") {
			cin >> operand;
			set ^= 1 << operand;
		}
		else if (instruction == "all") {
			set = ~0;
		}
		else if (instruction == "empty") {
			set = 0;
		}
	}
}