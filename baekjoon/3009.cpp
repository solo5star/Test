#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x_coords[3];
	int y_coords[3];

	cin >> x_coords[0];
	cin >> y_coords[0];
	cin >> x_coords[1];
	cin >> y_coords[1];
	cin >> x_coords[2];
	cin >> y_coords[2];

	if (x_coords[2] == x_coords[0]) cout << x_coords[1];
	else if (x_coords[2] == x_coords[1]) cout << x_coords[0];

	cout << " ";

	if (y_coords[2] == y_coords[0]) cout << y_coords[1];
	else if (y_coords[2] == y_coords[1]) cout << y_coords[0];
}