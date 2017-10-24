#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/*
������� ������� AverHt(������),
������������ ������� ���� ������ � ��������� ������ �����.
��� �������� �������� ������������ ���������(������, ���, ���, ����).
_CRT_SECURE_NO_WARNINGS
*/

typedef struct
{
	char name[20];
	unsigned short groupNumber;
	unsigned short growth;
	char gender;
}people;	//���

float GetAverageGrowth(people* hu, const int size, const int group)
{	
	unsigned int i = 0, count = 0;
	float avGrowth = 0;

	for (i = 0; i < size; i++)
	{
		if (hu[i].groupNumber == group && hu[i].gender == 'm')
		{
			avGrowth += (float)hu[i].growth;
			count++;
		}
	}

	return (count == 0) ? 0.0 : avGrowth / count;
}

int main()
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("������������ ������ �5");
	printf("\n��������� ������� ������� ���� ������ � ��������� ������ �����.");
	printf("\n��� �������� ����� ������������ ��������� ����: ������, ���, ���, ����.");
	printf("\n���� ��� ����� �������������� �������.");

	srand((unsigned int)time(NULL)); //	�������������� ��������� ��������� ����� �� �������� �������
	
	unsigned int size = rand() % 10 + 1; // ���������� ����� � ������.
	
	printf("���������� �����: %d", size);
	
	people* human = (people*)malloc(sizeof(people) * size);
	// ��������� ��������� ������������ ����, ���������� ���
	// ��������� �� ������� ������ ��������, ����������� ��� ������ �����.
	
	unsigned int i = 0;
	for (i = 0; i < size; i++)	// ��������� ��������� ������.
	{
		human[i].growth = rand() % 300 + 50;
		human[i].groupNumber = rand() % 3 + 1;
		human[i].gender = (rand() % 2) ? 'm' : 'f';
		printf("\n������� ���(%c): ", human[i].gender); //������ ����.
		gets(human[i].name);
	}

	i = 0;
	while (i < size)
	{
		printf("\n���: %c, ���: %s, ����: %d, ������: %d", human[i].gender,
			human[i].name, human[i].growth, human[i].groupNumber);
		i++;
	}
	
	printf("\n�������� �������� ������(1-3): ");
	scanf("%d", &i);
	while (i >= 4 || i <= 0)
	{
		printf("\n������. �������� �������� ������(1-3): ");
		scanf("%d", &i);
	}
	
	printf("\n������� ���� � ������ �%d: %f", i, GetAverageGrowth(human, size, i));
	
	_getch();
	return 0;
}
