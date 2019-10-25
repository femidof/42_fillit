#include <stdio.h>

int main(void)
{
	char *str1 = "";
	char *str2 = NULL;
	char str3[] = {'\0'};
	char *str4 = 0;

	printf("%s", str1);
	printf("+++++++\n");
	printf("%s", str2);
	printf("\n+++++++\n");
	printf("%s", str3);
	printf("\n+++++++\n");
	printf("%s", str4);
}
