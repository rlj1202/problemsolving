#include <cstdio>

bool X[1003];
bool Z[1003];

int main() {
	int P, Q, L, R;
	scanf("%d %d %d %d", &P, &Q, &L, &R);
	for (int p = 0; p < P; p++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = a; i <= b; i++) {
			Z[i] = true;
		}
	}
	for (int q = 0; q < Q; q++) {
		int c, d;
		scanf("%d %d", &c, &d);
		for (int i = c; i <= d; i++) {
			X[i] = true;
		}
	}

	int result = 0;

	for (int offset = L; offset <= R; offset++) {
		for (int i = 0; i <= 1000; i++) {
			if (i - offset >= 0 && Z[i] && X[i - offset]) {
				result++;
				break;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
