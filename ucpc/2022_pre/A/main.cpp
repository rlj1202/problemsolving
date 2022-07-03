#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int longs = (N + 4 - 1) / 4;

    for (int i = 0; i < longs; i++) cout << "long ";
    cout << "int" << '\n';

    return 0;
}
