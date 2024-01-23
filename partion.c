#include "sort.h"
/**
 * swap - Swap values
 *
 * @x: New holder
 * @y: Value being swap from
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * partition - Pivoting technique
 *
 * @array: Array to be partitioned
 * @low: Lowest index
 * @high: Highest index
 * @size: Size of the array
 *
 * Return: The current pivot
 */
size_t partition(int *array, size_t  low, size_t high, size_t size)
{
	int pivot_value;
	size_t j, i;

	pivot_value =  array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	print_array(array, size);

	return (i);
}
