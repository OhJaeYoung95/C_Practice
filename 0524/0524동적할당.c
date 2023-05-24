#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문제1
void Practice1()
{
	char* str;
	int strLen = 0;
	//char *str1;
	printf("입력할 문자열의 최대 길이 입력 : ");
	scanf("%d ", &strLen);

	str = (char*)malloc(sizeof(char) * (strLen+1));

	gets(str);

	for (int i = strLen; i >= 0; i--)
	{
		printf("%c", str[i]);
	}

	free(str);
	str = NULL;
}

// 문제2
void Practice2()
{
	char str2[20];
	int len = 0;
	int count = 0;
	printf("문자열의 길이 입력 : ");
	scanf("%d ", &len);

	char* str1 = (char)malloc(sizeof(char) * len + 1);
	memset(str1, 0, len + 1);

	gets(str1);

	for (int i = len; i >= 0; i--)
	{

		if (str2[count] = getchar() != ' ')
		{
			 
			count++;
			continue;
		}


		printf("%c", str1[i]);
	}

	free(str1);
	str1 = NULL;
}

int main()
{
	Practice1();

	return 0;
}