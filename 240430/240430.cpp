// 240430.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    getline('ed ', str, ' '); // ab cde => ab cde 출력
    cout << str << endl;

    getline(cin, str, 'a'); // edc ba => edc b 출력 
    // a가 나올 때까지 입력 받고, 엔터 상관없이 a 이전까지 입력한 모든 값을 출력함.
    cout << str << endl;

    //str.at(index);
}

			// 이름에 문자가 제대로 들어갔는지 확인하고, 배열에 값 넣기
						/*for (int n = 0; n < name.length(); n++) {
							if (isdigit(char(name[n])) == 0) {
								cout << "이름은 숫자를 입력할 수 없습니다." << endl;
								break;
							}
							else {

								if (name[n] == name.back()) {
									arr[i][0] = name;
									input_check += 1;
								}
							}
						}*/

			// 나이가 숫자인지 확인하고, 배열에 값 넣기
			/*for (int n = 0; n < age.length(); n++) {
				if (isdigit(age[n]) != 0) {
					cout << "나이는 숫자만 입력할 수 있습니다." << endl;
					break;
				}
				else {
					if (n == age.length() - 1) {
						arr[i][1] = age;
						input_check += 1;
					}
				}
			}*/

			// 생일이 숫자인지 확인하고, 배열에 값 넣기
						/*if (birth.length() != 4) {
							cout << "생일은 네 자리만 입력할 수 있습니다." << endl;
							break;
						}
						else {
							for (int n = 0; n < birth.length(); n++) {
								if (isdigit(birth[n]) != 0) {
									cout << "생일은 숫자만 입력할 수 있습니다." << endl;
									break;
								}
								else {
									if (n == birth.length() - 1) {
										arr[i][2] = birth;
										input_check += 1;
									}
								}
							}
						}*/