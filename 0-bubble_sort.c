#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order the Bubble sort
* @array : pointer array
* @size : size
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp = 0;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - 1 - a; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = tmp;
				print_array(array, size);
			}
		}
	}
}
