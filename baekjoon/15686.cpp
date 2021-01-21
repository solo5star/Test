#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x;
	int y;
	bool removed;
} point;

int world[50][50];
vector<point> houses;
vector<point> kfcs;
int width;

int minValue = INT_MAX;

int getDistance(const point& a, const point& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int getNearestKfc(const point& house) {
	int nearest = INT_MAX;

	for (int i = 0; i < kfcs.size(); i++) {
		if (kfcs[i].removed) continue;

		int dist = getDistance(house, kfcs[i]);
		nearest = min(nearest, dist);
	}

	return nearest;
}

int getSumOfDistances() {
	int sum = 0;

	for (int i = 0; i < houses.size(); i++) {
		sum += getNearestKfc(houses[i]);
	}

	return sum;
}

void permutation(int maxCount, int id = 0, int count = 0) {
	if (maxCount == 0) {
		minValue = getSumOfDistances();
		return;
	}

	if (count == 0) {
		for (int i = 0; i < kfcs.size(); i++) {
			permutation(maxCount, i, count + 1);
		}
		return;
	}

	kfcs[id].removed = true;

	if (count == maxCount) {
#ifdef DEBUG
		cout << "PERMUTATION: ";
		for (int i = 0; i < kfcs.size(); i++) {
			if (!kfcs[i].removed) cout << "<" << kfcs[i].x << "," << kfcs[i].y << "> ";
		}
#endif

		int sumOfDistances = getSumOfDistances();

		minValue = min(minValue, sumOfDistances);
#ifdef DEBUG
		cout << "(" << sumOfDistances << ")\n";
#endif
	}
	
	if (count < maxCount) {
		for (int i = id + 1; i < kfcs.size(); i++) {
			permutation(maxCount, i, count + 1);
		}
	}

	kfcs[id].removed = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int kfcCount;

	cin >> width >> kfcCount;

	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> world[y][x];

			switch (world[y][x]) {
			case 1:
				houses.push_back({ x, y });
				break;

			case 2:
				kfcs.push_back({ x, y });
				break;
			}
		}
	}

	permutation(kfcs.size() - kfcCount);

	cout << minValue;
}