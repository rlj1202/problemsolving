#include <cstdio>
#include <queue>

using namespace std;

int getindex(char);

struct Trie {
	bool output;
	Trie *go[4];
	Trie *fail;

	Trie() : output(false), fail(NULL) {
		for (int i = 0; i < 4; i++) go[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 4; i++)
			if (go[i]) delete go[i];
	}

	Trie* add(char *str, int len, bool forward, bool terminal) {
		if (len == 0) {
			output |= terminal;

			return this;
		}

		int index = getindex(*str);
		if (!go[index]) go[index] = new Trie();

		return go[index]->add(str + (forward ? 1 : -1), len - 1, forward, terminal);
	}
};

char dna[1000006];
char marker[102];

int getindex(char c) {
	if (c == 'A') return 0;
	else if (c == 'G') return 1;
	else if (c == 'T') return 2;
	else return 3; // C
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N, M;
		scanf("%d %d", &N, &M);
		scanf("%s %s", dna, marker);

		// make mutants
		Trie root;

		root.add(marker, M, true, true);

		for (int i = 0; i <= M - 2; i++) {
			for (int j = i + 2; j <= M; j++) {
				root.add(marker, i, true, false)
					->add(marker + j - 1, j - i, false, false)
					->add(marker + j, M - j, true, true);
			}
		}

		// make failure
		queue<Trie*> q;
		q.push(root.fail = &root);

		while (!q.empty()) {
			Trie *cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				Trie *next = cur->go[i];
				if (!next) continue;

				q.push(next);

				Trie *dest = cur->fail;
				while (dest != &root && !dest->go[i])
					dest = dest->fail;

				if (cur != &root && dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}
		}

		// find mutantation
		Trie *state = &root;

		int count = 0;

		for (int i = 0; dna[i] != 0; i++) {
			int index = getindex(dna[i]);

			while (state != &root && !state->go[index])
				state = state->fail;

			if (state->go[index]) state = state->go[index];

			bool found = false;
			found |= state->output;
			found |= state->fail->output;

			if (found) count++;
		}

		// print result
		printf("%d\n", count);
	}

	return 0;
}
