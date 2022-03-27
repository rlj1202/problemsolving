#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

unordered_map<string, string> mapping;

int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (int n = 1; n <= N; n++) {
        string str;
        cin >> str;

        stringstream stream;
        stream << n;

        string index = stream.str();

        mapping[index] = str;
        mapping[str] = index;
    }
    for (int m = 0; m < M; m++) {
        string cmd;
        cin >> cmd;

        cout << mapping[cmd] << "\n";
    }

    return 0;
}
