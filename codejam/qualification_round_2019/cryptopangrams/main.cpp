#include <cstdio>
#include <algorithm>

using namespace std;

int primes[10004];
int primeslen;

bool decode(int *nums, int numslen, int *codes) {
	for (int l = 1; l < numslen + 1; l++) {
		if (nums[l - 1] % codes[l - 1] != 0) return false;
		codes[l] = nums[l - 1] / codes[l - 1];
	}

	return true;
}

int main() {
	primes[primeslen++] = 2;
	for (int n = 3; n <= 10000; n += 2) {
		int p;
		for (p = 0; p < primeslen; p++)
			if (n % primes[p] == 0) break;
		if (p == primeslen) primes[primeslen++] = n;
	}

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N, L;
		scanf("%d %d", &N, &L);

		int nums[102];
		for (int l = 0; l < L; l++) {
			scanf("%d", nums + l);
		}

		int codes[102];
		int table[102];

		// hack first prime number
		for (int p = 0; p < primeslen; p++) {
			if (nums[0] % primes[p] == 0) {
				codes[0] = nums[0] / primes[p];
				if (decode(nums, L, codes)) break;
			}
		}

		for (int l = 0; l < L + 1; l++) table[l] = codes[l];
		sort(table, table + L + 1);
		unique(table, table + L + 1);

		char result[102];
		for (int l = 0; l < L + 1; l++) {
			int index = lower_bound(table, table + 26, codes[l]) - table;
			result[l] = index + 'A';
		}
		result[L + 1] = 0;

		printf("Case #%d: %s\n", t, result);
	}

	return 0;
}
