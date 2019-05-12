/*
 * failed code
 */
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> words[26];

int out[26];

int dp(int alpha) {
	if (alpha == 26) return 1;

	printf("%d : ", alpha);
	for (int i = 0; i < N; i++) {
		printf("%d ", out[i]);
	}
	printf("\n");

	int sum = 0;

	for (int n : words[alpha]) {
		if (out[n]) {
			return dp(alpha + 1);
		}

		out[n] = 1;

		int result = dp(alpha + 1);
		sum += result;

		out[n] = 0;
	}

	return sum;
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		char word[101];
		scanf("%s", word);

		for (int i = 0; word[i] != 0; i++)
			words[word[i] - 'a'].push_back(n);
	}

	for (int i = 0; i < 26; i++) {
		printf("[%c] : ", i + 'a');
		for (int n : words[i]) printf("%d ", n);
		printf("\n");
	}

	printf("%d\n", dp(0));

	return 0;
}
