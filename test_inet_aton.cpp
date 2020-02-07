#include<stdio.h>
#include<stdlib.h>
#include"inet_aton.h"
#include"testFrame.h"

typedef struct TEST_CASE_2
{
	char input[100];
	unsigned int prediction;
	int returnValue;
}CASE_2;

void parseTestCaseA(void* param, int idx)
{	
	PARAM* test_param = (PARAM*)param;
	CASE_2* case2 = (CASE_2*)test_param->caseTest;

	fscanf(test_param->fp, "%s %u %d",case2[idx].input, &case2[idx].prediction, &case2[idx].returnValue);
	printf("%s %u %d\n",case2[idx].input, case2[idx].prediction, case2[idx].returnValue);
}

void unitTestFuncA(void* testCase, int idx)
{
	CASE_2* case2 = (CASE_2*)testCase;
	unsigned int lp = 0;

	int result = inet_aton(case2[idx].input, &lp);

	if(result == case2[idx].returnValue && lp == case2[idx].prediction)
	{
		printf("第%d个：%s 用例测试成功\n", idx + 1, case2[idx].input);
		return;
	}

	printf("第%d个：%s 用例测试失败\n", idx + 1, case2[idx].input);

	return;
}

int main()
{
	char* fpath = "inet_aton.txt";
	int structSize = sizeof(CASE_2);

	registerFunc(fpath, structSize, parseTestCaseA, unitTestFuncA);

	testFramework();

	return 0;
}