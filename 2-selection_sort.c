#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* using the Selection sort
* @array : pointer array
* @size : size
*/

void selection_sort(int *array, size_t size)
{
	size_t a, b, indx;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		indx = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[indx])
				indx = b;
		}
		if (array[indx] != array[a])
		{
			tmp = array[indx];
			array[indx] = array[a];
			array[a] = tmp;
			print_array(array, size);
		}
	}
}
