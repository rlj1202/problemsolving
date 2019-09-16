#include <cstdio>
#include <algorithm>

using namespace std;

int nums[30004];

int updp[30004][4];
int downdp[30004][4];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++)
		scanf("%d", nums + n);

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= 3; i++) {
			updp[n][i] = updp[n - 1][i] + (nums[n] != i);
			if (i > 1) updp[n][i] = min(
					updp[n][i],
					updp[n - 1][i - 1] + (nums[n] != i));
		}
	}

	printf("%d\n", 0);

	return 0;
}
