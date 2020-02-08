#ifndef UNITTEST_H
#define UNITTEST_H

/*
测试框架里面的参数
typedef struct TEST_PARAM
{
	FILE* fp;
	int count;
	void* caseTest;
}PARAM;
*/

#define __DEBUG

#ifdef __DEBUG
	#define DEBUGPRINT(format, ...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)			
#else
	#define DEBUGPRINT(msg)
#endif

/* 文件形式测试时，测试代码需要实现测函数*/
void parseTestCaseA(void* param, int idx);

/* 两种测试方式都需要实现 */
int unitTestFuncA(void* testCase, int idx);

#endif