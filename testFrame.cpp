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

/* ͳ���ļ����������������ĸ��� */
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

/* �����ļ����ԣ����ļ���������ݰ��ж���struct������ */
void parseDataToStruct()
{
	int idx = 0;

	while(idx < gParam.count)
	{
		gTestCtx.parse((void*)(&gParam), idx);
		idx++;
	}
}

/* �����ļ����ԣ��رմ򿪵��ļ����ͷ�������ڴ� */
void destory()
{
	fclose(gParam.fp);

	free(gParam.caseTest);

	gParam.caseTest = NULL;

	return;
}

int testFramework()
{
	/* ��������Ϊ�ļ���ʽ */
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
	/* ��������Ϊ����*/
	else 
	{
		for(int i = 0; i < gTestCtx.structSizeOrArraySize; i++)
		{
			/* Ϊ��������������ļ����Է�ʽһ�£����ｫָ�봫NULL */
			gTestCtx.unitTest(NULL, i);
		}
	}

	return 0;
}