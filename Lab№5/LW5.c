#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/*
Описать функцию AverHt(группа),
определяющую средний рост мужчин в некоторой группе людей.
Для описания человека используется структура(группа, имя, пол, рост).
_CRT_SECURE_NO_WARNINGS
*/

// Загрузка списков имён для генерации(корректный вариант: Имя1, Имя2, ИмяN.)
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
//Закончить!

// Получение размера файла для выделения памяти под его данные
int GetFileSize(FILE *file)
{
	int sizeFile = -1;

	if (file)
	{
		// Запомнили текущую позицию указателя в файле (смещение от начала).
		int currentOffset = ftell(file);
		// Устанавливаем указатель в файле на последний символ.
		fseek(file, 0, SEEK_END);
		// Считываем позицию указателя и тем самым получаем размер файла в byte. 
		sizeFile = ftell(file);
		// Возвращаем позицию обратно.
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
}people;	//тип


int main()
{	
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(NULL)); //	Инициализируем генератор случайных чисел от текущего времени
	
	//char* MaleNames = GetList("m.txt");
	//Загрузка списков имён					
	
	
	
	unsigned int size = rand() % 20 + 1; // Количество людей в группе.
	printf("Debug: %d", size);
	people* human = (people*)malloc(sizeof(people) * size);
	// Объявляем указатель структурного типа, определяем как
	// указатель на область памяти размером, достаточным для группы людей.
	
	unsigned int i = 0;
	for (i = 0; i < size; i++)
	{
		human[i].growth = rand() % 300 + 50;
		human[i].groupNumber = rand() % 3;
		human[i].gender = rand() % 2;
		printf("\n%d", human[i].gender); //Костыль
		gets(human[i].name);
	}
	i = 0;
	while (i < size)
	{
		printf("\nGender: %d, Name: %s, Growth: %d, Group: %d", human[i].gender,
			human[i].name, human[i].growth, human[i].groupNumber);
		i++;
	}

	printf("\nВыберете желаемую группу(0-3): ");
	scanf("%d", &i);

	printf("\nСредний рост в группе №%d: %f", i, GetAverageGrowth(human, size, i));
	
	_getch();
	return 0;
}
