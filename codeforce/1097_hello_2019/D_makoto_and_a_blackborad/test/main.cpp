#include <iostream>
#include <algorithm>

using namespace std;

float table[4][4] = {
	{1, 0, 0, 0},
	{1.0/2, 1.0/2, 0, 0},
	{1.0/2, 0, 1.0/2, 0},
	{1.0/4, 1.0/4, 1.0/4, 1.0/4}
};

float other[4][4];

int main() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			for (int i = 0; i < 4; i++) {
				other[r][c] += table[r][i] * table[i][c];
			}
		}
	}

	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			printf("%f ", other[r][c]);
		}
		printf("\n");
	}

	float sum = 0;
	int tmp[] = {1, 2, 3, 6};
	for (int i = 0; i < 4; i++) sum += tmp[i] * other[3][i];
	printf("%f\n", sum);

	return 0;
}
