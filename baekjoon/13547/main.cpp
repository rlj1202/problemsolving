#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

int arr[100005];

vector<tiii> ranges;

int counts[1000006];
int answers[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }
    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({ l, r, m });
    }

    // sort queries
    int sqrtN = sqrt(N);

    sort(ranges.begin(), ranges.end(), [&](const tiii &a, const tiii &b) {
        auto [al, ar, aidx] = a;
        auto [bl, br, bidx] = b;
        int ablock = ar / sqrtN;
        int bblock = br / sqrtN;
        if (ablock != bblock) return ablock < bblock;
        else return al < bl;
    });

    // calc first query
    int uniques = 0;
    auto [l, r, idx] = ranges.front();
    for (int i = l; i <= r; i++) {
        if (counts[arr[i]]++ == 0) uniques++;
    }
    answers[idx] = uniques;
    
    // calc remaining queries
    for (int m = 1; m < M; m++) {
        auto [curl, curr, curidx] = ranges[m];

        while (curl < l) if (counts[arr[--l]]++ == 0) uniques++;
        while (r < curr) if (counts[arr[++r]]++ == 0) uniques++;

        while (l < curl) if (--counts[arr[l++]] == 0) uniques--;
        while (curr < r) if (--counts[arr[r--]] == 0) uniques--;

        answers[curidx] = uniques;
    }

    // print answers all at once
    for (int m = 0; m < M; m++) {
        cout << answers[m] << '\n';
    }

    return 0;
}
