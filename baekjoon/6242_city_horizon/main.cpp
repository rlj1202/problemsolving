#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Building { int id; long long pos, height; bool opening; };

bool operator< (const Building &a, const Building &b) {
	if (a.pos == b.pos) return a.opening < b.opening;
	return a.pos < b.pos;
}

int N;
Building buildings[80004];

Building compressed[80004];
int compressedlen;

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

	for (int i = 0; i < N * 2; i++) {
		Building cur = buildings[i];

		if (compressedlen
				&& compressed[compressedlen - 1].pos == cur.pos
				&& compressed[compressedlen - 1].opening == cur.opening) {
			compressed[compressedlen - 1].height = max(
					compressed[compressedlen - 1].height,
					cur.height);
		} else {
			compressed[compressedlen++] = cur;
		}
	}

	long long area = 0;

	for (int i = 0; i < compressedlen - 1; i++) {
		Building l = compressed[i];
		Building r = compressed[i + 1];

		if (l.opening) {
			pq.push({l.height, l.id});
		} else {
			out[l.id] =  true;
		}

		while (!pq.empty() && out[pq.top().second]) pq.pop();

		long long maxheight = pq.top().first;

		if (!l.opening && r.opening) {
			continue;
		} else if (l.opening && r.opening) {
			area += max(maxheight, l.height) * (r.pos - l.pos);
		} else if (l.opening && !r.opening) {
			area += max(maxheight, max(l.height, r.height)) * (r.pos - l.pos);
		} else if (!l.opening && !r.opening) {
			area += max(maxheight, r.height) * (r.pos - l.pos);
		}
	}

	printf("%lld\n", area);
	
	return 0;
}
