#include <stdbool.h>
bool isMulOverflow(long long A, long long B) { 
    __uint128_t c = (__uint128_t) A * B; 
    if (c > (unsigned long long) -1LL) {
        return true;
    }
    if (A == 0 || B == 0) 
        return false; 
    long long result = A * B; 
    if (A == result / B) 
        return false; 
    else 
        return true;
}
int fact(long long num, long long*result)
{ 
    long long fact = 1;
    for(long long int i=1;i<=num;i++){ 
        long long old = fact;
        fact=fact*i; 
        if(isMulOverflow(i, fact))
            return -1;
    }
    if(result != (void*)0)
        *result = fact;
    return 0;
}
