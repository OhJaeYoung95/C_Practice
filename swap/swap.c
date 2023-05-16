#include <stdio.h>

//void Swap(int num1, int num2)
//{
//    int temp = num1;
//    num1 = num2;
//    num2 = temp;
//    printf("num1 : % d num2 : % d \n", num1, num2);
//}

void Swap(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;\
    printf("num1 : % d num2 : % d \n", *ptr1, *ptr2);

}


int main()
{
    int num1 = 10;
    int num2 = 20;
    printf("SwapÀü num1 : %d num2 : %d \n", num1, num2);

    Swap(&num1, &num2);
    printf("SwapÈÄ num1 : %d num2 : %d \n", num1, num2);
    return 0;
}