#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int min_diffs = 0x3f3f3f3f;

	for (int j = 0; j <= B.size() - A.size(); j++) {
		int diffs = 0;

		for (int i = 0; i < A.size(); i++) {
			if (B[i + j] != A[i]) diffs++;
		}

		if (min_diffs > diffs) {
			min_diffs = diffs;
		}
	}

    cout << min_diffs << '\n';

    return 0;
}
