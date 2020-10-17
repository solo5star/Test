#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int* nums;

	int n, m, a;
	cin >> n;

	nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums[i] = a;
	}

	sort(nums, nums+n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int search;
		cin >> search;

		int low = 0;
		int high = n;
		bool found = false;

		while (low != high) {
			int mid = (low + high) / 2;

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

		cout << (found ? 1 : 0) << "\n";
	}

	delete[] nums;
}