#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// 문제 1: 바이너리 파일을 생성하는 함수를 작성하시오.
void CreateBinaryFile(char* fileName);
void Practice1();
// 문제 2: 바이너리 파일에 정수를 쓰는 함수를 작성하시오.
void WriteIntToBinaryFile(char* fileName, int num);
void Practice2();
// 문제 3: 바이너리 파일에서 정수를 읽는 함수를 작성하시오.
int ReadIntFromBinaryFile(char* fileName);
void Practice3();
// 문제 4: 바이너리 파일에 정수 배열을 쓰는 함수를 작성하시오.
void WriteIntArrayToBinaryFile(char* fileName, int* arr, int size);
void Practice4();
// 문제 5: 바이너리 파일에서 정수 배열을 읽는 함수를 작성하시오.
void ReadIntArrayFromBinaryFile(char* fileName, int* arr, int size);
void Practice5();
// 문제 6: 바이너리 파일에 정수를 추가하는 함수를 작성하시오.
void AppendIntToBinaryFile(char* fileName, int num);
void Practice6();
// 문제 7: 바이너리 파일에 있는 정수의 개수를 세는 함수를 작성하시오.
int CountIntsInBinaryFile(char* fileName);
void Practice7();

// 문제 8: 바이너리 파일에서 최대 정수를 찾는 함수를 작성하시오.
int FindMaxIntInBinaryFile(char* fileName);
void Practice8();

// 문제 9: 바이너리 파일에 문자열을 쓰는 함수를 작성하시오.
void WriteStringToBinaryFile(char* fileName, char* str);
void Practice9();

// 문제 10: 바이너리 파일에서 문자열을 읽는 함수를 작성하시오.
void ReadStringFromBinaryFile(char* fileName, char* str);
void Practice10();

int main()
{
	Practice10();
	return 0;
}

// 문제 1: 바이너리 파일을 생성하는 함수를 작성하시오.
void CreateBinaryFile(char* fileName)
{
	FILE* file = fopen(fileName, "wb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}
	fclose(file);
}
void Practice1()
{
	CreateBinaryFile("BinaryFile.txt");
}

// 문제 2: 바이너리 파일에 정수를 쓰는 함수를 작성하시오.
void WriteIntToBinaryFile(char* fileName, int num)
{
	FILE* file = fopen("BinaryFile.txt", "wb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	fwrite(&num, sizeof(int), 1, file);

	fclose(file);

}
void Practice2()
{
	WriteIntToBinaryFile("BinaryFile.txt", 5);
}

// 문제 3: 바이너리 파일에서 정수를 읽는 함수를 작성하시오.
int ReadIntFromBinaryFile(char* fileName)
{
	int num;
	FILE* file = fopen(fileName, "rb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	int count = fread(&num, sizeof(int), 1, file);
	if (count < 1)
	{
		puts("바이너리 파일 읽기 실패");
		return -1;
	}
	fclose(file);
	return num;
}
void Practice3()
{
	int num = ReadIntFromBinaryFile("BinaryFile.txt");
	printf("%d", num);
}

// 문제 4: 바이너리 파일에 정수 배열을 쓰는 함수를 작성하시오.
void WriteIntArrayToBinaryFile(char* fileName, int* arr, int size)
{
	FILE* file = fopen(fileName, "wb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	fwrite(arr, sizeof(int), size, file);

	fclose(file);
}
void Practice4()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int arrLen = sizeof(arr) / sizeof(int);
	WriteIntArrayToBinaryFile("BinaryFile.txt", arr, arrLen);
}

// 문제 5: 바이너리 파일에서 정수 배열을 읽는 함수를 작성하시오.
void ReadIntArrayFromBinaryFile(char* fileName, int* arr, int size)
{
	FILE* file = fopen(fileName, "rb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}
	fread(arr, sizeof(int), size, file);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	fclose(file);
}
void Practice5()
{
	int arr[5];
	int arrLen = sizeof(arr) / sizeof(int);
	ReadIntArrayFromBinaryFile("BinaryFile.txt", arr, arrLen);
}

// 문제 6: 바이너리 파일에 정수를 추가하는 함수를 작성하시오.
void AppendIntToBinaryFile(char* fileName, int num)
{
	FILE* file = fopen(fileName, "ab");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	fwrite(&num, sizeof(int), 1, file);
	fclose(file);
}
void Practice6()
{
	int addNum = 100;
	AppendIntToBinaryFile("BinaryFile.txt", addNum);
}

// 문제 7: 바이너리 파일에 있는 정수의 개수를 세는 함수를 작성하시오.
int CountIntsInBinaryFile(char* fileName)
{
	int num;
	int count = 0;
	FILE* file = fopen(fileName, "rb");

	while (fread(&num, sizeof(int), 1, file) == 1)
		count++;
	return count;
}
void Practice7()
{
	int count = CountIntsInBinaryFile("BinaryFile.txt");
	printf("정수 개수 : %d", count);
}

// 문제 8: 바이너리 파일에서 최대 정수를 찾는 함수를 작성하시오.
int FindMaxIntInBinaryFile(char* fileName)
{
	int max = 0;
	int num;
	FILE* file = fopen(fileName, "rb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	while (fread(&num, sizeof(int), 1, file))
	{
		if (num > max)
			max = num;
	}
	fclose(file);
	return max;
}
void Practice8()
{
	int max = FindMaxIntInBinaryFile("BinaryFile.txt");
	printf("최대값 : %d\n", max);
}

// 문제 9: 바이너리 파일에 문자열을 쓰는 함수를 작성하시오.
void WriteStringToBinaryFile(char* fileName, char* str)
{
	FILE* file = fopen(fileName, "wb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}
	fwrite(str, sizeof(char), strlen(str)+1, file);
	fclose(file);
}
void Practice9()
{
	char str[20];
	gets(str);
	WriteStringToBinaryFile("BinaryFile.txt", str);
}

// 문제 10: 바이너리 파일에서 문자열을 읽는 함수를 작성하시오.
void ReadStringFromBinaryFile(char* fileName, char* str)
{
	int i = 0;
	char word;
	FILE* file = fopen(fileName, "rb");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}

	//fread(str, sizeof(char), sizeof(str), file);
	fread(str, sizeof(char), strlen(str), file);
	for (i = 0; i < strlen(str); i++)
	{
		word = fgetc(file);
		printf("%c", word);
	}
	fclose(file);
}
void Practice10()
{
	char str[20];
	ReadStringFromBinaryFile("BinaryFile.txt", str);
	//printf("%s", str);

}
