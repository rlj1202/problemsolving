#include <cstdio>

int comb[11][11];

char ori[11];
char rcg[11];

int main() {
	scanf("%s %s", ori, rcg);

	int delta = 0;
	int unknowns = 0;
	for (int i = 0; ori[i]; i++) {
		if (ori[i] == '+') delta++;
		else delta--;
	}
	for (int i = 0; rcg[i]; i++) {
		if (rcg[i] == '+') delta--;
		else if (rcg[i] == '-') delta++;
		else unknowns++;
	}

	for (int i = 0; i <= 10; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++)
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}

	int total_outcomes = 1 << unknowns;

	int plus = (unknowns + delta) / 2;
	int outcomes = comb[unknowns][plus];

	double prob = outcomes / (double) total_outcomes;

	printf("%.12f\n", prob);

	return 0;
}
