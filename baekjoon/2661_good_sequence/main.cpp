#include <iostream>

int N;

int seq[80];

bool dfs(int length) {
	for (int sublength = 1; sublength <= length / 2; sublength++) {
		bool fail = true;
		for (int j = 0; j < sublength; j++) {
			if (seq[length - j - 1] != seq[length - j - 1 - sublength])
				fail = false;
		}
		if (fail)
			return false;
	}

	if (length == N)
		return true;

	for (int i = 1; i <= 3; i++) {
		seq[length] = i;
		if (dfs(length + 1))
			return true;
	}

	return false;
}

int main() {
	scanf("%d", &N);

	dfs(0);

	for (int i = 0; i < N; i++) {
		printf("%d", seq[i]);
	}
	printf("\n");

	return 0;
}
