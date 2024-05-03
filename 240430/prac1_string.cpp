#include <iostream>
#include <string>

using namespace std;

int main() {
	// 1)
	string s = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

	// 2)
	cout << s.length() << endl;

	// 3) 
	cout << s[99] << endl;

	// 4)
	cout << s.find("two") << endl;

	// 5)
	cout << s.find("two", s.find("two") + 1) << endl;


}