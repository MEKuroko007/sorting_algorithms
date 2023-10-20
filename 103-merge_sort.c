#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * merge - Merges two subarrays of 'array'.
 * @array: The array to be sorted.
 * @left: Pointer to the left subarray.
 * @right: Pointer to the right subarray.
 * @size_l: Size of the left subarray.
 * @size_r: Size of the right subarray.
 */
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_l + size_r) * sizeof(int));

	if (temp == NULL)
	{
		return;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);
	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		} else
		{
			temp[k] = right[j];
			j++;
		}
		k++; }
	while (i < size_l)
	{
		temp[k] = left[i];
		i++;
		k++; }
	while (j < size_r)
	{
		temp[k] = right[j];
		j++;
		k++; }
	for (i = 0; i < size_l + size_r; i++)
	{
		array[i] = temp[i]; }
	free(temp);
	printf("[Done]: ");
	print_array(array, size_l + size_r);
}


/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;

		merge_sort(left, mid);
		merge_sort(right, size - mid);
		merge(array, left, right, mid, size - mid);
	}
}
