#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

struct trie {
    trie *go[26];
    trie *fail;

    int output = -1;

    trie() {
        fill(go, go + 26, nullptr);
    }

    ~trie() {
        for (int i = 0; i < 26; i++) {
            if (go[i]) delete go[i];
        }
    }

    void insert(const char *str, int id) {
        if (*str == '\0') {
            output = id;
            return;
        }

        int index = *str - 'a';
        if (!go[index]) go[index] = new trie();
        go[index]->insert(str + 1, id);
    }
};

int hashing(const char *str, int l, int r) {
    long long hash = 0;

    for (int i = l; i < r; i++) {
        hash *= 29;
        hash += str[i];
        hash %= MOD;
    }

    return hash;
}

long long power(long long n, int k) {
    long long result = 1;

    long long cur = n;
    while (k) {
        if (k & 1) {
            result *= cur;
            result %= MOD;
        }

        k >>= 1;
        cur *= cur;
        cur %= MOD;
    }

    return result;
}

long long inv(int n) {
    return power(n, MOD - 2);
}

string words[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    trie *root = new trie();

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> words[n];

        root->insert(words[n].c_str(), n);
    }

    queue<trie*> q;
    root->fail = root;
    q.push(root);

    while (!q.empty()) {
        trie *cur = q.front(); q.pop();

        for (int i = 0; i < 26; i++) {
            trie *next = cur->go[i];
            if (!next) continue;

            if (cur == root) next->fail = root;
            else {
                trie *dest = cur->fail;
                while (dest != root && !dest->go[i]) dest = dest->fail;
                if (dest->go[i]) dest = dest->go[i];
                next->fail = dest;
            }

            if (next->fail->output != -1 && next->output == -1) next->output = next->fail->output;

            q.push(next);
        }
    }

    string S;
    cin >> S;

    // find prefixes and suffixes
    vector<int> prefixes;
    vector<int> suffixes;

    trie *cur = root;
    for (int i = 0; i < S.length(); i++) {
        int index = S[i] - 'a';

        while (cur != root && !cur->go[index]) cur = cur->fail;
        if (cur->go[index]) cur = cur->go[index];

        if (cur->output != -1) {
            if (i + 1 == words[cur->output].length()) {
                prefixes.push_back(i + 1);
            }

            if (i + 1 == S.length()) {
                trie *temp = cur;

                while (temp != root) {
                    if (temp->output != -1)
                        suffixes.push_back(S.length() - words[temp->output].length());
                    temp = temp->fail;
                }
            }
        }
    }

    //
    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(hashing(words[i].c_str(), 0, words[i].size()));
    }

    vector<int> hash_accum(S.size());
    vector<int> pows(S.size());
    pows[0] = 1;
    for (int i = 0; i < S.size(); i++) {
        if (i) hash_accum[i] = (long long) hash_accum[i - 1] * 29;
        hash_accum[i] += S[i];
        hash_accum[i] %= MOD;

        if (i) pows[i] = (pows[i - 1] * 29LL) % MOD;
    }

    int result = 0;

    for (int i = 0; i < prefixes.size(); i++) {
        int l = prefixes[i];

        for (int j = 0; j < suffixes.size(); j++) {
            int r = suffixes[j];

            if (l >= r) continue;

            // int hash = hashing(S.c_str(), l, r);

            long long hash = hash_accum[r - 1];
            if (l) hash -= hash_accum[l - 1];
            hash += MOD;
            hash %= MOD;

            hash *= inv(pows[l]);
            hash %= MOD;

            result += s.count(hash);
        }
    }

    //
    cout << result << '\n';

    return 0;
}
