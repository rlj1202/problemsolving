#include <iostream>
#include <algorithm>

using namespace std;

int needs[3];
int grapes[3];

int main() {
	for (int i = 0; i < 3; i++) scanf("%d", needs + i);
	for (int i = 0; i < 3; i++) scanf("%d", grapes + i);

	bool result = true;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= i; j++) {
			int take = min(grapes[j], needs[i]);
			grapes[j] -= take;
			needs[i] -= take;
		}
		if (needs[i] > 0) {
			result = false;
			break;
		}
	}

	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
