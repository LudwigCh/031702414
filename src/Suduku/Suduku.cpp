#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

#include"stdafx.h"

using namespace std;
streampos pos_i;
/* term�� ���������� */

/* ---term Begin--- */
class sudu
{
public:
	int row;//row=col������� 
	int *Martrix = new int[row*row];//����ʱnewһ������ 
	void Martrix_input(int *Martrix, int row, const char* filename);
	void Martrix_output(int *Martrix, int row, const char* filename);
	void Martrix_sudu_num(int *Martrix, int row);
	void Martrix_num_sudu(int *Martrix, int row);
	sudu(int a);
	~sudu();
};

sudu::sudu(int a) :row(a)
{
	cout << "Hello!\n";
}

sudu::~sudu()
{
	delete[]Martrix;
	cout << "This sudu is complete!\n";
}
/*�����ı����뺯��*/
void sudu::Martrix_input(int *Martrix, int row, const char* filename) {
	ifstream infile;
	infile.open(filename, ios::in | ios::binary);
	if (!infile) {// �ж������ļ��Ƿ���� 
		cout << filename << " is not found";
		exit(1);
		return;
	}
	infile.seekg(pos_i, ios::beg);//����ʼλ��ƫ��pos_i��ʼ��ȡ��n������ 
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			infile >> *(Martrix + j + i * row);
		}
	}
	pos_i = infile.tellg();// �Ѷ���һ���������λ�ô���pos_i�Ա��ȡ��һ������ 
	infile.close();
}
/*�����ı��������*/
void sudu::Martrix_output(int *Martrix, int row, const char* filename) {
	ofstream outfile;
	outfile.open(filename, ios::app);//�Ժ�̷�ʽ���ļ��Ա����д 
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			outfile << *(Martrix + i * row + j) << " ";
		}
		outfile << endl;
	}
	outfile << "\n";
	outfile.close();
}
/*����->���� �Ա���������������в���*/
void sudu::Martrix_num_sudu(int *Martrix, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			num[i][j] = *(Martrix + i * row + j);
		}
	}
}
/*����->���� �Ա�����������ļ�д�����*/
void sudu::Martrix_sudu_num(int *Martrix, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			*(Martrix + i * row + j) = num[i][j];
		}
	}
}
/* ---term End--- */

int main(int argc, char *argv[]) {
	/*�������н��ղ��� */
	level = atoi(argv[2]);
	int m = atoi(argv[2]);
	int n = atoi(argv[4]);

	/*�Զ���������в���*/
	for (int kk = 1; kk <= n; ++kk) {
		sign = false;
		init_num();
		sudu sudu1(m);//�����m������ 
		sudu1.Martrix_input((int*)sudu1.Martrix, m, (char*)argv[6]);//��������ָ�����ļ����ж���һ��m������ 
		sudu1.Martrix_num_sudu((int*)sudu1.Martrix, m);//����->���� 
		DFS(0); //��������������� 
		sudu1.Martrix_sudu_num((int*)sudu1.Martrix, m);//����->���� 
		sudu1.Martrix_output((int*)sudu1.Martrix, m, (char*)argv[8]);//��������ָ�����ļ�������������Ľ� 
	}
}

