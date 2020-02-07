#include "inet_aton.h"

int inet_aton(const char *cp, unsigned int *lp)
{
	int dots = 0;
    unsigned long acc = 0, addr = 0;
	
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
				acc = acc * 10 + (cc - '0');
				break;
					
			case '.':
				if (++dots > 3)
				{
					return -1; //ip地址长度错误
				}
					
			case '\0':
				if (acc > 255) 
				{
					return -2; //ip地址数值错误
				}
				addr = addr << 8 | acc; 
				acc = 0;
				break;
					
			default:
				return -3; //非法字符
		}

    } while(*cp++) ;
	
    // 规范化ip地址
    if (dots < 3)
	{
		addr <<= 8 * (3 - dots) ;
    }
	
	*lp = addr;
	
    return 0; //正常返回0
}
