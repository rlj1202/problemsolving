#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool alphabets[26];
int indices[26];
string words[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    for (int n = 0; n < N; n++) cin >> words[n];

    for (int n = 0; n < N; n++) {
        string &cur = words[n];
        for (int i = 0; i < cur.size(); i++) {
            alphabets[cur[i] - 'A'] = true;
        }
    }

    int cur_index = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i]) {
            indices[i] = cur_index++;
        }
    }

    vector<int> perm(10);
    for (int i = 0; i < perm.size(); i++) perm[i] = i;

    ll result = 0;

    do {
        ll sum = 0;

        for (int n = 0; n < N; n++) {
            string &cur = words[n];
            ll place = 1;
            for (int i = 0; i < cur.size(); i++) {
                int alpha = cur[cur.size() - 1 - i] - 'A';
                int digit = perm[indices[alpha]];
                sum += digit * place;

                place *= 10;
            }
        }

        result = max(result, sum);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << result << '\n';

    return 0;
}
