#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[10004];
int maxPay;

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int p, d;
		scanf("%d %d", &p, &d);

		for (int day = d; day > 0; day--) {
		}

		maxPay = max(maxPay, p);
	}

	int sum = 0;

	for (int day = 1; day <= 10000; day++) {
		sum += D[day];
	}

	printf("%d\n", sum);

	return 0;
}
