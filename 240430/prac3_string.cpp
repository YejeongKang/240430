#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define FIND_STR 'ding'

int main() {

	string s = "Codingon";

	// ù��° ���� �ҹ��ڷ� ���� �� ���
	s[0] = tolower(s[0]);

	cout << s << endl;

	// ���ڿ� "ding" ��ȯ	
	string ding = s.substr(2, 4);

	cout << ding << endl;

	// "coooooon"�� �ǵ��� ���ڿ� ����
	s.replace(2, 4, "oooo");
	
	cout << s << endl;

	// "con"�� �ǵ��� ���ڿ� ����
	s.erase(unique(s.begin(), s.end()),s.end());

	cout << s << endl;


}
