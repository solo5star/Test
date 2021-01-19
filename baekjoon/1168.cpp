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

using namespace std;

typedef struct node {
	int id;
	node* previous;
	node* next;
} node;

int remain;

node nodes[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		nodes[i].id = i;
		nodes[i].previous = &nodes[i == 1 ? n : i - 1];
		nodes[i].next = &nodes[i == n ? 1 : i + 1];
	}

	cout << "<";

	remain = n;
	node* current = &nodes[1];

	while (remain) {
		for (int i = 1; i < k; i++) {
			current = current->next;
		}

		remain--;
		cout << current->id << (remain ? ", " : ">");

		current->previous->next = current->next;
		current->next->previous = current->previous;

		current = current->next;
	}
}