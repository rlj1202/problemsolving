#include <iostream>

int N;
int degrees[20];

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", degrees + n);
	}

	int combinations = 1 << N;

	bool result = false;

	for (int c = 0; c < combinations; c++) {
		int rotation = 0;

		for (int i = 0; i < N; i++) {
			rotation += (((c >> i) & 1) ? 1 : -1) * degrees[i];
		}

		rotation %= 360;

		if (rotation == 0) {
			result = true;
		}
	}

	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
