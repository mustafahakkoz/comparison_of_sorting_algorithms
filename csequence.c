#include "csequence.h"
 
 
// all elements are constant integer 
static int fill_constant;

void setfillconst(int c)
{
  fill_constant = c;
}
 
void fillwithconst(int *v, int n)
{
  while( --n >= 0 ) v[n] = fill_constant;
}



//All elements are sorted 
void sortedarray(int *v, int n){
	int length; length=n; int max_number = 1001;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand() % max_number;
	}
	
    qsort(v, n, sizeof(int), intcompare);		
}

//shuffled array
void shuffledarray(int *v, int n){
	int length; length=n; int max_number = 1001;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand() % max_number;
	}	
}

//rerverse sorted 
void reversesorted(int *v, int n)
{
  int c, d;
  int *b = malloc(n * sizeof(int));
  sortedarray(v, n);
  for (c = n - 1, d = 0; c >= 0; c--, d++)
	b[d] = v[c];
  for (c = 0; c < n; c++)
    v[c] = b[c];
}


//required function to use built-in qsort()
int intcompare( const void *a, const void *b )
{
  if ( *(const int *)a < *(const int *)b ) return -1;
  else return *(const int *)a > *(const int *)b;
}



//%15 percent of array not sorted
void almostsortedarray(int *v, int n){
	int length; length=n; int max_number = 1001;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand() % max_number;
	}
	
	qsort(v, n, sizeof(int), intcompare);	
	
	//change almost %15 of the array with random numbers
	long almost_element = (length*15)/100;
	for(a=0; a<almost_element; a++){
		int random_index = rand() % length;
		v[random_index] = rand() % max_number;
	}
	
}


//Last 256 element unsorted
void last256notsortedarray(int *v, int n){
	int length;	length = n; int max_number = 1001;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand() % max_number;
	}
	
	qsort(v, n, sizeof(int), intcompare);	
    
	//make random last 256 element
	if(n>256){
		int last;
		for(last=n-256; last<length; last++){
			v[last] = rand() % max_number;
		}
	}
	
}


//All array highRepetition (arrayda bulunan en büyük sayýyý 10a çektim haliyle sayýlar çok tekrar ediyor)
void highRepetitionArray(int *v, int n){
	int length;	length = n; int max_number = 11;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand()%max_number;
	}
}

//All array highRepetition Sorted (arrayda bulunan en büyük sayýyý 10a çektim haliyle sayýlar çok tekrar ediyor ve bunlarý sýraladým)
void SortedHighRepetitionArray(int *v, int n){
	int length;	length = n; int max_number = 11;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand()%max_number;
	}
	
	qsort(v, n, sizeof(int), intcompare);	
}

// Just one element is repeating too much more than 1000 to length (en az bin 1000 en çok dizideki eleman sayýsý kadar)
void OneHighRepetitionArray(int *v, int n){
	int length;	length = n; int max_number = 1001;
	int a=0;
	for(a=0; a<length; a++){
		v[a] = rand()%max_number;
	}
	
	if (n>1001){
		//en az 1000 en çok n-1
		int repetition_count = (rand()%(n-1000))+1000;
		int random_number = rand()%1001;
		int i=0;
		for(i=0; i<repetition_count; i++){
			int random_index = rand()%n;		
			//zaten 1e eþitse tekrar index seç; bu baya uzun sürebilir 1 milyon inputta 3 5 dk filan ;) while loop kalkarsa sýkýntý olmaz ama
			while(v[random_index] == random_number){
				random_index = rand()%n;
			}
			v[random_index] = random_number;
		}	
	}
	
}
