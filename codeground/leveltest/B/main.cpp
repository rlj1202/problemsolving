#include <iostream>
#include <string>

using namespace std;

int C; // number of test cases

int datablocks[38 + 1];
int pointer; // byte pointer
int offset; // offset in byte

int require(int bitcounts) {
	int result = 0;

	while (bitcounts > 0) {
		int bits = 4 - offset;
		bits = bits < bitcounts ? bits : bitcounts;

		bitcounts -= bits;

		result <<= bits;
		result |= (datablocks[pointer] >> (4 - bits - offset)) & ((1 << bits) - 1);

		offset += bits;
		pointer += offset / 4;
		offset %= 4;
	}

	return result;
}

char decodeChar(int charcode) {
	if (0 <= charcode && charcode <= 9) return charcode + '0';
	else if (10 <= charcode && charcode <= 35) return charcode - 10 + 'A';
	else return " $%*+-./:"[charcode - 36];
	return ' ';
}

void pushHex(string &str, int n, int len) {
	for (int i = 0; i < len; i++) {
		int bits = (n >> ((len - i - 1) * 4)) & 0xf;
		if (bits < 10) str.push_back(bits + '0');
		else str.push_back(bits - 10 + 'A');
	}
}

int main() {
	scanf("%d", &C);

	setbuf(stdout, NULL); // for codeground

	for (int c = 1; c <= C; c++) {
		// init
		char rawData[38 + 1];
		scanf("%s", rawData);
		for (int i = 0; i < 38; i++) {
			int c = rawData[i];
			if ('0' <= c && c <= '9') datablocks[i] = c - '0';
			else datablocks[i] = c - 'A' + 10;
		}
		pointer = 0;
		offset = 0;

		string result = "";
		result.reserve(40);
		int counts = 0;

		// parsing
		while (pointer < 38) {
			int mode = require(4);

			if (mode == 1) { // numeric
				int count = require(10);
				counts += count;

				while (count > 0) {
					if (count == 2) {
						count -= 2;
						int digits = require(7);
						result.push_back(digits / 10 + '0');
						result.push_back(digits % 10 + '0');
					} else if (count == 1) {
						count--;
						int digits = require(4);
						result.push_back(digits % 10 + '0');
					} else {
						count -= 3;
						int digits = require(10);
						result.push_back(digits / 100 + '0');
						digits %= 100;
						result.push_back(digits / 10 + '0');
						result.push_back(digits % 10 + '0');
					}
				}
			} else if (mode == 2) { // alphanumeric
				int count = require(9);
				counts += count;

				while (count > 0) {
					if (count == 1) {
						count--;
						int encoding = require(6);
						result.push_back(decodeChar(encoding));
					} else {
						count -= 2;
						int encoding = require(11);
						int firstCharCode = encoding / 45;
						int secondCharCode = encoding % 45;
						result.push_back(decodeChar(firstCharCode));
						result.push_back(decodeChar(secondCharCode));
					}
				}
			} else if (mode == 4) { // byte
				int count = require(8);
				counts += count;

				while (count > 0) {
					count--;
					int encoding = require(8);
					if (0x29 <= encoding && encoding <= 0x7e) {
						result.push_back(encoding);
					} else {
						result.push_back('\\');
						pushHex(result, encoding, 2);
					}
				}
			} else if (mode == 8) { // kanji
				int count = require(8);
				counts += count;

				while (count > 0) {
					count--;
					int encoding = require(13);
					result.push_back('#');
					pushHex(result, encoding, 4);
				}
			} else if (mode == 0) { // terminate parsing
				break;
			}
		}

		// print result
		printf("Case #%d\n", c);
		printf("%d %s\n", counts, result.c_str());
	}

	return 0;
}
