#include <stdio.h>

void swap (int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition (int array[], int left, int right)
{
	int i;
	int j;
	int pivot;

	i = left;
	j = right + 1;
	pivot = left;

	while(i < j)
	{
		while(array[i] < array[pivot])
			i++
		while(array[pivot] < array[j]);
			j++;
		if (i < j) 
			swap(&array[i], &array[j]);
	}
	swap(&array[pivot], &array[j]);
	
	return j;
}
	
	do { i++; } while (array[i] < array[pivot]);
	do { j--; } while (array[pivot] < array[j]);
}

void quick_sort (int array[], int left, int right)
{

	int pivot;
	if (left < right)
	{
		pivot = partittion(array, left, right);
		quick_sort(array, left, pivot-1);
		quick_sort(array, pivot+1, right);
	}
}
