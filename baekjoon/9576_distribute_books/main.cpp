#include <cstdio>
#include <cstring>

int range[1003][2];

int person[1003];
int book[1003];

bool visited[1003];

int result;

bool find_match(int m) {
	visited[m] = true;
	int l = range[m][0];
	int r = range[m][1];
	for (int next = l; next <= r; next++) {
		if (book[next] == -1 || (!visited[book[next]] && find_match(book[next]))) {
			person[m] = next;
			book[next] = m;
			return true;
		}
	}

	return false;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		for (int m = 0; m < M; m++) {
			int a, b;
			scanf("%d %d", &a, &b);
			range[m][0] = a;
			range[m][1] = b;
		}

		result = 0;
		memset(person, -1, sizeof(person));
		memset(book, -1, sizeof(book));
		for (int m = 0; m < M; m++) {
			if (person[m] != -1) continue;

			memset(visited, false, sizeof(visited));
			if (find_match(m)) result++;
		}

		printf("%d\n", result);
	}

	return 0;
}
