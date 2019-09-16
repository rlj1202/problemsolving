#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Shark {
	int volume, speed, intelli;
	bool operator<= (Shark &o) {
		return volume <= o.volume
			&& speed <= o.speed
			&& intelli <= o.intelli;
	}
	bool operator>= (Shark &o) {
		return volume >= o.volume
			&& speed >= o.speed
			&& intelli >= o.intelli;
	}
	bool operator== (Shark &o) {
		return volume == o.volume
			&& speed == o.speed
			&& intelli == o.intelli;
	}
};

Shark sharks[52];
vector<int> adj[52];

int eater[52][2];
int victim[52][2];

bool visited[52][2];

int result;

bool find_match(int n, int i) {
	visited[n][i] = true;

	for (int next : adj[n]) {
		if (victim[next][0] == -1 ||
				(!visited[victim[next][0]][victim[next][1]]
				 && find_match(victim[next][0], victim[next][1]))) {
			eater[n][i] = next;
			victim[next][0] = n;
			victim[next][1] = i;
			return true;
		}
	}

	return false;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int volume, speed, intelli;
		scanf("%d %d %d", &volume, &speed, &intelli);
		sharks[n] = {volume, speed, intelli};
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (sharks[i] == sharks[j]) {
				adj[i].push_back(j);
			} else if (sharks[i] >= sharks[j]) {
				adj[i].push_back(j);
			} else if (sharks[i] <= sharks[j]) {
				adj[j].push_back(i);
			}
		}
	}

	memset(eater, -1, sizeof(eater));
	memset(victim, -1, sizeof(victim));
	for (int n = 1; n <= N; n++) {
		for (int i = 0; i < 2; i++) {
			if (eater[n][i] != -1) continue;

			memset(visited, false, sizeof(visited));
			if (find_match(n, i)) result++;
		}
	}

	printf("%d\n", N - result);

	return 0;
}
