#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<tuple<int, int, int>> boxes;

    int N, C;
    cin >> N >> C;
    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        int from, to, count;
        cin >> from >> to >> count;

        boxes.push_back({ to, from, count });
    }

    sort(boxes.begin(), boxes.end());

    int answer = 0;

    vector<int> flow(N + 1);

    for (int m = 0; m < M; m++) {
        auto [to, from, count] = boxes[m];

        int min_flow = count;

        for (int n = from; n < to; n++) {
            min_flow = min(min_flow, C - flow[n]);
        }

        for (int n = from; n < to; n++) {
            flow[n] += min_flow;
        }

        answer += min_flow;
    }

    cout << answer << '\n';

    return 0;
}
