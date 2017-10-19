#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/*
������� ������� AverHt(������),
������������ ������� ���� ������ � ��������� ������ �����.
��� �������� �������� ������������ ���������(������, ���, ���, ����).
_CRT_SECURE_NO_WARNINGS
*/

// �������� ������� ��� ��� ���������(���������� �������: ���1, ���2, ���N.)
/*
char* GetList(const char* filename)
{
	FILE *file = fopen(filename, "r");
	int size = GetFileSize(file);
	char* list = (char *)malloc(sizeof(char) * (size + 1)); 
	fgets(list, (size + 1), file);	 
	puts(list);
	fclose(file);
	
	int count = 0;
	char* temp = list;
	while (*temp)
	{
		if (*temp == ',' || *temp == '.')
		{
			count++;
		}
		temp++;
	}
	
	
	printf("\n%s", definiteListPtr);
	return list;
}
*/
//���������!

// ��������� ������� ����� ��� ��������� ������ ��� ��� ������
int GetFileSize(FILE *file)
{
	int sizeFile = -1;

	if (file)
	{
		// ��������� ������� ������� ��������� � ����� (�������� �� ������).
		int currentOffset = ftell(file);
		// ������������� ��������� � ����� �� ��������� ������.
		fseek(file, 0, SEEK_END);
		// ��������� ������� ��������� � ��� ����� �������� ������ ����� � byte. 
		sizeFile = ftell(file);
		// ���������� ������� �������.
		fseek(file, currentOffset, SEEK_SET);
	}

	return sizeFile;
}


float GetAverageGrowth(people* hu, const int size, const int group)
{	
	unsigned int i = 0;
	unsigned int sum = 0;
	for (i = 0; i < size; i++)
	{
		if (hu[i].groupNumber == group)
		{
			sum += hu[i].growth;
		}
	}

	float avGrowth = sum / i;
		return avGrowth;
}

typedef struct
{
	char name[20];
	unsigned short groupNumber;
	unsigned short growth;
	unsigned short gender;
}people;	//���


int main()
{	
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(NULL)); //	�������������� ��������� ��������� ����� �� �������� �������
	
	//char* MaleNames = GetList("m.txt");
	//�������� ������� ���					
	
	
	
	unsigned int size = rand() % 20 + 1; // ���������� ����� � ������.
	printf("Debug: %d", size);
	people* human = (people*)malloc(sizeof(people) * size);
	// ��������� ��������� ������������ ����, ���������� ���
	// ��������� �� ������� ������ ��������, ����������� ��� ������ �����.
	
	unsigned int i = 0;
	for (i = 0; i < size; i++)
	{
		human[i].growth = rand() % 300 + 50;
		human[i].groupNumber = rand() % 3;
		human[i].gender = rand() % 2;
		printf("\n%d", human[i].gender); //�������
		gets(human[i].name);
	}
	i = 0;
	while (i < size)
	{
		printf("\nGender: %d, Name: %s, Growth: %d, Group: %d", human[i].gender,
			human[i].name, human[i].growth, human[i].groupNumber);
		i++;
	}

	printf("\n�������� �������� ������(0-3): ");
	scanf("%d", &i);

	printf("\n������� ���� � ������ �%d: %f", i, GetAverageGrowth(human, size, i));
	
	_getch();
	return 0;
}
