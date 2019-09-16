#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Trie {
	bool output;
	int wordid;
	Trie *go[26];

	Trie() : output(false), wordid(0) {
		for (int i = 0; i < 26; i++) go[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (go[i]) delete go[i];
	}

	void add(char *str, int wordid) {
		if (*str == 0) {
			output = true;
			this->wordid = wordid;
			return;
		}

		int index = *str - 'A';
		if (!go[index]) go[index] = new Trie();

		go[index]->add(str + 1, wordid);
	}
};

const int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const int scores[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

char words[300005][10];
char *wordssorted[300005];

char grid[6][6];

bool found[300005];

bool visited[6][6];

void dfs(Trie *state, int r, int c) {
	int index = grid[r][c] - 'A';
	Trie *next = state->go[index];
	if (!next) return;

	visited[r][c] = true;

	if (next->output) found[next->wordid] = true;

	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (grid[nr][nc] == 0) continue;
		if (visited[nr][nc]) continue;

		dfs(next, nr, nc);
	}

	visited[r][c] = false;
}

bool wordsort(const char *a, const char *b) {
	if (strlen(a) == strlen(b)) return strcmp(a, b) <= 0;
	else return strlen(a) < strlen(b);
}

int main() {
	// read input
	int W;
	scanf("%d", &W);

	Trie root;

	for (int w = 0; w < W; w++) {
		scanf("%s", words[w]);
		wordssorted[w] = words[w];
	}

	sort(wordssorted, wordssorted + W, wordsort);

	for (int w = 0; w < W; w++) {
		root.add(wordssorted[w], w);
	}

	// per test cases
	int B;
	scanf("%d", &B);

	while (B--) {
		// read board
		for (int r = 1; r <= 4; r++)
			for (int c = 1; c <= 4; c++)
				scanf(" %c", &grid[r][c]);

		memset(found, 0, sizeof(found));

		for (int r = 1; r <= 4; r++)
			for (int c = 1; c <= 4; c++)
				dfs(&root, r, c);

		int score = 0;
		int totalwords = 0;

		int maxlen = 0;
		char *maxword = 0;

		for (int w = 0; w < W; w++) {
			if (!found[w]) continue;

			totalwords++;

			char *word = wordssorted[w];
			int wordlen = strlen(word);

			score += scores[wordlen];

			if (maxlen < wordlen) {
				maxlen = wordlen;
				maxword = word;
			}
		}

		// print result
		printf("%d %s %d\n", score, maxword, totalwords);
	}

	return 0;
}
