#include <iostream>
#include <cstring>

using namespace std;

int N, start, finish;
char alphas[16][27];
int alphaslen[16];

char code[17];
int codeindex;

bool f(int pos, int alpha, int flag) {
	code[pos] = alphas[pos][alpha];

	if (pos == N - 1) {
		codeindex++;
		if (codeindex >= start) {
			if (codeindex <= finish) printf("%s\n", code);
			else return true;
		}
		return false;
	}

	for (int i = 0; i < alphaslen[pos + 1]; i++) {
		int mask = 1 << (alphas[pos + 1][i] - 'A');
		if ((flag & mask) > 0) continue;

		bool finished = f(pos + 1, i, flag | mask);
		if (finished) return true;
	}

	return false;
}

int main() {
	scanf("%d %d %d", &N, &start, &finish);
	for (int n = 0; n < N; n++) {
		scanf("%s", alphas[n]);
		alphaslen[n] = strlen(alphas[n]);
	}

	for (int alpha = 0; alpha < alphaslen[0]; alpha++) {
		bool finished = f(0, alpha, 1 << (alphas[0][alpha] - 'A'));
		if (finished) break;
	}
	
	return 0;
}
