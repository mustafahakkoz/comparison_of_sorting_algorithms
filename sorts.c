#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>

//INSERTION SORT
void insertion_sort(int *a, int n) {
	for(size_t i = 1; i < n; ++i) {
		int tmp = a[i];
		size_t j = i;
		while(j > 0 && tmp < a[j - 1]) {
			a[j] = a[j - 1];
			--j;
		}
		a[j] = tmp;
	}
}



//merge sort 
void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}
 
void merge_sort (int *a, int n) {
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
 
//quicksort
void quick_sort(int *A, int len) {
  if (len < 2) return;
 
  int pivot = A[len / 2];
 
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
 
    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }
 
  quick_sort(A, i);
  quick_sort(A + i, len - i);
}

//Randomized quick sort with separated components.
void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
}
 
int partition(int *A, int p, int q) {
  swap(&A[p + (rand() % (q - p + 1))], &A[q]);   // PIVOT = A[q]
 
  int i = p - 1;
  for(int j = p; j <= q; j++) {
    if(A[j] <= A[q]) {
      swap(&A[++i], &A[j]);
    }
  }
 
  return i;
}
 
void quickrand_sort(int *A, int p, int q) {
  if(p < q) {
    int pivotIndx = partition(A, p, q);
 
    quickrand_sort(A, p, pivotIndx - 1);
    quickrand_sort(A, pivotIndx + 1, q);
  }
}


//HEAP SORT 
int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}
 
void heap_sort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
    }
    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
    }
}



//COUNTING SORT
void counting_sort(int *array, int n)
{
  int i, j, z, min, max;
  
  min = max = array[0];
  for(i=1; i < n; i++) {
    if ( array[i] < min ) {
      min = array[i];
    } else if ( array[i] > max ) {
      max = array[i];
    }
  }
 
  int range = max - min + 1;
  int *count = malloc(range * sizeof(*array));
 
  for(i = 0; i < range; i++) count[i] = 0;
  for(i = 0; i < n; i++) count[ array[i] - min ]++;
 
  for(i = min, z = 0; i <= max; i++) {
    for(j = 0; j < count[i - min]; j++) {
      array[z++] = i;
    }
  } 
 
  free(count);
}
 
