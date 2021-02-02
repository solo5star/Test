#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string rsp[10];
int robots;
int _round;
unordered_set<int> winners;

void lose(char ch) {
	for (int i = 0; i < robots; i++) {
		if (rsp[i][_round] == ch) winners.erase(i);
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

		for (int i = 0; i < robots; i++) {
			cin >> rsp[i];
			winners.insert(i);
		}

		int rounds = rsp[0].length();
		for (_round = 0; _round < rounds; _round++) {
			bool r = false, s = false, p = false;

			for (int robot : winners) {
				switch (rsp[robot][_round]) {
				case 'R': r = true; break;
				case 'S': s = true; break;
				case 'P': p = true; break;
				}
			}

			if (r && s && p) continue;

			if (r && s) lose('S');
			else if (r && p) lose('R');
			else if (p && s) lose('P');

			if (winners.size() == 1) {
				for (auto& winner : winners) {
					cout << winner + 1 << "\n";
					break;
				}
				// finish the game
				roundsFinished = true;
				break;
			}
		}

		if (roundsFinished) continue;
		else cout << 0 << "\n";

		winners.clear();
	}
}