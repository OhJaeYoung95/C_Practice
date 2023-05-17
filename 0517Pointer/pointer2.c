#include <stdio.h>
// ����1 C�� ����Ͽ� �迭�� �����ϴ� �Լ��� �ۼ��غ�����.
void Practice1();
void copyArray(int* arr, int* arrCopy, int size);

// ����2 C�� ����Ͽ� �� �迭�� ������ ��ȯ�ϴ� �Լ��� �ۼ��غ�����.
void Practice2();
void SwapArrays(int*, int*, int);

// ����3 �����͸� �̿��� �迭�� Ư�� ������ ��� ������
void Practice3();
void ReverseRange(int*, int, int);

// ����4 �����͸� �̿��� �迭�� Ư�� ��ġ�� �� ����
void Practice4();
int insertAt(int* arr, int size, int index, int value);

// ����5 �����͸� �̿��� �迭�� Ư�� ��ġ�� �� ����
void Practice5();
int RemoveAt(int* arr, int size, int index);

// ����6 �����͸� �̿��� �迭�� Ư�� ������ ��� ���
void Practice6();
double calculateRangeAverage(int* arr, int start, int end);

// ����7 �����͸� �̿��� �迭�� Ư�� ������ ū ����� ���� ���
void Practice7();
int countGreater(int* arr, int size, int value);

// ����8�����͸� �̿��� �迭�� Ư�� ������ ���� ����� ���� ���
void Practice8();
int countLess(int* arr, int size, int value);

// ����9 ����: �����͸� �̿��� �迭�� Ư�� ������ ū ù ��° ��� ã��
void Practice9();
int findFirstGreater(int* arr, int size, int value);

// ����10 �����͸� �̿��� �迭�� Ư�� ���� ������ ��ġ ã��
void Practice10();
int findLast(int* arr, int size, int value);


int main(void)
{
    Practice10();
    return 0;
}

// ����1 C�� ����Ͽ� �迭�� �����ϴ� �Լ��� �ۼ��غ�����.
void Practice1()
{
    int arr[5] = { 0 };
    int arrCopy[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arrCopy) / sizeof(int);
    printf("���� �迭 : ");
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr[i]);
    printf("\n");
    copyArray(arr, arrCopy, arrLen);
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr[i]);


}
void copyArray(int* arr, int* arrCopy, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = arrCopy[i];
    }
}

// ����2 C�� ����Ͽ� �� �迭�� ������ ��ȯ�ϴ� �Լ��� �ۼ��غ�����.
void Practice2()
{
    int arr1[5] = { 1, 2, 3, 4, 5 };
    int arr2[5] = { 5, 4, 3, 2, 1 };
    int arrLen = sizeof(arr1) / sizeof(int);
    printf("���� �迭1 : ");
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    printf("���� �迭2 : ");
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    SwapArrays(arr1, arr2, arrLen);
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr2[i]);

}
void SwapArrays(int* arr1, int* arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

// ����3 �����͸� �̿��� �迭�� Ư�� ������ ��� ������
void Practice3()
{
    int arr[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    ReverseRange(arr,1, 4);
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr[i]);

}
void ReverseRange(int* arr, int start, int end)
{
    //if (end - start == 1)
    //{
    //    int temp = arr[start];
    //    arr[start] = arr[end];
    //    arr[end] = temp;
    //    return;
    //}
    //for (int i = 0; i <= end/2; i++)
    //{
    //    int temp = arr[start + i];
    //    arr[start + i] = arr[end - i];
    //    arr[end - i] = temp;
    //}
    for (int i = 0; i < (end - start) / 2 + 1; i++)
    {
        int temp = arr[start + i];
        arr[start + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

// ����4 �����͸� �̿��� �迭�� Ư�� ��ġ�� �� ����
void Practice4()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int arrLen = sizeof(arr) / sizeof(int);
    insertAt(arr, arrLen, 2, 10);
    for (int i = 0; i < arrLen; i++)
    {
        printf("%d ", arr[i]);
    }
}
int insertAt(int* arr, int size, int index, int value)
{
    if (index == size - 1)
    {
        arr[index] = value;
        return size;
    }
    else
    {
        for (int i = size - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        return size;
    }
}

// ����5 �����͸� �̿��� �迭�� Ư�� ��ġ�� �� ����
void Practice5()
{
    int arr[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    int arrLen2 = RemoveAt(arr, arrLen, 4);
    for (int i = 0; i < arrLen2; i++)
    {
        printf("%d ", arr[i]);
    }
}
int RemoveAt(int* arr, int size, int index)
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    return size - 1;
}

// ����6 �����͸� �̿��� �迭�� Ư�� ������ ��� ���
void Practice6()
{
    int arr[5] = { 1,2,3,4,5 };
    printf("��� : %f",calculateRangeAverage(arr, 0, 2));
}
double calculateRangeAverage(int* arr, int start, int end)
{
    double sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return (double)(sum / (end - start + 1));
}

// ����7 �����͸� �̿��� �迭�� Ư�� ������ ū ����� ���� ���
void Practice7()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d���� ū���� ���� :%d",4 ,countGreater(arr, arrLen, 4));
}
int countGreater(int* arr, int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > value)
            count++;
    }
    return count;
}

// ����8 �����͸� �̿��� �迭�� Ư�� ������ ���� ����� ���� ���
void Practice8()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d���� �������� ���� :%d", 4, countLess(arr, arrLen, 4));
}
int countLess(int* arr, int size, int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < value)
            count++;
    }
    return count;

}

// ����9 �����͸� �̿��� �迭�� Ư�� ������ ū ù ��° ��� ã��
void Practice9()
{
    int arr[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("ū ù��° ��� : %d��° �ε���", findFirstGreater(arr, arrLen, 4));
}
int findFirstGreater(int* arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (value < arr[i])
            return i;
    }
    return -1;
}

// ����10 �����͸� �̿��� �迭�� Ư�� ���� ������ ��ġ ã��
void Practice10()
{
    int arr[10] = { 1,1,2,2,3,3,4,4,5,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d��° �ε���", findLast(arr, arrLen, 4));
}
int findLast(int* arr, int size, int value)
{
    int lastIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            lastIndex = i;
    }
    return lastIndex;
}