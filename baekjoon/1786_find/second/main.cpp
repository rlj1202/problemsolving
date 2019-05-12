#include <cstdio>
#include <cstring>

using namespace std;

char T[1000006];
char P[1000006];
int plen;

int pi[1000006];

void makeFailure() {
	int j = 0;
	for (int i = 0; P[i] != 0; i++) {
		
		if (P[i] == P[j]) {
		}
	}
}

int main() {
	scanf("%s %s", T, P);
	plen = strlen(P);


	printf("############################################################################\n");
	for (int i = 0; i < plen; i++) printf("%d ", pi[i]); printf("\n");

	// find using KMP
	int j = 0;
	for (int i = 0; T[i] != 0; i++) {
		while (j && T[i] != P[j])
			j = pi[j];

		if (T[i] == P[j]) {
			if (j == plen) { // found word
				// TODO
				printf("at %d\n", i);
				// TODO

				j = pi[j];
			} else {
				j++;
			}
		}
	}

	printf("%d\n", 0);

	return 0;
}
