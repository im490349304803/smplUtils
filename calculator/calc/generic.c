#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#define iff(FUNC, TEXT) if(!strncmp((FUNC),(TEXT),strlen (TEXT)))
const char *supported_s = "+,-, *, /, SQRT, !, QUIT (Q)";
const char *sfuncs_starts_s = "+-*/Ss!Qq";
const char *num_starts_s = "0123456789";
const char *avail_symbols_s = "+-*/SQRT!QUIT0123456789sqrt";
int fact(long long num, long long*result);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
int sqrt(int x) ;
#pragma GCC diagnostic pop
char* findoccur(char*str, char*chars)
{
    for(int i=0; i<strlen(str); i++) {
        for(int j=0; j<strlen(chars); j++) { 
            if(chars[j] == str[i]) { 
                return &str[i]; 
            } 
        }
    }
    
    return NULL;
}
bool chr_in_str(char ch, const char*str)
{ 
    for(int j=0; j<strlen(str); j++) { 
        if(str[j] == ch) { 
            return true;
        } 
    }
    return false;
}
bool strinvalid(char*str, int* num_inv)
{
    
    // at the beginning - num or +-
    char*numorpm = "0123456789+-";
    if(!chr_in_str(str[0], numorpm)) {
        if(num_inv != NULL)
            *num_inv = 0;
        return true;
    }
    for(int i=0; i<strlen(str); i++) {
        if(!chr_in_str(str[i], avail_symbols_s)){ 
            // invalid symbol 
            if(num_inv != NULL) 
                *num_inv = i; 
            return true;
        }
    }
    return false;
}
int calc(char*str, long long int*nump,char**errstr)
{
    if(str == NULL || nump == NULL )
        return -1;
    // test str for invalid chars
    int inv_sym;
    if(strinvalid(str,&inv_sym)) {
        if(errstr != 0) { 
            *errstr = "INVALID SYM FOUND";
        }
        mvprintw(8,1, "INVALID SYM AT %lld", inv_sym+1);
        return -1;
    }
    long long num1;
    sscanf(str, "%lld", &num1);
    char* func_s = findoccur(str+1, (char*)sfuncs_starts_s);
    //mvprintw(8,1, "func_s:%s", func_s);
    if(func_s == NULL) { 
        // no func found
        *nump = num1;
        if(errstr != NULL)
            *errstr = "OP SUCCESS";
        return 0;
    }
    char *num2_s = NULL;
    if(func_s != NULL)
        num2_s = findoccur(func_s+1, (char*)num_starts_s);
    //mvprintw(9,1, "num2_s:%s", num2_s);
    long long int num2;
    if(num2_s != NULL)
        sscanf(num2_s, "%lld", &num2);
    iff(func_s, "+") {
        if(num2_s == NULL) { 
            if(errstr != NULL) 
                *errstr = "ERR NO SECOND NUMBER"; 
            return -1;
        }
        *nump = num1 + num2;
    } 
    else iff(func_s, "-") {
        if(num2_s == NULL) { 
            if(errstr != NULL) 
                *errstr = "ERR NO SECOND NUMBER"; 
            return -1;
        }
        *nump = num1 - num2;
    } 
    else iff(func_s, "*") {
        if(num2_s == NULL) { 
            if(errstr != NULL) 
                *errstr = "ERR NO SECOND NUMBER"; 
            return -1;
        }
        *nump = num1 * num2;
    }
    else iff(func_s, "/") {
        if(num2_s == NULL) { 
            if(errstr != NULL) 
                *errstr = "ERR NO SECOND NUMBER"; 
            return -1;
        }
        if(num2 == 0) {
            if(errstr != NULL)
                *errstr = "EXC DIVIDE BY ZERO NUM2=0";
            return -1;
        }
        *nump = num1 / num2;
    }
    else iff(func_s, "SQRT") {
        if(num1 < 0 ) {
            if(errstr != NULL)
                *errstr = "EXC SQRT NEGATIVE NUM1";
            return -1;
        }

        *nump = sqrt(num1);
    }
    else iff(func_s, "sqrt") {
        if(num1 < 0 ) {
            if(errstr != NULL)
                *errstr = "EXC SQRT NEGATIVE NUM1";
            return -1;
        }


        *nump = sqrt(num1);
    }
    else iff(func_s, "Sqrt") {
        if(num1 < 0 ) {
            if(errstr != NULL)
                *errstr = "EXC SQRT NEGATIVE NUM1";
            return -1;
        }


        *nump = sqrt(num1);
    }
    else iff(func_s, "!") {
        if(num1 < 0 ) {
            if(errstr != NULL)
                *errstr = "NO SUPPORT FOR COMPLEX NUMBERS";
            return -1;
        }
        int res = fact(num1, nump);
        if(res) {
            if(errstr != NULL)
                *errstr = "ERR FACT OVF";
            return -1;
        }
    } else {
        if(errstr != NULL)
            *errstr = "ERR FUNC UNKNOWN";
        mvprintw(8,1, "FUNC AT %s", func_s);
        return -1;
    }
    if(errstr != NULL)
        *errstr = "OP SUCCESS";
    return 0;
}
