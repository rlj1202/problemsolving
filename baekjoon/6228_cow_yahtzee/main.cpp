/*
 * time complexity : O(N^2 2^E),
 *                       N^2 for outcomes function
 *                       and 2^E for inclusion-exclusion principle
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int comb[22][22]; // comb[i][j] = i C j

int N, S, E; // N = number of rolling dice, S = sides of dice, E = number of expressions
int exprs[22][10]; // exprs[expression][eye]

int exprindices[22];

int result; // will not exceed 1,512,768

// count number of outcomes by given expression
int outcomes(int *expr, int eye, int types, int remains) {
	if (eye == S + 1) {
		int result = 1;
		while (remains--) result *= S - types;
		return result;
	}
	if (expr[eye] == 0) return outcomes(expr, eye + 1, types, remains);
	if (remains < expr[eye]) return 0;

	int result = 0;

	for (int used = expr[eye]; used <= remains; used++)
		result += comb[remains][used] * outcomes(expr, eye + 1, types + 1, remains - used);

	return result;
}

// inclusion-exclusion principle
int intersection_sum(int intersize, int count, int expr) {
	if (count == intersize) {
		int newexpr[22];
		memset(newexpr, 0, sizeof(newexpr));

		for (int i = 0; i < intersize; i++)
			for (int j = 1; j <= S; j++)
				newexpr[j] = max(newexpr[j], exprs[exprindices[i]][j]);

		return outcomes(newexpr, 1, 0, N);
	}

	if (expr >= E) return 0;

	int result = 0;

	for (int nxtexpr = expr; nxtexpr < E; nxtexpr++) {
		exprindices[count] = nxtexpr;
		result += intersection_sum(intersize, count + 1, nxtexpr + 1);
	}

	return result;
}

int main() {
	// make combination table
	for (int i = 0; i <= 20; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
	}

	// read input
	scanf("%d %d %d", &N, &S, &E);
	for (int e = 0; e < E; e++) {
		while (true) {
			int times, eye;
			char suffix;
			scanf("%dx%d%c", &times, &eye, &suffix);
			exprs[e][eye] += times;

			if (suffix == '\n') break;
		}
	}

	// calculate
	for (int s = 1; s <= E; s++) {
		result += (s % 2 == 1 ? 1 : -1) * intersection_sum(s, 0, 0);
	}

	// print result
	printf("%d\n", result);

	return 0;
}
