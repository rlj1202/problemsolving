#include <cstdio>
#include <algorithm>

using namespace std;

char seq[200005];

int stack;

int tmpDelta;
bool moved;

int main() {
	int N;
	scanf("%d %s", &N, seq + 1);

	if (N % 2 == 1) {
		printf("No\n");
		return 0;
	}

	int minheight = 0x3f3f3f3f;

	bool possible = true;

	for (int i = 1; seq[i]; i++) {
		int delta = seq[i] == '(' ? 1 : -1;

		if (stack + delta >= 0) {
			stack += delta;
		} else { // error!
			if (moved) {
				possible = false;
				break;
			} else {
				if (tmpDelta == 0) {
					tmpDelta = delta;
				} else {
					if (stack + tmpDelta + delta >= 0) {
						stack += tmpDelta + delta;
						moved = true;
					} else {
						possible = false;
						break;
					}
				}
			}
		}
	}

	if (!moved && tmpDelta) {
		if (stack + tmpDelta >= 0) {
			stack += tmpDelta;
		} else {
			possible = false;
		}
	}

	if (stack != 0) possible = false;

	printf("%s\n", possible ? "Yes" : "No");

	return 0;
}
