#include<iostream>
#include "stdafx.h"
using namespace std;
int num[20][20];
bool sign;
int level;

/* Check函数：判断key填入n时是否满足条件 */

/* ---Check Begin--- */
bool Check(int n,int key)
{
	int x, y, height, width;
	for (int i=0;i<level;i++)// 判断n所在横列是否合法 
	{
		int j=n/level;// j为n竖坐标 
		if (num[j][i]==key) return false;
	}
	for (int i=0;i<level;i++)//判断n所在竖列是否合法
	{
		int j=n%level;//j为n横坐标 
		if (num[i][j]==key) return false;
	}
	/* 若为9，8，6，4阶数独则判断小宫格 */
	if (level==9||level==8||level==6||level==4) {
		/* x为n所在的小九宫格左顶点竖坐标 */
		/* y为n所在的小九宫格左顶点横坐标 */
		/* height为小宫格高度 */
		/* weidth为小宫格宽度 */
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
		for (int i=x;i<x+height;i++)//判断n所在的小九宫格是否合法 
		{
			for (int j=y;j<y+width;j++)
			{
				if (num[i][j]==key) return false;
			}
		}
	}
	return true;//全部合法，返回正确
}
/* ---Check End--- */

/* DFS函数 ：深搜+回溯 解决数独*/

/* ---DFS Begin--- */
int DFS(int n)
{
	if (n>(level*level-1))//所有的都符合，退出递归 
	{
		sign = true;
		return 0;
	}
	if (num[n/level][n%level]!= 0) //当前位不为空时跳过 
	{
		DFS(n+1);
	}
	else
	{
		for (int i=1;i<=level;i++)//否则对当前位进行枚举测试
		{
			if (Check(n,i) == true)//满足条件时填入数字
			{
				num[n/level][n%level] = i;

				DFS(n+1);//继续搜索

				if (sign == true) return 0;//返回时如果构造成功，则直接退出

				num[n/level][n%level] = 0;//如果构造不成功，还原当前位
			}
		}
	}
}
/* ---DFS Begin--- */
/* init_num 函数：初始化num数组 */
/* ---init_num Begin--- */
void init_num() {
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			num[i][j] = 0;
}
/* ---init_num end--- */


