#include <stdio.h>

struct employee
{
	char name[20];
	char id[20];
	int pay;
};

int main()
{
	struct employee man1;

	printf("종업원 이름 입력 : ");
	scanf("%s", man1.name);
	while (getchar() != '\n');
	printf("종업원 주민등록번호 입력 : ");
	fgets(man1.id, sizeof(man1.id), stdin);
	if (man1.id[(strlen(man1.id) - 1)] == '\n')
		man1.id[(strlen(man1.id) - 1)] = '\0';
	printf("종업원 월급 입력 : ");
	scanf("%d", &man1.pay);


	printf("이름 출력 : %s \n", man1.name);
	printf("주민등록번호 출력 : %s \n", man1.id);
	printf("월급 출력 : %d \n", man1.pay);
	return 0;
}