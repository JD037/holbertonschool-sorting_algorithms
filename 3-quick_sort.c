#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursive helper function for quick_sort
 * @array: The array to sort
 * @low: The lower bound of the subarray
 * @high: The upper bound of the subarray
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * partition - partition a subarray using the Lomuto partition scheme
 * @array: The array to sort
 * @low: The lower bound of the subarray
 * @high: The upper bound of the subarray
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
