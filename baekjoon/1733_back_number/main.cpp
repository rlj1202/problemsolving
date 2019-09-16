#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int adj[1000006][2];

int toward[1000006];
int back[1000006];
int step[1000006];

bool find_match(int n, int curstep) {
	step[n] = curstep;
	
	for (int next : adj[n]) {
		if (back[next] == -1 ||
				(step[back[next]] != curstep && find_match(back[next], curstep))) {
			toward[n] = next;
			back[next] = n;
			return true;
		}
	}

	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[n][0] = a;
		adj[n][1] = b;
	}

	bool valid = true;
	memset(back, -1, sizeof(back));
	int step = 1;
	for (int n = 0; n < N; n++) {
		if (!find_match(n, step++)) {
			valid = false;
			break;
		}
	}

	if (valid) {
		for (int n = 0; n < N; n++) printf("%d\n", toward[n]);
	} else {
		printf("%d\n", -1);
	}

	return 0;
}
