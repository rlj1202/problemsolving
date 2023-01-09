#include <iostream>
#include <algorithm>

using namespace std;

int Q;

int main() {
	scanf("%d", &Q);

	while (Q--) {
		int l1, l2;
		int r1, r2;
		scanf("%d %d", &l1, &l2);
		scanf("%d %d", &r1, &r2);

		int a = l1;
		int b = r1 == a ? r2 : r1;
		printf("%d %d\n", a, b);
	}

	return 0;
}
