#include <cstdio>

int N, P;
int stack[7][500005];
int size[7];
int cnt;

int main() {
	scanf("%d %d", &N, &P);

	for (int string = 1; string <= 6; string++) stack[string][size[string]++] = 0;

	for (int n = 1; n <= N; n++) {
		int string, flat;
		scanf("%d %d", &string, &flat);

		while (size[string] > 1 && stack[string][size[string] - 1] > flat) {
			size[string]--;
			cnt++;
		}

		if (stack[string][size[string] - 1] < flat) {
			stack[string][size[string]++] = flat;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
