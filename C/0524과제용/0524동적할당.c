#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//// ����1
//void Practice1()
//{
//	char* str;
//	int strLen = 0;
//	//char *str1;
//	printf("�Է��� ���ڿ��� �ִ� ���� �Է� : ");
//	scanf("%d ", &strLen);
//
//	str = (char*)malloc(sizeof(char) * (strLen+1));
//	gets(str);
//
//	for (int i = strlen(str); i >= 0; i--)
//	{
//		printf("%c", str[i]);
//	}
//
//	free(str);
//	str = NULL;
//}
//
//// ����2
void Practice2()
{
	int len = 0;
	int count = 0;
	printf("���ڿ��� ���� �Է� : ");
	scanf("%d ", &len);

	char* str = (char*)malloc(sizeof(char) * len + 1);
	memset(str, 0, len + 1);

	fgets(str, sizeof(str), stdin);

	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	int i = 0;
	int j = 0;
	int slen = strlen(str);
	for (i = 0, j = slen - 1; i < j; i++, j--) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	//for (int i = 0; i < (slen-1) /2; i++)
	//{
	//	char temp = str[i];
	//	str[i] = str[slen - i - 1];
	//	str[slen - i - 1] = temp;
	//}

	printf("%s", str);

	//while ()
	//{
	//	if(str[i] == ' ')

	//}

	free(str);
	str = NULL;
}

int main()
{
	Practice2();

	return 0;
}

//#include <stdio.h>
//#include <string.h>

//void reverse_words(char* string) {
//    int i, j, k;
//    int length = strlen(string);
//
//    // ���ڿ� ��ü�� ������
//    for (i = 0, j = length - 1; i < j; i++, j--) {
//        char temp = string[i];
//        string[i] = string[j];
//        string[j] = temp;
//    }

    //// �� �ܾ ������
    //i = 0;
    //while (i < length) {
    //    // �ܾ��� ���� �ε��� ã��
    //    while (i < length && string[i] == ' ') {
    //        i++;
    //    }

    //    // �ܾ��� �� �ε��� ã��
    //    j = i;
    //    while (j < length && string[j] != ' ') {
    //        j++;
    //    }

    //    // �ܾ� ������
    //    for (k = i, j = j - 1; k < j; k++, j--) {
    //        char temp = string[k];
    //        string[k] = string[j];
    //        string[j] = temp;
    //    }

    //    i = j + 1;  // ���� �ܾ�� �̵�
    //}
//}

//int main() {
//    char string[100];
//
//    printf("���ڿ��� �Է��ϼ���: ");
//    fgets(string, sizeof(string), stdin);
//
//    // fgets�� ���� ����('\n')�� �Է¹����Ƿ� ����
//    if (string[strlen(string) - 1] == '\n') {
//        string[strlen(string) - 1] = '\0';
//    }
//
//    reverse_words(string);
//
//    printf("�ܾ ������ ���: %s\n", string);
//
//    return 0;
//}