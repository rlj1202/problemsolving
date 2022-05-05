#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int location[100005];
int items[100005][62];

vector<int> logs;
vector<int> players;

int main() {
    int T, N;
    scanf("%d %d", &T, &N);

    for (int n = 1; n <= N; n++) location[n] = 1;

    while (T--) {
        int logid;
        int player;
        char action;
        int a_param, b_param;
        scanf("%d %d %c %d", &logid, &player, &action, &a_param);

        if (action == 'C') scanf("%d", &b_param);

        bool valid = true;
        bool unvalid_attack = false;

        if (action == 'M') {
            location[player] = a_param;
        } else if (action == 'F') {
            if (a_param != location[player]) {
                valid = false;
            }

            items[player][a_param]++;
        } else if (action == 'C') {
            if (!items[player][a_param] || !items[player][b_param]) {
                valid = false;
            }

            if (items[player][a_param]) items[player][a_param]--;
            if (items[player][b_param]) items[player][b_param]--;
        } else if (action == 'A') {
            if (location[a_param] != location[player]) {
                valid = false;
                unvalid_attack = true;
            }
        }

        if (!valid) {
            logs.push_back(logid);
            if (unvalid_attack) players.push_back(player);
        }
    }

    sort(players.begin(), players.end());
    players.erase(unique(players.begin(), players.end()), players.end());

    printf("%d\n", logs.size());
    for (int log : logs) printf("%d ", log);
    if (logs.size()) printf("\n");

    printf("%d\n", players.size());
    for (int player : players) printf("%d ", player);
    if (players.size()) printf("\n");

    return 0;
}
