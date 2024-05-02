#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INFO_COLUMN 3

//1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
//2. �л� �� ��ŭ �̸� ���� ����" ������ �ѹ��� �Է� �ޱ�
//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����, �� ���� ��ɿ� ��� ����
//4. ���ݱ��� ��� �ڷᱸ��(�迭, ����, ����Ʈ), ���ڿ�(��Ʈ��) �� �����Ӱ� Ȱ�� �Ͽ� �ۼ� ~�ۼ� ���� � ����� ��� �������� ���� ���ϰ� �ۼ� �����ϱ�~
//5. * �ð��� ������ * ���� ó��, �ּ�, �ڵ� ���� ���� �ǽ��Ͽ� �ϼ����� ���̱�

void save_st_info(string **arr, int num);
float get_avg(string** arr, int num);
int get_early_birth(string** arr, int num);

int main() {
	int stnum;

	cout << "�Է��� �л��� �� : ";
	cin >> stnum;
	cout << endl;
	cin.ignore();

	// ���� �迭 ����
	string** st_matrix = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_matrix[i] = new string[INFO_COLUMN];

	}

	// �迭 ��ܿ� ������ ���� �Ҵ�
	st_matrix[0][0] = "�̸�";
	st_matrix[0][1] = "����";
	st_matrix[0][2] = "����";

	// 2) �л� ���� �Է¹��� �� �迭�� �����ϴ� �Լ� ȣ��
	save_st_info(st_matrix, stnum);

	// 3 - 1) �л� ���� ���
	for (int i = 0; i < stnum + 1; i++) {

		cout << endl;

		for (int j = 0; j < INFO_COLUMN; j++) {

			cout << st_matrix[i][j] << "\t";
		
		}
	}
	cout << endl << endl;
	
	// 3 - 2) ��� ���� ���
	cout << "�л��� ��� ���̴� : " << get_avg(st_matrix, stnum) << endl << endl;

	// 3 - 3) ���� ���� ���� ���
	cout << "���� ���� ������ : " << get_early_birth(st_matrix, stnum) << endl << endl;

	// 3 - 4) �迭 ���� �� ���α׷� ����
	for (int i = 0; i < stnum + 1; i++) {
		delete[] st_matrix[i];
	}
	delete[] st_matrix;
}

void save_st_info(string** arr, int num) {
	// 0 1 2 3 4 5 6 7 8 9 10 11 12
	// ������   2 5   0 0 1 1  3  0
	int name_split_point = 0;
	int age_split_point = 0;
	string input;
	string name;
	string age;
	string birth;

	// �л� ���� �� �ٿ� �Է� �ޱ� (�̸�, ����, ����)
	cout << num << " ���� �л��� �̸�, ����, ������ ������� �Է��Ͻÿ�. (ex: ������ 20 050101)" << endl << endl;

	// �л� ���� �Է¹ޱ�
	for (int i = 1; i < num + 1; i++) {

			getline(cin, input);

			// �̸� ����
			name_split_point = input.find(" ");

			name = input.substr(0, name_split_point);
			
			arr[i][0] = name;
			
			// ���� ����
			age_split_point = input.find(" ", name_split_point + 1);

			age = input.substr((name_split_point + 1), (age_split_point - name_split_point - 1));

			arr[i][1] = age;
			
			// ���� ����
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
