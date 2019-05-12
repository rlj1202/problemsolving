#include <iostream>

int N, Q;
bool slots[10004];

int main() {
	scanf("%d %d", &N, &Q);
	for (int q = 0; q < Q; q++) {
		int l, i;
		scanf("%d %d", &l, &i);
		for (int s = l - 1; s < N; s += i) slots[s] = true;
	}

	int empty = 0;
	for (int s = 0; s < N; s++) if (!slots[s]) empty++;

	printf("%d\n", empty);

	return 0;
}
