#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int init[3];
		int targ[3];
		for (int i = 0; i < 3; i++) scanf("%d", init + i);
		for (int i = 0; i < 3; i++) scanf("%d", targ + i);

		int count = 0;

		for (int i = 0; i < 3; i++) {
			int delta = abs(init[i] - targ[i]);

			count += delta > 5 ? 10 - delta : delta;
		}

		printf("%d\n", count);
	}

	return 0;
}
