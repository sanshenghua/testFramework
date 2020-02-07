#include<stdio.h>

 int str2hex( const char str[],  char hexStr[], unsigned int sLen, unsigned int hLen)
 {
	 if((sLen == 0) || (2 * sLen > hLen))
	 {
		 hexStr[0] = '\0';
		 return -1;
	 }

     unsigned char highByte, lowByte;

     for (int i = 0; i < sLen; i++)
     {
         highByte = str[i] >> 4;
         lowByte = str[i] & 0x0f ;
         highByte += 0x30;
 
         if (highByte > 0x39)
		 {
			 hexStr[i * 2] = highByte + 0x07;
		 }              
         else
		 {
			 hexStr[i * 2] = highByte;
		 }            
 
         lowByte += 0x30;

         if (lowByte > 0x39)
		 {
			 hexStr[i * 2 + 1] = lowByte + 0x07;
		 }  
         else
		 {
			 hexStr[i * 2 + 1] = lowByte;
		 }
             
	 }

	  if(2 * sLen < hLen)
	  {
	 	 hexStr[2 * sLen] = '\0';
	  }

      return 0;
 }

 //int main(int argc, char const *argv[])
 //{
 //    char source[100]="H\0*l00";
 //    char dest[100]={0};
 //    str2hex(source,dest,5,12);
 //    puts(dest);
 //    return 0;
 //}//48656C6C6F00776F726C64
