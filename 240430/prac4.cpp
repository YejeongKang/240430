#include <iostream>
#include <string>

using namespace std;

#define INFO_COLUMN 3

//1. ����ڿ��� �� ���� �л��� �Է��� ������ ����
//2. �л� �� ��ŭ �̸� ���� ����" ������ �ѹ��� �Է� �ޱ�
//3. 1) �л� ���� ���, 2) ��� ����, 3) ���� ���� ����, 4) ���α׷� ����, �� ���� ��ɿ� ��� ����
//4. ���ݱ��� ��� �ڷᱸ��(�迭, ����, ����Ʈ), ���ڿ�(��Ʈ��) �� �����Ӱ� Ȱ�� �Ͽ� �ۼ� ~�ۼ� ���� � ����� ��� �������� ���� ���ϰ� �ۼ� �����ϱ�~
//5. * �ð��� ������ * ���� ó��, �ּ�, �ڵ� ���� ���� �ǽ��Ͽ� �ϼ����� ���̱�

int save_st_info(string **arr);

int main() {
	int stnum;

	cout << "�Է��� �л��� �� : " << endl;
	cin >> stnum;

	// ���� �迭 ����
	string** st_info = new string * [stnum + 1];

	for (int i = 0; i < stnum + 1; i++) {

		st_info[i] = new string[INFO_COLUMN];

	}

	// �迭 ��ܿ� ������ ���� �Ҵ�
	st_info[0][0] = "�̸�";
	st_info[0][1] = "����";
	st_info[0][2] = "����";

	// �л� ���� �Է¹��� �� �迭�� �����ϴ� �Լ� ȣ��
	save_st_info(st_info);


}

int save_st_info(string **arr) {
	
	string st;

	// �л� ���� �� �ٿ� �Է� �ޱ� (�̸�, ����, ����)
	
	cout << "�л��� �̸�, ����, ������ ������� �Է��Ͻÿ�. (������ �ΰ� �Է�)" << endl << "=> ";
	getline(cin, st);
//	st.substr().find(" ") // ���� ������ ������ �ܾ ����

}