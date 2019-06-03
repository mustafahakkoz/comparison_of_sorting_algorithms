#ifndef _CSEQUENCE_H
#define _CSEQUENCE_H
#include <stdlib.h>
 
void setfillconst(int c);
void fillwithconst(int *v, int n);
void sortedarray(int *v, int n);
void reversesorted(int *v, int n);
void shuffledarray(int *v, int n);
int intcompare( const void *a, const void *b );
void almostsortedarray(int *v, int n);
void last256notsortedarray(int *v, int n);
void highRepetitionArray(int *v, int n);
void SortedHighRepetitionArray(int *v, int n);
void OneHighRepetitionArray(int *v, int n);

#endif
