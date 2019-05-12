#include <iostream>

using namespace std;

int N, M;
char target[102];

int main() {
	scanf("%d %d", &N, &M);
	scanf("%s", target);

	for (int m = 0; m < M; m++) {
		char postit[1003];
		scanf("%s", postit);

		int found = 0;

		for (int i = 0; postit[i] != 0 && found < N; i++) {
			if (target[found] == postit[i]) found++;
		}

		printf("%s\n", found == N ? "true" : "false");
	}

	return 0;
}
