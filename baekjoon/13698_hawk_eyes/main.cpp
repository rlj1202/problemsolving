#include <iostream>

const int ls[] = {1, 1, 1, 2, 2, 3};
const int rs[] = {2, 3, 4, 3, 4, 4};

char swaps[202];
int balls[5];

int main() {
	scanf("%s", swaps);

	balls[1] = 1; // small
	balls[4] = 2; // big

	for (int i = 0; swaps[i] != 0; i++) {
		int swap = swaps[i] - 'A';
		int l = ls[swap];
		int r = rs[swap];

		int tmp = balls[l];
		balls[l] = balls[r];
		balls[r] = tmp;
	}

	for (int i = 1; i <= 4; i++)
		if (balls[i] == 1) printf("%d\n", i);

	for (int i = 1; i <= 4; i++)
		if (balls[i] == 2) printf("%d\n", i);
	
	return 0;
}
