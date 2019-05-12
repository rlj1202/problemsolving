#include <iostream>

int N;
int indices[1000006];
int fenwick[500005];

long long result;

void update(int index, int delta) {
	while (index <= N) {
		fenwick[index] += delta;
		index += index & -index;
	}
}

int accum(int index) {
	int result = 0;
	while (index >= 1) {
		result += fenwick[index];
		index -= index & -index;
	}
	return result;
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int machine;
		scanf("%d", &machine);
		indices[machine] = n;
	}
	for (int n = 1; n <= N; n++) {
		int machine;
		scanf("%d", &machine);

		int index = indices[machine];

		result += accum(N) - accum(index);
		update(index, 1);
	}

	printf("%lld\n", result);

	return 0;
}
