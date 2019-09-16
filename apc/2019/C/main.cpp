#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Card {
	int attack;
	int life;

	bool operator< (const Card &o) const {
		return life < o.life;
	}
};

int N, M;

vector<Card> A;
vector<Card> B;

bool lifemark[20];

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		int attack;
		int life;
		scanf("%d %d", &attack, &life);

		A.push_back({attack, life});
	}
	for (int m = 0; m < M; m++) {
		int attack;
		int life;
		scanf("%d %d", &attack, &life);

		B.push_back({attack, life});
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
		}
	}

	for (int n = 0; n < N; n++) {
		lifemark[A[n].life] = true;
	}
	for (int m = 0; m < M; m++) {
		lifemark[B[m].life] = true;
	}

	for (int life = 1; life <= 12; life++) {
		if (!lifemark[life]) {

		}
	}

	printf("%d\n", 0);

	return 0;
}
