#include <stdio.h>

int main() {
    FILE* file;
    int num = 42;
    float f = 3.14;
    char str[] = "Hello, World!";

    // ���� ���� (���� ���)
    file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("���� ���� ����\n");
        return 1;
    }

    // ���Ͽ� ������ ����
    fprintf(file, "����: %d\n", num);
    fprintf(file, "�Ǽ�: %.2f\n", f);
    fprintf(file, "���ڿ�: %s\n", str);

    // ���� �ݱ�
    fclose(file);

    return 0;
}
