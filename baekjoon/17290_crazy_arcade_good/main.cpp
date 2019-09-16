#include <cstdio>
#include <algorithm>

using namespace std;

char str[12];
bool rows[12];
bool cols[12];

int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int r = 1; r <= 10; r++) {
		scanf("%s", str);

		for (int c = 1; c <= 10; c++) {
			if (str[c - 1] == 'o') {
				rows[r] = true;
				cols[c] = true;
			}
		}
	}

	int result = 0x3f3f3f3f;

	for (int r = 1; r <= 10; r++) {
		for (int c = 1; c <= 10; c++) {
			if (rows[r] || cols[c]) continue;

			int dist = abs(r - R) + abs(c - C);
			result = min(result, dist);
		}
	}

	printf("%d\n", result);

	return 0;
}
