#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"str2hex.h"
#include"testFrame.h"
#include"unitTest.h"

typedef struct TEST_CASE_3
{
	char input[100];
	unsigned int sLen;
	unsigned int hLen;
	char prediction[100];
	int returnValue;
}CASE_3;

void parseTestCaseB(void* param, int idx)
{	
	PARAM* test_param = (PARAM*)param;
	CASE_3* case3 = (CASE_3*)test_param->caseTest; 

	fscanf(test_param->fp, "%s %u %u %s %d",case3[idx].input, &case3[idx].sLen, &case3[idx].hLen, case3[idx].prediction, &case3[idx].returnValue);
	DEBUGPRINT("%s %u %u %s %d\n",case3[idx].input, case3[idx].sLen, case3[idx].hLen, case3[idx].prediction, case3[idx].returnValue);
}

int unitTestFuncB(void* testCase, int idx)
{
	CASE_3* case3 = (CASE_3*)testCase;
	char hexStr[100];

	int result = str2hex(case3[idx].input, hexStr, case3[idx].sLen, case3[idx].hLen);

	if(result == case3[idx].returnValue)
	{
		if(case3[idx].sLen == 0)
		{
			if(hexStr[0] == '\0')
			{
				DEBUGPRINT("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return 0;
			}
			DEBUGPRINT("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return idx + 1;		
		}

		if((case3[idx].sLen * 2 == case3[idx].hLen))
		{
			if(!memcmp(hexStr, case3[idx].prediction, case3[idx].hLen))
			{
				DEBUGPRINT("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return 0;
			}
			DEBUGPRINT("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return idx + 1;
		}
		else if((case3[idx].sLen * 2 > case3[idx].hLen))
		{
			if(hexStr[0] == '\0')
			{
				DEBUGPRINT("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return 0;
			}
			DEBUGPRINT("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return idx + 1;		
		}
		else
		{
			if(!memcmp(hexStr, case3[idx].prediction, case3[idx].sLen * 2 + 1))
			{
				DEBUGPRINT("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return 0;
			}
			DEBUGPRINT("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return idx + 1;
		}
	}
	DEBUGPRINT("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
	return idx + 1;
}

int main()
{
	char* fpath = "str2hex.txt";
	int structSize = sizeof(CASE_3);

	registerFunc(fpath, structSize, parseTestCaseB, unitTestFuncB);

	testFramework();

	return 0;
}