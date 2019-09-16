#include <cstdio>
#include <algorithm>

using namespace std;

const static int PRIME_MAX = 300000;

bool isNotPrime[PRIME_MAX + 1];

int delete_digit(int num, int unit) {
	return num % unit + (num - num % (unit * 10)) / 10;
}

int search(int num) {
	if (isNotPrime[num]) return 0;

	int maxnext = 0;
	for (int unit = 1; unit <= num; unit *= 10) {
		int next = delete_digit(num, unit);
		maxnext = max(maxnext, search(next));
	}

	return 1 + maxnext;
}

int main() {
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (int n = 2; n <= PRIME_MAX; n++) {
		if (isNotPrime[n]) continue;
		
		int m = n + n;
		while (m <= PRIME_MAX) {
			isNotPrime[m] = true;
			m += n;
		}
	}

	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int A, B;
	
		scanf("%d %d", &A, &B);

		int Ascore = search(A);
		int Bscore = search(B);

		printf("Case #%d\n", t);

		int result;
		if (Ascore > Bscore) result = 1;
		else if (Ascore < Bscore) result = 2;
		else result = 3;

		printf("%d\n", result);
	}

	return 0;
}
