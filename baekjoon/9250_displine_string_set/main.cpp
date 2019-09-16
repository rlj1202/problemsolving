#include <cstdio>
#include <queue>

using namespace std;

struct Trie {
	bool output;

	Trie *go[26];
	Trie *fail;

	Trie() {
		output = false;
		fail = NULL;
		for (int i = 0; i < 26; i++)
			go[i] = NULL;
	}

	~Trie() {
		for (int i = 0; i < 26; i++)
			if (go[i]) delete go[i];
	}

	void add(char *str) {
		if (*str == 0) {
			output = true;
			return;
		}

		int index = *str - 'a';
		if (!go[index]) go[index] = new Trie();

		go[index]->add(str + 1);
	}
};

int main() {
	// read input
	int N;
	scanf("%d", &N);

	Trie root;

	for (int n = 0; n < N; n++) {
		char S[102];
		scanf("%s", S);

		root.add(S);
	}

	// make failure edge
	queue<Trie*> q;
	q.push(root.fail = &root);

	while (!q.empty()) {
		Trie *cur = q.front(); q.pop();

		for (int i = 0; i < 26; i++) {
			Trie *next = cur->go[i];
			if (!next) continue;

			if (cur == &root) { // fail of root is root itself
				next->fail = &root;
			} else { // find longest suffix
				Trie *dest = cur->fail;

				// until encounter root and cannot go
				while (dest != &root && dest->go[i] == NULL) dest = dest->fail;

				if (dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}

			q.push(next); // push it to the queue to do BFS
		}
	}

	// print result
	int Q;
	scanf("%d", &Q);

	while (Q--) {
		char S[10004];
		scanf("%s", S);

		Trie *state = &root;
		bool found = false;

		for (int i = 0; S[i] != 0; i++) {
			int index = S[i] - 'a';

			// until encouter root and cannot go
			while (state != &root && state->go[index] == NULL) state = state->fail;

			if (state->go[index]) state = state->go[index];

			found |= state->output;
			found |= state->fail->output;

			if (found) break;
		}

		printf("%s\n", found ? "YES" : "NO");
	}

	return 0;
}
