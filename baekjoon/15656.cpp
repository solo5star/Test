#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <unordered_set>

using namespace std;

int numbers[9];
bool visited[9];
int stack[9];
int n, m;

void dfs(int index, int depth = 1) {
	// if (visited[index]) return;

	stack[depth] = numbers[index];

	if (depth == m) {
		for (int i = 1; i <= depth; i++) {
			cout << stack[i] << (i == depth ? "\n" : " ");
		}
	}
	else if (depth < m) {
		visited[index] = true;
		for (int i = 0; i < n; i++) {
			dfs(i, depth + 1);
		}
		visited[index] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> numbers[i];

	sort(numbers, numbers + n);

	for (int i = 0; i < n; i++) dfs(i);
}