#include <iostream>
#include <algorithm>

using namespace std;

int N;

int result;

int main() {
	scanf("%d", &N);

	int l = 1;
	int r = N;
	result = l + r;

	while (l < r) {
		l++;
		while (N <= l * (r - 1)) r--;
		result = min(result, l + r);
	}

	printf("%d\n", result);

	return 0;
}
