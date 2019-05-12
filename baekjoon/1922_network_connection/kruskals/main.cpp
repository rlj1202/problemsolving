#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
	int a;
	int b;
	int cost;

	bool operator < (const Edge &a) {
		return cost < a.cost;
	}
};

int N, M;
Edge edges[100005];

int p[1003];
int s[1003];

int cost;

int find(int e) {
	if (e == p[e]) return e;
	return (p[e] = find(p[e]));
}

bool merge(int a, int b) {
	int A = find(a);
	int B = find(b);

	if (A == B) return false;

	if (s[A] < s[B]) {
		int tmp = A;
		A = B;
		B = tmp;
	}

	p[B] = A;
	s[A] += s[B];

	return true;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		p[i] = i;
		s[i] = 1;
	}

	for (int m = 0; m < M; m++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);

		edges[m] = {a, b, cost};
	}
	
	sort(edges, edges + M);

	for (int m = 0; m < M; m++) {
		Edge edge = edges[m];

		if (merge(edge.a, edge.b))
			cost += edge.cost;
	}

	printf("%d\n", cost);

	return 0;
}
