#include <iostream>
#include <algorithm>

using namespace std;

struct Cow { int x, y; };

int N;
Cow cows[10004];

int minx, maxx;
int miny, maxy;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		cows[n] = {x, y};
		minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y);
	}

	printf("%d %d\n", 0, 0);

	return 0;
}
