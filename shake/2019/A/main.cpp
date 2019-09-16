#include <cstdio>
#include <algorithm>

using namespace std;

int pattern[12];

bool used[3][3];

int main() {
	// read input
	int L;
	scanf("%d", &L);
	for (int l = 0; l < L; l++) {
		scanf("%d", pattern + l);
		pattern[l]--; // to make zero-based indices
	}

	//
	bool result = true;

	int prev = -1;
	int prevr = -1;
	int prevc = -1;
	for (int l = 0; l < L; l++) {
		int cur = pattern[l];
		int c = cur % 3;
		int r = cur / 3;

		if (used[r][c]) {
			result = false;
			break;
		}

		used[r][c] = true;

		if (prev != -1) {
			int dr = r - prevr;
			int dc = c - prevc;

			if ((abs(dr) == abs(dc)) || dr == 0 || dc == 0) {
				if (dr != 0) dr /= abs(dr);
				if (dc != 0) dc /= abs(dc);

				int curr = prevr + dr;
				int curc = prevc + dc;

				while (curr != r || curc != c) {
					if (!used[curr][curc]) {
						result = false;
						break;
					}
					curr += dr;
					curc += dc;
				}
			}
		}

		prev = cur;
		prevr = r;
		prevc = c;
	}

	// print result
	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
