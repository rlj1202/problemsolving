#include <iostream>

int N;
int shuffleBack[102];
int ids[102];

int pos[102];
int results[102];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int to;
		scanf("%d", &to);
		shuffleBack[to] = n;
	}

	for (int n = 1; n <= N; n++)
		scanf("%d", ids + n);

	for (int n = 1; n <= N; n++)
		pos[n] = n;

	for (int i = 0; i < 3; i++) {
		for (int n = 1; n <= N; n++)
			pos[n] = shuffleBack[pos[n]];
	}

	for (int n = 1; n <= N; n++)
		results[pos[n]] = n;

	for (int n = 1; n <= N; n++)
		printf("%07d\n", ids[results[n]]);

	return 0;
}
