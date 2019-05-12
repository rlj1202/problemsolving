#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
priority_queue<int, vector<int>, greater<int>> difficulties[100005];

int result[100005];

int main() {
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int difficulty;
		scanf("%d", &difficulty);
		difficulties[difficulty].push(m);
	}

	bool failed = false;
	while (!failed) {
		int upperindex = 0;
		for (int n = 1; n <= N; n++) {
			if (difficulties[n].empty()) {
				failed = true;
				break;
			}
			upperindex = max(upperindex, difficulties[n].top());
			difficulties[n].pop();
		}
		if (!failed) result[upperindex] = 1;
	}

	for (int m = 0; m < M; m++) printf("%d", result[m]);
	printf("\n");

	return 0;
}
