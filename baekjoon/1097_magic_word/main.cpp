#include <cstdio>
#include <cstring>

int N, K;

char words[8][21];
int wordlen[8];

bool used[8];
int perm[8];

char newword[161];
int failure[161];

int result;

void makefailure(char *str) {
	memset(failure, 0, sizeof(failure));
	int j = 0;
	for (int i = 1; str[i]; i++) {
		while (j && str[i] != str[j])
			j = failure[j - 1];

		if (str[i] == str[j])
			failure[i] = ++j;
	}
}

void iterateperm(int curindex) {
	if (N == curindex) {
		int len = 0;
		for (int i = 0; i < N; i++) {
			char *curword = words[perm[i]];

			strcpy(newword + len, curword);
			len += wordlen[perm[i]];
		}
		makefailure(newword);

		/*
		printf("\t%s\n", newword);
		printf("\t");
		for (int i = 0; i < len; i++) printf("%d ", failure[i]);
		printf("\n");
		*/

		if ((len - failure[len - 1]) * K == len)
			result++;

		return;
	}
	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		used[i] = true;
		perm[curindex] = i;
		iterateperm(curindex + 1);
		used[i] = false;
	}
}

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%s", words[n]);
		wordlen[n] = strlen(words[n]);
	}
	scanf("%d", &K);

	//
	iterateperm(0);

	// print result
	printf("%d\n", result);

	return 0;
}
