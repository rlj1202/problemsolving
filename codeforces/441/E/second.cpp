#include <cstdio>

const int MAX_DIGIT = 300;

int cur;
long double digit_probs[2][MAX_DIGIT];

int main() {
	// read input
	int X, K, P;
	scanf("%d %d %d", &X, &K, &P);

	long double prob = P / 100.0;
	long double inv_prob = 1.0 - prob;

	// decompose number into binary digits
	{
		int tmp = X;
		int i = 0;
		while (tmp) {
			digit_probs[cur][i] = tmp & 1;
			i++;
			tmp >>= 1;
		}
	}

	// calculate probability on each digit in binary
	for (int k = 0; k < K; k++) {
		int next = !cur;

		// a = a * 2
		digit_probs[next][0] = 0.0;
		for (int i = 1; i < MAX_DIGIT; i++) {
			digit_probs[next][i] = digit_probs[cur][i - 1] * prob;
		}
		
		// a = a + 1
		for (int i = 0; i < MAX_DIGIT; i++) {
			long double allone = 1.0;

			for (int j = 0; j < i; j++)
				allone *= digit_probs[cur][j];

			digit_probs[next][i] += (
						digit_probs[cur][i] * (1.0 - allone)
						+ (1.0 - digit_probs[cur][i]) * allone
						) * inv_prob;
		}

		cur = next;

		// XXX
		printf("\t");
		for (int i = 0; i < 10; i++) printf("%.2Lf ", digit_probs[cur][i]); printf("\n");
		// XXX
	}

	// calculate expected value
	long double result = 0.0;

	for (int s = 1; s < MAX_DIGIT; s++) {
		long double allzero = 1.0;
		
		for (int i = 0; i < s; i++)
			allzero *= 1.0 - digit_probs[cur][i];

		result += s * (digit_probs[cur][s] * allzero);
	}

	// print result
	printf("%.13Lf\n", result);
	
	return 0;
}
