#include <iostream>
#include <cstring>

typedef unsigned long long hash;

const static int BASE = 131;

char S[1000006];
char T[1000006];

int result[1000006];
int cnt;

void rabinKarp(int strLen, int tokenLen, char *str, char *token) {
	if (strLen < tokenLen) return;

	hash MSD = 1;
	for (int i = 1; i < tokenLen; i++) MSD *= BASE;

	hash tokenHash = 0;
	for (char *c = token; *c; c++) {
		tokenHash *= BASE;
		tokenHash += *c;
	}

	hash strHash = 0;
	char *c;
	for (c = str; c < str + tokenLen; c++) {
		strHash *= BASE;
		strHash += *c;
	}

	for (; *c; c++) {
		if (tokenHash == strHash) {
			result[cnt++] = c - str - tokenLen;
		}
		strHash -= (*(c - tokenLen)) * MSD;
		strHash = strHash * BASE + *c;
	}

	if (tokenHash == strHash) {
		result[cnt++] = c - str - tokenLen;
	}
}

int main() {
	scanf("%[^\n]%*c", S);
	scanf("%[^\n]", T);

	int strLen = strlen(S);
	int tokenLen = strlen(T);

	rabinKarp(strLen, tokenLen, S, T);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", result[i] + 1);
	}
	printf("\n");

	return 0;
}
