#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define FIND_STR 'ding'

int main() {

	string s = "Codingon";

	// 첫번째 문자 소문자로 변경 후 출력
	s[0] = tolower(s[0]);

	cout << s << endl;

	// 문자열 "ding" 반환	
	string ding = s.substr(2, 4);

	cout << ding << endl;

	// "coooooon"이 되도록 문자열 변경
	s.replace(2, 4, "oooo");
	
	cout << s << endl;

	// "con"이 되도록 문자열 변경
	s.erase(unique(s.begin(), s.end()),s.end());

	cout << s << endl;


}
