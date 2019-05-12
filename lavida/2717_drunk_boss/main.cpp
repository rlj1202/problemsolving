#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	float result = 0;

	for (int i = 0; i < 5; i++) {
		float max = 0;

		for (int n = 0; n < N; n++) {
			float V;
			scanf("%f", &V);

			if (max < V) max = V;
		}

		result += max;
	}

	printf("%.3f\n", result);

	return 0;
}
