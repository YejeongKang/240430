#include <iostream>
#include <string>

using namespace std;

string isNum();

int main() {
	string str1, str2;

	// 1)
	cout << "���ڷ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
	str1 = isNum();

	cout << "���ڷ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
	str2 = isNum();

	// 2)
	cout << str1 + str2 << endl;

	// 3)
	cout << to_string(stoi(str1) + stoi(str2)) << endl;
}

string isNum() {
	bool isd = 0;

	// ���ڿ� �Է¹ޱ�
	while(isd == 0){
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {

			if (isdigit(str[i]) == 0) {
				isd = 0; 
				cout << "�Է��Ͻ� ���ڿ��� " << str << endl << "NO" << endl << "���ڷθ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
				break;
			}
			else {
				isd = 1;
				if (i == str.length() - 1) {
					cout << "�Է��Ͻ� ���ڿ��� " << str << endl << "OK" << endl;
					return str;
				}
			}
		}
	} 
}