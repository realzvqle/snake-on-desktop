#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED


#include "main.h"

void* alloc_mem(size_t size);
BOOL free_mem(void* memory);
double ssqrt(double x);
double ppow(double x, int n);
char* i_to_a(int num, size_t size);
char* str_cat(char* destination, const char* source);
int getRandomNumber(int min, int max);

#endif