#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char buffer[3000006];

struct trie;
trie* root;

struct trie {
    trie* go[26];
    bool term;

    trie() {
        memset(go, 0, sizeof(go));
        term = false;
    }

    void insert(char* str) {
        if (*str == 0) {
            term = true;
            return;
        }

        int index = *str - 'a';
        if (go[index] == nullptr) go[index] = new trie();
        go[index]->insert(str + 1);
    }

    int search(char* str, int words) {
        int result = 0;

        if (*str == 0) {
            if (term && words == 1) {
                return 1;
            }

            return 0;
        }

        if (term) {
            result += root->search(str, words - 1);
        }
        
        int index = *str - 'a';
        if (go[index]) result += go[index]->search(str + 1, words);

        return result;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    root = new trie();
    for (int n = 0; n < N; n++) {
        scanf("%s", buffer);

        root->insert(buffer);
    }
    scanf("%s", buffer);

    printf("%d\n", root->search(buffer, 3));

    return 0;
}
