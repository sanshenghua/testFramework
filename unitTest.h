#ifndef UNITTEST_H
#define UNITTEST_H

/*
���Կ������Ĳ���
typedef struct TEST_PARAM
{
	FILE* fp;
	int count;
	void* caseTest;
}PARAM;
*/

#define __DEBUG

#ifdef __DEBUG
	#define DEBUGPRINT(format, ...) printf("FILE: "__FILE__", LINE: %d: "format"", __LINE__, ##__VA_ARGS__)			
#else
	#define DEBUGPRINT(msg)
#endif

/* �ļ���ʽ����ʱ�����Դ�����Ҫʵ�ֲ⺯��*/
void parseTestCaseA(void* param, int idx);

/* ���ֲ��Է�ʽ����Ҫʵ�� */
int unitTestFuncA(void* testCase, int idx);

#endif