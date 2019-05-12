#include <cstdio>

int a[502];
int b[502];

int main() {
	for (int i = 1; i <= 500; i++) a[i] = i + a[i - 1];
	for (int i = 1; i <= 500; i++) b[i] = a[i] + b[i - 1];

	int T;
	scanf("%d", &T);

	while (T--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", b[x]);
	}

	return 0;
}
