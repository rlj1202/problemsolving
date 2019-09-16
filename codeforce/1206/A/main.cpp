#include <cstdio>

int A[102];
int B[102];
bool check[202];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", A + n);
		check[A[n]] = true;
	}
	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		scanf("%d", B + m);
		check[B[m]] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num = A[i] + B[j];
			if (!check[num]) {
				printf("%d %d\n", A[i], B[j]);
				return 0;
			}
		}
	}

	return 0;
}
