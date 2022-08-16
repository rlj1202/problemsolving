#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct ball {
    int id;
    int color;
    int size;

    bool operator<(const ball &o) const {
        return size < o.size;
    }
};

vector<ball> balls;

ll size_sums[200005];
ll size_total;

ll answers[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        int c, s;
        cin >> c >> s;
        balls.push_back({ n, c, s });
    }

    sort(balls.begin(), balls.end());

    auto iter = balls.begin();

    for (int n = 0; n < N; n++) {
        ball &cur = balls[n];

        while (iter != balls.end() && iter->size < cur.size) {
            size_sums[iter->color] += iter->size;
            size_total += iter->size;

            iter++;
        }

        answers[cur.id] = size_total - size_sums[cur.color];
    }

    for (int n = 0; n < N; n++) {
        cout << answers[n] << '\n';
    }

    return 0;
}
