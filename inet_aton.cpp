#include<stdio.h>
#include "inet_aton.h"

#define SUCCESS 0
#define LENGTH_ERROR -1
#define VALUE_ERROR -2
#define INVAILD_CHAR -3

int inet_aton(const char *cp, unsigned int *lp)
{
	int dots = 0;
    unsigned long singleSum = 0, totalSum = 0;
	
    do{
		char cc = *cp;
		
		switch(cc) 
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				singleSum = singleSum * 10 + (cc - '0');
				break;
					
			case '.':
				if (++dots > 3)
				{
					return LENGTH_ERROR; //ip��ַ���ȴ���
				}
					
			case '\0':
				if (singleSum > 255) 
				{
					return VALUE_ERROR; //ip��ַ��ֵ����
				}
				totalSum = totalSum << 8 | singleSum; 
				singleSum = 0;
				break;
					
			default:
				return INVAILD_CHAR; //�Ƿ��ַ�
		}

    } while(*cp++) ;
	
    // �淶��ip��ַ
    if (dots < 3)
	{
		totalSum <<= 8 * (3 - dots) ;
    }
	
	*lp = totalSum;
	
    return SUCCESS; //��������0
}
