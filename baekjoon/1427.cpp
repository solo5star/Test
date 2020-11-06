#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int nums[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;
	
	for (int i = 0; i < input.length(); i++) {
		nums[input[i] - '0']++;
	}


	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < nums[i]; j++) {
			cout << i;
		}
	}
}