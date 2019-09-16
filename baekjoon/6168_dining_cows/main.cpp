#include <cstdio>
#include <algorithm>

using namespace std;

int cows[30004];

int ones;
int twos;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", cows + n);
		if (cows[n] == 1) ones++;
	}

	int result = 0x3f3f3f3f;

	for (int n = 0; n < N + 1; n++) {
		int cost = twos + ones;
		result = min(result, cost);

		if (cows[n] == 2) {
			twos++;
		} else {
			ones--;
		}
	}

	printf("%d\n", result);

	return 0;
}
