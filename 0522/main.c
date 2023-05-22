# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
void Test()
{
	int ch1, ch2;
	scanf("%c", &ch1);

	ch1 = getchar();
	ch2 = fgetc(stdin);

	putchar(ch1);
	fputc(ch2, stdout);

}
void Practice1();
void Practice2();
void Practice3();
void Practice4();

int main()
{
	Practice4();

	return 0;
}

void Practice1()
{
	printf("알파벳 문자 하나 입력 : ");
	int ch1 = getchar();
	int value = 'a' - 'A';

	if (ch1 >= 'a' && ch1 <= 'z')
		putchar(ch1 - value);
	else if (ch1 >= 'A' && ch1 <= 'Z')
		putchar(ch1 + value);
	else
		printf("오류");
}

void Practice2()
{
	char input[10] = { 0 };
	int sum = 0;
	gets(input);
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] > '0' && input[i] <= '9')
			sum += input[i] - '0';
	}
	printf("%d", sum);
}

void Practice3()
{
	char str1[20];
	char str2[30];
	char str3[40];

	fgets(str1, strlen(str1), stdin);
	fgets(str2, strlen(str2), stdin);

	strcpy(str3, str1);
	str3[strlen(str3) - 1] = 0;
	strcat(str3, str2);
	str3[strlen(str3) - 1] = 0;
	puts(str3);
	printf("%d", strlen(str3));
}

void Practice4()
{
	char input1[1024];
	char input2[1024];
	char name1[1024];
	char name2[1024];
	char strAge1[1024];
	char strAge2[1024];
	int spaceIndex1 = 0;
	int spaceIndex2 = 0;
	fgets(input1, strlen(input1), stdin);
	fgets(input2, strlen(input2), stdin);

	while (input1[spaceIndex1] != ' ')
		spaceIndex1++;
	while (input2[spaceIndex2] != ' ')
		spaceIndex2++;

	if (spaceIndex1 != spaceIndex2)
		printf("이름이 다르다\n");
	else
	{
		strncpy(name1, input1, spaceIndex1);
		strncpy(name2, input2, spaceIndex2);
		if (strcmp(name1, name2))
			printf("이름이 같다\n");
	}

	strncpy(strAge1, input1 + spaceIndex1 + 1, strlen(input1) - 1);
	strncpy(strAge2, input2 + spaceIndex2 + 1, strlen(input2) - 1);
	printf("age1 : %s\n", strAge1);
	printf("age2 : %s\n", strAge2);
	int age1 = atoi(strAge1);
	int age2 = atoi(strAge2);
	if (age1 == age2)
		printf("나이도 같다\n");
	else
		printf("나이는 다르다\n");





}