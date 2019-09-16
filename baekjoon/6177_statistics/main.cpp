#include <cstdio>
#include <algorithm>

using namespace std;

int arr[502];
int sum;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
		sum += arr[n];
	}
	sort(arr, arr + N);

	double median;
	if (N % 2 == 0) { // even
		median = (arr[N / 2] + arr[N / 2 - 1]) / 2.0;
	} else { // odd
		median = arr[N / 2];
	}

	printf("%f\n", sum / (double) N);
	printf("%f\n", median);

	return 0;
}
