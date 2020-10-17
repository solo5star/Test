#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

unordered_set<int> nums;

int main() {
	int n, m, a, search, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		nums.insert(a);
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &search);

		printf("%d\n", (nums.find(search) != nums.end()) ? 1 : 0);
	}
}