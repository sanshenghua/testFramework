#include<stdio.h>
#include<stdlib.h>
//#include"inet_aton.h"
#include "main.h"


int test(int structType, void *stuctP, void *func, char *f)
{
	FILE *fp = fopen(f, "r");

	if(fp == NULL)
	{
		printf("file open error\n");
        return -1;
	}

	char ch;
	int line = 0, i = 0;

	fscanf(fp, "%d",&line);

	test_case *A;
	test_case1 *case1;
	test_case2 *case2;
	test_case3 *case3;



	switch (structType)
	{

		case 2: 
			{

			case2 = (struct test_case2*)stuctP; 
			case2 = (struct test_case2 *) malloc (sizeof(test_case2) * line);

			while(1)
			{
				ch = fgetc(fp);
				if(ch == EOF) break;
		
				fscanf(fp, "%s %u %d",case2[i].input, &case2[i].prediction, &case2[i].returnValue);
				printf("%s %u %d\n",case2[i].input, case2[i].prediction, case2[i].returnValue);
				i++;
			}
			func2 f2 = (func2)func;
			
			int idx = 0;

			while(idx < line)
			{   
				unsigned int lp = 0;
				//char *lll = test[idx].input;
				int result = f2(case2[idx].input, &lp);
				if(result == case2[idx].returnValue  && lp == case2[idx].prediction)
				{
					printf("第%d 个用例测试成功\n",idx+1);
					idx++;
					continue;
				}
				printf("第%d 个用例测试失败\n",idx+1);
				idx++;
			}
			break;
			}

		//case 5: case5 = (struct test_case2*)stuctP; break;
		//scase 3: case3 = (struct test_case3*)stuctP; break;
		default:
			break;
	}

	//test_case *date =  (test_case*) stuctDate;
	


	//struct test_case *test = (struct test_case *) malloc (sizeof(test_case) * line);

	//while(1)
	//{
	//	ch = fgetc(fp);
	//	if(ch == EOF) break;
	//	
	//	fscanf(fp, "%s %u %d",test[i].input, &test[i].prediction, &test[i].returnValue);
	//	//printf("%s %d %d",input, prediction, returnValue);
	//	i++;
	//}

	return 0;

}
//struct test_case *a;
//int inet_aton(const char *cp, unsigned int *lp)
//{
//	int dots = 0;
//    unsigned long acc = 0, addr = 0;
//	
//    do{
//
//		char cc = *cp;
//		
//		switch(cc) 
//		{
//			case '0':
//			case '1':
//			case '2':
//			case '3':
//			case '4':
//			case '5':
//			case '6':
//			case '7':
//			case '8':
//			case '9':
//				acc = acc * 10 + (cc - '0');
//				break;
//					
//			case '.':
//				if (++dots > 3)
//				{
//					return -1; //ip地址长度错误
//				}
//					
//			case '\0':
//				if (acc > 255) 
//				{
//					return -2; //ip地址数值错误
//				}
//				addr = addr << 8 | acc; 
//				acc = 0;
//				break;
//					
//			default:
//				return -3; //非法字符
//		}
//
//    } while(*cp++) ;
//	
//    // 规范化ip地址
//    if (dots < 3)
//	{
//		addr <<= 8 * (3 - dots) ;
//    }
//	
//	*lp = addr;
//	
//    return 0; //正常返回0
//}
//
//int main()
//{
//	struct test_case2  *case2 = NULL;
//	test(2,(void*)case2, (void*)inet_aton, "inet_aton.txt");
//	//printf("%d", sizeof(*a));
//	return 0;
//}