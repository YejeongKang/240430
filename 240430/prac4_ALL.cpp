#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INFO_COLUMN 3
#define NAME_IDX 0
#define AGE_IDX 1
#define BIRTH_IDX 2

//1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
//2. �л� �� ��ŭ �̸� ���� ����" ������ �ѹ��� �Է� �ޱ�
//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����, �� ���� ��ɿ� ��� ����
//4. ���ݱ��� ��� �ڷᱸ��(�迭, ����, ����Ʈ), ���ڿ�(��Ʈ��) �� �����Ӱ� Ȱ�� �Ͽ� �ۼ� ~�ۼ� ���� � ����� ��� �������� ���� ���ϰ� �ۼ� �����ϱ�~
//5. * �ð��� ������ * ���� ó��, �ּ�, �ڵ� ���� ���� �ǽ��Ͽ� �ϼ����� ���̱�

// <�߰� ����>
// save_st_info() �κп��� ����� �Է��� �ùٸ��� üũ�ϴ� ����� �־��ּ���!
// �̸�, ����, ������Ͽ� ���� ���̵���ο� �°� �����Ͱ� ���Դ��� üũ�� ���ֽø� �˴ϴ�!
// �������� ��������
// ���̴� ��ġ�ϴ��� ��
// 
// �л����� �˻� �� ���� ����� �߰����ּ���!
// �л����� �˻� : 1) �̸�, 2)����, 3)������� �� ��1 �Ͽ� ���� ���� ���� �л� ���� ��� ���!
// �л����� ���� : �л� �̸��� �Է��ϸ� �л� ������ ����ϰ� Ȥ�� ���� �̸��� �л��� �ִٸ� 1�� �����ϵ��� �� ��, ����, ��������� �Է¹޾� �л����� ������Ʈ!


void save_st_info(string **arr, int i);
float get_avg(string** arr, int num);
int get_early_birth(string** arr, int num);

int main() {
	int stnum;
	string early_birth;

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
	st_matrix[0][NAME_IDX] = "�̸�";
	st_matrix[0][AGE_IDX] = "����";
	st_matrix[0][BIRTH_IDX] = "�������";

	// 2) �л� ���� �Է¹��� �� �迭�� �����ϴ� �Լ� ȣ��
	cout << stnum << " ���� �л��� �̸�, ����, ��������� ������� �Է��Ͻÿ�. (ex: ������ 20 050101)" << endl << endl;
	
	for (int i = 1; i < stnum + 1; i++) {
		save_st_info(st_matrix, i);
	}

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
	early_birth = to_string(get_early_birth(st_matrix, stnum));
	cout << "���� ���� ������ : " << early_birth.substr(0,2) << " / " << early_birth.substr(2,2) << endl << endl;

	// 3 - 4) �迭 ���� �� ���α׷� ����
	for (int i = 0; i < stnum + 1; i++) {
		delete[] st_matrix[i];
	}
	delete[] st_matrix;

	return 0;
}

void save_st_info(string** arr, int i) {
	// 0 1 2 3 4 5 6 7 8 9 10 11 12
	// ������   2 5   0 0 1 1  3  0
	bool error;
	int ok = 0;
	int name_split_point;
	int age_split_point;
	string input;
	string name;
	string age;
	string birth;

	while (ok == 0) {

		bool error = false; // �߰��� �ѹ� ���� �޼��� ��� �������� ok �ް� ���� �� �ֵ��� error ���� �ʱ�ȭ

		getline(cin, input);

		// �̸� ����
		name_split_point = input.find(" ");

		name = input.substr(0, name_split_point);

		// �̸��� ���ڰ� �ִ��� Ȯ��(���ڸ� 0, �׷��� Ư�����ڵ� 0�� �Ǵ°� ��� �ذ��մϱ� ???)
		// �̸��� ���̴� �������.
		for (char c : name) {

			if (isdigit(c) != 0) {
				cout << "***�Է� ����: �̸��� ���ڷθ� �Է��Ͻÿ�.***" << endl;
				error = true;
				break;
			}
		}

		// ���� ����
		age_split_point = input.find(" ", name_split_point + 1);

		age = input.substr((name_split_point + 1), (age_split_point - name_split_point - 1));

		// ���̰� ���ڷ� �̷�����ִ��� Ȯ��
		// ������ ���̴� �������.
		for (char c : age) {

			if (isdigit(c) == 0) {
				cout << "***�Է� ����: ���̴� ���ڷθ� �Է��Ͻÿ�.***" << endl;
				error = true;
				break;
			}
		}

		// ���� ����
		birth = input.substr(age_split_point + 1);

		// ������ ���̰� �����ڸ����� Ȯ��
		if (birth.length() != 6) {
			cout << "***�Է� ����: ������ ���� �ڸ��� �Է��Ͻÿ�.***" << endl;
			error = true;
		}

		// ���̰� ���ڷ� �̷�����ִ��� Ȯ��
		for (char c : birth) {

			if (isdigit(c) == 0) {
				cout << "***�Է� ����: ������ ���ڷθ� �Է��Ͻÿ�.***" << endl;
				error = true;
				break;
			}
		}

		if (error == false) {
			arr[i][NAME_IDX] = name;
			arr[i][AGE_IDX] = age;
			arr[i][BIRTH_IDX] = birth;
			ok++;
		}
	}

}

float get_avg(string** arr, int num) {

	float sum = 0;

	for (int i = 1; i < num + 1; i++) {

		sum += stof(arr[i][AGE_IDX]);

	} return (sum / num);
}

int get_early_birth(string** arr, int num) {
	
	int min = 10000;

	for (int i = 1; i < num + 1; i++) {
		int birth_md = stoi(arr[i][BIRTH_IDX].substr(2, 5));
		if (birth_md <= min) {

			min = birth_md;
	
		}
	}
	return min;
}
