#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/*
Описать функцию AverHt(группа),
определяющую средний рост мужчин в некоторой группе людей.
Для описания человека используется структура(группа, имя, пол, рост).
_CRT_SECURE_NO_WARNINGS
*/

typedef struct
{
	char name[20];
	unsigned short groupNumber;
	unsigned short growth;
	char gender;
}people;	//тип

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

	printf("Лабораторная работа №5");
	printf("\nПрограмма находит средний рост мужчин в некоторой группе людей.");
	printf("\nДля описания людей используется структура вида: группа, имя, пол, рост.");
	printf("\nВвод имён людей осуществляется вручную.");

	srand((unsigned int)time(NULL)); //	Инициализируем генератор случайных чисел от текущего времени
	
	unsigned int size = rand() % 10 + 1; // Количество людей в группе.
	
	printf("Количество людей: %d", size);
	
	people* human = (people*)malloc(sizeof(people) * size);
	// Объявляем указатель структурного типа, определяем как
	// указатель на область памяти размером, достаточным для группы людей.
	
	unsigned int i = 0;
	for (i = 0; i < size; i++)	// Генерация случайных данных.
	{
		human[i].growth = rand() % 300 + 50;
		human[i].groupNumber = rand() % 3 + 1;
		human[i].gender = (rand() % 2) ? 'm' : 'f';
		printf("\nВведите имя(%c): ", human[i].gender); //Ручной ввод.
		gets(human[i].name);
	}

	i = 0;
	while (i < size)
	{
		printf("\nПол: %c, Имя: %s, Рост: %d, Группа: %d", human[i].gender,
			human[i].name, human[i].growth, human[i].groupNumber);
		i++;
	}
	
	printf("\nВыберете желаемую группу(1-3): ");
	scanf("%d", &i);
	while (i >= 4 || i <= 0)
	{
		printf("\nОшибка. Выберете желаемую группу(1-3): ");
		scanf("%d", &i);
	}
	
	printf("\nСредний рост в группе №%d: %f", i, GetAverageGrowth(human, size, i));
	
	_getch();
	return 0;
}
