#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

const int MAX_FACTORIAL = 30;

long long factorial[MAX_FACTORIAL + 1];

char words[3003][3003];
char *wordssorted[3003];

bool wordsort(char *a, char *b) {
	return strcmp(a, b) < 0;
}

int childs[3003];
char line[3003];

int main() {
	factorial[0] = 1;
	for (int f = 1; f <= MAX_FACTORIAL; f++) {
		factorial[f] = f * factorial[f - 1];
		factorial[f] %= MOD;
	}

	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%s", wordssorted[n] = words[n]);
	sort(wordssorted, wordssorted + N, wordsort);

	long long count = 1;

	for (int n = 0; n < N; n++) {
		char *str = wordssorted[n];
		int state = 0;

		while (true) {
			if (*str == 0) {
				childs[state]++;
				break;
			}

			if (line[state] == 0) {
				count *= factorial[childs[state + 1]];
				count %= MOD;
				line[state + 1] = 0;
				childs[state + 1] = 0;

				line[state] = *str;
				childs[state] = 1;
			} else if (line[state] != *str) {
				count *= factorial[childs[state + 1]];
				count %= MOD;
				line[state + 1] = 0;
				childs[state + 1] = 0;

				line[state] = *str;
				childs[state]++;
			}

			str++;
			state++;
		}
	}

	for (int n = 0; n < N; n++) {
		count *= factorial[childs[n]];
		count %= MOD;
	}

	printf("%lld\n", count);

	return 0;
}
