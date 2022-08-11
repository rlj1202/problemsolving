#include <bits/stdc++.h>

using namespace std;

struct trie {
    trie *go[2];
    trie *fail;

    int output = -1;

    trie() {
        fill(go, go + 2, nullptr);
    }
    ~trie() {
        for (int i = 0; i < 2; i++) if (go[i]) delete go[i];
    }

    void insert(const char *str, int id) {
        if (*str == 0) {
            if (output == -1) output = id;
            return;
        }

        int index = *str == 'o';
        if (!go[index]) go[index] = new trie();
        go[index]->insert(str + 1, id);
    }
};

string P[2003];
string M[2003];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int PH, PW, MH, MW;
    cin >> PH >> PW >> MH >> MW;

    trie *root = new trie();
    
    for (int r = 0; r < PH; r++) {
        cin >> P[r];
        root->insert(P[r].c_str(), r);
    }
    for (int r = 0; r < MH; r++) {
        cin >> M[r];
    }

    queue<trie*> q;
    root->fail = root;
    q.push(root);

    while (!q.empty()) {
        trie *cur = q.front(); q.pop();

        for (int i = 0; i < 2; i++) {
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

            if (next->fail->output != -1) next->output = next->fail->output;

            q.push(next);
        }
    }

    for (int r = 0; r < MH; r++) {
        trie *cur = root;

        for (int c = 0; c < MW; c++) {
            int i = M[r][c] == 'o';

            while (cur != root && !cur->go[i]) cur = cur->fail;
            if (cur->go[i]) cur = cur->go[i];

            if (cur->output != -1) {
                cout << '\t' << "at " << r << ", " << c << ": " << cur->output << '\n';
            }
        }
    }

    cout << 0 << '\n';

    return 0;
}
