#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char A[102];
char W[50004];
char S[500005];

int order[102];

int pi[50004];

int offsets[102];

int getindex(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a' + ('9' - '0' + 1);
    if ('A' <= c && c <= 'Z') return c - 'A' + ('9' - '0' + 1) + ('z' - 'a' + 1);
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%s %s %s", A, W, S);

        memset(offsets, 0, sizeof(offsets));

        int Alen = strlen(A);
        int Wlen = strlen(W);
        int Slen = strlen(S);

        for (int i = 0; i < Alen; i++) order[getindex(A[i])] = i;
        for (int i = 0; i < Wlen; i++) W[i] = order[getindex(W[i])];
        for (int i = 0; i < Slen; i++) S[i] = order[getindex(S[i])];

        {
            int j = 0;
            for (int i = 1; i < Wlen; i++) {
                while (j && W[i] != W[j]) j = pi[j - 1];
                if (W[i] == W[j]) pi[i] = ++j;
            }
        }

        for (int offset = 0; offset < Alen; offset++) {
            int j = 0;
            for (int i = 0; i < Slen; i++) {
                int cur = ((int) S[i] + offset) % Alen;
                
                while (j && cur != W[j]) j = pi[j - 1];

                if (cur == W[j]) {
                    if (j + 1 == Wlen) {
                        offsets[(Alen - offset) % Alen]++;

                        j = pi[j];
                    } else {
                        j++;
                    }
                }
            }
        }

        vector<int> results;
        for (int i = 0; i < Alen; i++) {
            if (offsets[i] == 1) results.push_back(i);
        }

        if (results.size() == 0) {
            printf("no solution");
        } else if (results.size() == 1) {
            printf("unique:");
        } else if (results.size() > 1) {
            printf("ambiguous:");
        }
        for (int value : results) printf(" %d", value);
        printf("\n");
    }

    return 0;
}
