#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

map<int, int> mp;
string str;

struct Double {
	double value;

	bool operator== (Double a) {
		return abs(value - a.value) < 1e3;
	}
};

int main() {
	mp[4] = 2;
	mp[3] = 12;
	mp[1] = 999;

	printf("%d\n", mp[4]);
	printf("%d\n", mp[3]);

	printf("%d\n", Double{1.0} == Double{1.00001});
	printf("%d\n", 1.0 == 1.00001);

	str = "Hello, world!";
	printf("%s\n", str.data());

	for (pair<int, int> element : mp) {
		printf("%d %d\n", element.first, element.second);
	}

	tuple<int, float, string> t(99, 2.123, "hello");

	int a = 1;
	float b = 2.12;
	string c = "";
	tie(a, b, c) = t;

	printf("tuple %d\n", get<0>(t));

	return 0;
}
