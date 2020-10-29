#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int numbers[500000];
int acc = 0;

// range: -4000 ~ 4000
int freq[8001];
int maxFreqs[500000];
int maxFreqsTop = 0;

double avg;
int median;
int mode;
int low, high;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, number;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers[i] = number;

		// Avg. Procedure
		acc += number;

		// Mode. Procedure
		freq[number + 4000]++;

		// Min/Max. Procedure
		if (i == 0) low = high = number;
		low = number < low ? number : low;
		high = number > high ? number : high;
	}

	// Avg. Procedure
	avg = (double)acc / n;
	avg = round(avg);

	// Median. Procedure
	sort(numbers, numbers + n);
	median = numbers[n / 2];

	// Mode. Procedure
	int maxFreq = 0;
	for (int i = 0; i < 8001; i++) {
		number = i - 4000;

		if (freq[i] > maxFreq) {
			maxFreqsTop = 0;
			maxFreq = freq[i];
		}
		if (freq[i] == maxFreq) {
			maxFreqs[maxFreqsTop++] = number;
		}
	}
	sort(maxFreqs, maxFreqs + maxFreqsTop);
	if (maxFreqsTop > 1) {
		mode = maxFreqs[1];
	}
	else {
		mode = maxFreqs[0];
	}

	// Output
	cout << avg << "\n";
	cout << median << "\n";
	cout << mode << "\n";
	cout << (high - low) << "\n";
}