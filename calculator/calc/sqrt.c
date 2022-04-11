#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
int sqrt(int x) {
    long a = 1;
    while (a * a <= x) a ++;
    return --a;
}
#pragma GCC diagnostic pop
