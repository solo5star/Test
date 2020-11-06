#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int nums[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nums[0] >> nums[1] >> nums[2];

	sort(nums, nums + 3);

	cout << nums[1];
}