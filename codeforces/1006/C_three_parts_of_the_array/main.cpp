#include <iostream>

int N;
int arr[200005];

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}

	long long max = 0;

	int left = 0;
	int right = N;

	long long leftSum = 0;
	long long rightSum = 0;

	while (left < right) {
		leftSum += arr[left++];

		while (left < right && rightSum + arr[right - 1] <= leftSum) {
			rightSum += arr[--right];
		}

		if (leftSum == rightSum) {
			max = leftSum;
		}
	}

	printf("%lld\n", max);

	return 0;
}
