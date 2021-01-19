#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <chrono>

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

typedef struct {
	int x;
	int y;
	int value;
} point;

vector<vector<int>> sparseMatrix;
vector<point> points;

void init(int columnCount) {
	node** columns = new node*[columnCount];

	// initialize columns
	// link each columns
	for (int i = 0; i < columnCount; i++) {
		columns[i] = new node;
		columns[i]->size = 0;
	}

	for (int i = 0; i < columnCount; i++) {
		columns[i]->right = columns[(i + 1) % columnCount];
		columns[i]->right->left = columns[i];

		columns[i]->up = columns[i];
		columns[i]->down = columns[i];
	}

	head = new node;
	head->right = columns[0];
	head->left = head->right->left;
	head->right->left = head;
	head->left->right = head;

	node* previous;
	node* current;

	int rows = sparseMatrix.size();
	// make dancing links
	for (int row = 0; row < rows; row++) {
		previous = NULL;
		current = NULL;

		for (int col : sparseMatrix[row]) {
			current = new node;
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
			if (previous == NULL) {
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

	// filter 0 sized column
	for (node* it = head->right; it != head; it = it->right) {
		if (it->size == 0) {
			it->left->right = it->right;
			it->right->left = it->left;
		}
	}
}

void cover(node* column) {
	node* it;
	node* jt;
	column->left->right = column->right;
	column->right->left = column->left;
	for (it = column->down; it != column; it = it->down) {
		for (jt = it->right; jt != it; jt = jt->right) {
			jt->up->down = jt->down;
			jt->down->up = jt->up;
			jt->column->size--;
		}
	}
}

void uncover(node* column) {
	node* it;
	node* jt;
	for (it = column->down; it != column; it = it->down) {
		for (jt = it->right; jt != it; jt = jt->right) {
			jt->up->down = jt;
			jt->down->up = jt;
			jt->column->size++;
		}
	}
	column->left->right = column;
	column->right->left = column;
}

int table[9][9];

bool search() {
	if (head->right == head) return true;

	node* it;
	node* jt;
	// select a column which has lowest size
	node* selected = head->right;
	int lowest = selected->size;
	for (it = selected; it != head; it = it->right) {
		if (it->size == 1) {
			selected = it;
			break;
		}

		if (it->size < lowest) {
			lowest = it->size;
			selected = it;
		}
	}
	
	// cover the selected column
	cover(selected);
	
	for (it = selected->down; it != selected; it = it->down) {
		for (jt = it->right; jt != it; jt = jt->right) {
			cover(jt->column);
		}

		if (search()) {
			table[points[it->row].y][points[it->row].x] = points[it->row].value;
			return true;
		}

		for (jt = it->right; jt != it; jt = jt->right) {
			uncover(jt->column);
		}
	}

	// uncover, go back and try another
	uncover(selected);

	return false;
}

void sudoku() {
	int num;
	int x, y, i;

	bool horizontal[9][9];
	bool vertical[9][9];
	bool boxed[3][3][9];

	memset(horizontal, 0, sizeof(horizontal));
	memset(vertical, 0, sizeof(vertical));
	memset(boxed, 0, sizeof(boxed));

	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			cin >> num;

			if (num > 0) {
				horizontal[x][num - 1] = true;
				vertical[y][num - 1] = true;
				boxed[y / 3][x / 3][num - 1] = true;

				table[y][x] = num;
			}
		}
	}

	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			if (table[y][x] != 0) continue;

			for (i = 0; i < 9; i++) {
				if (
					horizontal[x][i]
					|| vertical[y][i]
					|| boxed[y / 3][x / 3][i]
				) continue;

				sparseMatrix.push_back({
					// fill any number in (x, y)
					81 * 0 + (9 * y + x),

					// fill unique number (0-9) in same row
					81 * 1 + (9 * y + i),

					// fill unique number (0-9) in same column
					81 * 2 + (9 * x + i),

					// fill unique number (0-9) in boxed
					81 * 3 + (9 * (3 * (y / 3) + (x / 3)) + i)
				});

				points.push_back({ x, y, i + 1 });
			}
		}
	}

	init(324);

	search();

	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			cout << table[y][x] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//auto start = chrono::steady_clock::now();
	sudoku();
	//auto end = chrono::steady_clock::now();

	//auto diff = end - start;

	//cout << chrono::duration<double, milli>(diff).count() << " ms\n";
}