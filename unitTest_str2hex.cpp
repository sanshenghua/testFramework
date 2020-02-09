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

#define MAX_MSG_LENGTH 512
 
/* fscanf会把字符串中含有转义字符的\读成\\,所以后处理将\\替换成\进行还原 */
int replaceStr(char *sSrc, char *sMatchStr, char *sReplaceStr)
{
        int  StringLen;
        char caNewString[MAX_MSG_LENGTH];
 
        char *FindPos = strstr(sSrc, sMatchStr);
        if((!FindPos) || (!sMatchStr))
		{
                return -1;
		}

        while( FindPos )
        {
                memset(caNewString, 0, sizeof(caNewString));
                StringLen = FindPos - sSrc;
                strncpy(caNewString, sSrc, StringLen);
                strcat(caNewString, sReplaceStr);
                strcat(caNewString, FindPos + strlen(sMatchStr));
                strcpy(sSrc, caNewString);
 
                FindPos = strstr(sSrc, sMatchStr);
        }
 
        return 0;
}

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

	replaceStr(case3[idx].input, "\\0", "\0" );

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