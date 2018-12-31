#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
	char c;
	printf("Ban hay nhap ki tu cho c : ");
	c = getchar();
	printf("Ky tu ban vua nhap la : %c \n",c);
	return 0;
}