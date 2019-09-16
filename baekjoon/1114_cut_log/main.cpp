#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Log {
	int len;
	int pos;
	bool operator< (const Log &o) const {
		if (len == o.len) return pos < o.pos;
		return len > o.len;
	}
};

int cuts[10004];

priority_queue<Log> pq;

int main() {
	int L, K, C;
	scanf("%d %d %d", &L, &K, &C);
	for (int k = 1; k <= K; k++) {
		scanf("%d", cuts + k);
	}
	cuts[K + 1] = L;

	for (int k = 0; k <= K; k++) {
		pq.push({cuts[k + 1] - cuts[k], cuts[k]});
	}

	for (int i = 0; i < K - C; i++) {
		Log a = pq.top(); pq.pop();
		Log b = pq.top(); pq.pop();
		pq.push({a.len + b.len, 0});
	}

	printf("%d %d\n", 0, 0);

	return 0;
}
