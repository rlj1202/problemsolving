#include <iostream>
#include <map>

using namespace std;

int T;

int F;
int index;
map<string, int> indices;

int p[100005];
int s[100005];

int find(int e) {
	if (e == p[e]) return e;
	return (p[e] = find(p[e]));
}

bool merge(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B) return false;
	if (s[A] < s[B]) {
		int tmp = A;
		A = B;
		B = tmp;
	}
	p[B] = A;
	s[A] += s[B];
	return true;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &F);
		index = 0;
		indices.clear();

		for (int f = 0; f < F; f++) {
			char a[21], b[21];
			scanf("%s %s", a, b);

			int ia = 0;
			int ib = 0;

			if (!indices.count(a)) {
				indices[a] = index;
				p[index] = index;
				s[index] = 1;
				index++;
			}
			if (!indices.count(b)) {
				indices[b] = index;
				p[index] = index;
				s[index] = 1;
				index++;
			}

			ia = indices[a];
			ib = indices[b];

			merge(ia, ib);
			printf("%d\n", s[find(ia)]);
		}
	}

	return 0;
}
