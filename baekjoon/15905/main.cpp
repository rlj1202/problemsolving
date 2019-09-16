#include <cstdio>
#include <algorithm>

using namespace std;

struct Person {
	int solved, penalty;

	bool operator< (const Person &o) const {
		if (solved == o.solved) return penalty < o.penalty;
		return solved > o.solved;
	}
};

Person persons[72];

int main() {
	int N;
	
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		int solved, penalty;

		scanf("%d %d", &solved, &penalty);
		persons[n] = {solved, penalty};
	}

	sort(persons, persons + N);

	int m = 5;
	while (m < N && persons[4].solved == persons[m].solved) m++;

	printf("%d\n", m - 5);
	
	return 0;
}
