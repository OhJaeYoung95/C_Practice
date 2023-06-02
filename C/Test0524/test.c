#include <stdio.h>

int main() {
    FILE* file;
    int num = 42;
    float f = 3.14;
    char str[] = "Hello, World!";

    // 파일 열기 (쓰기 모드)
    file = fopen("data.txt", "w");

    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    // 파일에 데이터 쓰기
    fprintf(file, "정수: %d\n", num);
    fprintf(file, "실수: %.2f\n", f);
    fprintf(file, "문자열: %s\n", str);

    // 파일 닫기
    fclose(file);

    return 0;
}
