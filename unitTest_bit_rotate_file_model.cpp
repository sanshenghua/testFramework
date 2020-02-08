#include<stdio.h>
#include<stdlib.h>
#include"bit_rotate.h"
#include"testFrame.h"
#include"unitTest.h"

typedef struct TEST_CASE_1
{
	unsigned int input;
	unsigned int bit;
	unsigned int prediction;
//	int returnValue;
}CASE_1;

void parseTestCaseD(void* param, int idx)
{	
	PARAM* test_param = (PARAM*)param;
	CASE_1* case1 = (CASE_1*)test_param->caseTest;

	fscanf(test_param->fp, "%u %u %u",&case1[idx].input, &case1[idx].bit, &case1[idx].prediction);
	DEBUGPRINT("%u %u %u\n",case1[idx].input, case1[idx].bit, case1[idx].prediction);
}

int unitTestFuncD(void* testCase, int idx)
{
	CASE_1* case1 = (CASE_1*)testCase;
	//unsigned int lp = 0;

	unsigned int result = BIT_ROTATE(case1[idx].input, case1[idx].bit);

	if(result == case1[idx].prediction)
	{
		DEBUGPRINT("第%d个：%u 用例测试成功\n", idx + 1, case1[idx].input);
		return 0;
	}

	DEBUGPRINT("第%d个：%u 用例测试失败\n", idx + 1, case1[idx].input);
	return idx + 1;
}

int main()
{
	char* fpath = "bit_rotate.txt";
	int structSize = sizeof(CASE_1);

	registerFunc(fpath, structSize, parseTestCaseD, unitTestFuncD);

	testFramework();

	return 0;
}