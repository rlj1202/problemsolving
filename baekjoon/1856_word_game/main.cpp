#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Segment { int l, r; int w; };

bool operator< (const Segment &a, const Segment &b) {
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

int W, L;
char S[302];
char words[602][26];

vector<Segment> segments;

int main() {
	scanf("%d %d", &W, &L);
	scanf("%s", S);
	for (int w = 0; w < W; w++) {
		scanf("%s", words[w]);

		int wordlen = strlen(words[w]);

		int wordpointer = 0;
		int start, end;
		for (int l = 0; l <= L; l++) {
			if (words[w][wordpointer] == 0) {
				end = l;
				printf("(%d %d) ", start, end); // XXX
				segments.push_back({start, end, wordlen});

				wordpointer = 0;
			}
			if (S[l] == words[w][wordpointer]) {
				if (wordpointer == 0) start = l;
				wordpointer++;
			}
		}

		printf("\n"); // XXX
	}

	sort(segments.begin(), segments.end());
	
	printf("%d\n", 0);

	return 0;
}
