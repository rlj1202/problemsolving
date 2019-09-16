#include <cstdio>

char word[100005];

char stack[100005];
int top;

int result;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%s", word);

		top = 0;
		for (int i = 0; word[i]; i++) {
			stack[top++] = word[i];
			if (top >= 2 && stack[top - 1] == stack[top - 2])
				top -= 2;
		}

		if (top == 0) result++;
	}

	printf("%d\n", result);

	return 0;
}
