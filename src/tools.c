#include "headers/tools.h"





void* alloc_mem(size_t size) {
    return VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

BOOL free_mem(void* memory) {
    return VirtualFree(memory, 0, MEM_RELEASE);
}

double ssqrt(double x) {
    if (x == 0) return 0;
    
    double epsilon = 0.000001;
    double guess = x / 2.0;
    
    while (TRUE) {
        double difference = (guess * guess) - x;
        if (difference < 0) difference = -difference;
        
        if (difference <= epsilon) return guess;
        
        guess = (guess + (x / guess)) / 2.0;
    }
}

double ppow(double x, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;
    
    double result = 1.0;
    double base = x;
    long long exp = n;
    
    if (n < 0) {
        base = 1.0 / x;
        exp = -exp;
    }
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    
    return result;
}


char* i_to_a(int num, size_t size) {
    char* str = alloc_mem(size);
    int i = 0;
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    do {
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);
    if (isNegative) {
        //str[i++] = '-';
    }

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    str[i] = '\0';

    return str;
}

char* str_cat(char* destination, const char* source) {
    char* dest = destination;

    while (*dest != '\0') {
        dest++;
    }
    while (*source != '\0') {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return destination;
}


unsigned int xorshift32(unsigned int *seed) {
    unsigned int x = *seed;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *seed = x;
    return x;
}

int getRandomNumber(int min, int max) {
    static unsigned int seed = 0;
    if (seed == 0) {
        seed = GetTickCount();
    }
    unsigned int randomValue = xorshift32(&seed);
    return min + (randomValue % (max - min + 1));
}
