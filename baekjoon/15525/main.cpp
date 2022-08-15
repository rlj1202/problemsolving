#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

struct trie {
    trie *go[26];
    trie *fail;
    vector<int> outputs;

    trie() : fail(nullptr) {
        fill(go, go + 26, nullptr);
    }
    ~trie() {
        for (int i = 0; i < 26; i++) if (go[i]) delete go[i];
    }

    void insert(const char *str, int id) {
        if (*str == '\0') {
            outputs.push_back(id);
            return;
        }

        int idx = *str - 'a';
        if (!go[idx]) go[idx] = new trie();
        go[idx]->insert(str + 1, id);
    }
};

ll dp[100005];
int lengths[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    trie *root = new trie();

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;

        root->insert(str.c_str(), n);
        lengths[n] = str.length();
    }
    string T;
    cin >> T;

    // build trie
    queue<trie*> q;
    q.push(root);
    root->fail = root;

    while (!q.empty()) {
        trie *cur = q.front(); q.pop();

        for (int i = 0; i < 26; i++) {
            trie *next = cur->go[i];
            if (!next) continue;

            if (cur == root) {
                next->fail = root;
            } else {
                trie *dest = cur->fail;
                while (dest != root && !dest->go[i]) dest = dest->fail;
                if (dest->go[i]) dest = dest->go[i];

                next->fail = dest;
            }

            if (next->fail->outputs.size()) {
                next->outputs.insert(
                    next->outputs.end(),
                    next->fail->outputs.begin(),
                    next->fail->outputs.end()
                );
            }

            q.push(next);
        }
    }

    for (int i = 0; i < 26; i++) {
        if (root->go[i]) q.push(root->go[i]);
        else root->go[i] = root;
    }

    while (!q.empty()) {
        trie *cur = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            if (cur->go[i]) q.push(cur->go[i]);
            else cur->go[i] = cur->fail->go[i];
        }
    }

    //
    dp[0] = 1;

    trie *cur = root;
    for (int i = 0; T[i]; i++) {
        char c = T[i];
        int idx = c - 'a';

        while (cur != root && !cur->go[idx]) cur = cur->fail;
        if (cur->go[idx]) cur = cur->go[idx];

        for (int id : cur->outputs) {
            dp[i + 1] += dp[i + 1 - lengths[id]];
            dp[i + 1] %= MOD;
        }
    }

    //
    cout << dp[T.length()] << '\n';

    return 0;
}
