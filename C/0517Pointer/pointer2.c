#include <stdio.h>
// 문제1 C언어를 사용하여 배열을 복사하는 함수를 작성해보세요.
void Practice1();
void copyArray(int* arr, int* arrCopy, int size);

// 문제2 C언어를 사용하여 두 배열의 내용을 교환하는 함수를 작성해보세요.
void Practice2();
void SwapArrays(int*, int*, int);

// 문제3 포인터를 이용한 배열의 특정 범위의 요소 뒤집기
void Practice3();
void ReverseRange(int*, int, int);

// 문제4 포인터를 이용한 배열의 특정 위치에 값 삽입
void Practice4();
int insertAt(int* arr, int size, int index, int value);

// 문제5 포인터를 이용한 배열의 특정 위치의 값 제거
void Practice5();
int RemoveAt(int* arr, int size, int index);

// 문제6 포인터를 이용한 배열의 특정 범위의 평균 계산
void Practice6();
double calculateRangeAverage(int* arr, int start, int end);

// 문제7 포인터를 이용한 배열의 특정 값보다 큰 요소의 개수 계산
void Practice7();
int countGreater(int* arr, int size, int value);

// 문제8포인터를 이용한 배열의 특정 값보다 작은 요소의 개수 계산
void Practice8();
int countLess(int* arr, int size, int value);

// 문제9 문제: 포인터를 이용한 배열의 특정 값보다 큰 첫 번째 요소 찾기
void Practice9();
int findFirstGreater(int* arr, int size, int value);

// 문제10 포인터를 이용한 배열의 특정 값의 마지막 위치 찾기
void Practice10();
int findLast(int* arr, int size, int value);


int main(void)
{
    Practice10();
    return 0;
}

// 문제1 C언어를 사용하여 배열을 복사하는 함수를 작성해보세요.
void Practice1()
{
    int arr[5] = { 0 };
    int arrCopy[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arrCopy) / sizeof(int);
    printf("원본 배열 : ");
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

// 문제2 C언어를 사용하여 두 배열의 내용을 교환하는 함수를 작성해보세요.
void Practice2()
{
    int arr1[5] = { 1, 2, 3, 4, 5 };
    int arr2[5] = { 5, 4, 3, 2, 1 };
    int arrLen = sizeof(arr1) / sizeof(int);
    printf("원본 배열1 : ");
    for (int i = 0; i < arrLen; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    printf("원본 배열2 : ");
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

// 문제3 포인터를 이용한 배열의 특정 범위의 요소 뒤집기
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

// 문제4 포인터를 이용한 배열의 특정 위치에 값 삽입
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

// 문제5 포인터를 이용한 배열의 특정 위치의 값 제거
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

// 문제6 포인터를 이용한 배열의 특정 범위의 평균 계산
void Practice6()
{
    int arr[5] = { 1,2,3,4,5 };
    printf("평균 : %f",calculateRangeAverage(arr, 0, 2));
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

// 문제7 포인터를 이용한 배열의 특정 값보다 큰 요소의 개수 계산
void Practice7()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d보다 큰값의 개수 :%d",4 ,countGreater(arr, arrLen, 4));
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

// 문제8 포인터를 이용한 배열의 특정 값보다 작은 요소의 개수 계산
void Practice8()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d보다 작은값의 개수 :%d", 4, countLess(arr, arrLen, 4));
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

// 문제9 포인터를 이용한 배열의 특정 값보다 큰 첫 번째 요소 찾기
void Practice9()
{
    int arr[5] = { 1,2,3,4,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("큰 첫번째 요소 : %d번째 인덱스", findFirstGreater(arr, arrLen, 4));
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

// 문제10 포인터를 이용한 배열의 특정 값의 마지막 위치 찾기
void Practice10()
{
    int arr[10] = { 1,1,2,2,3,3,4,4,5,5 };
    int arrLen = sizeof(arr) / sizeof(int);
    printf("%d번째 인덱스", findLast(arr, arrLen, 4));
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