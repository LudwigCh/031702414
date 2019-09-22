#include<iostream>
#include "stdafx.h"
using namespace std;
int num[20][20];
bool sign;
int level;

/* Check�������ж�key����nʱ�Ƿ��������� */

/* ---Check Begin--- */
bool Check(int n,int key)
{
	int x, y, height, width;
	for (int i=0;i<level;i++)// �ж�n���ں����Ƿ�Ϸ� 
	{
		int j=n/level;// jΪn������ 
		if (num[j][i]==key) return false;
	}
	for (int i=0;i<level;i++)//�ж�n���������Ƿ�Ϸ�
	{
		int j=n%level;//jΪn������ 
		if (num[i][j]==key) return false;
	}
	/* ��Ϊ9��8��6��4���������ж�С���� */
	if (level==9||level==8||level==6||level==4) {
		/* xΪn���ڵ�С�Ź����󶥵������� */
		/* yΪn���ڵ�С�Ź����󶥵������ */
		/* heightΪС����߶� */
		/* weidthΪС������ */
		switch (level) {
			case 9: {
				x = n / 9 / 3 * 3;
				y = n % 9 / 3 * 3;
				height = 3; width = 3;
				break;
			}
			case 8: {
				x = n / 8 / 4 * 4;
				y = n % 8 / 2 * 2;
				height = 4; width = 2;
				break;
			}
			case 6: {
				x = n / 6 / 2 * 2;
				y = n % 6 / 3 * 3;
				height = 2; width = 3;
				break;
			}
			case 4: {
				x = n / 4 / 2 * 2;
				y = n % 4 / 2 * 2;
				height = 2; width = 2;
				break;
			}
		}
		for (int i=x;i<x+height;i++)//�ж�n���ڵ�С�Ź����Ƿ�Ϸ� 
		{
			for (int j=y;j<y+width;j++)
			{
				if (num[i][j]==key) return false;
			}
		}
	}
	return true;//ȫ���Ϸ���������ȷ
}
/* ---Check End--- */

/* DFS���� ������+���� �������*/

/* ---DFS Begin--- */
int DFS(int n)
{
	if (n>(level*level-1))//���еĶ����ϣ��˳��ݹ� 
	{
		sign = true;
		return 0;
	}
	if (num[n/level][n%level]!= 0) //��ǰλ��Ϊ��ʱ���� 
	{
		DFS(n+1);
	}
	else
	{
		for (int i=1;i<=level;i++)//����Ե�ǰλ����ö�ٲ���
		{
			if (Check(n,i) == true)//��������ʱ��������
			{
				num[n/level][n%level] = i;

				DFS(n+1);//��������

				if (sign == true) return 0;//����ʱ�������ɹ�����ֱ���˳�

				num[n/level][n%level] = 0;//������첻�ɹ�����ԭ��ǰλ
			}
		}
	}
}
/* ---DFS Begin--- */
/* init_num ��������ʼ��num���� */
/* ---init_num Begin--- */
void init_num() {
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			num[i][j] = 0;
}
/* ---init_num end--- */


