#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Grade { int t, p; };

int N;
Grade grades[5003];

Grade total;

bool operator< (const Grade &a, const Grade &b) {
	return ((float) a.t) / a.p < ((float) b.t) / b.p;
}

int operator* (const Grade &a, const Grade &b) {
	return a.t * b.p - a.p * b.t;
}

float len(const Grade &a) {
	return sqrt(a.t * a.t + a.p * a.p);
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int t, p;
		scanf("%d %d", &t, &p);
		grades[n] = {t, p};
		total.t += t;
		total.p += p;
	}
	sort(grades, grades + N);

	printf("\t");
	for (int n = 0; n < N; n++) {
		float delta = (total * grades[n]) / len(total);
		printf("%f ", delta);
	}
	printf("\n");

	printf("%d\n", 0);
	printf("\n");
	
	return 0;
}
