#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Task {
	int time;
	int amounts;
};

int A, B, N;

queue<Task> tasksA;
queue<Task> tasksB;

int cooltimeA;
int cooltimeB;

int productID;

vector<int> productsA;
vector<int> productsB;

int main() {
	scanf("%d %d %d", &A, &B, &N);
	for (int n = 0; n < N; n++) {
		int t;
		char c;
		int m;
		scanf("%d %c %d", &t, &c, &m);

		if (c == 'B') {
			tasksA.push({t, m});
		} else { // c == 'R'
			tasksB.push({t, m});
		}
	}

	for (long long t = 0; !tasksA.empty() || !tasksB.empty(); t++) {
		if (cooltimeA) cooltimeA--;
		if (cooltimeB) cooltimeB--;

		while (cooltimeA == 0) {
			if (!tasksA.empty() && tasksA.front().time <= t) {
				tasksA.front().amounts--;
				cooltimeA = A;
				if (tasksA.front().amounts == 0) tasksA.pop();

				productsA.push_back(++productID);
			} else {
				break;
			}
		}

		while (cooltimeB == 0) {
			if (!tasksB.empty() && tasksB.front().time <= t) {
				tasksB.front().amounts--;
				cooltimeB = B;
				if (tasksB.front().amounts == 0) tasksB.pop();

				productsB.push_back(++productID);
			} else {
				break;
			}
		}
	}

	printf("%d\n", (int) productsA.size());
	for (int id : productsA) printf("%d ", id);
	printf("\n");
	printf("%d\n", (int) productsB.size());
	for (int id : productsB) printf("%d ", id);
	printf("\n");

	return 0;
}
