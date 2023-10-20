#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int idx = 0;
    int max = 0;
    size_t i;
    int *count;

    if (array == NULL || size < 2)
    {
        return;
    }

    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
    {
        return;
    }

    for (i = 0; i <= (size_t)max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    /* Print the counting array */
    print_array(count, max + 1);

    for (i = 0; i <= (size_t)max; i++)
    {
        while (count[i] > 0)
        {
            array[idx] = (int)i;
            idx++;
            count[i]--;
        }
    }

    free(count);
}
