#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> pokemons;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	string pokemon;
	for (int i = 1; i <= n; i++) {
		cin >> pokemon;
		pokemons[pokemon] = to_string(i);
		pokemons[to_string(i)] = pokemon;
	}

	for (int i = 0; i < m; i++) {
		cin >> pokemon;
		cout << pokemons[pokemon] << "\n";
	}
}