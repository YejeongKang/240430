#include <iostream>
#include <string>

using namespace std;

void isNum(string str);

int main() {
	string str1, str2;


	// 1)
	cout << "숫자로 이루어진 문자열을 2 개 입력하시오. : ";
	cin >> str1 >> str2;

	isNum(str1);
	isNum(str2);

	// 2)
	cout << str1 + str2 << endl;

	// 3)
	cout << to_string(stoi(str1) + stoi(str2)) << endl;
}

void isNum(string str) {

	for (int i = 0; i < str.length(); i++) {

		if (isdigit(str[i]) == 0) {
			cout << "NO" << endl;
			break;
		}
		else {
			if (i == str.length() - 1) cout << "OK" << endl;
			else continue;
		}
	}
}