#include <cstdio>
#include <algorithm>

using namespace std;

struct Vector {
	int x, y;
	Vector operator- (Vector o) {
		return {x - o.x, y - o.y};
	}
	int cross(Vector o) {
		return x * o.y - y * o.x;
	}
	int dot(Vector o) {
		return x * o.x + y * o.y;
	}
};

struct Line {
	Vector tail, head;
};

Line lines[3003];
int parent[3003];
int counts[3003];

int ccw(Vector a, Vector b, Vector c) {
	Vector u = c - b;
	Vector v = a - b;
	int value = u.cross(v);
	if (value > 0) return 1;
	else if (value < 0) return -1;
	else return 0;
}

bool overlap(Line l1, Line l2) {
	if (ccw(l1.tail, l1.head, l2.head) == 0 && ccw(l1.tail, l1.head, l2.tail) == 0) {
		return (l2.head - l1.tail).dot(l2.head - l1.head) <= 0
			|| (l2.tail - l1.tail).dot(l2.tail - l1.head) <= 0

			|| (l1.tail - l2.tail).dot(l1.tail - l2.head) <= 0
			|| (l1.tail - l2.tail).dot(l1.tail - l2.head) <= 0;
	}

	return false;
}

bool isLineCross(Line l1, Line l2) {
	return ((ccw(l1.tail, l1.head, l2.head) != ccw(l1.tail, l1.head, l2.tail)) &&
			(ccw(l2.tail, l2.head, l1.head) != ccw(l2.tail, l2.head, l1.tail)))
		|| overlap(l1, l2);
}

int find(int i) {
	if (parent[i] == i) return i;
	return parent[i] = find(parent[i]);
}

void merge(int i, int j) {
	int p = find(i);
	int q = find(j);
	if (p != q) {
		if (counts[p] < counts[q]) swap(p, q);
		parent[q] = p;
		counts[p] += counts[q];
	}
}

int main() {
	// read input
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		lines[n] = {{x1, y1}, {x2, y2}};
		parent[n] = n;
		counts[n] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isLineCross(lines[i], lines[j])) {
				merge(i, j);
			}
		}
	}

	int groups = 0;
	int maxcounts = 0;
	for (int i = 0; i < N; i++) {
		if (find(i) != i) continue;
		groups++;
		maxcounts = max(maxcounts, counts[i]);
	}

	// print result
	printf("%d\n", groups);
	printf("%d\n", maxcounts);

	return 0;
}
