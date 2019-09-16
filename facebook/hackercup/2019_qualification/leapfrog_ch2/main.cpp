#include <cstdio>
#include <cstring>

char L[5003];

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%s", L);

		int len = strlen(L);
		int betas = 0;

		for (int i = 0; i < len; i++) betas += L[i] == 'B';

		bool cond = (betas >= 2 || betas >= len / 2) && betas <= len - 2;

		printf("Case #%d: %c\n", t, cond ? 'Y' : 'N');
	}

	return 0;
}
