#include <cstdio>

bool check[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int n;
		scanf("%d", &n);
		check[n] = true;
	}

	for (int n = 1; n <= 30; n++)
		if (!check[n]) printf("%d\n", n);

	return 0;
}
