#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;
const int MAX_FACTORIAL = 30;

long long factorial[MAX_FACTORIAL + 1];

char words[3003][3003];
char *wordssorted[3003];

long long result = 1;

struct Trie {
	int index;
	Trie* go;

	int childs;

	Trie(int index) : index(index), childs(0), go(NULL) {
	}
	~Trie() {
		if (childs > 1) {
			result *= factorial[childs];
			result %= MOD;
		}
		if (go) delete go;
	}
};

bool wordsort(const char *a, const char *b) {
	return strcmp(a, b) < 0;
}

int main() {
	// init
	factorial[0] = 1;
	for (int f = 1; f <= MAX_FACTORIAL; f++) {
		factorial[f] = f * factorial[f - 1];
		factorial[f] %= MOD;
	}

	// read input
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%s", wordssorted[n] = words[n]);
	sort(wordssorted, wordssorted + N, wordsort);

	// calculate
	Trie *root = new Trie(-1);
	for (int n = 0; n < N; n++) {
		Trie *state = root;
		char *str = wordssorted[n];

		while (true) {
			if (*str == 0) {
				state->childs++; // pseudo child which represents terminate state
				break;
			}

			int index = *str - 'A';
			if (!state->go) {
				state->go = new Trie(index);
				state->childs++;
			} else if (state->go->index != index) {
				delete state->go;
				state->go = new Trie(index);
				state->childs++;
			}

			state = state->go;
			str++;
		}
	}

	// print result
	delete root;
	printf("%lld\n", result);

	return 0;
}
