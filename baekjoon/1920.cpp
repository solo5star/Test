#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int nums[100000];

int main() {
	int n, m, a, search, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		nums[i] = a;
	}

	sort(nums, nums+n);

	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &search);

		int low = 0;
		int high = n;
		int mid;
		bool found = false;

		while (low != high) {
			mid = (low + high) / 2;

			if (nums[mid] == search) {
				found = true;
				break;
			}
			else if (search < nums[mid]) {
				high = mid - 1;
			}
			else if (nums[mid] < search) {
				low = mid + 1;
			}
		}

		printf("%d\n", found ? 1 : 0);
	}
}