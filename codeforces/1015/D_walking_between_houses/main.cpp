#include <iostream>

int N, K;
long long S;
int seq[200005];

bool f(int index, int cnt, long long sum) {
	if (cnt == K) return sum == S;

	if (index <= (N + 1) / 2) {
		for (int next = N; next > index; next--) {
			seq[cnt] = next;
			bool result = f(next, cnt + 1, sum + next - index);
			
			if (result) return true;
		}
	} else {
		for (int next = 1; next < index; next++) {
			seq[cnt] = next;
			bool result = f(next, cnt + 1, sum + index - next);

			if (result) return true;
		}
	}

	return false;
}

int main() {
	// read input
	scanf("%d %d %lld", &N, &K, &S);

	bool result = f(1, 0, 0);

	// print result
	printf("%s\n", result ? "YES" : "NO");
	if (result) {
		for (int k = 0; k < K; k++) {
			printf("%d ", seq[k]);
		}
		printf("\n");
	}

	return 0;
}
