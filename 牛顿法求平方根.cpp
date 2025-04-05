long long int_sqrt_newton(long long n) {
    if (n <= 1) return n;
    long long x = n;
    while (x > n / x) {
        x = (x + n / x) / 2;
    }
    return x;
}