#ifndef SAFEINT_H_
#define SAFEINT_H_

typedef struct{
    int value;
    int errorflag;
}SafeResult;

SafeResult safeadd(int a, int b);
SafeResult safesubtract(int a, int b);
SafeResult safemultiply(int a, int b);
SafeResult safedivide(int a, int b);
SafeResult safestrtoint(char str[]);

#endif