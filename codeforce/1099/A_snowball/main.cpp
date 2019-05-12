#include <iostream>
#include <algorithm>

using namespace std;

int w, h;
int u1, d1;
int u2, d2;

int main() {
	scanf("%d %d", &w, &h);
	scanf("%d %d", &u1, &d1);
	scanf("%d %d", &u2, &d2);

	while (h > 0) {
		w += h;

		if (h == d1) {
			w -= u1;
		} else if (h == d2) {
			w -= u2;
		}
		w = max(w, 0);

		h--;
	}

	printf("%d\n", w);

	return 0;
}
