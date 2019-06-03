#ifndef _TIMEIT_H
#define _TIMEIT_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
int identity(int x);
int sum(int s);
double time_it(int (*action)(int), int arg);
#endif
