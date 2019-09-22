#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

#include"stdafx.h"

using namespace std;
streampos pos_i;
/* term类 构造数独类 */

/* ---term Begin--- */
class sudu
{
public:
	int row;//row=col行列相等 
	int *Martrix = new int[row*row];//创建时new一个数组 
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
/*数独文本输入函数*/
void sudu::Martrix_input(int *Martrix, int row, const char* filename) {
	ifstream infile;
	infile.open(filename, ios::in | ios::binary);
	if (!infile) {// 判断输入文件是否存在 
		cout << filename << " is not found";
		exit(1);
		return;
	}
	infile.seekg(pos_i, ios::beg);//从起始位置偏移pos_i开始读取第n个数独 
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			infile >> *(Martrix + j + i * row);
		}
	}
	pos_i = infile.tellg();// 把读完一个数独后的位置传给pos_i以便读取下一个数独 
	infile.close();
}
/*数独文本输出函数*/
void sudu::Martrix_output(int *Martrix, int row, const char* filename) {
	ofstream outfile;
	outfile.open(filename, ios::app);//以后继方式打开文件以便继续写 
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			outfile << *(Martrix + i * row + j) << " ";
		}
		outfile << endl;
	}
	outfile << "\n";
	outfile.close();
}
/*数独->数组 以便数独计算引擎进行操作*/
void sudu::Martrix_num_sudu(int *Martrix, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			num[i][j] = *(Martrix + i * row + j);
		}
	}
}
/*数组->数独 以便数独类进行文件写入操作*/
void sudu::Martrix_sudu_num(int *Martrix, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			*(Martrix + i * row + j) = num[i][j];
		}
	}
}
/* ---term End--- */

int main(int argc, char *argv[]) {
	/*从命令行接收参数 */
	level = atoi(argv[2]);
	int m = atoi(argv[2]);
	int n = atoi(argv[4]);

	/*对多个数独进行操作*/
	for (int kk = 1; kk <= n; ++kk) {
		sign = false;
		init_num();
		sudu sudu1(m);//构造出m阶数独 
		sudu1.Martrix_input((int*)sudu1.Martrix, m, (char*)argv[6]);//从命令行指定的文件名中读入一个m阶数独 
		sudu1.Martrix_num_sudu((int*)sudu1.Martrix, m);//数独->数组 
		DFS(0); //数独数组计算引擎 
		sudu1.Martrix_sudu_num((int*)sudu1.Martrix, m);//数组->数独 
		sudu1.Martrix_output((int*)sudu1.Martrix, m, (char*)argv[8]);//在命令行指定的文件名中输出数独的解 
	}
}

