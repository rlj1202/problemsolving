#include <cstdio>
#include <algorithm>

using namespace std;

int A[5003];
int B[5003];

int Binvshift[5003][5003]; // Binvshift[r-shift][index]

int sum[5003];
int invshiftsum[5003][5003];

int main() {
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int result = 0;
		
		// read input
		int N;
		scanf("%d", &N);
		for (int n = 1; n <= N; n++) scanf("%d", A + n);
		for (int n = 1; n <= N; n++) scanf("%d", B + n);

		// make sum table
		// O(n)
		for (int n = 1; n <= N; n++) {
			sum[n] = sum[n - 1] + (A[n] == B[n]);
		}

		// make inverse-shift table and inverse-shift sum table
		// O(n^2)
		for (int s = 0; s < N; s++) {
			for (int i = 1; i <= N; i++) {
				//int index = (N - i + s) % N + 1;
				int index = N - i + 1 + s;
				if (index > N) index -= N;

				Binvshift[s][i] = B[index];

				invshiftsum[s][i] = invshiftsum[s][i - 1] + (A[i] == Binvshift[s][i]);
			}
		}

		// look up all possible combinations
		// O(n^2)
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				int similarness = 0;

				similarness += sum[i - 1];
				similarness += sum[N] - sum[j];

				int shift = (j) - (N - i + 1);
				if (shift < 0) shift += N;

				similarness += invshiftsum[shift][j] - invshiftsum[shift][i - 1];

				result = max(result, similarness);
			}
		}

		// print result
		printf("Case #%d\n", t);
		printf("%d\n", result);
	}

	return 0;
}
