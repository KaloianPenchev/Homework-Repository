#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    int a = 12, b = 18;

    int result = lcm(a, b);

    printf("%d", result);

    return 0;
}
