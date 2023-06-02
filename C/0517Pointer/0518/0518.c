#include <stdio.h>

int main()
{
	int num1 = 10, num2 = 20, num3 = 30;
	int* ptr[3] = { &num1, &num2, &num3 };

	for (int i = 0; i < 3; i++)
	{
		printf("%d \n", *ptr[i]);	// 10 20 30 Ãâ·Â
	}

	return 0;
}