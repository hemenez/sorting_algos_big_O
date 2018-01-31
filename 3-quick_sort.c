#include "sort.h"
/**
 * partition - partitions array using pivot
 * Return: index of pivot
 * @array: represents pointer to array
 * @start: low of array
 * @end: high of array
 * @size: size of array
 */
size_t partition(int *array, int start, int end, size_t size)
{
	int i;
	int j;
	int pivot;
	int store;


	i = start - 1;
	j = start;
	pivot = end;
	while (j < pivot)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			store = array[j];
			array[j] = array[i];
			array[i] = store;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	i++;
	if (array[i] > array[pivot])
	{
		store = array[pivot];
		array[pivot] = array[i];
		array[i] = store;
		if (i != j)
			print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort - calls quick_sort helper
 * Return: no value
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	if (size > 1 && array != NULL)
		sorter_helper(array, start, end, size);
}

/**
 * sorter_helper - recursive call to partition function
 * Return: no value
 * @array: represents pointer to array
 * @start: low of the array
 * @end: high of the array
 * @size: size of the array
 */
void sorter_helper(int *array, int start, int end, size_t size)
{
	size_t pIndex;

	if (start < end)
	{
		pIndex = partition(array, start, end, size);
		sorter_helper(array, start, pIndex - 1, size);
		sorter_helper(array, pIndex + 1, end, size);
	}
}
