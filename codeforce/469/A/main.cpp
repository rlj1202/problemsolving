#include <cstdio>

bool chk[102];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 2; i++) {
		int p;
		scanf("%d", &p);

		for (int j = 0; j < p; j++) {
			int idx;
			scanf("%d", &idx);
			chk[idx] = true;
		}
	}

	bool possible = true;
	for (int n = 1; n <= N; n++) {
		if (!chk[n]) {
			possible = false;
			break;
		}
	}

	printf("%s\n", possible ? "I become the guy." : "Oh, my keyboard!");

	return 0;
}
