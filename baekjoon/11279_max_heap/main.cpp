#include <iostream>

int N;
int heap[100005];
int size;

void push(int x) {
	heap[size++] = x;

	int child = size - 1;
	while (child > 0) {
		int parent = (child - 1) / 2;
		if (heap[parent] < heap[child]) {
			int tmp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = tmp;
			child = parent;
		} else {
			break;
		}
	}
}

void pop() {
	if (size == 0) return;
	heap[0] = heap[--size];

	int parent = 0;
	int child;
	while ((child = parent * 2 + 1) < size) {
		int childR = parent * 2 + 2;
		if (childR < size && heap[childR] > heap[parent] && heap[childR] > heap[child]) child = childR;
		if (heap[child] > heap[parent]) {
			int tmp = heap[child];
			heap[child] = heap[parent];
			heap[parent] = tmp;
			parent = child;
		} else {
			break;
		}
	}
}

int top() {
	return size > 0 ? heap[0] : 0;
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);
		if (value > 0) push(value);
		else {
			printf("%d\n", top());
			pop();
		}
	}

	return 0;
}
