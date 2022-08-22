#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int *Oarray = NULL;
size_t Osize;

void quick_sort(int *array, size_t size)
{
	int pivot;
	int end = size - 2;
	int beg = 0;
	int tmp;

	if (!array || size <= 1)
		return;
	pivot  = array[size - 1];
	if (!Oarray)
	{
		Oarray = array;
		Osize = size;
	}
	while (1)
	{
		while (array[end] > pivot && end > -1)
			end--;
		if (end == -1)
			break;
		while (array[beg] < pivot && beg < end)
			beg ++;
		if (end == beg)
			break;
		tmp = array[end];
		array[end] = array[beg];
		array[beg] = tmp;
		print_array(Oarray, Osize);
	}
	end++;
	if ((size_t)end != size - 1)
	{
		array[size - 1] = array[end];
		array[end] = pivot;
		print_array(Oarray, Osize);
	}
	if (end > 1)
		quick_sort(array, end);
	if ((size_t)end < size - 2)
		quick_sort(array + end + 1, size - end - 1);
}