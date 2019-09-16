#include <cstdio>

const int MOD = 1e9 + 7;

long long factorial[100005];

char words[100005][12];

long long nwords;
long long cwords;
long long cnwords;
long long ncwords;
long long nonewords;

long long result;

int main() {
	factorial[0] = 1;
	for (int f = 1; f <= 100000; f++) {
		factorial[f] = f * factorial[f - 1];
		factorial[f] %= MOD;
	}

	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%s", words[n]);

		bool nincluded = false;
		bool cincluded = false;
		bool isNC = false;
		for (int i = 0; words[n][i]; i++) {
			if (words[n][i] == 'N') nincluded = true;
			if (words[n][i] == 'C') {
				cincluded = true;
				if (nincluded) isNC = true;
			}
		}

		if (nincluded && !cincluded) {
			nwords++;
		} else if (!nincluded && cincluded) {
			cwords++;
		} else if (nincluded && cincluded) {
			if (isNC) ncwords++;
			else cnwords++;
		} else {
			nonewords++;
		}
	}

	// total outcomes
	for (int l = 1; l <= N; l++) {
		result += 1;
		result *= l;
		result %= MOD;
	}

	int cstr = 0;
	int nstr = 0;
	int cnstr = 0;
	for (int l = 1; l <= cwords; l++) {
		cstr += 1;
		cstr *= l;
		cstr %= MOD;
	}
	for (int l = 1; l <= nwords; l++) {
		nstr += 1;
		nstr *= l;
		nstr %= MOD;
	}
	for (int l = 1; l <= cnwords; l++) {
		cnstr += 1;
		cnstr *= l;
		cnstr %= MOD;
	}

	int nonestr = 1;
	nonestr *= cstr;
	nonestr %= MOD;
	nonestr *= nstr;
	nonestr %= MOD;
	nonestr *= cnstr;
	nonestr %= MOD;

	result -= nonestr;

	// print result
	printf("%lld\n", result);

	return 0;
}
