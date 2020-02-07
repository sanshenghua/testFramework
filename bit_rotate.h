#ifndef BIT_ROTATE_H
#define BIT_ROTATE_H

#define BITS 8 * sizeof(unsigned int)
#define BIT_ROTATE(n, i) ((n) >> (i)) | ((n) << ((BITS) - (i)))

#endif
//int main()
//{
//	unsigned int v1 = 0xffff1122u;
//
//	printf("%0x\n", BIT_ROTATE(v1,2));
//
//}

