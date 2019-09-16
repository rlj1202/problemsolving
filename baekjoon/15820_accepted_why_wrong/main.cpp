#include <cstdio>

int main() {
	int S1, S2;
	scanf("%d %d", &S1, &S2);

	bool sample = true;
	bool system = true;

	for (int i = 0; i < S1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a != b) sample = false;
	}

	for (int i = 0; i < S2; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a != b) system = false;
	}

	if (sample && system) {
		printf("Accepted\n");
	} else if (!sample) {
		printf("Wrong Answer\n");
	} else {
		printf("Why Wrong!!!\n");
	}

	return 0;
}
