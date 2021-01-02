#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

typedef struct {
	int index;
	int value;
} element;

struct cmp {
	bool operator()(element& a, element& b) {
		return a.value > b.value;
	}
};

// first=index, second=value
priority_queue<element, vector<element>, struct cmp> pq;

int numbers[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;

		while (!pq.empty() && pq.top().value < num) {
			numbers[pq.top().index] = num;
			pq.pop();
		}

		pq.push({ i, num });
	}

	for (int i = 0; i < n; i++) {
		cout << (numbers[i] ? numbers[i] : -1) << " ";
	}
}