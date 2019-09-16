#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char T[1000006];
char P[1000006];

int pi[1000006];

void makeFailure() {
	int j = 0;
	for (int i = 1; P[i] != 0; i++) {
		while (j && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
}

int main() {
	// read input
	scanf("%[^\n]%*c%[^\n]%*c", T, P);

	// make failure table
	makeFailure();

	// find using KMP algorithm
	vector<int> results;

	int j = 0;
	for (int i = 0; T[i] != 0; i++) {
		while (j && T[i] != P[j])
			j = pi[j - 1];

		if (T[i] == P[j]) {
			j++;
			if (P[j] == 0) {
				results.push_back(i - j + 1);
				j = pi[j - 1];
			}
		}
	}

	// print result
	printf("%d\n", (int) results.size());
	for (int i : results)
		printf("%d ", i + 1);
	printf("\n");

	return 0;
}
