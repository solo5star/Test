#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <stack>

using namespace std;

struct { int value; int follows; int root; int previous; } arr[1000];

stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, best = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].value;
		arr[i].follows = 1;
		arr[i].root = i;
		arr[i].previous = i;

		for (int j = 0; j < i; j++) {
			if (arr[j].value < arr[i].value && arr[j].follows + 1 > arr[i].follows) {
				arr[i].follows = arr[j].follows + 1;
				arr[i].root = arr[j].root;
				arr[i].previous = j;

				if (arr[best].follows < arr[i].follows) {
					best = i;
				}
			}
		}
	}

	cout << arr[best].follows << "\n";

	while (arr[best].previous != best) {
		s.push(arr[best].value);

		best = arr[best].previous;
	}
	s.push(arr[best].value);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}