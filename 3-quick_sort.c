#include "sort.h"

/**
 * partition - Lomuto scheme partitioning
 * @array: array to sort
 * @low: Lowest index of the partition
 * @high: Highest index of the partition
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[high];
		array[high] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array
 * @array: array to sort
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
