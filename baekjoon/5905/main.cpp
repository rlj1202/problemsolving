#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct trie {
    trie *go[3];
    trie *fail;
    bool output = false;

    int dp[32];

    trie() {
        for (int i = 0; i < 3; i++) {
            go[i] = nullptr;
        }
        for (int i = 0; i < 32; i++) {
            dp[i] = 0;
        }
    }
    ~trie() {
        for (int i = 0; i < 3; i++) {
            if (go[i]) {
                delete go[i];
                go[i] = nullptr;
            }
        }
    }

    void insert(const char *str) {
        if (*str == '\0') {
            output = true;
            return;
        }

        int idx = *str - 'A';
        if (!go[idx]) go[idx] = new trie();
        go[idx]->insert(str + 1);
    }
};

int dp[1003][402];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    trie *root = new trie();

    int N, K;
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        string str;
        cin >> str;

        root->insert(str.c_str());
    }

    queue<trie*> q;
    q.push(root);
    root->fail = root;

    while (!q.empty()) {
        trie *cur = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            trie *next = cur->go[i];
            if (!next) continue;

            trie *dest = cur->fail;
            while (dest != root && !dest->go[i]) {
                dest = dest->fail;
            }

            if (dest->go[i]) {
                dest = dest->go[i];
            }

            next->fail = dest;
            if (next->fail->output) dest->output = true;

            q.push(next);
        }
    }

    dp[0][0] = 0;

    cout << 0 << '\n';

    return 0;
}
