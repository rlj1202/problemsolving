#include <cstdio>

bool flag[102];

int main() {
	int N;
	scanf("%d", &N);

	int l, r;
	scanf("%d %d", &l, &r);
	for (int i = l; i < r; i++) {
		flag[i] = true;
	}

	for (int n = 1; n < N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		for (int i = l; i < r; i++) {
			flag[i] = false;
		}
	}

	int result = 0;

	for (int i = l; i < r; i++) {
		if (flag[i]) result++;
	}

	printf("%d\n", result);

	return 0;
}
