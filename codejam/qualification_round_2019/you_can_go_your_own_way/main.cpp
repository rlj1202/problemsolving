#include <cstdio>

char raw[100005];

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		scanf("%s", raw);
		for (int i = 0; raw[i]; i++) raw[i] = raw[i] == 'S' ? 'E' : 'S';
		printf("Case #%d: %s\n", t, raw);
	}

	return 0;
}
