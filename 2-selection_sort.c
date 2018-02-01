#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order
 * Return: nothing, just printing values
 * @array: pointer to array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest_val, holder;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		lowest_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[lowest_val])
				lowest_val = j;
		}
		if (lowest_val != i)
		{
			holder = array[i];
			array[i] = array[lowest_val];
			array[lowest_val] = holder;
			print_array(array, size);
		}

	}
}
