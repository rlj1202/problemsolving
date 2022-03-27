#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int A[4003];
int B[4003];
int C[4003];
int D[4003];

vector<int> AB;
vector<int> CD;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d %d %d %d", A + n, B + n, C + n, D + n);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = A[i] + B[j];
            AB.push_back(sum);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = C[i] + D[j];
            CD.push_back(sum);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long answer = 0;

    for (int ab : AB) {
        long long count =
            upper_bound(CD.begin(), CD.end(), -ab)
            - lower_bound(CD.begin(), CD.end(), -ab);

        answer += count;
    }

    printf("%lld\n", answer);

    return 0;
}
