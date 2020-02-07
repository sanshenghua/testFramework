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
	/* ��Ϊ�ļ�����ʱ��ʾһ��struct���ȣ�Ϊ����ʱ��ʾ�������� */
	int structSizeOrArraySize; 
}TESTFW_CTX;

void registerFunc(char* fpath, int structSize, parseTestCase parse, unitTestFunc unitTest);

int initial();

int testFramework();

#endif

