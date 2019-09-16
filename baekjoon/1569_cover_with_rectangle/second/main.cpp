#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Point { int x, y; };

int N;
Point points[102];

int main() {
	// read input
	scanf("%d", &N);

	int leftmost = INF;
	int rightmost = -INF;
	int bottommost = INF;
	int topmost = -INF;

	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[n] = {x, y};

		leftmost = min(leftmost, x);
		rightmost = max(rightmost, x);
		bottommost = min(bottommost, y);
		topmost = max(topmost, y);
	}

	//
	int result = -1;

	for (int w = 0; w <= 2000; w++) {
		bool possible = true;

		for (int n = 0; n < N; n++) {
			Point cur = points[n];

			bool included = false;
			
			if (leftmost <= cur.x && cur.x <= leftmost + w) {
				if (cur.y == bottommost || cur.y == bottommost + w) included = true;
			}
			if (bottommost <= cur.y && cur.y <= leftmost + w) {
				if (cur.x == leftmost || cur.x == leftmost + w) included = true;
			}

			if (!included) possible = false;
		}
		
		if (possible) {
			result = w;
			break;
		}
	}

	for (int w = 0; w <= 2000; w++) {
		bool possible = true;

		for (int n = 0; n < N; n++) {
			Point cur = points[n];

			bool included = false;
			
			if (rightmost - w <= cur.x && cur.x <= rightmost) {
				if (cur.y == bottommost || cur.y == bottommost + w) included = true;
			}
			if (bottommost <= cur.y && cur.y <= leftmost + w) {
				if (cur.x == rightmost - w || cur.x == rightmost) included = true;
			}

			if (!included) possible = false;
		}
		
		if (possible) {
			result = w;
			break;
		}
	}

	for (int w = 0; w <= 2000; w++) {
		bool possible = true;

		for (int n = 0; n < N; n++) {
			Point cur = points[n];

			bool included = false;
			
			if (leftmost <= cur.x && cur.x <= leftmost + w) {
				if (cur.y == topmost - w || cur.y == topmost) included = true;
			}
			if (topmost - w <= cur.y && cur.y <= topmost) {
				if (cur.x == leftmost || cur.x == leftmost + w) included = true;
			}

			if (!included) possible = false;
		}
		
		if (possible) {
			result = w;
			break;
		}
	}

	for (int w = 0; w <= 2000; w++) {
		bool possible = true;

		for (int n = 0; n < N; n++) {
			Point cur = points[n];

			bool included = false;
			
			if (rightmost - w <= cur.x && cur.x <= rightmost) {
				if (cur.y == topmost - w || cur.y == topmost) included = true;
			}
			if (topmost - w <= cur.y && cur.y <= topmost) {
				if (cur.x == rightmost - w || cur.x == rightmost) included = true;
			}

			if (!included) possible = false;
		}
		
		if (possible) {
			result = w;
			break;
		}
	}

	// print result
	printf("%d\n", result);

	return 0;
}
