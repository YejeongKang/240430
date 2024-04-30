#include <iostream>
#include <string>

using namespace std;

#define INFO_COLUMN 3

//1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
//2. 학생 수 만큼 이름 나이 생일" 순서로 한번에 입력 받기
//3. 1) 학생 정보 출력, 2) 평균 나이, 3) 가장 빠른 생일, 4) 프로그램 종료, 네 가지 기능올 모두 구현
//4. 지금까지 배운 자료구조(배열, 벡터, 리스트), 문자열(스트링) 등 자유롭게 활용 하여 작성 ~작성 전에 어떤 기능을 어떻게 구현할지 먼저 정하고 작성 시작하기~
//5. * 시간이 남으면 * 예외 처리, 주석, 코드 정리 등을 실시하여 완성도를 높이기

int save_st_info(string **arr);

int main() {
	int stnum;

	cout << "입력할 학생의 수 : " << endl;
	cin >> stnum;

	// 동적 배열 선언
	string** st_info = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_info[i] = new string[INFO_COLUMN];

	}

	// 배열 상단에 정보의 종류 할당
	st_info[0][0] = "이름";
	st_info[0][1] = "나이";
	st_info[0][2] = "생일";

	// 학생 정보 입력받은 뒤 배열에 저장하는 함수 호출
	save_st_info(st_info);


}

int save_st_info(string **arr) {
	
	string st;

	// 학생 정보 한 줄에 입력 받기 (이름, 나이, 생일)
	
	cout << "학생의 이름, 나이, 생일을 순서대로 입력하시오. (공백을 두고 입력)" << endl << "=> ";
	getline(cin, st);
//	st.substr().find(" ") // 공백 나오기 전까지 단어를 추출

}