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
#include <cstring>

using namespace std;

// Knuth X (with dancing links)
//
// Sudoku solve algorithm

typedef struct node {
	int row;
	int size;

	node* column;

	node* up;
	node* down;
	node* right;
	node* left;
} node;

node* head;
node* columns[324];
int columnCount;

typedef struct {
	int x;
	int y;
	int value;
} point;

vector<vector<int>> sparseMatrix;
vector<point> points;

vector<int> solution;

node* createNode() {
	node* n = new node;
	memset(n, 0, sizeof(node));

	return n;
}

void init() {
	// initialize columns
	// column[0] is head
	for (int i = 0; i < columnCount; i++) {
		columns[i] = createNode();
	}

	// link each columns
	for (int i = 0; i < columnCount; i++) {
		columns[i]->right = columns[(i + 1) % columnCount];
		columns[i]->right->left = columns[i];

		columns[i]->up = columns[i];
		columns[i]->down = columns[i];
	}

	// link head
	head = createNode();

	head->right = columns[0];
	head->left = head->right->left;
	head->right->left = head;
	head->left->right = head;

	// make dancing links
	for (int row = 0; row < sparseMatrix.size(); row++) {
		node* previous = nullptr;
		node* current = nullptr;

		for (int col : sparseMatrix[row]) {
			current = createNode();
			current->row = row;

			// link with column
			current->column = columns[col];
			current->column->size++;

			// link with bottom node
			current->up = columns[col]->up;
			current->down = columns[col];
			columns[col]->up->down = current;
			columns[col]->up = current;

			// link with left and right
			if (previous == nullptr) {
				previous = current;
				previous->right = current;
			}
			current->right = previous->right;
			current->left = previous;
			previous->right->left = current;
			previous->right = current;

			previous = current;
		}
	}
}

void cover(node* column) {
	column->left->right = column->right;
	column->right->left = column->left;

	for (node* it = column->down; it != column; it = it->down) {
		for (node* jt = it->right; jt != it; jt = jt->right) {
			jt->up->down = jt->down;
			jt->down->up = jt->up;

			jt->column->size--;
		}
	}
}

void uncover(node* column) {
	for (node* it = column->down; it != column; it = it->down) {
		for (node* jt = it->right; jt != it; jt = jt->right) {
			jt->up->down = jt;
			jt->down->up = jt;

			jt->column->size++;
		}
	}

	column->left->right = column;
	column->right->left = column;
}

bool search() {
	if (head->right == head) return true;

	// select a column which has lowest size
	node* selected = head->right;
	int lowest = head->right->size;
	for (node* it = selected->right; it != head; it = it->right) {
		if (it->size < lowest) {
			lowest = it->size;
			selected = it;
		}
	}

#ifdef DEBUG
	cout << "SELECTED: " << selected->size << "\n";
#endif
	
	// cover the selected column
	cover(selected);

	for (node* it = selected->down; it != selected; it = it->down) {
		for (node* jt = it->right; jt != it; jt = jt->right) {
			cover(jt->column);
		}

		solution.push_back(it->row);

		if (search()) return true;

		solution.pop_back();

		for (node* jt = it->right; jt != it; jt = jt->right) {
			uncover(jt->column);
		}
	}

	// uncover, go back and try another
	uncover(selected);

	return false;
}

int table[9][9];

void sudoku() {
	int num;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> num;

			for (int i = 0; i < 9; i++) {
				if (num != 0) i = num - 1;

				sparseMatrix.push_back({
					// fill any number in (x, y)
					81 * 0 + (9 * y + x),
					// fill unique number (0-9) in same row
					81 * 1 + (9 * y + i),
					// fill unique number (0-9) in same column
					81 * 2 + (9 * x + i),
					// fill unique number (0-9) in sub-square
					81 * 3 + (9 * (3 * (y / 3) + (x / 3)) + i)
				});
				points.push_back({ x, y, i + 1 });

				if (num != 0) break;
			}
		}
	}

	columnCount = 81 * 4;

	init();

#ifdef DEBUG
	cout << "PRINT COLUMNS SIZE: \n";
	int counter = 0;
	for (node* it = head->right; it != head; it = it->right) {
		cout << it->size << " ";
		if (++counter % 81 == 0) {
			cout << "\n";
		}
	}
	cout << "PRINT END(" << counter << ")\n";
#endif

	search();

	for (int i : solution) {
		table[points[i].y][points[i].x] = points[i].value;
	}

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << table[y][x] << " ";
		}
		cout << "\n";
	}
}

void test() {
	/**
	 * X = {1, 2, 3, 4, 5, 6, 7}
	 *
	 * A = {      3,    5, 6   }
	 * B = {1,       4,       7}
	 * C = {   2, 3,       6   }
	 * D = {1,       4         }
	 * E = {   2,             7}
	 * F = {         4, 5,    7}
	 */
	sparseMatrix.push_back({ 2, 4, 5 });
	sparseMatrix.push_back({ 1, 3, 6 });
	sparseMatrix.push_back({ 1, 2, 5 });
	sparseMatrix.push_back({ 0, 3 });
	sparseMatrix.push_back({ 1, 6 });
	sparseMatrix.push_back({ 3, 4, 6 });

	columnCount = 7;

	init();

	search();

	for (int i : solution) {
		cout << i << " ";
	}

	// expected result: 0 3 4
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	sudoku();
}