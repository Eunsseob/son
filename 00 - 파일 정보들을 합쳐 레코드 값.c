#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 3

typedef struct people_info {
	char name[4];
	int age;
	double score;
} people_info;

void get_name(FILE* p);
void get_age(FILE* p);
void get_score(FILE* p);

people_info people[MAX]; //정보를 입력받을 전역변수 생성

int main(void)
{
	FILE* p = NULL;
	int i;

	get_name(p);
	get_age(p);
	get_score(p);

	p = fopen("total_list.txt", "a+");

	for (i = 0; i < MAX; i++)
	{
		fprintf(stdout, "이름: %s 나이: %d 성적: %.1lf\n", people[i].name, people[i].age, people[i].score);
		fprintf(p, "이름: %s 나이: %d 성적: %.1lf\n", people[i].name, people[i].age, people[i].score);
	}
	
	fclose(p);
	system("notepad.exe total_list.txt"); //이름, 나이, 성적을 합친 파일

	return 0;
}

void get_name(FILE* p)
{
	p = fopen("name_list.txt", "r"); //이름 정보만 있는 파일
	int i = 0;

	while (!feof(p))
	{
		fscanf(p, "%s", &people[i].name);
		i++;
	}
	
	fclose(p);
}

void get_age(FILE* p)
{
	p = fopen("age_list.txt", "r"); //나이 정보만 있는 파일

	int i = 0;

	while (!feof(p))
	{
		fscanf(p, "%d", &people[i].age);
		i++;
	}

	fclose(p);
}

void get_score(FILE* p)
{
	p = fopen("score_list.txt", "r"); //성적 정보만 있는 파일

	int i = 0;

	while (!feof(p))
	{
		fscanf(p, "%lf", &people[i].score);
		i++;
	}
	
	fclose(p);
}