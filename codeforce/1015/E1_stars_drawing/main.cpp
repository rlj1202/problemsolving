#include <iostream>
#include <vector>

using namespace std;

struct Star {
	int r, c, l;
};

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, M;
char grid[102][102];
int mark[102][102];

vector<Star> stars;

int main() {
	// read input
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%s", grid[n] + 1);
	}

	//
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (grid[r][c] == '*') {
				int l = 1;
				bool accepted = true;
				while (accepted) {
					for (int i = 0; i < 4; i++) {
						if (grid[r + dr[i]*l][c + dc[i]*l] != '*') {
							accepted = false;
							break;
						}
					}
					if (accepted) {
						mark[r][c] = 1;
						for (int i = 0; i < 4; i++) {
							mark[r + dr[i]*l][c + dc[i]*l] = 1;
						}

						l++;
					}
				}
				
				if (l > 1) {
					Star star = {r, c, l - 1};
					stars.push_back(star);
				}
			}
		}
	}

	bool fail = false;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (grid[r][c] == '*' && mark[r][c] != 1) {
				fail = true;
				break;
			}
		}
		if (fail) break;
	}

	if (fail) {
		printf("%d\n", -1);
		return 0;
	}

	// print result
	printf("%d\n", stars.size());
	for (Star star : stars) {
		printf("%d %d %d\n", star.r, star.c, star.l);
	}

	return 0;
}
