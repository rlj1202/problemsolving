#include <iostream>
#include <algorithm>

using namespace std;

int N;
int series[1003];

int lis[1003];
int sum[1003];
int len;

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", series + n);
	}

	int result = 0;

	for (int n = 1; n <= N; n++) {
		int cur = series[n];

		int index = upper_bound(lis + 1, lis + 1 + len, cur) - lis;

		lis[index] = cur;
		sum[index] = sum[index], cur + sum[index - 1];

		result = max(result, sum[index]);

		if (index > len) len++;

		//for (int i = 1; i <= len; i++) printf("%d ", lis[i]);
		//printf("\t\t%d\n", sum[index]);
	}

	printf("%d\n", result);

	return 0;
}
