#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int a; int b; int cost;

	bool operator < (const Edge &a) {
		return cost < a.cost;
	}
};

int V, E;
Edge edges[100005];

int p[10004];
int s[10004];

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
	scanf("%d %d", &V, &E);

	for (int v = 1; v <= V; v++) {
		p[v] = v;
		s[v] = 1;
	}

	for (int e = 0; e < E; e++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);

		edges[e] = Edge{a, b, cost};
	}

	sort(edges, edges + E);

	for (Edge edge : edges) {
		if (merge(edge.a, edge.b)) {
			cost += edge.cost;
		}
	}
	
	printf("%d\n", cost);

	return 0;
}
