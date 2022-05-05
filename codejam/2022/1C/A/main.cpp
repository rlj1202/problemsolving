#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

char towers[102][12];

bool check_valid(char *str) {
    bool appeared[26];
    memset(appeared, 0, sizeof(appeared));

    for (int i = 1; str[i] != 0; i++) {
        int prev = str[i - 1] - 'A';
        int cur = str[i] - 'A';

        if (prev != cur) {
            if (appeared[prev]) return false;
            appeared[prev] = true;
        }
    }

    return !appeared[str[strlen(str) - 1] - 'A'];
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%s", towers[n]);
        }

        bool possible = true;

        for (int n = 0; n < N; n++) {
            if (!check_valid(towers[n])) {
                possible = false;
                break;
            }
        }

        vector<int> adj[102];
        int indegree[102];
        memset(indegree, 0, sizeof(indegree));

        for (int n = 0; n < N; n++) {
            char* A = towers[n];
            int Alen = strlen(A);

            for (int m = n + 1; m < N; m++) {
                char* B = towers[m];
                int Blen = strlen(B);

                if (A[Alen - 1] == B[0]) {
                    adj[n].push_back(m);
                    indegree[m]++;
                } else if (B[Blen - 1] == A[0]) {
                    adj[m].push_back(n);
                    indegree[n]++;
                }
            }
        }

        stack<int> s;

        for (int n = 0; n < N; n++) {
            if (indegree[n] == 0) {
                s.push(n);
            }
        }

        queue<int> result;

        while (!s.empty()) {
            int cur = s.top();
            s.pop();

            result.push(cur);

            for (int next : adj[cur]) {
                if ((--indegree[next]) == 0) {
                    s.push(next);
                }
            }
        }

        if (result.size() != N) {
            possible = false;
        }

        char final[1003] = { '\0' };

        while (!result.empty()) {
            int cur = result.front();
            result.pop();

            strcat(final, towers[cur]);
        }

        if (possible) possible = check_valid(final);

        printf("Case #%d: %s\n", t, possible ? final : "IMPOSSIBLE");
    }

    return 0;
}
