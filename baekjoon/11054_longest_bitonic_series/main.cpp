#include <iostream>
#include <cstring>

using namespace std;

int N;
int series[1003];

int rdp[1003];
int ldp[1003];

int right_longest(int index) {
	if (rdp[index] != -1) return rdp[index];

	int result = 0;
	for (int next = index + 1; next <= N; next++) {
		if (series[index] <= series[next]) continue;

		result = max(result, right_longest(next));
	}

	return rdp[index] = 1 + result;
}

int left_longest(int index) {
	if (ldp[index] != -1) return ldp[index];

	int result = 0;
	for (int next = index - 1; next >= 1; next--) {
		if (series[next] >= series[index]) continue;

		result = max(result, left_longest(next));
	}

	return ldp[index] = 1 + result;
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", series + n);
	}

	memset(rdp, -1, sizeof(rdp));
	memset(ldp, -1, sizeof(ldp));

	int result = 0;
	for (int n = 1; n <= N; n++) {
		result = max(result, left_longest(n) + right_longest(n));
	}

	printf("%d\n", result - 1);

	return 0;
}
