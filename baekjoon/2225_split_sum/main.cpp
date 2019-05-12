#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000000;

int N, K;
int tri[402][202];

int main() {
	scanf("%d %d", &N, &K);

	int a = (N + 1) + (K - 1) - 1;
	int b = (K - 1);

	for (int n = 0; n <= a; n++) {
		tri[n][0] = 1;
		for (int k = 1; k <= n; k++) {
			tri[n][k] = tri[n - 1][k - 1] + tri[n - 1][k];
			tri[n][k] %= MOD;
		}
	}

	printf("%d\n", tri[a][b]);

	return 0;
}
