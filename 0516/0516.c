#include <stdio.h>

int main()
{
	char str1[] = "My String";
	char* str2 = "Your String";
	printf("%s %s \n", str1, str2);

	//str1 = "Our String";	컴파일 오류발생
	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'X';
	//str2[0] = 'X';	컴파일 오류 발생
	printf("%s %s\n", str1, str2);

	return 0;
}
