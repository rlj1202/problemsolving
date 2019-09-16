#include <cstdio>

struct Trie {
	bool terminal;

	Trie *child[10];

	Trie() {
		terminal = false;
		for (int d = 0; d < 10; d++)
			child[d] = NULL;
	}
	~Trie() {
		for (int d = 0; d < 10; d++)
			if (child[d]) delete child[d];
	}

	bool add(char *str) {
		if (*str == 0) {
			for (int d = 0; d < 10; d++) {
				if (child[d]) return false;
			}

			terminal = true;

			return true;
		} else if (terminal) {
			return false;
		}

		int index = *str - '0';
		if (!child[index]) child[index] = new Trie();

		return child[index]->add(str + 1);
	}
};

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		Trie root;

		bool consistent = true;

		for (int n = 0; n < N; n++) {
			char phonenumber[12];
			scanf("%s", phonenumber);

			if (!root.add(phonenumber)) consistent = false;
		}

		printf("%s\n", consistent ? "YES" : "NO");
	}

	return 0;
}
