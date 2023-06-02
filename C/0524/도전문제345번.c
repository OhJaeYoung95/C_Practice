#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 문제3
typedef struct
{
	double real;
	double imag;
} ComplexNumber;
ComplexNumber AddComplexNumber(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	result.real = num1.real + num2.real;
	result.imag = num1.imag + num2.imag;

	return result;
}
ComplexNumber MulComplexNumber(ComplexNumber num1, ComplexNumber num2)
{
	ComplexNumber result;
	result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
	result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
	return result;
}
void Practice3()
{
	ComplexNumber cn1;
	ComplexNumber cn2;

	
	printf("복소수 입력 1[실수 허수] : ");
	scanf("%lf %lf", &cn1.real, &cn1.imag);
	printf("복소수 입력 2[실수 허수] : ");
	scanf("%lf %lf", &cn2.real, &cn2.imag);


	ComplexNumber addResult = AddComplexNumber(cn1, cn2);
	ComplexNumber mulResult = MulComplexNumber(cn1, cn2);

	printf("합의 결과] 실수 : %f, 허수 : %f\n", addResult.real, addResult.imag);
	printf("곱의 결과] 실수 : %f, 허수 : %f\n", mulResult.real, mulResult.imag);
}

// 문제 4

void CreateFile()
{
	char string[50];
	FILE* file = fopen("text.txt", "wt");
	if (file == NULL)
	{
		puts("파일 오류");
		return -1;
	}
	puts(string);
	fprintf(file, "%s", string);
	

	fclose(file);
}

void Practice4()
{
	CreateFile();
	//fscanf(file, "%s", string);

}

int main()
{
	Practice4();
	return 0;
}