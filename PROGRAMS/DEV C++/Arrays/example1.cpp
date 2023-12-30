
#include<stdio.h>
#include<string.h>
#define SIZE 30
int main(void)
{
	char st1[SIZE]="computer",st2[SIZE]="programming";
	int i;

	printf("\n\nString st1 :\n");
	puts(st1);
	printf("\n\nString st2 :\n");
	puts(st2);

	strncpy(st1,st2, 3);
	printf("\n\nString st1 :\n");
	puts(st1);

	printf("\n\nString st2 :\n");
	puts(st2);
	return 0;
}


