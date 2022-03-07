#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct trie {
    trie* next[26];
    int value;

    trie() : value(0) {
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }

    trie* get_next(char c) {
        if (next[c - 'a'] == nullptr) {
            next[c - 'a'] = new trie();
        }
        return next[c - 'a'];
    }
};

char str[100005];
int cnt[26];
trie root;

int main() {
    scanf("%s", str);

    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        cnt[str[i] - 'a']++;
    }

    int result = 1;

    for (int start = 0; start < len; start++) {
        root.get_next(str[start])->value++;

        if (cnt[str[start] - 'a'] <= 1) continue;

        for (int d = 1; d < len; d++) {
            trie* node = &root;

            for (int i = start; i < len; i += d) {
                if (cnt[str[i] - 'a'] <= 1) break;

                node = node->get_next(str[i]);
                if (i != start) node->value++;

                result = max(result, node->value);
            }
        }
    }

    printf("%d\n", result);

    return 0;
}
