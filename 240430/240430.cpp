// 240430.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    getline(cin, str); // ab cde => ab cde 출력
    cout << str << endl;

    getline(cin, str, 'a'); // edc ba => edc b 출력 
    // a가 나올 때까지 입력 받고, 엔터 상관없이 a 이전까지 입력한 모든 값을 출력함.
    cout << str << endl;

    //str.at(index);
}
