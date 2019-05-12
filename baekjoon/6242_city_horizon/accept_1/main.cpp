#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Building { int id; long long pos, height; bool opening; };

bool operator< (const Building &a, const Building &b) {
	if (a.pos == b.pos) return a.opening < b.opening;
	return a.pos < b.pos;
}

int N;
Building buildings[80004];

priority_queue<pair<int, int>> pq;
bool out[40004];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int a, b, h;
		scanf("%d %d %d", &a, &b, &h);
		buildings[n * 2] = {n, a, h, true};
		buildings[n * 2 + 1] = {n, b, h, false};
	}
	sort(buildings, buildings + N * 2);
	
	long long area = 0;
	
	pq.push({buildings[0].height, buildings[0].id});

	for (int i = 1; i < N * 2; i++) {
		Building cur = buildings[i];

		while (!pq.empty() && out[pq.top().second]) pq.pop();
		long long maxheight = !pq.empty() ? pq.top().first : 0;

		area += maxheight * (cur.pos - buildings[i - 1].pos);

		if (cur.opening) pq.push({cur.height, cur.id});
		else out[cur.id] = true;
	}

	printf("%lld\n", area);

	return 0;
}
