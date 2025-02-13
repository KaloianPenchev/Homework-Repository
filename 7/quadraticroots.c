#include"quadraticroots.h"
#include<math.h>

QuadraticRootsResult findroots(double a, double b,double c){
    
    QuadraticRootsResult res;
    res.norealroots = 0;
    double D = b*b - 4*a*c;

    if(D < 0){
        res.norealroots = 1;
        return res;
    }

    double sqrtD = sqrtl(D);
    
    res.x1 = (-b + sqrtD) / (2 * a);
    res.x2 = (-b - sqrtD) / (2 * a);

    return res;
}