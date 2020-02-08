#include<stdio.h>
#include<stdlib.h>
#include"bit_rotate.h"
#include"testFrame.h"
#include"unitTest.h"

                       /*  0x0012d687    0xc004b5a1*/
unsigned int testData[][3]={{1234567, 0, 3221534113},
							{1234567, 2, 3221534113},
							{1234567, 32, 1234567},
						  /*  0xffffffff    0xffffffff */
						    {4294967295, 2, 4294967295}};

/* 使用数组测试时，不需要实现该函数*/
void parseTestCaseC(void* param, int idx)
{

}

/* 为了保持数组测试方式与文件测试方式接口一致，这里只用到第二个参数，测试框架会传一个NULL */
int unitTestFuncC(void* testCase, int idx)
{
	unsigned int b = BIT_ROTATE(testData[idx][0], testData[idx][1]);

	if(b == testData[idx][2])
	{
		DEBUGPRINT("第%d个：%u 用例测试成功\n", idx + 1, testData[idx][0]);	
		return 0;
	}

	DEBUGPRINT("第%d个：%u 用例测试失败\n", idx + 1, testData[idx][0]);
	return idx + 1;	
}

int main()
{
	/* 使用数组进行测试时，文件路径传入空 */
	char *fp = "";
	int count = sizeof(testData)/ sizeof(testData[0]);

	registerFunc(fp, count, parseTestCaseC, unitTestFuncC);

	testFramework();

	return 0;
}
