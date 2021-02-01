#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<char> alphabets;
vector<char> combination;
int combinationLength;

void dfs(int index = 0, int vowels = 0, int consonants = 0) {
	combination.push_back(alphabets[index]);

	bool isVowel = alphabets[index] == 'a'
					|| alphabets[index] == 'e'
					|| alphabets[index] == 'i'
					|| alphabets[index] == 'o'
					|| alphabets[index] == 'u';

	vowels += isVowel;
	consonants += !isVowel;

	if (combination.size() == combinationLength) {
		if (vowels >= 1 && consonants >= 2) {
			for (auto& ch : combination) {
				cout << ch;
			}
			cout << "\n";
		}
		combination.pop_back();
		return;
	}

	for (int i = index + 1; i < alphabets.size(); i++) {
		dfs(i, vowels, consonants);
	}

	combination.pop_back();
}

void generateCombinations() {
	for(int i = 0; i < alphabets.size(); i++) dfs(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	char ch;
	cin >> combinationLength >> n;

	for (int i = 0; i < n; i++) {
		cin >> ch;
		alphabets.push_back(ch);
	}

	sort(alphabets.begin(), alphabets.end());

	generateCombinations();
}