#include <cstdio>
#include <vector>

using namespace std;

struct Trie;

struct Edge {
	char c;
	Trie *to;
};

struct Trie {
	vector<Edge> go;

	int count(char *str, int j, int *fail) {
		int result = 0;

		for (Edge edge : go) {
			int curj = j;
			char c = edge.c;

			while (curj && c != str[curj])
				curj = fail[curj - 1];
			
			if (c == str[curj]) {
				curj++;

				if (str[curj] == 0) {
					result++;
				}
			}

			result += edge.to->count(str, curj, fail);
		}

		return result;
	}
};

int N;
char P[500005];

Trie tries[500005];

int fail[500005];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N - 1; n++) {
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);

		tries[a].go.push_back({c, tries + b});
	}
	scanf("%s", P);

	int j = 0;
	for (int i = 1; P[i] != 0; i++) {
		while (j && P[i] != P[j])
			j = fail[j - 1];

		if (P[i] == P[j])
			fail[i] = ++j;
	}

	int result = tries[1].count(P, 0, fail);
	printf("%d\n", result);

	return 0;
}
