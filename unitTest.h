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

/* �ļ���ʽ����ʱ�����Դ�����Ҫʵ�ֲ⺯��*/
void parseTestCaseA(void* param, int idx);

/* ���ֲ��Է�ʽ����Ҫʵ�� */
void unitTestFuncA(void* testCase, int idx);

#endif