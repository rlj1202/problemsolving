#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const string characters = "\
abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
0123456789\
!?.,:;-_'#$%&/=*+(){}[] \
";

int get_idx(const char c) {
    for (int i = 0; characters[i]; i++) {
        if (characters[i] == c) return i;
    }
    return -1;
}

struct trie {
    trie *go[102];
    trie *fail;
    bool output;

    trie() : fail(nullptr), output(false) {
        memset(go, 0, sizeof(go));
    }
    ~trie() {
        for (int i = 0; i < 26; i++) if (go[i]) delete go[i];
    }

    void insert(const char *str) {
        if (*str == '\0') {
            output = true;
            return;
        }

        int idx = get_idx(*str);
        if (!go[idx]) go[idx] = new trie();
        go[idx]->insert(str + 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        trie *root = new trie();

        for (int n = 0; n < N; n++) {
            string emoji;
            cin >> emoji;

            root->insert(emoji.c_str());
        }

        queue<trie*> q;
        q.push(root);
        root->fail = root;

        while (!q.empty()) {
            trie *cur = q.front(); q.pop();

            for (int i = 0; characters[i]; i++) {
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

                if (next->fail->output) {
                    next->output = true;
                }

                q.push(next);
            }
        }

        int answer = 0;

        cin.ignore();

        for (int m = 0; m < M; m++) {
            string str;
            getline(cin, str);

            trie *cur = root;

            for (int i = 0; str[i]; i++) {
                char c = str[i];
                int idx = get_idx(c);

                while (cur != root && !cur->go[idx]) cur = cur->fail;
                if (cur->go[idx]) cur = cur->go[idx];

                if (cur->output) {
                    cur = root;
                    answer++;
                }
            }
        }

        cout << answer << '\n';

        delete root;
    }

    return 0;
}
