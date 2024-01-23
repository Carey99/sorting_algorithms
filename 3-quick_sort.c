#include "sort.h"
/**
 * quicksort_recursion - Wrapper for quicksort func
 *
 * @array: Array to be sorted
 * @low: Lowest partion
 * @high: Highest partition of the array
 * @size: Size of the array
 */
void quicksort_recursion(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		if (pivot_index > 0)
		{
			quicksort_recursion(array, low, pivot_index - 1, size);
		}
		quicksort_recursion(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort -  Quick sorting in c
 *
 * @array: Array to be sorted
 * @size: Length of the array
 */

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}
