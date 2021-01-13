#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> ac;
unordered_map<string, int> failures;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int id, result, memory, time, lang, len;
	string user;

	int success = 0;
	int failure = 0;

	for (int i = 0; i < n; i++) {
		cin >> id >> user >> result >> memory >> time >> lang >> len;

		if (user == "megalusion") continue;

		if (ac.count(user)) continue;

		if (result == 4) {
			ac.insert(user);
			success++;
		}
		else {
			failures[user] = failures.count(user) ? failures[user] + 1 : 1;
		}
	}

	for (string user : ac) {
		if(failures.count(user)) failure += failures[user];
	}

	cout.precision(12);

	if (success == 0) cout << 0;

	else cout << (success / ((double)success + failure)) * 100;
}