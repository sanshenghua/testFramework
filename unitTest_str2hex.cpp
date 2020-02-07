#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"str2hex.h"
#include"testFrame.h"

//typedef struct TEST_CASE_2
//{
//	char input[100];
//	unsigned int prediction;
//	int returnValue;
//}CASE_2;
/*
//测试框架里面的参数struct
typedef struct TEST_PARAM
{
	FILE* fp;
	int count;
	void* caseTest;

}PARAM;
*/
typedef struct TEST_CASE_3
{
	char input[100];
	unsigned int sLen;
	unsigned int hLen;
	char prediction[100];
	int returnValue;
}CASE_3;

//这里可以和框架公用一个，之后优化
//typedef struct TEST_PARAM_
//{
//	FILE* fp;
//	int count;
////	CASE_2* caseTset;
//}PARAM_;
//PARAM* test_param;
//CASE_2 *case3;
int a =0;

//void* iniFuncA(void* param)
//{
//	PARAM* test_param = (PARAM*)param;
//	CASE_2 *case3 = (CASE_2*)malloc(sizeof(CASE_2) * test_param->count);
//	a = 3;
//	//这里注意一下，可能会报错，可能要转化为void指针。
//	return (void*)case3;
//}

void parseTestCaseA(void* param, int idx)
{	
	//printf("%d", a);
	//CASE_2* case3 = test_param->caseTset;
	//if(idx == 0)
	//{
	//	case3 = (CASE_2*)malloc(sizeof(CASE_2) * test_param->count);
	//}
	PARAM* test_param = (PARAM*)param;
	CASE_3* case3 = (CASE_3*)test_param->caseTest; 

	fscanf(test_param->fp, "%s %u %u %s %d",case3[idx].input, &case3[idx].sLen, &case3[idx].hLen, case3[idx].prediction, &case3[idx].returnValue);
	printf("%s %u %u %s %d\n",case3[idx].input, case3[idx].sLen, case3[idx].hLen, case3[idx].prediction, case3[idx].returnValue);

}

void unitTestFuncA(void* testCase, int idx)
{
	CASE_3* case3 = (CASE_3*)testCase;
	char hexStr[100];

	int result = str2hex(case3[idx].input, hexStr, case3[idx].sLen, case3[idx].hLen);
	//printf("%s\n",hexStr);
	if(result == case3[idx].returnValue)
	{
		if(case3[idx].sLen == 0)
		{
			if(hexStr[0] == '\0')
			{
				printf("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return;
			}
			printf("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return;		
		}

		if((case3[idx].sLen * 2 == case3[idx].hLen))
		{
			if(!memcmp(hexStr, case3[idx].prediction, case3[idx].hLen))
			{
				printf("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return;
			}
			printf("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return;
		}
		else if((case3[idx].sLen * 2 > case3[idx].hLen))
		{
			if(hexStr[0] == '\0')
			{
				printf("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return;
			}
			printf("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return;		
		}
		else
		{
			if(!memcmp(hexStr, case3[idx].prediction, case3[idx].sLen * 2 + 1))
			{
				printf("第%d个：%s 用例测试成功\n", idx + 1, case3[idx].input);	
				return;
			}
			printf("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
			return;
		}
	}
	printf("第%d个：%s 用例测试失败\n", idx + 1, case3[idx].input);
	return;
}



int main()
{
	char* fpath = "str2hex.txt";
	int structSize = sizeof(CASE_3);

	registerFunc(fpath, structSize, parseTestCaseA, unitTestFuncA);

	testFramework();

	return 0;
}