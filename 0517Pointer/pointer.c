#include <stdio.h>
// 문제1 포인터를 이용한 배열의 요소 뒤집기
void Practice1();
void ReverseArray(int*, int);

// 문제2 포인터를 이용한 배열의 최대값과 최소값 찾기
void Practice2();
void FindMaxMin(int*, int, int*, int*);

// 문제3 포인터를 이용한 배열의 중간값 찾기
void Practice3();
void Sort(int* ,int);
double FindMedian(int*, int);

// 문제4 포인터를 이용한 배열의 모드 계산
void Practice4();
int FindMode(int*, int);

// 문제5 포인터를 이용한 배열의 두 요소의 거리 계산
void Practice5();
int calculateDistance(int*, int, int, int);

// 문제6 포인터를 이용한 배열의 두 요소 교환
void Practice6();
void SwapElements(int*, int, int, int);

// 문제7 포인터를 이용한 배열의 특정 값 찾기
void Practice7();
int Contains(int*, int, int);

// 문제8 포인터를 이용한 배열의 특정 값의 개수 계산
void Practice8();
int CountElement(int*, int, int);

// 문제9 포인터를 이용한 배열의 특정 범위의 합 계산
void Practice9();
int CalculateRangeSum(int*, int, int, int);

// 문제10 포인터를 이용한 배열의 특정 값 제거
void Practice10();
int RemoveElement(int*, int, int);
void RemoveSort(int* arr, int size);


int main()
{
	Practice10();

	return 0;
}

// 문제1 포인터를 이용한 배열의 요소 뒤집기
void Practice1()
{
	int arr[5] = { 1,2,3,4,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	ReverseArray(arr, arrLen);
	for (int i = 0; i < arrLen; i++)
	{
		printf("%d", arr[i]);
	}
}
void ReverseArray(int* input, int inputLen)
{
	for (int i = 0; i < inputLen - 1; i++)
	{
		for (int j = 0; j < (inputLen - i - 1); j++)
		{
			if (input[j] < input[j + 1])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}
}

// 문제2 포인터를 이용한 배열의 최대값과 최소값 찾기
void Practice2()
{
	int arr[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int arrLen = sizeof(arr) / sizeof(int);
	int max = 0;
	int min = arr[0];
	FindMaxMin(arr, arrLen, &max, &min);
	printf("최대값 : %d 최소값 : %d", max, min);
}
void FindMaxMin(int* arr, int size, int* max, int* min)
{
	*max = *min = arr[0];

	for (int i = 1; i < size; i++)
	{
		*max = *max < arr[i] ? arr[i] : *max;
		*min = *min < arr[i] ? *min : arr[i];
	}

}

// 문제3 포인터를 이용한 배열의 중간값 찾기
void Practice3()
{
	int arr[5] = { 2,1,1,8,4 };
	int arrLen = sizeof(arr) / sizeof(int);
	Sort(arr, arrLen);
	printf("%lf", FindMedian(arr, arrLen));

}
void Sort(int* arr, int arrLen)
{
	for (int i = 0; i < arrLen-1; i++)
	{
		for (int j = 0; j < arrLen-i-1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
double FindMedian(int* arr, int size)
{
	if (size % 2 == 0)
	{
		double sum = arr[size / 2] + arr[(size / 2) - 1];
		sum = sum / 2;
		return sum;
	}
	else
	{
		return arr[size / 2];
	}
}

// 문제4 포인터를 이용한 배열의 모드 계산
void Practice4()
{
	int arr[15] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("%d", FindMode(arr, arrLen));
}
int FindMode(int* arr, int size)
{
	int mode = arr[0];
	int maxCount = 0;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				++count;
			}
		}
		if (maxCount < count)
		{
			maxCount = count;
			mode = arr[i];
		}
	}
	return mode;
}

// 문제5 포인터를 이용한 배열의 두 요소의 거리 계산
void Practice5()
{
	int arr[10] = { 11, 2, 3, 4, 5, 6, 10, 8, 1, 0 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("%d", calculateDistance(arr, arrLen, 8, 1));
}
int calculateDistance(int* arr, int size, int element1, int element2)
{
	int* dist1 = 0;
	int* dist2 = 0;
	int* result = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == element1 && dist1 != 0)
			return -1;
		else if (*(arr + i) == element2 && dist2 != 0)
			return -1;

		if (*(arr + i) == element1 && dist1 == 0)
			dist1 = arr + i;
		else if (*(arr + i) == element2&& dist2 == 0)
			dist2 = arr + i;
	}
	if (dist2 > dist1)
	{
		int* temp = dist2;
		dist2 = dist1;
		dist1 = temp;
	}
	result = dist1 - dist2;
	return result;
}

// 문제6 포인터를 이용한 배열의 두 요소 교환
void Practice6()
{
	int arr[5] = { 1,2,3,4,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	SwapElements(arr, arrLen, 0, 2);
	
	for (int i = 0; i < arrLen; i++)
	{
		printf("%d ", arr[i]);
	}
}
void SwapElements(int* arr, int size, int index1, int index2)
{
	if ((index1 < 0 || index1 >= size ||
		index2 < 0 || index2 >= size))
	{
		printf("아무것도 하지 않는다\n");
		return;
	}
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

// 문제7 포인터를 이용한 배열의 특정 값 찾기
void Practice7()
{
	int arr[5] = { 1,2,3,4,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("0 : 포함X 1 : 포함O\n");
	printf("%d", Contains(arr, arrLen, 1));
}
int Contains(int* arr, int size, int element)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
			return 1;
	}
	return 0;
}

// 문제8 포인터를 이용한 배열의 특정 값의 개수 계산
void Practice8()
{
	int arr[15] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("특정 값의 개수 : %d\n",CountElement(arr, arrLen, 5));
}
int CountElement(int* arr, int size, int element)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
			count++;
	}
	return count;
}

// 문제9 포인터를 이용한 배열의 특정 범위의 합 계산
void Practice9()
{
	int arr[5] = {0,1,2,3,4};
	int arrLen = sizeof(arr) / sizeof(int);
	printf("합계 : %d\n", CalculateRangeSum(arr, 0, 4, arrLen));
}
int CalculateRangeSum(int* arr, int start, int end, int arrLen)
{
	int sum = 0;
	if (start > end || start < 0 || end < 0 ||
		start >= arrLen || end>= arrLen)
	{
		printf("인덱스 범위 재설정\n");
		return 0;
	}

	for (int i = start; i <= end; i++)
	{
		sum += arr[i];
	}
	return sum;
}

// 문제10 포인터를 이용한 배열의 특정 값 제거
void Practice10()
{
	int arr[7] = { 1,1,2,1,3,1 ,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("원본 : ");
	for (int i = 0; i < arrLen; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int removeArray = RemoveElement(arr, arrLen, 1);
	for (int i = 0; i < arrLen- removeArray; i++)
	{
		printf("%d ", arr[i]);
	}
}
int RemoveElement(int* arr, int size, int element)
{
	int removeCount = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
		{
			arr[i] = 0;
			removeCount++;
		}
	}
	RemoveSort(arr, size);

	//for (int i = 0; i < removeCount; i++)
	//{
	//	*(arr + 1) = NULL;
	//}
	return removeCount;
}
void RemoveSort(int* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] == 0)
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}