#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct trie {
    trie *go[26];
    trie *fail;
    int output;

    trie() : fail(nullptr), output(-1) {
        fill(go, go + 26, nullptr);
    }
    ~trie() {
        for (int i = 0; i < 26; i++) if (go[i]) delete go[i];
    }

    void insert(const char *str, int id) {
        if (*str == '\0') {
            output = id;
            return;
        }

        int idx = *str - 'a';
        if (!go[idx]) go[idx] = new trie();
        go[idx]->insert(str + 1, id);
    }
};

int lengths[300005];

int lazy[300005 * 4];
int tree[300005 * 4];

void update_lazy(int node, int l, int r) {
    if (lazy[node] != 0x3f3f3f3f) {
        tree[node] = min(tree[node], lazy[node]);
        if (l != r) {
            lazy[node * 2] = min(lazy[node * 2], lazy[node]);
            lazy[node * 2 + 1] = min(lazy[node * 2 + 1], lazy[node]);
        }
        lazy[node] = 0x3f3f3f3f;
    }
}

void update(int node, int l, int r, int i, int j, int value) {
    update_lazy(node, l, r);

    if (j < l || r < i) return;

    if (i <= l && r <= j) {
        lazy[node] = value;
        update_lazy(node, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, j, value);
    update(node * 2 + 1, mid + 1, r, i, j, value);
}

int query(int node, int l, int r, int i) {
    update_lazy(node, l, r);

    if (i < l || r < i) return 0;
    if (l == r) return tree[node];

    int mid = (l + r) / 2;

    return query(node * 2, l, mid, i) + query(node * 2 + 1, mid + 1, r, i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int L;
    string str;
    cin >> L;
    cin >> str;

    memset(tree, 0x3f, sizeof(tree));
    memset(lazy, 0x3f, sizeof(lazy));

    trie *root = new trie();

    for (int l = 0; l < L; l++) {
        string word;
        cin >> word;

        root->insert(word.c_str(), l);
        lengths[l] = word.length();
    }

    //
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

            if (next->fail->output != -1) {
                if (next->output == -1) next->output = next->fail->output;
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
    update(1, 0, str.length(), 0, 0, 0);

    trie *cur = root;

    for (int i = 0; str[i]; i++) {
        char c = str[i];
        int idx = c - 'a';

        while (cur != root && !cur->go[idx]) cur = cur->fail;
        if (cur->go[idx]) cur = cur->go[idx];

        if (cur->output != -1) {
            int prev = query(1, 0, str.length(), i + 1 - lengths[cur->output]);

            update(1, 0, str.length(),
                i + 1 - lengths[cur->output] + 1,
                i + 1,
                prev + 1);
        }
    }

    //
    int result = query(1, 0, str.length(), str.length());
    if (result != 0x3f3f3f3f) cout << result << '\n';
    else cout << -1 << '\n';

    return 0;
}
