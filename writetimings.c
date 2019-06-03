#include <stdio.h>
#include <stdlib.h>
 
#include "writetimings.h"
 
int *tobesorted = NULL;
const char *bname = "data_";
const char *filetempl = "%s%s_%s.dat";
int datlengths[] = {100, 500, 1000, 1024, 4000, 4096, 8000, 8192, 30000, 32768, 60000, 65536, 130000, 131072};
 
testpiece_t testpieces[] =
{
  MAKEPIECE(insertion),
  MAKEPIECE(merge),
  MAKEPIECE(quick),
  //MAKEPIECE(quickrand),	//we excluded randomized quicksort for not performing consistent but left its code for possible improvements
  //MAKEPIECE(qsort),		//we eclude this also since its almost same with normal quicksort
  MAKEPIECE(heap),
  MAKEPIECE(counting),
  { NULL, NULL }
};
 
seqdef_t seqdefs[] =
{
  { "c1", fillwithconst },
  { "s", sortedarray },
  { "shf", shuffledarray },
  { "rs", reversesorted },  
  { "as", almostsortedarray },
  { "256", last256notsortedarray },
  { "hr", highRepetitionArray },
  { "hrs", SortedHighRepetitionArray },
  { "1hr", OneHighRepetitionArray },
  { NULL, NULL }
};
 
 
//function generators
MAKEACTION(insertion)
MAKEACTION(merge)
MAKEACTION(quick)
MAKEACTION(heap)
MAKEACTION(counting)


//action_qsort and action_quickrand are exceptions since they cant be produced by makro due to theirs extra input variable
int action_qsort(int size)
{
  qsort(tobesorted, size, sizeof(int), intcompare);
  return 0;
}

int action_quickrand(int size)
{
  int p=0, q=size-1;
  quickrand_sort(tobesorted, p, q);
  return 0;
}


 
int get_the_longest(int *a)
{
  int r = *a;
  while( *a > 0 ) {
    if ( *a > r ) r = *a;
    a++;
  }
  return r;
}
 
 
int main()
{
  int i, j, k, z, lenmax;
  char buf[BUFLEN];
  FILE *out;
  double thetime;
 
  lenmax = get_the_longest(datlengths);
  printf("Bigger data set has %d elements\n", lenmax);
  tobesorted = malloc(sizeof(int)*lenmax);
  if ( tobesorted == NULL ) return 1;
 
  setfillconst(1);
 
  for(i=0; testpieces[i].name != NULL; i++) {
    for(j=0; seqdefs[j].name != NULL; j++) {
      snprintf(buf, BUFLEN, filetempl, bname, testpieces[i].name,
	       seqdefs[j].name);
      out = fopen(buf, "w");
      if ( out == NULL ) goto severe;
      printf("Producing data for sort '%s', created data type '%s'\n", 
	     testpieces[i].name, seqdefs[j].name);
      for(k=0; datlengths[k] > 0; k++) {
		printf("\tNumber of elements: %10d", datlengths[k]);
		thetime = 0.0;
		seqdefs[j].seqcreator(tobesorted, datlengths[k]);
		fprintf(out, "%d ", datlengths[k]);
		for(z=0; z < MEANREPEAT; z++) {
		  thetime += time_it(testpieces[i].action, datlengths[k]);
		}
		thetime /= MEANREPEAT;
		printf("\tExecution time: %.5lf\n", thetime*1000);
		fprintf(out, "%.5lf\n", thetime*1000);
      }
      fclose(out);
    }
  }
severe:
  free(tobesorted);
  return 0;
}
