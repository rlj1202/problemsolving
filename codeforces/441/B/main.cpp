#include <cstdio>
#include <algorithm>

using namespace std;

int fruits[3003];

int main() {
	int N, V;
	scanf("%d %d", &N, &V);
	for (int n = 0; n < N; n++) {
		int a, b;
		scanf("%d %d", &a, &b);
		fruits[a] += b;
	}

	int result = 0;

	for (int d = 1; d <= 3001; d++) {
		int remains = V;

		if (fruits[d - 1]) {
			int delta = min(fruits[d - 1], remains);

			result += delta;
			remains -= delta;
		}

		if (fruits[d]) {
			int delta = min(fruits[d], remains);

			result += delta;
			remains -= delta;
			fruits[d] -= delta;
		}
	}

	printf("%d\n", result);

	return 0;
}
