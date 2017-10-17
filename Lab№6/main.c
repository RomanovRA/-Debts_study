#include "stdafx.h"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Функция возвращает размер файла в байтах сохраняя указатель
// в той же позиции. В случае ошибки возвращает -1.
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

int main()
{
	setlocale(LC_ALL, "Rus");

	printf("Лабораторная работа №6");
	printf("\nПрограмма сжимает test.txt файл путём замены ");
	printf("последовательности вхождений одного и того же символа на запись ");
	printf("вида k'x',\nгде x – число вхождений символа k в исходную ");
	printf("последовательность, после чего сравнивает размеры файлов.");
	

	FILE *file = fopen("test.txt", "r");

	if (file != NULL)
	{
		int size = GetFileSize(file);	//	Запись размера файла
		char *strFromFile = (char *)malloc(sizeof(char) * (size + 1)); // Исходная строка. С запасом на символ конца строки.
		fgets(strFromFile, (size + 1), file); // Нуль-терминатор автоматически будет помещён в конец строки.
		// (char *) приводит тип возвращаемого указателя malloc() к char *
		fclose(file);
		char *resultStr = (char *)malloc(sizeof(char) * (size + 1)); // Сжатая строка строка. С запасом на символ конца строки.
		resultStr[size] = '\0';

		char *iStr = strFromFile; // Дубликат исходной строки
		char *oStr = resultStr;	  //Дубликат конечного файла

        // Идём по входной строке.
		while (*iStr)
		{
			int symbolCount = 1;

            // Считаем кол-во символов, учитывая что строка может закончиться.
            // Сравнивая текущий со следующим мы останавливаемся на последнем элементе серии
            // и это позволяет нам взять его значение просто разыменовав указатель.
			while (*(iStr + 1) && *iStr == *(iStr + 1))
			{
				++symbolCount;
				++iStr;
            }
            
            if (symbolCount > 4)
            {
                // Функция возвращает число символов, действительно занесенных в массив.
                // Таким образом перемещаемся на нужное кол-во символов по строке.
                oStr += sprintf(oStr, "%c'%d'", *iStr, symbolCount);
            }
            else
            {
                // Если серия меньше 4 элементов, то сжимать её нет смысла,
                // поэтому переписываем нужное кол-во элементов в массив.
                while (symbolCount--)
                {
                    *oStr = *iStr;
                    ++oStr;
                }
            }

            ++iStr;
        }
        *oStr = '\0';
		
		// Записываем строку обратно в файл
		FILE *file = fopen("after.txt", "w");
		if (fputs(resultStr, file) != EOF)
		{
			printf("\n\nВходная строка:  %s\nВыходная строка: %s", strFromFile, resultStr);
			printf("\n\nИсходный размер: %dБ.\nТеперь файл весит на %dБ меньше.", strlen(strFromFile), (strlen(strFromFile) - strlen(resultStr)));
		}
		else
		{
			printf("\nОшибка записи!");
		}
		free(strFromFile); // Освобождаем память и закрываем поток
		free(resultStr);
		fclose(file);
	}
	else
	{
		printf("\nФайл не найден!");
	}

	_getch();
	return 0;
}