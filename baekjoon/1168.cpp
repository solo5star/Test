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
		nodes[i].next = &nodes[i % n + 1];
	}

	cout << "<";

	remain = n;
	node* current = &nodes[1];
	node* removed;

	while (remain) {
		removed = current->next->next;
		current->next->next = removed->next;
		
		current = removed->next;
		remain--;

		cout << removed->id << (remain ? ", " : ">");
	}
}