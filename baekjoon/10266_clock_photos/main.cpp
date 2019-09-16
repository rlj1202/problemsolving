#include <cstdio>
#include <algorithm>

using namespace std;

int clock[2][200005];

int a[400005];
int b[200005];

int pi[200005];

void makefailure(int *arr) {
	int j = 0;
	for (int i = 1; arr[i] != 0; i++) {
		while (j && arr[i] != arr[j])
			j = pi[j - 1];

		if (arr[i] == arr[j])
			pi[i] = ++j;
	}
}

int main() {
	// read input
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 2; i++) {
		for (int n = 0; n < N; n++) {
			scanf("%d", &clock[i][n]);
		}
		sort(&clock[i][0], &clock[i][N]);
	}
	
	// get delta
	for (int n = 0; n < N - 1; n++) {
		int delta = clock[0][n + 1] - clock[0][n];
		a[n] = delta;
		a[n + N] = a[n];
	}
	a[N - 1] = clock[0][0] - clock[0][N - 1];
	a[N - 1 + N] = a[N - 1];

	for (int n = 0; n < N - 1; n++) {
		int delta = clock[1][n + 1] - clock[1][n];
		b[n] = delta;
	}
	b[N - 1] = clock[1][0] - clock[1][N - 1];

	for (int n = 0; n < N*2; n++) {
		if (a[n] < 0) a[n] += 360000;
	}
	for (int n = 0; n < N; n++) {
		if (b[n] < 0) b[n] += 360000;
	}

	// make failure
	makefailure(b);

	// run kmp
	bool found = false;
	int j = 0;
	for (int i = 0; a[i] != 0; i++) {
		while (j && a[i] != b[j])
			j = pi[j - 1];

		if (a[i] == b[j]) {
			j++;

			if (j == N) {
				found = true;
				break;
			}
		}
	}

	// print result
	printf("%s\n", found ? "possible" : "impossible");

	return 0;
}
