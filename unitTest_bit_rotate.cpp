#include<stdio.h>
#include<stdlib.h>
#include"bit_rotate.h"
#include"testFrame.h"

                       /*  0x0012d687    0xc004b5a1*/
unsigned int testData[][3]={{1234567, 2, 3221534113},
							{1234567, 32, 1234567},
						  /*  0xffffffff    0xffffffff */
						    {4294967295, 2, 4294967295}};

/* ʹ���������ʱ������Ҫʵ�ָú���*/
void parseTestCaseC(void* param, int idx)
{

}

/* Ϊ�˱���������Է�ʽ���ļ����Է�ʽ�ӿ�һ�£�����ֻ�õ��ڶ������������Կ�ܻᴫһ��NULL */
void unitTestFuncC(void* testCase, int idx)
{
	unsigned int b = BIT_ROTATE(testData[idx][0], testData[idx][1]);

	if(b == testData[idx][2])
	{
		printf("��%d����%u �������Գɹ�\n", idx + 1, testData[idx][0]);	
		return;
	}

	printf("��%d����%u ��������ʧ��\n", idx + 1, testData[idx][0]);
	return;	
}

//int main()
//{
//	/* ʹ��������в���ʱ���ļ�·������� */
//	char *fp = "";
//	int count = sizeof(testData)/ sizeof(testData[0]);
//
//	registerFunc(fp, count, parseTestCaseC, unitTestFuncC);
//
//	testFramework();
//
//	return 0;
//}
