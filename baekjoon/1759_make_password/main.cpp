#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alphas[15];

char password[16];

bool isVowel(char c) {
	switch (c) {
		case 'a': case 'e': case 'i': case 'o': case 'u': return true;
		default: return false;
	}
}

void f(int len, int index, int vowels) {
	if (len == L) {
		if (vowels >= 1 && L - vowels >= 2) printf("%s\n", password);
		return;
	}

	for (int i = index; i < C; i++) {
		password[len] = alphas[i];
		f(len + 1, i + 1, vowels + isVowel(alphas[i]));
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int c = 0; c < C; c++) scanf(" %c", alphas + c);
	sort(alphas, alphas + C);

	f(0, 0, 0);

	return 0;
}
