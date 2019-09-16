#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Gift { int time, amounts; };

queue<Gift> Atasks;
queue<Gift> Btasks;

vector<int> Agifts;
vector<int> Bgifts;
int curGiftID;

int main() {
	// read input
	int A, B, N;
	scanf("%d %d %d", &A, &B, &N);
	for (int n = 0; n < N; n++) {
		int t, m;
		char c;
		scanf("%d %c %d", &t, &c, &m);
		if (c == 'B') Atasks.push({t, m});
		else if (c == 'R') Btasks.push({t, m});
	}

	int Alast = 0;
	int Blast = 0;

	while (!Atasks.empty() || !Btasks.empty()) {
		if (!Atasks.empty()) {
			Gift &cur = Atasks.front();
			if (Alast <= cur.time) {
				Alast = cur.time + A;
				cur.time += A;
				cur.amounts--;
				Agifts.push_back(++curGiftID);
				if (!cur.amounts) Atasks.pop();
			}
		}

		if (!Btasks.empty()) {
			Gift &cur = Btasks.front();
			if (Blast <= cur.time) {
				Blast = cur.time + B;
				cur.time += B;
				cur.amounts--;
				Bgifts.push_back(++curGiftID);
				if (!cur.amounts) Btasks.pop();
			}
		}
	}
	
	// print result
	printf("%d\n", (int) Agifts.size());
	for (int id : Agifts) printf("%d ", id);
	printf("\n");
	printf("%d\n", (int) Bgifts.size());
	for (int id : Bgifts) printf("%d ", id);
	printf("\n");

	return 0;
}
