#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int distances[101][101];
int usersCount = 0;

int sumOfDistances[101];

void floydWarshall() {
	for (int mid = 1; mid <= usersCount; mid++) {
		for (int from = 1; from <= usersCount; from++) {
			for (int to = 1; to <= usersCount; to++) {
				if (from == to) continue;

				// search relations (via mid)
				if (distances[from][mid] && distances[mid][to]) {
					if (distances[from][to] == 0) {
						distances[from][to] = distances[from][mid] + distances[mid][to];
					}
					else {
						distances[from][to] = min(distances[from][to], distances[from][mid] + distances[mid][to]);
					}
				}
			}
		}
	}

	for (int from = 1; from <= usersCount; from++) {
		for (int to = 1; to <= usersCount; to++) {
			sumOfDistances[from] += distances[from][to];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, a, b;
	cin >> usersCount >> m;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;

		distances[a][b] = 1;
		distances[b][a] = 1;
	}

	floydWarshall();

	int minimumUser = 1;
	int minimum = sumOfDistances[minimumUser];

	for (int i = 1; i <= usersCount; i++) {
		if (minimum > sumOfDistances[i]) {
			minimumUser = i;
			minimum = sumOfDistances[i];
		}
	}

	// for (int i = 1; i <= usersCount; i++) {
	// 	for (int j = 1; j <= usersCount; j++) {
	// 		cout << i << " to " << j << " : " <<  distances[i][j] << "\n";
	// 	}
	// }

	cout << minimumUser;
}