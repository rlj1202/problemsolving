#include <cstdio>

int Y;
int M;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int time;
		scanf("%d", &time);

		Y += 10 + (time / 30) * 10;
		M += 15 + (time / 60) * 15;
	}

	if (Y < M) printf("Y %d\n", Y);
	else if (Y > M) printf("M %d\n", M);
	else printf("Y M %d\n", Y);

	return 0;
}
