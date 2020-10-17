#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int next;
	int prev;

	bool asc = false;
	bool dsc = false;

	for (int i = 0; i < 8; i++) {
		if (i == 0) cin >> prev;
		else {
			cin >> next;
			asc = asc || next > prev;
			dsc = dsc || next < prev;
			prev = next;
		}
	}

	cout << (asc && dsc ? "mixed" : asc ? "ascending" : dsc ? "descending" : "");
}