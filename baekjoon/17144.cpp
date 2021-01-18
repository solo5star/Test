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

typedef struct {
	int x;
	int y;
	int amount;
} dust;

const int AIR_CLEANER = -1;

// Dusts on the ground.
struct {
	int amount;
	int velocityX;
	int velocityY;
} dusts[50][50];

int width, height;

// This dusts are in the air.
// Values does not synchronized with 2d array map.
queue<dust> dustPropagation;

// returns propagated amount
int propagate(int x, int y, int amount) {
	if (x < 0 || x >= width || y < 0 || y >= height) return 0;

	if (dusts[y][x].amount == AIR_CLEANER) return 0;

	// New dust, added it to queue
	if (dusts[y][x].amount == 0) {
		// There is nothing in the air
		dustPropagation.push({ x, y, 0 });
	}

	// Dusts are propagate to ground.
	dusts[y][x].amount += amount;
	return amount;
}

void procedure_propagate() {
	int count = dustPropagation.size();

	// Dusts in the air will propagate.
	// (propagated dusts will fall to the ground)
	while (count--) {
		dust d = dustPropagation.front();
		dustPropagation.pop();

		int amount = d.amount / 5;
		int propagated = 0;

		if (amount > 0) {
			propagated += propagate(d.x - 1, d.y, amount);
			propagated += propagate(d.x + 1, d.y, amount);
			propagated += propagate(d.x, d.y - 1, amount);
			propagated += propagate(d.x, d.y + 1, amount);
		}

		propagate(d.x, d.y, d.amount - propagated);
	}

	// Rise dusts up to the air
	count = dustPropagation.size();
	while (count--) {
		dust d = dustPropagation.front();
		dustPropagation.pop();

		// visited.
		if (dusts[d.y][d.x].amount == 0) continue;

		d.amount = dusts[d.y][d.x].amount;

		dusts[d.y][d.x].amount = 0;

		// if current location is affected by air cleaner,
		// calculate its new location
		if (dusts[d.y][d.x].velocityX != 0 || dusts[d.y][d.x].velocityY != 0) {
			int velocityX = dusts[d.y][d.x].velocityX;
			int velocityY = dusts[d.y][d.x].velocityY;

			d.x += velocityX;
			d.y += velocityY;

			// purified by air cleaner
			if (dusts[d.y][d.x].amount == AIR_CLEANER) continue;
		}

		// put it into queue
		dustPropagation.push({ d.x, d.y, d.amount });
	}
}

void calculate_air_cleaner_velocity() {
	for (int y = 0; y < height; y++) {
		if (dusts[y][0].amount == AIR_CLEANER) {
			// top and bottom: air blows <-
			for (int _x = 1; _x < width; _x++) {
				dusts[0][_x].velocityX = -1;
				dusts[height - 1][_x].velocityX = -1;
			}

			// middle: air blows ->
			for (int _x = 1; _x < width - 1; _x++) {
				dusts[y][_x].velocityX = 1;
				dusts[y + 1][_x].velocityX = 1;
			}

			// left side
			for (int _y = 0; _y < height; _y++) {
				// above of air cleaner: ↓
				// below of air cleaner: ↑
				dusts[_y][0].velocityY = _y <= y ? 1 : -1;
			}

			// right side
			for (int _y = 1; _y < height - 1; _y++) {
				// above of air cleaner: ↑
				// below of air cleaner: ↓
				dusts[_y][width - 1].velocityY = _y <= y ? -1 : 1;
			}

			break;
		}
	}
}

void print_air_cleaner_velocity() {
#ifdef DEBUG
	cout << "\n";
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << "(" << dusts[y][x].velocityX << "," << dusts[y][x].velocityY << ") ";
		}
		cout << "\n";
	}
#endif
}

int amount_all_of_dusts() {
	int amount = 0;
	int count = dustPropagation.size();
	while (count--) {
		dust d = dustPropagation.front();
		dustPropagation.pop();

		amount += d.amount;

		dustPropagation.push(d);
	}

	return amount;
}

void print_dusts() {
#ifdef DEBUG
	int count = dustPropagation.size();

	int _dusts[50][50] = { 0, };

	while (count--) {
		dust d = dustPropagation.front();
		dustPropagation.pop();

		_dusts[d.y][d.x] = d.amount ? d.amount : dusts[d.y][d.x].amount;

		dustPropagation.push(d);
	}

	cout << "\n";
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << setw(2) << (dusts[y][x].amount == AIR_CLEANER ? -1 : _dusts[y][x]) << " ";
		}
		cout << "\n";
	}

	cout << "DUSTS=" << amount_all_of_dusts() << "\n";
#endif
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int time, amount;

	cin >> height >> width >> time;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> amount;

			if (amount == -1) {
				dusts[y][x].amount = AIR_CLEANER;
			}
			else if (amount > 0) {
				dustPropagation.push({ x, y, amount });
			}
		}
	}

	calculate_air_cleaner_velocity();

	print_air_cleaner_velocity();

	for (int i = 0; i < time; i++) {
		procedure_propagate();

		print_dusts();
	}

	cout << amount_all_of_dusts();
}