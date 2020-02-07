#ifndef TESTFRAME_H
#define TESTFRAME_H

typedef void* (*getTestCaseFunc)(void* param);
typedef void (* unitTestFunc)(void* testCase, int);
typedef void (*parseTestCase)(void* param, int);

typedef struct TEST_PARAM
{
	FILE* fp;
	int count;
	void* caseTest;
}PARAM;

typedef struct TESTFW_CTX_T
{
	getTestCaseFunc getTestCase;
	parseTestCase parse;
	unitTestFunc unitTest;
	char *fpath;
	/* 当为文件测试时表示一个struct长度，为数组时表示数组行数 */
	int structSizeOrArraySize; 
}TESTFW_CTX;

void registerFunc(char* fpath, int structSize, parseTestCase parse, unitTestFunc unitTest);

int initial();

int testFramework();

#endif

