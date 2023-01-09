#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[300005];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", arr + n);
	sort(arr, arr + N);

	long long result = 0;

	int l = 0;
	int r = N - 1;
	while (l < r) {
		int add = arr[l] + arr[r];
		result += add * add;
		l++;
		r--;
	}

	printf("%lld\n", result);

	return 0;
}
