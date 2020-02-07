#include"bit_rotate.h"
#include<iostream>
using namespace std;


int d[2][2]={ {0xffff1122u, 1}, {0xffff1122u, 2}};

int main()
{
	atoi(d[0][0]);
	cout<<d<<endl;
	int a = BIT_ROTATE(d[0][0], d[0][1]);
	return 0;
}