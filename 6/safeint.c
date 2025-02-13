#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "safeint.h"
#include "util.h"

SafeResult safeadd(int a, int b) {
    SafeResult result;
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        result.value = 0;
        result.errorflag = 1;
        errormsg('+');
    } else {
        result.value = a + b;
        result.errorflag = 0;
    }
    return result;
}

SafeResult safesubtract(int a, int b) {
    SafeResult result;
    if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)) {
        result.value = 0;
        result.errorflag = 1;
        errormsg('-');
    } else {
        result.value = a - b;
        result.errorflag = 0;
    }
    return result;
}

SafeResult safemultiply(int a, int b) {
    SafeResult result;
    if ((a > 0 && b > INT_MAX / a) || (a < 0 && b < INT_MIN / a) ||
        (a < 0 && b > INT_MAX / a) || (a > 0 && b < INT_MIN / a)) {
        result.value = 0;
        result.errorflag = 1;
        errormsg('*');
    } else {
        result.value = a * b;
        result.errorflag = 0;
    }
    return result;
}

SafeResult safedivide(int a, int b) {
    SafeResult result;
    if (b == 0) {
        result.value = 0;
        result.errorflag = 1;
        errormsg('/');
    } else if (a == INT_MIN && b == -1) {
        result.value = 0;
        result.errorflag = 1;
        errormsg('/');
    } else {
        result.value = a / b;
        result.errorflag = 0;
    }
    return result;
}

SafeResult safestrtoint(char str[]) {
    SafeResult res;
    res.value = 0;
    res.errorflag = 1;
    int length = strlen(str);
    int is_negative = 0;
    int start_index = 0;

    if (str[0] == '-') {
        is_negative = 1;
        start_index = 1;
    }

    for (int i = start_index; i < length; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return res;
        }
    }

    for (int i = start_index; i < length; i++) {
        if ((res.value > (INT_MAX / 10)) ||
            (res.value == (INT_MAX / 10) && (str[i] - '0') > (INT_MAX % 10))) {
            return res;
        }
        res.value = res.value * 10 + (str[i] - '0');
    }

    if (is_negative) {
        res.value = -res.value;
    }
    res.errorflag = 0;
    return res;
}
