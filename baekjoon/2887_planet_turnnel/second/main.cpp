#include <iostream>
#include <algorithm>

using namespace std;

struct Planet {
	int coords[3];
	Planet *left[3];
	Planet *right[3];
};

int compareCoord;
bool operator< (const Planet &a, const Planet &b) {
	return a.coords[compareCoord] < b.coords[compareCoord];
}

int N;
Planet planets[100005]; // one-base indexing

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		planets[n] = {{x, y, z}, {}, {}};
	}

	// sort planets and make double-linked list for each axis
	for (int coord = 0; coord < 3; coord++) {
		compareCoord = coord;
		sort(planets, planets + N);
		for (int n = 1; n <= N; n++) {
			planets[n].left[coord] = &planets[n - 1];
			planets[n].right[coord] = &planets[n - 1];
		}
	}

	// make minimum spanning tree
	int cost = 0;
	// TODO

	// print result
	printf("%d\n", cost);

	return 0;
}
