#include <iostream>
#include <algorithm>

using namespace std;

struct Bale { int width, breadth, area; };

bool operator> (const Bale &a, const Bale &b) {
	return a.area > b.area;
}

int N;
Bale bales[22];

int max_heights[22];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int width, breadth;
		scanf("%d %d", &width, &breadth);
		bales[n] = {width, breadth, width * breadth};
	}
	sort(bales, bales + N, greater<Bale>());

	for (int n = 0; n < N; n++) {
		Bale cur = bales[n];

		int prev_max = 0;
		for (int m = 0; m < n; m++) {
			if (bales[m].width <= cur.width || bales[m].breadth <= cur.breadth) continue;
			prev_max = max(prev_max, max_heights[m]);
		}

		max_heights[n] = prev_max + 1;
	}

	int result = 0;
	for (int n = 0; n < N; n++)
		result = max(result, max_heights[n]);
	printf("%d\n", result);

	return 0;
}
