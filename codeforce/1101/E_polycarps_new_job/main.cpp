#include <iostream>
#include <algorithm>

using namespace std;

int N;

int maxwidth;
int maxheight;

int main() {
	scanf("%d", &N);

	while (N--) {
		char cmd;
		int w, h;
		scanf(" %c %d %d", &cmd, &w, &h);

		if (w < h) {
			int tmp = w;
			w = h;
			h = tmp;
		}

		if (cmd == '+') {
			maxwidth = max(maxwidth, w);
			maxheight = max(maxheight, h);
		} else {
			if (maxwidth <= w && maxheight <= h) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}
