#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
char words[20004][52];
int wordlens[20004];
long long wordhashs[20004];

int arr1[20004];
int arr2[20004];

int *indices;
int *newindices;

int main() {
	// init
	indices = arr1;
	newindices = arr2;

	// read input
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%s", words[n]);

		wordlens[n] = strlen(words[n]);
		indices[n] = n;

		long long hash = 0;
		for (int i = 0; i < wordlens[n]; i++) {
			hash *= 26;
			hash += words[n][i] - 'a';
		}
		wordhashs[n] = hash;
	}

	// sort words using merge sort algorithm
	int tmp = N;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;

	for (int l = 0; l <= log; l++) {
		int len = 1 << l;
		int blocks = (N + len - 1) / len;

		int index = 0;

		for (int b = 0; b < blocks - 1; b += 2) {
			int leftoffset = b * len;
			int rightoffset = (b + 1) * len;

			int leftlen = len;
			int rightlen = min(len, N - rightoffset);

			int l = 0;
			int r = 0;
			
			while (l < leftlen || r < rightlen) {
				if (l >= leftlen) newindices[index++] = indices[rightoffset + r++];
				else if (r >= rightlen) newindices[index++] = indices[leftoffset + l++];
				else {
					if (wordlens[indices[leftoffset + l]] < wordlens[indices[rightoffset + r]]) {
						newindices[index++] = indices[leftoffset + l++];
					} else if (wordlens[indices[leftoffset + l]] > wordlens[indices[rightoffset + r]]) {
						newindices[index++] = indices[rightoffset + r++];
					} else {
						int cmp = strcmp(words[indices[leftoffset + l]], words[indices[rightoffset + r]]);
						if (cmp <= 0) newindices[index++] = indices[leftoffset + l++];
						else newindices[index++] = indices[rightoffset + r++];
					}
				}
			}
		}

		while (index < N) { // move unsorted elements
			newindices[index] = indices[index];
			index++;
		}

		// swap arrays
		int *tmp = indices;
		indices = newindices;
		newindices = tmp;
	}

	// print result
	long long lasthash = wordhashs[indices[0]];
	printf("%s\n", words[indices[0]]);
	for (int n = 1; n < N; n++) {
		long long curhash = wordhashs[indices[n]];
		if (lasthash != curhash) {
			printf("%s\n", words[indices[n]]);
			lasthash = curhash;
		}
	}

	return 0;
}
