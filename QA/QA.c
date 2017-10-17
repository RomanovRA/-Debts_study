// QA.c: определяет точку входа для консольного приложения.
//turn on _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>



int main() 
{
	int size = 10;

	char *resultStr = (char *)malloc(sizeof(char) * (size + 1));
	int i = 0;
	resultStr[size] = '\0';
	while (i < size)
	{
		resultStr[i] = '$';
		i++;
	}
	i = 0;
	while (resultStr[i])
	{
		printf("\n%c", resultStr[i]);
		i++;
	}
	puts(resultStr);

	_getch();
	return 0;
}