//////////////////////////////////////////////////////////////////////////
// main 함수는 수정 및 접근이 불가능 합니다.

#include <iostream>
#include <cstdlib>
#include <cstdio>

#define MAX 4096
using namespace std;
static unsigned char ori_pattern[MAX][32][32];
int dummy1[MAX];
unsigned char pattern[MAX][32][32];
int dummy2[MAX];
unsigned char input[64][64];
int dummy3[MAX];
extern void init();
extern int solve(unsigned char pattern[][32][32], unsigned char picture[][64]);
int main() {
	int seed;
	cin>>seed;
	srand(seed);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 32; j++) {
			for (int k = 0; k < 32; k++) {
				ori_pattern[i][j][k] = rand() % 256;
			}
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 32; j++) {
			for (int k = 0; k < 32; k++) {
				pattern[i][j][k] = ori_pattern[i][j][k];
			}
		}
	}

	int problemNum = 4096;
	int correct = 0;
	int score = 0;

	init();

	for (int TestCase = 1; TestCase <= problemNum; TestCase++) {
		int curIdx = rand() % MAX;
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 64; j++) {
				input[i][j] = rand() % 256;
			}
		}

		int sr = rand() % 33;
		int sc = rand() % 33;

		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 32; j++) {
				input[sr + i][sc + j] = ori_pattern[curIdx][i][j];
			}
		}
		int result = solve(pattern, input);
		if (result == curIdx) score += 1;
	}

	cout << "score : " << score;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

// user 영역은 수정 및 접근이 가능합니다.
// user 영역에서 init 함수 및 solve 함수를 구현하여 score 값을 최대화 하시오.

#include <algorithm>

#define MAX 4096

using namespace std;

struct hashinfo { unsigned long long hash; int index; };

bool operator< (const hashinfo& a, const hashinfo& b) {
	return a.hash < b.hash;
}

void init() {
}

int solve(unsigned char pattern[][32][32], unsigned char picture[][64]) {
	hashinfo patternHashs[MAX];
	for (int i = 0; i < MAX; i++) {
		unsigned long long patternHash = 0;
		for (int c = 0; c < 8; c++) {
			patternHash <<= 8;
			patternHash |= pattern[i][0][c];
		}
		patternHashs[i] = hashinfo{patternHash, i};
	}
	sort(patternHashs, patternHashs + MAX);

	for (int r = 0; r < 32; r++) {
		unsigned long long pictureHash = 0;
		for (int c = 0; c < 8; c++) {
			pictureHash <<= 8;
			pictureHash |= picture[r][c];
		}

		int index = lower_bound(patternHashs, patternHashs + MAX, hashinfo{pictureHash, 0}) - patternHashs;
		if (patternHashs[index].hash == pictureHash) return patternHashs[index].index;

		for (int c = 8; c < 64; c++) {
			pictureHash <<= 8;
			pictureHash |= picture[r][c];

			int index = lower_bound(patternHashs, patternHashs + MAX, hashinfo{pictureHash, 0}) - patternHashs;
			if (patternHashs[index].hash == pictureHash) return patternHashs[index].index;
		}
	}

	return 1;
}
