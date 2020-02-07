#include<stdio.h>
#include<stdlib.h>
#include"testFrame.h"

PARAM gParam;
TESTFW_CTX gTestCtx;
//CASE* caseTest = NULL;

void registerFunc(char* fpath, int structSize, parseTestCase parse, unitTestFunc unitTest)
{
	gTestCtx.structSize = structSize;
	gTestCtx.parse = parse;
	gTestCtx.unitTest = unitTest;
	gTestCtx.fpath = fpath;
}

int countFile(FILE *fp)
{
	char ch;
	int count = 0;

	while((ch=fgetc(fp)) != EOF)
	{
        if(ch=='\n') count++;   
    }
	//printf("%d\n",count + 1);
	rewind(fp);
	return count + 1;
}

int initial()
{
	FILE *fp = fopen(gTestCtx.fpath, "r");
	gParam.fp = fp;

	if(fp == NULL)
	{
		printf("file open error\n");
        return 0;
	}

	//fscanf(fp, "%d", &gParam.count);
	gParam.count = countFile(gParam.fp);

	gParam.caseTest = (void *)malloc(gTestCtx.structSize * gParam.count);
	//gParam.caseTest = caseTest;

	return 0;
}

void parseDataToStruct()
{
	char ch;
	int idx = 0;

	while(idx < gParam.count)
	{
	/*	ch = fgetc(gParam.fp);

		if(ch == EOF) break;
*/
		gTestCtx.parse((void*)(&gParam), idx);

		idx++;
	}
}

void destory()
{
	fclose(gParam.fp);

	free(gParam.caseTest);

	gParam.caseTest = NULL;

	return;
}

int testFramework()
{
	initial();

	parseDataToStruct();

	for(int i = 0; i < gParam.count; i++)
	{
		gTestCtx.unitTest(gParam.caseTest, i);
	}

	destory();

	return 0;
}