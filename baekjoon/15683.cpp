#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

const int EMPTY = 0;
const int WALL = -1;

int map[8][8];
int width;
int height;

int emptyCount = 0;

bool hasCCTV(int x, int y, int id) {
	if (map[y][x] == WALL) return false;

	return map[y][x] & (1 << id);
}

void removeCCTV(int x, int y, int id) {
	if (map[y][x] == WALL) return;
	if (map[y][x] == 0) return;

	map[y][x] &= ~(1 << id);

	if (map[y][x] == 0) emptyCount++;
}

void addCCTV(int x, int y, int id) {
	if (map[y][x] == WALL) return;

	if (map[y][x] == 0) emptyCount--;

	map[y][x] |= (1 << id);
}

class CCTV {
public:
	static int counter;

	int id;
	int angle = 0;
	int x, y;

	CCTV(int x, int y)
		: x(x)
		, y(y)
		, id(++counter)
	{ }

	virtual int getRotateTrialCount() {
		return 4;
	}

	virtual void rotate(int _angle = 90) {
		angle = (angle + _angle) % 360;
	}

	void initializeSight() {
		rotate(0);
	}

	void setSight(int _angle, bool set) {
		_angle = _angle % 360;

		int __x = _angle == 0 ? 1 : _angle == 180 ? -1 : 0;
		int __y = _angle == 90 ? 1 : _angle == 270 ? -1 : 0;

		switch (_angle) {
		case 0:
		case 180:
			for (int _x = x; 0 <= _x && _x < width; _x += __x) {
				if (map[y][_x] == WALL) break;

				set ? addCCTV(_x, y, id) : removeCCTV(_x, y, id);
			}
			break;

		case 90:
		case 270:
			for (int _y = y; 0 <= _y && _y < height; _y += __y) {
				if (map[_y][x] == WALL) break;

				set ? addCCTV(x, _y, id) : removeCCTV(x, _y, id);
			}
			break;
		}

	}
};

int CCTV::counter = 0;

class CCTV_1 : public CCTV {
	using CCTV::CCTV;

	void rotate(int _angle) {
		setSight(angle, false);

		CCTV::rotate(_angle);

		setSight(angle, true);
	}
};

class CCTV_2 : public CCTV {
	using CCTV::CCTV;

	int getRotateTrialCount() {
		return 2;
	}

	void rotate(int _angle) {
		setSight(angle, false);
		setSight(angle + 180, false);

		CCTV::rotate(_angle);

		setSight(angle, true);
		setSight(angle + 180, true);
	}
};

class CCTV_3 : public CCTV {
	using CCTV::CCTV;

	void rotate(int _angle) {
		setSight(angle, false);

		CCTV::rotate(_angle);

		setSight(angle, true);
		setSight(angle + 90, true);
	}
};

class CCTV_4 : public CCTV {
	using CCTV::CCTV;

	void rotate(int _angle) {
		setSight(angle, false);

		CCTV::rotate(_angle);

		setSight(angle, true);
		setSight(angle + 90, true);
		setSight(angle + 180, true);
	}
};

class CCTV_5 : public CCTV {
	using CCTV::CCTV;

	int getRotateTrialCount() {
		return 1;
	}

	void rotate(int _angle) {
		setSight(angle, true);
		setSight(angle + 90, true);
		setSight(angle + 180, true);
		setSight(angle + 270, true);
	}
};

void print() {
#ifdef DEBUG
	cout << "\n";
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << map[y][x] << " ";
		}
		cout << "\n";
	}
	cout << "EMPTY COUNT=" << emptyCount << "\n";
#endif
}

CCTV* installed[8];
int installedCount = 0;

int minValue;

void tryRotation(int i = 0) {
	if (i >= installedCount) return;

	int trialCount = installed[i]->getRotateTrialCount();

	for (int j = 0; j < trialCount; j++) {
		installed[i]->rotate();

		if (emptyCount < minValue) {
			minValue = emptyCount;

			print();
		}

		tryRotation(i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tile;

	cin >> height >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> tile;

			CCTV* cctv = nullptr;

			switch (tile) {
			case 1:
				cctv = new CCTV_1(x, y);
				break;
			case 2:
				cctv = new CCTV_2(x, y);
				break;
			case 3:
				cctv = new CCTV_3(x, y);
				break;
			case 4:
				cctv = new CCTV_4(x, y);
				break;
			case 5:
				cctv = new CCTV_5(x, y);
				break;
			case 6:
				map[y][x] = WALL;
				break;
			default:
				break;
			}

			emptyCount += map[y][x] != WALL;

			if (cctv != nullptr) {
				installed[installedCount++] = cctv;
				addCCTV(x, y, cctv->id);
			}
		}
	}

	for (int i = 0; i < installedCount; i++) {
		installed[i]->initializeSight();
	}

	print();

	minValue = emptyCount;
	tryRotation();

	cout << minValue;

	for (int i = 0; i < installedCount; i++) {
		delete installed[i];
	}
}