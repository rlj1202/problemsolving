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

int main() {
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		char raw[102];
		scanf("%s", raw);
		for (int c = 1; c <= N; c++) {
			grid[r][c] = raw[c - 1];

			if (grid[r][c] == 'J') {
				points[pointslen++] = {r, c};
			}
		}
	}

	for (int i = 0; i < pointslen; i++) {
		for (int j = 0; j < pointslen; j++) {
			if (j == i) continue;

			for (int k = 0; k < pointslen; k++) {
				if (k == i) continue;

				Vec2 vec1 = points[j] - points[i];
				Vec2 vec2 = points[k] - points[i];

				if (vec1 * vec2 == 0 && vec1.lensquare() == vec2.lensquare()) {
					Vec2 normy = points[i] + vec1 + vec2;

					if (grid[normy.r][normy.c] == '*') {
						int area = vec1.lensquare();
						result = max(result, area);
					}
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
