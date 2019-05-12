#include <iostream>
#include <algorithm>

using namespace std;

struct Vec2 {
	int r, c;
	int lensquare() { return r*r + c*c; }
};

Vec2 operator+ (const Vec2 &a, const Vec2 &b) { return Vec2{ a.r + b.r, a.c + b.c }; }
Vec2 operator- (const Vec2 &a, const Vec2 &b) { return Vec2{ a.r - b.r, a.c - b.c }; }
int operator* (const Vec2 &a, const Vec2 &b) { return a.r * b.r + a.c * b.c; }

int N;
char grid[102][102];

Vec2 points[10004];
int pointslen;

int result;

const int nr[] = {1, -1};
const int nc[] = {-1, 1};

char get_char(Vec2 point) {
	if (point.r < 1 || N < point.r ||
			point.c < 1 || N < point.c) return 'B';

	return grid[point.r][point.c];
}

int check_square(Vec2 A, Vec2 B) {
	Vec2 a = B - A;

	for (int i = 0; i < 2; i++) {
		Vec2 b = {a.c * nr[i], a.r * nc[i]};

		Vec2 C = A + b;
		Vec2 D = A + a + b;
		char c_char = get_char(C);
		char d_char = get_char(D);

		if ((c_char == 'J' && d_char != 'B') || (d_char == 'J' && c_char != 'B'))
			return a.lensquare();
	}

	return 0;
}

int main() {
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		scanf("%s", grid[r] + 1);
		for (int c = 1; c <= N; c++)
			if (grid[r][c] == 'J') points[pointslen++] = {r, c};
	}

	for (int i = 0; i < pointslen - 1; i++) {
		for (int j = i + 1; j < pointslen; j++)
			result = max(result, check_square(points[i], points[j]));
	}

	printf("%d\n", result);

	return 0;
}
