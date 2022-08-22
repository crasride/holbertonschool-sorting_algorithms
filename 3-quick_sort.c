#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

static int *Oarray;
static size_t Osize;

/**
 * quick_sort - recursif sorting algorithim based on a pivot
 *
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	unsigned int Pos = 0;
	unsigned int TmpP = 0;
	int tmp;

	if (!array || size <= 1)
		return;
	pivot  = array[size - 1];
	if (!Oarray)
	{
		Oarray = array;
		Osize = size;
	}
	while (TmpP < size - 1)
	{
		TmpP = Pos;
		while (array[TmpP] < pivot)
			TmpP++;
		if (TmpP == size - 1)
		{
			quick_sort(array, size - 1);
			break;
		}
		Pos = TmpP;
		while (array[TmpP] >= pivot && TmpP < size - 1)
			TmpP++;
		if (array[Pos] != array[TmpP])
		{
			tmp = array[Pos];
			array[Pos] = array[TmpP];
			array[TmpP] = tmp;
			print_array(Oarray, Osize);
		}
	}
	if (Pos > 1)
		quick_sort(array, Pos);
	while (array[Pos + 1] == pivot)
		Pos++;
	if (Pos < size - 2)
		quick_sort(array + Pos + 1, size - Pos - 1);
}
