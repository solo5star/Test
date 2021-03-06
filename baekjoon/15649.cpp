#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

bool visited[9];
int stack[9];
int n, m;

void dfs(int number, int depth = 1) {
	if (visited[number]) return;

	stack[depth] = number;

	if (depth == m) {
		for (int i = 1; i <= depth; i++) {
			cout << stack[i] << (i == depth ? "\n" : " ");
		}
	}
	else if (depth < m) {
		visited[number] = true;
		for (int i = 1; i <= n; i++) {
			dfs(i, depth + 1);
		}
		visited[number] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) dfs(i);
}