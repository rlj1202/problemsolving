#include <iostream>

const char UNKNOWN[] = "UNKNOWN";

int N, M;

int p[100005];
int s[100005];

int find(int e) {
	if (e == p[e]) return e;
	return (p[e] = find(p[e]));
}

bool merge(int a, int b, int w) {
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
	while (true) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;

		for (int n = 1; n <= N; n++) {
			p[n] = n;
			s[n] = 1;
		}

		for (int m = 1; m <= M; m++) {
			char c;
			int a, b, w;
			scanf("%c %d %d", &c, &a, &b);

			if (c == '!') {
				scanf("%d", &w);

				if (merge(a, b, w)) {
					// TODO
				}
			} else if (c == '?') {
			}
		}
	}

	return 0;
}
