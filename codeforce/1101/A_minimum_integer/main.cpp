#include <iostream>

int Q;

int main() {
	scanf("%d", &Q);

	while (Q--) {
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);

		if (d < l || r < d) {
			printf("%d\n", d);
		} else {
			printf("%d\n", d * (r / d + 1));
		}
	}

	return 0;
}
