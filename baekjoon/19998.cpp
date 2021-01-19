#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
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

node head;
node columns[324];
int columnCount;

node nodeStore[2916];
int nodeCount = 0;

typedef struct {
	int x;
	int y;
	char value;
} point;

int sparseMatrix[729][4];
int rows;
point points[729];

void init() {
	// initialize columns
	// link each columns
	for (int i = 0; i < columnCount; i++) {
		columns[i].right = &columns[(i + 1) % columnCount];
		columns[i].right->left = &columns[i];

		columns[i].up = &columns[i];
		columns[i].down = &columns[i];
	}

	head.right = &columns[0];
	head.left = head.right->left;
	head.right->left = &head;
	head.left->right = &head;

	node* previous;
	node* current;

	int row, j, col;
	// make dancing links
	for (row = 0; row < rows; row++) {
		previous = nullptr;
		current = nullptr;

		for (j = 0; j < 4; j++) {
			col = sparseMatrix[row][j];

			current = &nodeStore[nodeCount++];
			current->row = row;

			// link with column
			current->column = &columns[col];
			current->column->size++;

			// link with bottom node
			current->up = columns[col].up;
			current->down = &columns[col];
			columns[col].up->down = current;
			columns[col].up = current;

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

inline void cover(node* column) {
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

inline void uncover(node* column) {
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

char table[9][9];

bool search() {
	if (head.right == &head) return true;

	node* it;
	node* jt;
	// select a column which has lowest size
	node* selected = head.right;
	int lowest = selected->size;
	for (it = selected; it != &head; it = it->right) {
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
	char num;
	int x, y;

	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			cin >> num;
			num -= '0';

			for (int i = 0; i < 9; i++) {
				if (num != 0) i = num - 1;

				// fill any number in (x, y)
				sparseMatrix[rows][0] = 81 * 0 + (9 * y + x);

				// fill unique number (0-9) in same row
				sparseMatrix[rows][1] = 81 * 1 + (9 * y + i);

				// fill unique number (0-9) in same column
				sparseMatrix[rows][2] = 81 * 2 + (9 * x + i);

				// fill unique number (0-9) in sub-square
				sparseMatrix[rows][3] = 81 * 3 + (9 * (3 * (y / 3) + (x / 3)) + i);

				points[rows].x = x;
				points[rows].y = y;
				points[rows].value = i + 1 + '0';

				rows++;

				if (num != 0) break;
			}
		}
	}

	columnCount = 324;

	init();

	search();

	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			cout << table[y][x] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//auto start = chrono::steady_clock::now();
	sudoku();
	//auto end = chrono::steady_clock::now();

	//auto diff = end - start;
	//cout << chrono::duration<double, milli>(diff).count() << " ms\n";
}