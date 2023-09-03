#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(long long int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to factorize a number
void factorize(long long int n) {
    if (is_prime(n)) {
        printf("%lld=%lld*%lld\n", n, n, 1LL);
        return;
    }

    long long int factor1 = 1LL, factor2 = 1LL;
    long long int sqrt_n = sqrt(n);

    for (long long int i = 2LL; i <= sqrt_n; i++) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            factor1 = i;
            factor2 = n / i;
            break;
        }
    }

    printf("%lld=%lld*%lld\n", n, factor1, factor2);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    long long int num;
    while (fscanf(file, "%lld", &num) != EOF) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
