#include <cstdio>
#include <algorithm>

using namespace std;

struct Vector {
	int x, y;
	Vector operator-(Vector o) {
		return {x - o.x, y - o.y};
	}
	int cross(Vector o) {
		return x * o.y - y * o.x;
	}
	int dot(Vector o) {
		return x * o.x + y * o.y;
	}
	bool operator< (Vector o) {
		if (x == o.x) return y < o.y;
		else return x < o.x;
	}
	bool operator> (Vector o) {
		if (x == o.x) return y > o.y;
		else return x > o.x;
	}
	bool operator== (Vector o) {
		return x == o.x && y == o.y;
	}
};

struct Line {
	Vector tail, head;
};

int ccw(Vector a, Vector b, Vector c) {
	Vector u = c - b;
	Vector v = a - b;
	int value = u.cross(v);
	if (value > 0) return 1;
	else if (value < 0) return -1;
	else return 0;
}

bool isOverlap(Line l1, Line l2, Vector *overlap) {
	if (ccw(l1.tail, l1.head, l2.head) == 0 && ccw(l1.tail, l1.head, l2.tail) == 0) {
		Vector l = l1.tail;
		Vector r = l1.head;
		Vector p = l2.tail;
		Vector q = l2.head;
		if (l > r) {
			Vector tmp = l;
			l = r;
			r = tmp;
		}
		if (p > q) {
			Vector tmp = p;
			p = q;
			q = tmp;
		}

		bool flag = !(r < p || q < l);
		if (flag && overlap != nullptr) {
			*overlap = p - r;
			if (*overlap < Vector{0, 0}) *overlap = l - q;
		}
		return flag;
	}
	return false;
}

bool isLineCross(Line l1, Line l2) {
	return (ccw(l1.tail, l1.head, l2.head) != ccw(l1.tail, l1.head, l2.tail) &&
			ccw(l2.tail, l2.head, l1.head) != ccw(l2.tail, l2.head, l1.tail))
		|| isOverlap(l1, l2, nullptr);
}

bool isPointIncluded(Line line, Vector point) {
	if (ccw(line.tail, line.head, point) == 0) {
		Vector l = line.tail;
		Vector r = line.head;
		if (l > r) {
			Vector tmp = l;
			l = r;
			r = tmp;
		}
		return !(point < l || r < point);
	}

	return false;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int xmin, ymin, xmax, ymax;
		scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);

		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int result = 0;

		Line line = {{x1, y1}, {x2, y2}};

		Vector points[4];
		points[0] = {xmin, ymin};
		points[1] = {xmax, ymin};
		points[2] = {xmax, ymax};
		points[3] = {xmin, ymax};

		Vector prev = points[3];
		for (int i = 0; i < 4; i++) {
			Vector cur = points[i];

			Line oline = {prev, cur};
			if (isLineCross(line, oline)) {
				Vector overlap;
				if (isOverlap(line, oline, &overlap)) {
					if (overlap == Vector{0, 0}) {
						result++;
					} else {
						result += 0x3f3f3f3f;
					}
				} else {
					result++;
				}
			}

			prev = cur;
		}
		for (int i = 0; i < 4; i++) {
			Vector cur = points[i];
			if (isPointIncluded(line, cur)) result--;
		}
		
		printf("%d\n", min(4, result));
	}

	return 0;
}
