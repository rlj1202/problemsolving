#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int scores[300005];
int highest;
int cnt;

int main() {
	scanf("%d", &N);

	highest = -1;
	for (int n = 1; n <= N; n++) {
		scanf("%d", scores + n);
		highest = max(highest, scores[n]);
	}

	for (int n = 1; n <= N; n++) {
		int delta = highest - scores[n];
		if (delta < N) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
