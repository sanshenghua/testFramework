
#include<stdio.h>

struct test_case1
{
	unsigned int input;
	unsigned int prediction;
};

struct test_case2
{
	char input[100];
	unsigned int prediction;
	int returnValue;
};

struct test_case3
{
	char str[100];
	unsigned int sLen;
	unsigned int hLen;
	char prediction[100];
	int returnValue;
};
//enum structT { test_case1 = 1, test_case2 = 2, test_case3 = 3};

struct test_case
{
	struct test_case1 *c1;
	struct test_case2 *c2;
	struct test_case3 *c3;
};

typedef int (*func2)(const char*, unsigned int *);
typedef int (*func3)(const char[],  char[], unsigned int, unsigned int);

int test(int structType, void *stuctP, void *func, char f[]);
