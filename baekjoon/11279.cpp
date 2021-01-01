#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

int heap[100001];
int index = 0;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// a > b : Min heap
// a < b : Max heap
bool cmp(int a, int b) {
	return a < b;
}

void print_heap() {
	cout << "[ ";
	for (int i = 0; i < index; i++) {
		cout << heap[i] << " ";
	}
	cout << "]\n";
}

void push_heap(int n) {
	heap[index] = n;

	int current = index;
	while (current > 0) {
		int parent = (current+1) / 2 - 1;

		if (!cmp(heap[parent], heap[current])) break;

		swap(&heap[parent], &heap[current]);
		current = parent;
	}

	index++;
}

int pop_heap() {
	int popped = heap[0];

	heap[0] = heap[index - 1];
	index--;

	int current = 0;
	while (true) {
		int child = (current * 2) + 1;
		if (!(child < index)) break;

		int child2 = (current * 2) + 2;
		if (child2 < index && cmp(heap[child], heap[child2])) child = child2;

		if (cmp(heap[child], heap[current])) break;

		swap(&heap[current], &heap[child]);
		current = child;
	}

	return popped;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ins;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ins;

		if (ins == 0) {
			if (index == 0) {
				cout << 0;
			}
			else {
				cout << pop_heap();
			}
			cout << "\n";
		}
		else {
			push_heap(ins);
		}
	}
}