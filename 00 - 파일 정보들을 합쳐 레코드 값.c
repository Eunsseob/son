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

people_info people[MAX]; //������ �Է¹��� �������� ����

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
		fprintf(stdout, "�̸�: %s ����: %d ����: %.1lf\n", people[i].name, people[i].age, people[i].score);
		fprintf(p, "�̸�: %s ����: %d ����: %.1lf\n", people[i].name, people[i].age, people[i].score);
	}
	
	fclose(p);
	system("notepad.exe total_list.txt"); //�̸�, ����, ������ ��ģ ����

	return 0;
}

void get_name(FILE* p)
{
	p = fopen("name_list.txt", "r"); //�̸� ������ �ִ� ����
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
	p = fopen("age_list.txt", "r"); //���� ������ �ִ� ����

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
	p = fopen("score_list.txt", "r"); //���� ������ �ִ� ����

	int i = 0;

	while (!feof(p))
	{
		fscanf(p, "%lf", &people[i].score);
		i++;
	}
	
	fclose(p);
}