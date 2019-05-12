#include <iostream>

int N;
int min[102];
int sum[100005];

float highest;
int results[102];
int cnt;

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int score;
		scanf("%d", &score);
		sum[n] = sum[n - 1] + score;
	}

	for (int k = 1; k <= N - 2; k++) {
		float grade = sum[N] - sum[k];
		float min = 0;

		grade -= min;
		grade /= N - k;

		if (highest < grade) {
			highest = grade;
			cnt = 0;
		}
		if (highest == grade)
			results[cnt++] = k;
	}

	for (int i = 0; i < cnt; i++)
		printf("%d\n", results[i]);

	return 0;
}
