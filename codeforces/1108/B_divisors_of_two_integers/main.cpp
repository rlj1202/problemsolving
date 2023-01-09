#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[200];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}
	sort(arr, arr + N);

	int a;
	int b;

	int l = 0;
	int r = N - 1;
	int mul = arr[l] * arr[r];
	a = mul;
	while (l < r) {
		int cur = arr[l] * arr[r];
		if (mul == cur) {
			arr[l] = 0;
			arr[r] = 0;
			l++;
			r--;
		} else if (mul < cur) {
			r--;
		} else {
			l++;
		}
	}
	
	b = *max_element(arr, arr + N);
	if (b == 0) b = a;

	printf("%d %d\n", a, b);

	return 0;
}
