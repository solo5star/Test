#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

using point = struct {
	int x;
	int y;
};

int makeHash(const point& p) {
	return p.x + p.y * 10;
}

point fromHash(int hash) {
	return { hash % 10, hash / 10 };
}

int priorities[10][10];
int toggleCounter[10][10];
bool board[10][10];
int lived = 0;

unordered_set<int> points[6];

void addPriority(int x, int y, int value) {
	if (x < 0 || y < 0 || x >= 10 || y >= 10) return;

	int priority = priorities[y][x];
	if (priority) {
		points[priority].erase(makeHash({ x, y }));
	}

	priority = (priorities[y][x] += value);

	if (priority) {
		points[priority].insert(makeHash({ x, y }));
	}
}

void toggle(int x, int y) {
	if (x < 0 || y < 0 || x >= 10 || y >= 10) return;
	// on -> off
	// off -> on
	int w = (board[y][x] = !board[y][x]) ? 1 : -1;

	lived += w;

	addPriority(x, y, w);
	addPriority(x + 1, y, w);
	addPriority(x - 1, y, w);
	addPriority(x, y + 1, w);
	addPriority(x, y - 1, w);
}

int turnOffAllHighestPriority() {
	int highestPriority = 0;
	for (int i = 1; i <= 5; i++) {
		if (points[i].size()) highestPriority = i;
	}

	queue<point> q;
	for (int pHash : points[highestPriority]) {
		q.push(fromHash(pHash));
	}

	int count = 0;

	while(!q.empty()) {
		point p = q.front();
		q.pop();

		count++;
		if (++toggleCounter[p.y][p.x] >= 2) return -1;

		toggle(p.x, p.y);
		toggle(p.x + 1, p.y);
		toggle(p.x - 1, p.y);
		toggle(p.x, p.y + 1);
		toggle(p.x, p.y - 1);

#ifdef DEBUG
		cout << "\n";
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++) {
				cout << (board[y][x] ? 'O' : '#');
			}
			cout << "\n";
		}
		cout << "TOGGLE (" << p.x << ", " << p.y << ")\n";
#endif
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char ch;
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			cin >> ch;
			if (ch == 'O') toggle(x, y);
		}
	}

	int count = 0;
	while (lived) {
		int ret = turnOffAllHighestPriority();

		if (ret == -1) {
			count = -1;
			break;
		}
		else {
			count += ret;
		}
	}

	cout << count;
}