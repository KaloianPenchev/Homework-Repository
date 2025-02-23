#include<stdio.h>
#include<limits.h>

int main(){
    printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s", "Type", "Format", "Size(Bytes)", "Min-value", "Max-value", "Format(Unsigned)", "Max(Unsigned)");
    printf("\n");
    printf("%-25s %-25s %-25s %-25d %-25d %-25s %-25u", "char", "d", "1", SCHAR_MIN, SCHAR_MAX, "u", UCHAR_MAX);
    printf("\n");
    printf("%-25s %-25s %-25s %-25hd %-25hd %-25s %-25hu", "short", "hd", "2", SHRT_MIN, SHRT_MAX, "hu", USHRT_MAX);
    printf("\n");
    printf("%-25s %-25s %-25s %-25d %-25d %-25s %-25u", "int", "d", "4", INT_MIN, INT_MAX, "u", UINT_MAX);
    printf("\n");
    printf("%-25s %-25s %-25s %-25ld %-25ld %-25s %-25lu", "long", "ld", "4/8", LONG_MIN, LONG_MAX, "lu", ULONG_MAX);
    printf("\n");
    printf("%-25s %-25s %-25s %-25lld %-25lld %-25s %-25llu", "long long", "lld", "8", LLONG_MIN, LLONG_MAX, "llu", ULLONG_MAX);

    return 0;
}