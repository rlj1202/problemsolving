#include <cstdio>
#include <algorithm>

using namespace std;

struct Task {
	int id, difficulty;
	bool hard;
	bool operator< (const Task &o) const {
		if (hard == o.hard) return difficulty < o.difficulty;
		return hard < o.hard;
	}
};

Task tasks[202];
bool solved[102];

int main() {
	int N, L, K;
	scanf("%d %d %d", &N, &L, &K);
	for (int n = 0; n < N; n++) {
		int easy, hard;
		scanf("%d %d", &easy, &hard);
		tasks[n * 2] = {n, easy, false};
		tasks[n * 2 + 1] = {n, hard, true};
	}
	sort(tasks, tasks + N*2);

	int result = 0;

	for (int i = 0; i < N*2 && K; i++) {
		Task cur = tasks[N*2 - i - 1];
		if (solved[cur.id]) continue;
		if (cur.difficulty > L) continue;

		solved[cur.id] = true;
		K--;

		if (cur.hard) result += 140;
		else result += 100;
	}

	printf("%d\n", result);

	return 0;
}
