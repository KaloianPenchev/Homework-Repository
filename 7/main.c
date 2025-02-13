
#include "quadraticroots.h"
#include <stdio.h>

int main() {
    
    int a1 = 1, b1 = 4, c1 = 5;
    QuadraticRootsResult eq1 = findroots(a1, b1, c1);
    if (eq1.norealroots == 1) {
        printf("No real roots\n");
    } else {
        printf("x1 = %Lf, x2 = %Lf\n", eq1.x1, eq1.x2);
    }

    
    float a2 = 1.0, b2 = -5.0, c2 = 6.0;
    QuadraticRootsResult eq2 = findroots(a2, b2, c2);
    if (eq2.norealroots == 1) {
        printf("No real roots\n");
    } else {
        printf("x1 = %Lf, x2 = %Lf\n", eq2.x1, eq2.x2);
    }

    
    double a3 = 1.0, b3 = -7.0, c3 = 12.0;
    QuadraticRootsResult eq3 = findroots(a3, b3, c3);
    if (eq3.norealroots == 1) {
        printf("No real roots\n");
    } else {
        printf("x1 = %Lf, x2 = %Lf\n", eq3.x1, eq3.x2);
    }

    return 0;
}
