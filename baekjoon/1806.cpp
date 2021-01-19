#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

const int INF = ~(1 << 31);

int nums[100000];
int length;
int goal;
int sum;
int front, rear = 0;
int minLength = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> length >> goal;

	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	for (front = 0; front < length; front++) {
		sum += nums[front];

		while (rear <= front && sum >= goal) {
			minLength = min(minLength, front - rear + 1);

			sum -= nums[rear];
			rear++;
		}
	}

	cout << (minLength == INF ? 0 : minLength);
}