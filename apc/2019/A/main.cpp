#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Problem {
	int easy;
	int hard;
};

Problem problems[102];
bool solved[102];

int main() {
	int N, L, K;
	scanf("%d %d %d", &N, &L, &K);
	for (int n = 0; n < N; n++) {
		int easy, hard;
		scanf("%d %d", &easy, &hard);
		problems[n] = {easy, hard};
	}

	int result = 0;

	int k = 0;

	for (int n = 0; n < N && k < K; n++) {
		Problem cur = problems[n];
		if (cur.hard <= L && !solved[n]) {
			result += 140;
			solved[n] = true;
			k++;
		}
	}

	for (int n = 0; n < N && k < K; n++) {
		Problem cur = problems[n];
		if (cur.easy <= L && !solved[n]) {
			result += 100;
			solved[n] = true;
			k++;
		}
	}

	printf("%d\n", result);
	
	return 0;
}
