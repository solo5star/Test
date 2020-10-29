#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

char brackets[100];
int top = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string line;
		getline(cin, line);

		if (line == ".") break;

		bool valid = true;

		for (int i = 0; i < line.length(); i++) {
			switch (line[i]) {
			case '(':
				brackets[top++] = '(';
				break;
			case '[':
				brackets[top++] = '[';
				break;
			case ')':
				if (brackets[--top] != '(') {
					valid = false;
				}
				break;
			case ']':
				if (brackets[--top] != '[') {
					valid = false;
				}
				break;
			}

			// No need to loop until end.
			// Already invalid
			if (!valid) break;
		}

		if (top != 0) valid = false;

		cout << (valid ? "yes" : "no") << "\n";

		// reset stack
		top = 0;
	}
}