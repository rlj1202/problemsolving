#include <cstdio>
#include <algorithm>

using namespace std;

int values[1003];

int result;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", values + n);
	}

	int start = values[0];

	for (int n = 1; n < N + 1; n++) {
		if (values[n - 1] >= values[n]) {
			int height = values[n - 1] - start;
			result = max(result, height);

			start = values[n];
		}

	}

	printf("%d\n", result);

	return 0;
}
