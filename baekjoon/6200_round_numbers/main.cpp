#include <iostream>
#include <algorithm>

using namespace std;

int start, finish;

int comb[40][40];

int sum[40];

int f(int n) {
	int tmp = n;
	int len = 0;

	sum[0] = !(tmp & 1);
	tmp >>= 1;
	len++;

	for (int i = 1; tmp > 0; i++) {
		sum[i] = sum[i - 1] + !(tmp & 1);
		tmp >>= 1;
		len++;
	}

	int minzeros = (len + 1) / 2;

	int result = 0;

	tmp = n;
	for (int i = 0; i < len - 1; i++) {
		if ((tmp & 1) == 1) {
			int zeros = sum[len - 1] - sum[i] + 1;
			
			for (int z = max(0, minzeros - zeros); z <= i; z++) {
				result += comb[i][z];
			}
		}
		

		tmp >>= 1;
	}

	for (int i = 1; i < len; i++) {
		int zeros = (i + 1) / 2;

		for (int z = zeros; z < i; z++) {
			result += comb[i - 1][z];
		}
	}

	return result;
}

int main() {
	scanf("%d %d", &start, &finish);

	comb[0][0] = 1;
	for (int i = 1; i <= 32; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}

	int result = f(finish + 1) - f(start);
	printf("%d\n", result);

	return 0;
}
