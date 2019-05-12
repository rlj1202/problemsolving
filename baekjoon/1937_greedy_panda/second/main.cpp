#include <iostream>
#include <algorithm>

using namespace std;

struct Bamboo { int r, c, amount; };

bool operator< (const Bamboo &a, const Bamboo &b) {
	return a.amount < b.amount;
}

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
Bamboo bamboos[300005];

int indices[502][502];
int maxlen[300005];

int getlen(int index) {
	if (maxlen[index] != 0) return maxlen[index];

	Bamboo cur = bamboos[index];

	int result = 0;
	for (int i = 0; i < 4; i++) {
		int nr = cur.r + dr[i], nc = cur.c + dc[i];
		int next = indices[nr][nc];
		if (index < next) result = max(result, getlen(next));
	}

	return maxlen[index] = 1 + result;
}

int main() {
	// read input
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int amount;
			scanf("%d", &amount);
			bamboos[c + (r - 1) * N] = {r, c, amount};
		}
	}

	// sort inputs by amount of bamboo
	sort(bamboos + 1, bamboos + 1 + N * N);
	for (int i = 1; i <= N*N; i++) {
		Bamboo cur = bamboos[i];
		indices[cur.r][cur.c] = i; // cache sorted index
	}

	// find longest series in which adjacent elements are also adjacent in 2d coordinate system.
	int result = 0;
	for (int i = 1; i <= N*N; i++)
		result = max(result, getlen(i));

	// print result
	printf("%d\n", result);

	return 0;
}
