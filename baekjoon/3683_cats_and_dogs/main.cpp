#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int CAT = 0;
const int DOG = 1;

int previous[502];

int visited[502];
int visited_flag;

bool dfs(vector<int> *adj, int cur) {
    if (visited[cur] == visited_flag) return false;
    visited[cur] = visited_flag;

    for (int next : adj[cur]) {
        if (!previous[next] || dfs(adj, previous[next])) {
            previous[next] = cur;
            return true;
        }
    }

    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int votes[502][3];
        vector<int> adj[502];
        vector<int> cats;
        memset(previous, 0, sizeof(previous));
        memset(visited, 0, sizeof(visited));
        visited_flag = 0;

        int C, D, V;
        scanf("%d %d %d", &C, &D, &V);
        for (int v = 1; v <= V; v++) {
            char A, B;
            int Aid, Bid;
            scanf(" %c%d %c%d", &A, &Aid, &B, &Bid);

            votes[v][0] = (A == 'C');
            votes[v][1] = Aid;
            votes[v][2] = Bid;

            if (A == 'C') cats.push_back(v);
        }

        for (int i = 1; i <= V; i++) {
            for (int j = 1; j < i; j++) {
                if (votes[i][0] != votes[j][0] &&
                    (votes[i][1] == votes[j][2] ||
                    votes[i][2] == votes[j][1])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int result = 0;

        for (int v : cats) {
            visited_flag++;
            result += dfs(adj, v);
        }

        printf("%d\n", V - result);
    }

    return 0;
}