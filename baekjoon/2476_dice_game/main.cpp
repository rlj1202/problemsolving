#include <cstdio>
#include <algorithm>

using namespace std;

int result;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int price;

		if (a == b && b == c) {
			price = 10000 + a * 1000;
		} else if (a != b && b != c && a != c) {
			int maxvalue = max(a, max(b, c));
			price = maxvalue * 100;
		} else {
			if (a == b) {
				price = 1000 + a * 100;
			} else if (a == c) {
				price = 1000 + a * 100;
			} else if (b == c) {
				price = 1000 + b * 100;
			}
		}

		result = max(result, price);
	}

	printf("%d\n", result);

	return 0;
}
