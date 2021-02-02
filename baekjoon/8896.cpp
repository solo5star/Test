#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string rsp[10];
int robots;
int _round;
unordered_set<int> losers;

void lose(char ch) {
	for (int robot = 0; robot < robots; robot++) {
		if (rsp[robot][_round] == ch) losers.insert(robot);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		bool roundsFinished = false;
		cin >> robots;

		losers.clear();

		for (int i = 0; i < robots; i++) {
			cin >> rsp[i];
		}

		int rounds = rsp[0].length();
		for (_round = 0; _round < rounds; _round++) {
			bool R = false, S = false, P = false;

			for (int robot = 0; robot < robots; robot++) {
				if (losers.count(robot)) continue;

				switch (rsp[robot][_round]) {
				case 'R': R = true; break;
				case 'S': S = true; break;
				case 'P': P = true; break;
				}
			}

			// DRAW
			if (R && S && P) continue;

			else if (R && S) lose('S');
			else if (R && P) lose('R');
			else if (P && S) lose('P');

			// DRAW
			else continue;

			if (losers.size() == robots - 1) {
				for (int robot = 0; robot < robots; robot++) {
					if (losers.count(robot)) continue;

					cout << robot + 1 << "\n";
					break;
				}

				// finish the game
				roundsFinished = true;
				break;
			}
		}

		if (!roundsFinished) cout << 0 << "\n";
	}
}