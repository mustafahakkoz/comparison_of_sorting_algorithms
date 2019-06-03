#ifndef _SORTS_H
#define _SORTS_H
#include <stdlib.h>
 
void insertion_sort(int *a, int n);

void merge (int *a, int n, int m);
void merge_sort (int *a, int n);

void quick_sort(int *A, int len);

void swap(int *a, int *b);
int partition(int *A, int p, int q);
void quickrand_sort(int *A, int p, int q);

int max (int *a, int n, int i, int j, int k);
void downheap (int *a, int n, int i);
void heap_sort (int *a, int n);

void counting_sort(int * array, int size);

#endif
