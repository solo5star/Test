#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int graph[100][100];

const int NIL = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	// k: 거쳐가는 노드
	for (int k = 0; k < n; k++) {
		// i: 출발 노드
		for (int i = 0; i < n; i++) {
			// j: 도착 노드
			for (int j = 0; j < n; j++) {
				// i 노드에서 j 노드로 갈 수 있는가?
				if (graph[i][j] != NIL) {
					graph[i][j] = 1;
				}
				// k 노드를 거쳐 i 노드에서 j 노드로 갈 수 있는가?
				else if (graph[i][k] != NIL && graph[k][j] != NIL) {
					graph[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << graph[i][0];
		for (int j = 1; j < n; j++) {
			cout << " " << graph[i][j];
		}
		cout << "\n";
	}
}