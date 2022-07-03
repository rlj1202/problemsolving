#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char colors[300005];
int weights[300005];

int num_groups;
int groups[300005];

vector<int> new_list;

long long solve(int l, int r) {
    if (r - l + 1 < 3) {
        return 0;
    }

    int cur_max = 0;
    int max_i = 0;
    for (int i = l + 1; i < r; i++) {
        if (cur_max < new_list[i]) {
            cur_max = new_list[i];
            max_i = i;
        }
    }

    return cur_max + solve(l, max_i - 1) + solve(max_i + 1, r);
}

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", colors);
    for (int n = 0; n < N; n++) {
        scanf("%d", weights + n);
    }

    int cur_max = weights[0];
    for (int n = 1; n < N; n++) {
        if (colors[n - 1] != colors[n]) {
            new_list.push_back(cur_max);

            cur_max = weights[n];
        } else {
            cur_max = max(cur_max, weights[n]);
        }
    }
    new_list.push_back(cur_max);

    long long result = solve(0, new_list.size() - 1);

    printf("%lld\n", result);

    return 0;
}
