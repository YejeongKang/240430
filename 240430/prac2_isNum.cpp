#include <iostream>
#include <string>

using namespace std;

string isNum_print_align();

int main() {
	string str1, str2;

	// 1)
	cout << "���ڷ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
	str1 = isNum_print_align();

	cout << "���ڷ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
	str2 = isNum_print_align();

	// 2)
	cout << str1 + str2 << endl;

	// 3)
	cout << to_string(stoi(str1) + stoi(str2)) << endl;
}

string isNum_print_align() {
	bool isd = 0;

	// ���ڿ� �Է¹ޱ�
	while(isd == 0){
		string str;
		cin >> str;

		/*for (int i = 0; i < str.length(); i++) {

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
			}*/

			for (char c : str) {
				if (!isdigit(c)) {
					isd = 0;
					cout << "�Է��Ͻ� ���ڿ��� " << str << endl << "NO" << endl << "���ڷθ� �̷���� ���ڿ��� �Է��Ͻÿ�. : ";
					break;
				}
				else {
					isd = 1;
					if (c == str.back()) {
						cout << "�Է��Ͻ� ���ڿ��� " << str << endl << "OK" << endl;
						return str;
					}
				}
			}
		}
	} 
