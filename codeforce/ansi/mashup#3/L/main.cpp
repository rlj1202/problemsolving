#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char passwords[200005][52];
vector<int> groups[26];
int parents[200005];

int find(int a) {
    if (parents[a] == -1) return a;
    return parents[a] = find(parents[a]);
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return;

    parents[A] = B;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%s", passwords[n]);

        for (int i = 0; passwords[n][i] != 0; i++) {
            groups[passwords[n][i] - 'a'].push_back(n);
        }
    }

    memset(parents, -1, sizeof(parents));

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < groups[i].size(); j++) {
            merge(groups[i][j - 1], groups[i][j]);
        }
    }

    int result = 0;
    for (int n = 0; n < N; n++) {
        if (find(n) == n) result++;
    }
    printf("%d\n", result);

    return 0;
}
