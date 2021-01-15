#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string word;
	int wordCounter = 0;

	while (!cin.eof()) {
		cin >> word;

		if (word == "<br>") {
			cout << "\n";
			wordCounter = 0;
		}
		else if (word == "<hr>") {
			if(wordCounter) cout << "\n";
			for (int i = 0; i < 80; i++) cout << "-";
			cout << "\n";
			wordCounter = 0;
		}
		else {
			if (wordCounter + word.length() > 80) {
				cout << "\n";
				wordCounter = 0;
			}
			else {
				cout << (wordCounter ? " " : "");
			}

			cout << word;
			wordCounter += word.length() + 1;
		}
	}
}