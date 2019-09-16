#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

long long powtwo[300005];

long long score[300005];

int main() {
	powtwo[0] = 1;
	for (int e = 1; e <= 300000; e++) {
		powtwo[e] = powtwo[e - 1] << 1;
		powtwo[e] %= MOD;
	}

	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%lld", score + n);
	sort(score, score + N);

	long long result = 0;

	for (int i = 0; i < N; i++) {
		if (i > 0) {
			result += score[i] * (powtwo[i] - 1);
		}
		if (i < N - 1) {
			result -= score[i] * (powtwo[N - i - 1] - 1);
		}
		result %= MOD;
	}

	printf("%lld\n", result);

	return 0;
}
