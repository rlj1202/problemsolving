#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii points[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> points[n].first >> points[n].second;
        }
        sort(points, points + N);

        map<int, vector<int>> horizontal;
        map<int, vector<int>> vertical;

        for (int n = 0; n < N; n++) {
            pii &cur = points[n];

            vertical[cur.first].push_back(n);
            horizontal[cur.second].push_back(n);
        }

        // Lets find error point
        int error_x = -1;
        int error_y = -1;

        for (auto &[x, col] : vertical) {
            if (col.size() % 2) error_x = x;
        }

        for (auto &[y, row] : horizontal) {
            if (row.size() % 2) error_y = y;
        }

        if (error_x != -1 && error_y != -1) {
            vector<int> &error_col = vertical[error_x];
            vector<int> &error_row = horizontal[error_y];

            auto c = error_col.begin();
            auto r = error_row.begin();
     
            while (c != error_col.end() || r != error_row.end()) {
                if (*c == *r) break;

                if (*c < *r) c++;
                else r++;
            }

            error_col.erase(c);
            error_row.erase(r);
        }

        //
        ll answer = 0;

        for (auto &[x, col] : vertical) {
            for (int i = 0; i < col.size(); i += 2) {
                pii &cur = points[col[i]];
                pii &next = points[col[i + 1]];
                answer += next.second - cur.second;
            }
        }
        for (auto &[y, row] : horizontal) {
            for (int i = 0; i < row.size(); i += 2) {
                pii &cur = points[row[i]];
                pii &next = points[row[i + 1]];
                answer += next.first - cur.first;
            }
        }

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
    }

    cout << '\n';

    return 0;
}
