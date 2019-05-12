#include <iostream>
#include <algorithm>

using namespace std;

int N;
int solutions[100005];

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++)
		scanf("%d", solutions + n);

	sort(solutions, solutions + N);

	int l = 0;
	int r = N - 1;

	int resultA = solutions[l];
	int resultB = solutions[r];
	int minsum = resultA + resultB;
	
	while (l < r) {
		int a = solutions[l];
		int b = solutions[r];

		int sum = a + b;

		if (abs(minsum) > abs(sum)) {
			minsum = sum;
			resultA = a;
			resultB = b;
		}

		if (abs(a) < abs(b)) {
			r--;
		} else {
			l++;
		}
	}

	printf("%d %d\n", resultA, resultB);

	return 0;
}
