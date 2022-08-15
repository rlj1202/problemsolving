#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

//                  A   B   C   D   E   F   G   H
const int dr[] = { -1, -1,  0,  1,  1,  1,  0,  -1 };
const int dc[] = {  0,  1,  1,  1,  0, -1, -1, -1 };

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

        int idx = *str - 'A';
        if (!go[idx]) go[idx] = new trie();
        go[idx]->insert(str + 1, id);
    }
};

char grid[1003][1003];
int lengths[1003];
pair<pii, int> answers[1003];

void update_answer(int idx, pair<pii, int> o) {
    if (answers[idx].second == -1) {
        answers[idx] = o;
    } else {
        if (answers[idx].first.first > o.first.first) {
            answers[idx] = o;
        } else if (answers[idx].first.first == o.first.first) {
            if (answers[idx].first.second > o.first.second) {
                answers[idx] = o;
            } else if (answers[idx].first.second == o.first.second) {
                if (answers[idx].second > o.second) {
                    answers[idx] = o;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    trie *root = new trie();

    int L, C, W;
    cin >> L >> C >> W;
    for (int r = 0; r < L; r++) {
        cin >> grid[r];
    }
    for (int w = 0; w < W; w++) {
        string word;
        cin >> word;

        root->insert(word.c_str(), w);
        lengths[w] = word.length();
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

    // Find words

    memset(answers, -1, sizeof(answers));

    // ->
    for (int r = 0; r < L; r++) {
        trie *cur = root;

        for (int c = 0; c < C; c++) {
            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r, c - lengths[cur->output] + 1 }, 2 });
            }
        }
    }

    // <-
    for (int r = 0; r < L; r++) {
        trie *cur = root;

        for (int c = C - 1; c >= 0; c--) {
            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r, c + lengths[cur->output] - 1 }, 6 });
            }
        }
    }

    // |
    // \/
    for (int c = 0; c < C; c++) {
        trie *cur = root;

        for (int r = 0; r < L; r++) {
            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r - lengths[cur->output] + 1, c }, 4 });
            }
        }
    }

    // ^
    // |
    for (int c = 0; c < C; c++) {
        trie *cur = root;

        for (int r = L - 1; r >= 0; r--) {
            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r + lengths[cur->output] - 1, c }, 0 });
            }
        }
    }

    //  /
    // \/
    for (int d = 0; d < L + C - 1; d++) {
        trie *cur = root;

        for (int i = 0; i <= d; i++) {
            int r = i;
            int c = d - i;
            if (r < 0 || c < 0 || r >= L || c >= C) continue;

            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r - lengths[cur->output] + 1, c + lengths[cur->output] - 1 }, 5 });
            }
        }
    }

    //   ^
    //  /
    for (int d = 0; d < L + C - 1; d++) {
        trie *cur = root;

        for (int i = 0; i <= d; i++) {
            int r = d - i;
            int c = i;
            if (r < 0 || c < 0 || r >= L || c >= C) continue;

            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r + lengths[cur->output] - 1, c - lengths[cur->output] + 1 }, 1 });
            }
        }
    }

    // ^
    //  \n
    for (int d = 0; d < L + C - 1; d++) {
        trie *cur = root;

        for (int i = 0; i <= d; i++) {
            int r = d - i;
            int c = C - i - 1;
            if (r < 0 || c < 0 || r >= L || c >= C) continue;

            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r + lengths[cur->output] - 1, c + lengths[cur->output] - 1 }, 7 });
            }
        }
    }

    //  \n
    //   \/
    for (int d = 0; d < L + C - 1; d++) {
        trie *cur = root;

        for (int i = 0; i <= d; i++) {
            int r = i;
            int c = C - d - 1 + i;
            if (r < 0 || c < 0 || r >= L || c >= C) continue;

            int idx = grid[r][c] - 'A';

            while (cur != root && !cur->go[idx]) cur = cur->fail;
            if (cur->go[idx]) cur = cur->go[idx];

            if (cur->output != -1) {
                update_answer(cur->output, { { r - lengths[cur->output] + 1, c - lengths[cur->output] + 1 }, 3 });
            }
        }
    }

    // Print answers
    for (int w = 0; w < W; w++) {
        cout
            << answers[w].first.first << ' '
            << answers[w].first.second << ' '
            << (char) (answers[w].second + 'A')
            << '\n';
    }

    return 0;
}
