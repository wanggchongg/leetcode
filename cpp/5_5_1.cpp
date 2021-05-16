#include <stdio.h>

int main()
{
	unsigned char a=0xA5; //由于寄存器是16位的,所以a在寄存器中表示=0000 0000 1010 0101
	unsigned char b = ~a>>4+1; //先取反，再右移5位；b在寄存器中表示为：0000 0111 1111 1010
	printf("b=%d\n", b); //b=250
	return 0;
}