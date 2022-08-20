#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct trie {
    vector<pair<char, trie*>> go;
    trie *fail;
    vector<trie*> inv_fails;
    int indegrees;
    int max_value;
    bool output;

    trie() : fail(nullptr), output(false), indegrees(0), max_value(0) {
    }
    ~trie() {
        for (auto [c, node] : go) delete node;
    }

    trie *find(char c) {
        for (auto [cur_c, node] : go) {
            if (cur_c == c) return node;
        }
        return nullptr;
    }

    void insert(const char *str) {
        if (*str == '\0') {
            output = true;
            return;
        }

        trie *next = this->find(*str);
        if (!next) {
            next = new trie();
            go.push_back({ *str, next });
            next->indegrees++;
        }
        next->insert(str + 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (!N) break;

        trie *root = new trie();

        for (int n = 0; n < N; n++) {
            string word;
            cin >> word;

            root->insert(word.c_str());
        }

        queue<trie*> q;
        q.push(root);
        root->fail = root;

        while (!q.empty()) {
            trie *cur = q.front(); q.pop();

            for (auto [c, next] : cur->go) {
                if (cur == root) {
                    next->fail = root;
                } else {
                    trie *dest = cur->fail;
                    while (dest != root && !dest->find(c)) dest = dest->fail;
                    if (dest->find(c)) dest = dest->find(c);

                    next->fail = dest;
                    dest->inv_fails.push_back(next);
                    next->indegrees++;
                }

                q.push(next);
            }
        }

        // 
        int answer = 0;
        q.push(root);

        while (!q.empty()) {
            trie *cur = q.front(); q.pop();

            answer = max(answer, cur->max_value);

            for (auto [c, next] : cur->go) {
                next->max_value = max(next->max_value, cur->max_value + next->output);
                if (--next->indegrees == 0) {
                    q.push(next);
                }
            }
            for (trie *next : cur->inv_fails) {
                next->max_value = max(next->max_value, cur->max_value + next->output);
                if (--next->indegrees == 0) {
                    q.push(next);
                }
            }
        }

        //
        cout << answer << '\n';
        delete root;
    }

    return 0;
}
