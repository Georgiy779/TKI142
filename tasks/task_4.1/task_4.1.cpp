﻿#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <locale.h>

int* intmas(int n)
{
	int f, i;
	int* array = NULL;

	printf("1 - keybord\n2 - random\n");
	scanf_s("%d", &f);
	printf("   -> %d\n\n", f);

	if (f == 1 || f == 2)
		array = (int*)calloc(n, sizeof(int));
	else
		printf("Неправильно введённая операция! \n");

	if (f == 1)
	{
		for (i = 0; i < n; i++)
			scanf_s("%d", &array[i]);
	}

	if (f == 2)
	{
		for (i = 0; i < n; i++)
			array[i] = rand();
	}

	return array;
}

int sumkrat(int* array, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0 && array[i] % 10 == 0)
		{
			sum = sum + array[i];
		}
	}
	printf("sum = %d\n", sum);
	return 0;
}

int zam(int* array, int n)
{
	int c, k;
	printf("input k\n");
	scanf_s("%d", &k);
	k--;
	printf("   -> %d\n\n", k);
	for (int i = 0; i < k; i++)
	{
		c = array[i];
		array[i] = array[k];
		array[k] = c;
		k = k - 1;
	}
	return 0;
}

int com(int* array, int n)
{
	int c, f;
	printf("input f\n");
	scanf_s("%d", &f);
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] * array[i + 1] == f)
		{
			printf(" array[%d] = %d and array[%d] = %d\n", i, array[i], i + 1, array[i + 1]);
		}
		else
			printf("Ьаких элементов нет.\n");
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en-US");

	int n, sum; //n - количество элементов массива
				//sum - Сумма элементов массива

	printf("input n\n");
	scanf_s("%d", &n);
	printf("   -> %d\n\n", n);

	//Создание массива
	int* array = intmas(n);

	if (array != NULL)
	{
		//Вывод массива
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}

		// Сумма отрицательных элементов массива кратных 10
		sumkrat(array, n);

		//Заменить первые к элементов массива в обратном порядке
		zam(array, n);
		for (int i = 0; i < n; i++)
		{
			printf("array[%d] = %d\n", i, array[i]);
		}

		//Определение пары элементов равных заданному числу.
		com(array, n);

		free(array);
	}
	else
		printf("error");

	return 0;
}