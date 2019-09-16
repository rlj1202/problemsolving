#include <cstdio>

struct Trie {
	Trie *go[26];

	Trie() {
		for (int i = 0; i < 26; i++) go[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (go[i]) delete go[i];
	}

	void add(char *str) {
		if (*str == 0) return; 

		int index = *str - 'a';
		if (!go[index]) go[index] = new Trie();

		go[index]->add(str + 1);
	}
};

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	char S[502];

	Trie root;

	while (N--) {
		scanf("%s", S);
		root.add(S);
	}

	int count = 0;

	while (M--) {
		scanf("%s", S);

		Trie *state = &root;

		int i;
		for (i = 0; S[i] != 0; i++) {
			int index = S[i] - 'a';
			if (state->go[index]) state = state->go[index];
			else break;
		}

		if (S[i] == 0) count++;
	}

	printf("%d\n", count);

	return 0;
}
