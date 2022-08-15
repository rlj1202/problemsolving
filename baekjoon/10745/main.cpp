#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct trie {
    trie *go[26];
    trie *fail;
    int output;

    trie() : output(-1) {
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

int wordlen[100005];

trie *states[100005];
char answer[100005];
int answer_len;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string S;
    cin >> S;

    trie *root = new trie();

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        string word;
        cin >> word;

        root->insert(word.c_str(), n);
        wordlen[n] = word.length();
    }

    queue<trie*> q;
    root->fail = root;
    q.push(root);

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
                next->output = next->fail->output;
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

    states[0] = root;

    for (int i = 0; S[i]; i++) {
        trie *cur = states[answer_len];

        char c = S[i];
        int idx = c - 'a';

        while (cur != root && !cur->go[idx]) cur = cur->fail;
        if (cur->go[idx]) cur = cur->go[idx];

        answer[answer_len++] = c;
        states[answer_len] = cur;

        if (cur->output != -1) {
            answer_len -= wordlen[cur->output];
        }
    }

    for (int i = 0; i < answer_len; i++) cout << answer[i];
    cout << '\n';

    return 0;
}
