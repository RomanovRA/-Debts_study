#include "stdafx.h"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ������� ���������� ������ ����� � ������ �������� ���������
// � ��� �� �������. � ������ ������ ���������� -1.
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

int main()
{
	setlocale(LC_ALL, "Rus");

	printf("������������ ������ �6");
	printf("\n��������� ������� test.txt ���� ���� ������ ");
	printf("������������������ ��������� ������ � ���� �� ������� �� ������ ");
	printf("���� k'x',\n��� x � ����� ��������� ������� k � �������� ");
	printf("������������������, ����� ���� ���������� ������� ������.");
	

	FILE *file = fopen("test.txt", "r");

	if (file != NULL)
	{
		int size = GetFileSize(file);	//	������ ������� �����
		char *strFromFile = (char *)malloc(sizeof(char) * (size + 1)); // �������� ������. � ������� �� ������ ����� ������.
		fgets(strFromFile, (size + 1), file); // ����-���������� ������������� ����� ������� � ����� ������.
		// (char *) �������� ��� ������������� ��������� malloc() � char *
		fclose(file);
		char *resultStr = (char *)malloc(sizeof(char) * (size + 1)); // ������ ������ ������. � ������� �� ������ ����� ������.
		resultStr[size] = '\0';

		char *iStr = strFromFile; // �������� �������� ������
		char *oStr = resultStr;	  //�������� ��������� �����

        // ��� �� ������� ������.
		while (*iStr)
		{
			int symbolCount = 1;

            // ������� ���-�� ��������, �������� ��� ������ ����� �����������.
            // ��������� ������� �� ��������� �� ��������������� �� ��������� �������� �����
            // � ��� ��������� ��� ����� ��� �������� ������ ����������� ���������.
			while (*(iStr + 1) && *iStr == *(iStr + 1))
			{
				++symbolCount;
				++iStr;
            }
            
            if (symbolCount > 4)
            {
                // ������� ���������� ����� ��������, ������������� ���������� � ������.
                // ����� ������� ������������ �� ������ ���-�� �������� �� ������.
                oStr += sprintf(oStr, "%c'%d'", *iStr, symbolCount);
            }
            else
            {
                // ���� ����� ������ 4 ���������, �� ������� � ��� ������,
                // ������� ������������ ������ ���-�� ��������� � ������.
                while (symbolCount--)
                {
                    *oStr = *iStr;
                    ++oStr;
                }
            }

            ++iStr;
        }
        *oStr = '\0';
		
		// ���������� ������ ������� � ����
		FILE *file = fopen("after.txt", "w");
		if (fputs(resultStr, file) != EOF)
		{
			printf("\n\n������� ������:  %s\n�������� ������: %s", strFromFile, resultStr);
			printf("\n\n�������� ������: %d�.\n������ ���� ����� �� %d� ������.", strlen(strFromFile), (strlen(strFromFile) - strlen(resultStr)));
		}
		else
		{
			printf("\n������ ������!");
		}
		free(strFromFile); // ����������� ������ � ��������� �����
		free(resultStr);
		fclose(file);
	}
	else
	{
		printf("\n���� �� ������!");
	}

	_getch();
	return 0;
}