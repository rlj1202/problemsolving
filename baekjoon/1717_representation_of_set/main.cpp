#include <iostream>

int N, M;
int p[1000006];
int s[1000006];

int find(int e) {
	if (e == p[e]) return e;
	return (p[e] = find(p[e]));
}

void merge(int a, int b) {
	int A = find(a);
	int B = find(b);

	if (A == B) return;

	// merge small one to big one
	if (s[A] < s[B]) {
		int tmp = A;
		A = B;
		B = tmp;
	}

	p[B] = A;
	s[A] += s[B];
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++) {
		p[i] = i;
		s[i] = 1;
	}

	for (int m = 1; m <= M; m++) {
		int cmd, a, b;
		scanf("%d %d %d", &cmd, &a, &b);

		if (cmd == 0) { // union
			merge(a, b);
		} else {
			int A = find(a);
			int B = find(b);

			if (A == B) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
