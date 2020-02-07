#include<stdio.h>
#include<stdlib.h>
#include"testFrame.h"

PARAM gParam;
TESTFW_CTX gTestCtx;

void registerFunc(char* fpath, int structSizeOrArraySize, parseTestCase parse, unitTestFunc unitTest)
{
	gTestCtx.structSizeOrArraySize = structSizeOrArraySize;
	gTestCtx.parse = parse;
	gTestCtx.unitTest = unitTest;
	gTestCtx.fpath = fpath;
}

/* 统计文件行数即测试用例的个数 */
int countFile(FILE *fp)
{
	char ch;
	int count = 0;

	while((ch=fgetc(fp)) != EOF)
	{
        if(ch=='\n') count++;   
    }

	rewind(fp);
	return count + 1;
}

int initial()
{
	gParam.fp = fopen(gTestCtx.fpath, "r");

	if(gParam.fp == NULL)
	{
		printf("file open error\n");
		return 0;
	}

	gParam.count = countFile(gParam.fp);

	gParam.caseTest = (void *)malloc(gTestCtx.structSizeOrArraySize * gParam.count);

	return 0;	
}

/* 用于文件测试，将文件里面的数据按行读入struct数组中 */
void parseDataToStruct()
{
	int idx = 0;

	while(idx < gParam.count)
	{
		gTestCtx.parse((void*)(&gParam), idx);
		idx++;
	}
}

/* 用于文件测试，关闭打开的文件和释放申请的内存 */
void destory()
{
	fclose(gParam.fp);

	free(gParam.caseTest);

	gParam.caseTest = NULL;

	return;
}

int testFramework()
{
	/* 测试用例为文件形式 */
	if(gTestCtx.fpath != "")
	{
		initial();

		parseDataToStruct();

		for(int i = 0; i < gParam.count; i++)
		{
			gTestCtx.unitTest(gParam.caseTest, i);
		}

		destory();
	}
	/* 测试用例为数组*/
	else 
	{
		for(int i = 0; i < gTestCtx.structSizeOrArraySize; i++)
		{
			/* 为保持数组测试与文件测试方式一致，这里将指针传NULL */
			gTestCtx.unitTest(NULL, i);
		}
	}

	return 0;
}