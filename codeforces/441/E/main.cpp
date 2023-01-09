#include <cstdio>

long long gcd(long long, long long);

struct Num { // a / b
	long long a, b;
	Num() : a(0), b(1) { }
	Num(long long n) : a(n), b(1) { }
	Num(long long a, long long b) : a(a), b(b) {
		long long div = gcd(a, b);
		if (div == 0) return;
		this->a /= div;
		this->b /= div;
	}

	Num operator* (Num o) {
		return Num(a * o.a, b * o.b);
	}
	Num operator+ (Num o) {
		return Num(a * o.b + o.a * b, b * o.b);
	}
	Num operator! () {
		return Num(b - a, b);
	}

	double toDouble() {
		return a / (double) b;
	}
};

const int MAX_DIGIT = 300;

int cur;
Num digit_probs[2][MAX_DIGIT];

long long gcd(long long a, long long b) {
	if (b == 0LL) return a;
	return gcd(b, a % b);
}

int main() {
	// read input
	int X, K, P;
	scanf("%d %d %d", &X, &K, &P);

	Num prob = Num(P, 100);
	Num inv_prob = !prob;

	// decompose number
	int tmp = X;
	int i = 0;
	while (tmp) {
		digit_probs[cur][i] = Num(tmp & 1);
		i++;
		tmp >>= 1;
	}

	// calculate probability on each digit in binary
	for (int k = 0; k < K; k++) {
		int next = !cur;

		digit_probs[next][0] = Num();
		for (int i = 1; i < MAX_DIGIT; i++) {
			digit_probs[next][i] = digit_probs[cur][i - 1] * prob;
		}
		
		for (int i = 0; i < MAX_DIGIT; i++) {
			Num newprob(1);

			for (int j = 0; j < i; j++) {
				newprob = newprob * digit_probs[cur][j];
			}

			digit_probs[next][i] = digit_probs[next][i]
				+ inv_prob * (digit_probs[cur][i] * !newprob
						+ !digit_probs[cur][i] * newprob);
		}

		cur = next;
	}

	// calculate expected value
	Num result;
	for (int s = 0; s < MAX_DIGIT; s++) {
		Num finalprob = digit_probs[cur][s];
		
		for (int i = 0; i < s; i++) {
			printf("\t\t %d %d %lld %lld %lld %lld\n", s, i,
					finalprob.a, finalprob.b,
					(!digit_probs[cur][i]).a,
					(!digit_probs[cur][i]).b);

			finalprob = finalprob * !digit_probs[cur][i];
		}

		result = result + Num(s) * finalprob;
	}

	// print result
	printf("%.13f\n", result.toDouble());
	
	return 0;
}
