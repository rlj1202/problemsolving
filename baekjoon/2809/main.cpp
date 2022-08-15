#include <bits/stdc++.h>

using namespace std;

struct trie {
    vector<pair<char, trie*>> go;
    trie *fail;
    int output = -1;

    trie *find(char c) {
        trie *next = nullptr;
        for (auto [ cur_c, node ] : go) {
            if (cur_c == c) {
                next = node;
                break;
            }
        }
        return next;
    }

    void insert(const char *str, int id) {
        if (*str == 0) {
            output = id;
            return;
        }

        trie *next = find(*str);
        if (!next) {
            next = new trie();
            go.push_back({ *str, next });
        }
        next->insert(str + 1, id);
    }
};

int tile_len[5003];
int arr[300005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    string str;
    cin >> N >> str;

    trie *root = new trie();

    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        string tile;
        cin >> tile;

        root->insert(tile.c_str(), m);
        tile_len[m] = tile.length();
    }

    queue<trie*> q;
    root->fail = root;
    q.push(root);

    while (!q.empty()) {
        trie *cur = q.front(); q.pop();

        for (char c = 'a'; c <= 'z'; c++) {
            trie *next = cur->find(c);
            if (!next) continue;

            if (cur == root) {
                next->fail = root;
            } else {
                trie *dest = cur->fail;
                while (dest != root && !dest->find(c)) dest = dest->fail;
                if (dest->find(c)) dest = dest->find(c);

                next->fail = dest;
            }

            if (next->fail->output != -1) {
                if (tile_len[next->output] < tile_len[next->fail->output]) {
                    next->output = next->fail->output;
                }
            }

            q.push(next);
        }
    }

    trie *cur = root;
    for (int i = 0; str[i]; i++) {
        char c = str[i];

        while (cur != root && !cur->find(c)) cur = cur->fail;
        if (cur->find(c)) cur = cur->find(c);

        if (cur->output != -1) {
            int len = tile_len[cur->output];

            arr[i - len + 1]++;
            arr[i + 1]--;
        }
    }

    int answer = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (!sum) answer++;
    }

    cout << answer << '\n';

    return 0;
}
