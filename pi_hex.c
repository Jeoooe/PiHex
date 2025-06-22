#include <stdio.h>

#define MORE 8 
#define hex_lsh(x, n) ((int64_t)(x) << (4*(n)))

typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;

// 16^n mod m
uint64_t pow_mod(uint64_t n, uint64_t m) {
    // 这里的base是可能溢出的
    uint64_t base = 16 % m;
    uint64_t result = 1;
    while (n > 0) {
        if (n & 1) 
            result = (result * base) % m;
        base = (base * base) % m;
        n >>= 1;
    }
    return result;
}

// We only need "MORE" hex digits i.e. result in [0, 1 << 4*MORE )
int64_t sigma(int n) {
    const uint64_t end = n + MORE;
    const uint32_t P[4] = {1,4,5,6};
    uint32_t results[4] = {0, 0, 0, 0};
    for (int i = 0;i <= n; ++i) {
        for (int j = 0;j < 4; ++j) {
            const uint32_t p = P[j];
            const uint64_t denominator = 8 * i + p;
            uint64_t numerator = pow_mod(n - i, denominator);
            numerator = hex_lsh(numerator, MORE);
            results[j] += numerator / denominator;
#ifdef DEBUG
            printf("%d : %lld\n",i, result);
#endif
        }
    }

    for (int i = n + 1;i <= end; ++i) {
        for (int j = 0;j < 4; ++j) {
            const uint32_t p = P[j];
            const uint64_t denominator = 8 * i + p;
            uint64_t numerator = hex_lsh(1, end - i);
            results[j] += (numerator / denominator);
#ifdef DEBUG
            printf("%d : %lld\n",i, result);
#endif
        }
    }
    int64_t result = 4 * (int64_t)results[0] - 2 * (int64_t) results[1] - (int64_t) results[2] - (int64_t) results[3];
    return result;
}

//calculate n th digit of pi
void run(int n) {
    const int64_t digit = hex_lsh(1, MORE);
    int64_t pi = sigma(n);
    while (pi < 0) {
        pi += digit;
    }
    while (pi > digit) {
        pi -= digit ;
    }
#ifdef DEBUG
    printf("\n\nNOW:%d\n",n);
    printf("pI:%lld\n",pi);
#endif
    printf("%d ditgit: %x --- %x\n",n+1,(int)(pi >> (4*MORE-4)) & 0b1111,(int)pi);
}


int main() {
    int start, end;
    printf("start=");
    scanf_s("%d",&start);
    printf("end=");
    scanf_s("%d",&end);
    for (int i = start;i <= end; ++i) {
        run(i);
    }
    return 0;
}
