#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	long long x, y;

	Point operator- (Point o) {
		return {x - o.x, y - o.y};
	}
	long long cross(Point o) {
		return x * o.y - y * o.x;
	}
	long long dot(Point o) {
		return x * o.x + y * o.y;
	}
};

struct Line {
	Point head, tail;
};

void readPoint(Point *point) {
	scanf("%lld %lld", &point->x, &point->y);
}

// 0 = on line which has infinite length
// 1 = on left
// -1 = on right
long long compare(Line line, Point point) {
	Point v1 = line.head - line.tail;
	Point v2 = point - line.tail;
	long long value = v1.cross(v2);

	if (value > 0) return 1;
	else if (value < 0) return -1;
	else return 0;
}

bool onSameLine(Line l1, Line l2) {
	bool a = compare(l1, l2.head) == 0 && ((l2.head - l1.head).dot(l2.head - l1.tail) > 0);
	bool b = compare(l1, l2.tail) == 0 && ((l2.tail - l1.head).dot(l2.tail - l1.tail) > 0);
	return a && b;
}

bool isLineCross(Line l1, Line l2) {
	bool a = (compare(l1, l2.head) * compare(l1, l2.tail)) > 0; // biased
	bool b = (compare(l2, l1.head) * compare(l2, l1.tail)) > 0; // biased
	bool c = onSameLine(l1, l2);
	return !(a || b || c);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		Point line_s, line_e, box_s, box_e;

		readPoint(&line_s);
		readPoint(&line_e);
		readPoint(&box_s);
		readPoint(&box_e);

		Line line = {line_s, line_e};

		if (box_s.x > box_e.x) swap(box_s.x, box_e.x);
		if (box_s.y > box_e.y) swap(box_s.y, box_e.y);

		Point points[4];
		points[0] = {box_s.x, box_s.y};
		points[1] = {box_e.x, box_s.y};
		points[2] = {box_e.x, box_e.y};
		points[3] = {box_s.x, box_e.y};

		bool cross = false;
		bool insidebox = true;

		Point prev = points[3];
		for (int i = 0; i < 4; i++) {
			Line l = {points[i], prev};

			if (isLineCross(l, line))
				cross = true;

			if (compare(l, line.head) < 0 ||
					compare(l, line.tail) < 0)
				insidebox = false;

			prev = points[i];
		}

		printf("%c\n", (cross || insidebox) ? 'T' : 'F');
	}

	return 0;
}
