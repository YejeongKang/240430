#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INFO_COLUMN 3

//1. 사용자에게 몇 명의 학생을 입력할 것인지 묻기
//2. 학생 수 만큼 이름 나이 생일" 순서로 한번에 입력 받기
//3. 1) 학생 정보 출력, 2) 평균 나이, 3) 가장 빠른 생일, 4) 프로그램 종료, 네 가지 기능올 모두 구현
//4. 지금까지 배운 자료구조(배열, 벡터, 리스트), 문자열(스트링) 등 자유롭게 활용 하여 작성 ~작성 전에 어떤 기능을 어떻게 구현할지 먼저 정하고 작성 시작하기~
//5. * 시간이 남으면 * 예외 처리, 주석, 코드 정리 등을 실시하여 완성도를 높이기

void save_st_info(string **arr, int num);
float get_avg(string** arr, int num);
int get_early_birth(string** arr, int num);

int main() {
	int stnum;

	cout << "입력할 학생의 수 : ";
	cin >> stnum;
	cout << endl;
	cin.ignore();

	// 동적 배열 선언
	string** st_matrix = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_matrix[i] = new string[INFO_COLUMN];

	}

	// 배열 상단에 정보의 종류 할당
	st_matrix[0][0] = "이름";
	st_matrix[0][1] = "나이";
	st_matrix[0][2] = "생일";

	// 2) 학생 정보 입력받은 뒤 배열에 저장하는 함수 호출
	save_st_info(st_matrix, stnum);

	// 3 - 1) 학생 정보 출력
	for (int i = 0; i < stnum + 1; i++) {

		cout << endl;

		for (int j = 0; j < INFO_COLUMN; j++) {

			cout << st_matrix[i][j] << "\t";
		
		}
	}
	cout << endl << endl;
	
	// 3 - 2) 평균 나이 출력
	cout << "학생의 평균 나이는 : " << get_avg(st_matrix, stnum) << endl << endl;

	// 3 - 3) 가장 빠른 생일 출력
	cout << "가장 빠른 생일은 : " << get_early_birth(st_matrix, stnum) << endl << endl;

	// 3 - 4) 배열 해제 후 프로그램 종료
	for (int i = 0; i < stnum + 1; i++) {
		delete[] st_matrix[i];
	}
	delete[] st_matrix;
}

void save_st_info(string** arr, int num) {
	// 0 1 2 3 4 5 6 7 8 9 10 11 12
	// 강예정   2 5   0 0 1 1  3  0
	int name_split_point = 0;
	int age_split_point = 0;
	string input;
	string name;
	string age;
	string birth;

	// 학생 정보 한 줄에 입력 받기 (이름, 나이, 생일)
	cout << num << " 명의 학생의 이름, 나이, 생일을 순서대로 입력하시오. (ex: 리더님 20 050101)" << endl << endl;

	// 학생 정보 입력받기
	for (int i = 1; i < num + 1; i++) {

			getline(cin, input);

			// 이름 추출
			name_split_point = input.find(" ");

			name = input.substr(0, name_split_point);
			
			arr[i][0] = name;
			
			// 나이 추출
			age_split_point = input.find(" ", name_split_point + 1);

			age = input.substr((name_split_point + 1), (age_split_point - name_split_point - 1));

			arr[i][1] = age;
			
			// 생일 추출
			birth = input.substr(age_split_point + 1);

			arr[i][2] = birth;

		}
	}


float get_avg(string** arr, int num) {

	float sum = 0;

	for (int i = 1; i < num + 1; i++) {

		sum += stof(arr[i][1]);

	} return (sum / num);
}

int get_early_birth(string** arr, int num) {
	
	int min = 10000;

	for (int i = 1; i < num + 1; i++) {
		int birth_md = stoi(arr[i][2].substr(2, 5));
		if (birth_md <= min) {

			min = birth_md;
	
		}
	}
	return min;
}
