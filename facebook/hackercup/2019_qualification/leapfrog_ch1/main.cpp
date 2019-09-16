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
		
		int i = 0;
		while (L[i]) {
			betas += L[i] == 'B';
			i++;
		}

		printf("Case #%d: %c\n",
				t,
				betas >= len / 2 && betas <= len - 2 ? 'Y' : 'N');
	}

	return 0;
}
