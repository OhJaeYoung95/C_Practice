#include <stdio.h>
// ����1 �����͸� �̿��� �迭�� ��� ������
void Practice1();
void ReverseArray(int*, int);

// ����2 �����͸� �̿��� �迭�� �ִ밪�� �ּҰ� ã��
void Practice2();
void FindMaxMin(int*, int, int*, int*);

// ����3 �����͸� �̿��� �迭�� �߰��� ã��
void Practice3();
void Sort(int* ,int);
double FindMedian(int*, int);

// ����4 �����͸� �̿��� �迭�� ��� ���
void Practice4();
int FindMode(int*, int);

// ����5 �����͸� �̿��� �迭�� �� ����� �Ÿ� ���
void Practice5();
int calculateDistance(int*, int, int, int);

// ����6 �����͸� �̿��� �迭�� �� ��� ��ȯ
void Practice6();
void SwapElements(int*, int, int, int);

// ����7 �����͸� �̿��� �迭�� Ư�� �� ã��
void Practice7();
int Contains(int*, int, int);

// ����8 �����͸� �̿��� �迭�� Ư�� ���� ���� ���
void Practice8();
int CountElement(int*, int, int);

// ����9 �����͸� �̿��� �迭�� Ư�� ������ �� ���
void Practice9();
int CalculateRangeSum(int*, int, int, int);

// ����10 �����͸� �̿��� �迭�� Ư�� �� ����
void Practice10();
int RemoveElement(int*, int, int);
void RemoveSort(int* arr, int size);


int main()
{
	Practice10();

	return 0;
}

// ����1 �����͸� �̿��� �迭�� ��� ������
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

// ����2 �����͸� �̿��� �迭�� �ִ밪�� �ּҰ� ã��
void Practice2()
{
	int arr[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int arrLen = sizeof(arr) / sizeof(int);
	int max = 0;
	int min = arr[0];
	FindMaxMin(arr, arrLen, &max, &min);
	printf("�ִ밪 : %d �ּҰ� : %d", max, min);
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

// ����3 �����͸� �̿��� �迭�� �߰��� ã��
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

// ����4 �����͸� �̿��� �迭�� ��� ���
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

// ����5 �����͸� �̿��� �迭�� �� ����� �Ÿ� ���
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

// ����6 �����͸� �̿��� �迭�� �� ��� ��ȯ
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
		printf("�ƹ��͵� ���� �ʴ´�\n");
		return;
	}
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

// ����7 �����͸� �̿��� �迭�� Ư�� �� ã��
void Practice7()
{
	int arr[5] = { 1,2,3,4,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("0 : ����X 1 : ����O\n");
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

// ����8 �����͸� �̿��� �迭�� Ư�� ���� ���� ���
void Practice8()
{
	int arr[15] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("Ư�� ���� ���� : %d\n",CountElement(arr, arrLen, 5));
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

// ����9 �����͸� �̿��� �迭�� Ư�� ������ �� ���
void Practice9()
{
	int arr[5] = {0,1,2,3,4};
	int arrLen = sizeof(arr) / sizeof(int);
	printf("�հ� : %d\n", CalculateRangeSum(arr, 0, 4, arrLen));
}
int CalculateRangeSum(int* arr, int start, int end, int arrLen)
{
	int sum = 0;
	if (start > end || start < 0 || end < 0 ||
		start >= arrLen || end>= arrLen)
	{
		printf("�ε��� ���� �缳��\n");
		return 0;
	}

	for (int i = start; i <= end; i++)
	{
		sum += arr[i];
	}
	return sum;
}

// ����10 �����͸� �̿��� �迭�� Ư�� �� ����
void Practice10()
{
	int arr[7] = { 1,1,2,1,3,1 ,5 };
	int arrLen = sizeof(arr) / sizeof(int);
	printf("���� : ");
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