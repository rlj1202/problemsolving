#include <iostream>

int N, M;
int p[1003];

int find(int a) {
	if (a == p[a]) return a;
	return (p[a] = find(p[a]));
}

void merge(int a, int b) {
	int A = find(a);
	int B = find(b);

	if (A == B) return;

	p[A] = B;
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		p[i] = i;
	
	for (int m = 1; m <= M; m++) {
		int u, v;
		scanf("%d %d", &u, &v);

		merge(u, v);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i == p[i]) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
