#include <iostream>
#include <algorithm>

using namespace std;

struct Detector { int pos; long long count; };

bool operator< (const Detector &a, const Detector &b) {
	return a.pos < b.pos;
}

int N, M;
Detector detectors[100005];

pair<int, int> table[20][100005];

pair<int, int> findmin(int l, int r) {
	int tmp = r - l;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	int len = 1 << log;

	return min(table[log][l], table[log][r - len]);
}

// l is inclusive, r is exclusive
long long getcost(int l, int r, long long offset) {
	long long result = 0;

	while (detectors[l].count <= offset) l++;
	if (l >= r) return 0;

	pair<int, int> minpair = findmin(l, r);
	int mincount = minpair.first;
	int m = minpair.second;

	result += getcost(l, m, mincount) + getcost(m, r, mincount);
	result += mincount - offset;

	return result;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		int p;// position
		long long c; // count
		scanf("%d %lld", &p, &c);
		detectors[n] = {p, c};
	}
	sort(detectors, detectors + N);

	for (int n = 0; n < N; n++) table[0][n] = {detectors[n].count, n};
	int tmp = N;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	for (int l = 1; l <= log; l++) {
		int prev = 1 << (l - 1);
		int len = 1 << l;

		for (int n = 0; n < N - len + 1; n++) {
			pair<int, int> left = table[l - 1][n];
			pair<int, int> right = table[l - 1][n + prev];

			if (left.first < right.first) table[l][n] = left;
			else table[l][n] = right;
		}
	}
	
	printf("%lld\n", getcost(0, N, 0));

	return 0;
}
