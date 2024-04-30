#include <iostream>
#include <string>

using namespace std;

string isNum();

int main() {
	string str1, str2;

	// 1)
	cout << "숫자로 이루어진 문자열을 입력하시오. : ";
	str1 = isNum();

	cout << "숫자로 이루어진 문자열을 입력하시오. : ";
	str2 = isNum();

	// 2)
	cout << str1 + str2 << endl;

	// 3)
	cout << to_string(stoi(str1) + stoi(str2)) << endl;
}

string isNum() {
	bool isd = 0;

	// 문자열 입력받기
	while(isd == 0){
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {

			if (isdigit(str[i]) == 0) {
				isd = 0; 
				cout << "입력하신 문자열은 " << str << endl << "NO" << endl << "숫자로만 이루어진 문자열을 입력하시오. : ";
				break;
			}
			else {
				isd = 1;
				if (i == str.length() - 1) {
					cout << "입력하신 문자열은 " << str << endl << "OK" << endl;
					return str;
				}
			}
		}
	} 
}