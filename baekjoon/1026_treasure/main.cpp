#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int A[50];
int B[50];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", A + n);
	for (int n = 0; n < N; n++) scanf("%d", B + n);
	sort(A, A + N);
	sort(B, B + N);

	int result = 0;
	for (int n = 0; n < N; n++) result += A[n] * B[N - n - 1];
	printf("%d\n", result);

	return 0;
}
