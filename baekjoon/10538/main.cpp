#include <bits/stdc++.h>

using namespace std;

struct trie {
    trie *go[2];
    trie *fail;

    int output = -1;

    trie() {
        fill(go, go + 2, nullptr);
        fail = nullptr;
    }
    ~trie() {
        for (int i = 0; i < 2; i++) if (go[i]) delete go[i];
    }

    int insert(const char *str, int id) {
        if (*str == 0) {
            if (output == -1) output = id;
            return output;
        }

        int index = *str == 'o';
        if (!go[index]) go[index] = new trie();
        return go[index]->insert(str + 1, id);
    }
};

int p_indices[2003];
string M[2003];

int indices[2003][2003];
int fail[2003];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int PH, PW, MH, MW;
    cin >> PH >> PW >> MH >> MW;

    trie *root = new trie();
    
    for (int r = 0; r < PH; r++) {
        string row;
        cin >> row;
        p_indices[r] = root->insert(row.c_str(), r);
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

    memset(indices, -1, sizeof(indices));

    for (int r = 0; r < MH; r++) {
        trie *cur = root;

        for (int c = 0; c < MW; c++) {
            int i = M[r][c] == 'o';

            while (cur != root && !cur->go[i]) cur = cur->fail;
            if (cur->go[i]) cur = cur->go[i];

            if (cur->output != -1) {
                indices[r][c] = cur->output;
            }
        }
    }

    {
        int j = 0;
        for (int i = 1; i < PH; i++) {
            while (j && p_indices[i] != p_indices[j]) j = fail[j - 1];
            if (p_indices[i] == p_indices[j]) fail[i] = ++j;
        }
    }

    int answer = 0;

    for (int c = 0; c < MW; c++) {
        int j = 0;

        for (int r = 0; r < MH; r++) {
            while (j && p_indices[j] != indices[r][c]) j = fail[j - 1];
            if (p_indices[j] == indices[r][c]) j++;

            if (j == PH) {
                answer++;

                j = fail[j - 1];
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
