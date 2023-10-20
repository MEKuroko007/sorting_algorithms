#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array containing the elements.
 * @size: The size of the array.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 */
void swap(int *array, size_t size, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	print_array(array, size);
}

/**
 * heapMax - Builds a max heap from an array.
 * @array: The array to be transformed into a heap.
 * @size: The size of the array.
 * @i: The index of the current element.
 * @len: The size of the heap.
 */
void heapMax(int *array, size_t size, int i, int len)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && array[left] > array[largest])
		largest = left;

	if (right < len && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array, size, i, largest);
		heapMax(array, size, largest, len);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapMax(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		heapMax(array, size, 0, i);
	}
}
