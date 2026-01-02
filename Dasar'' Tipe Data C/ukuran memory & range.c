#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== UKURAN TIpe Data ===\n");
    
    printf("char: %d byte\n", sizeof(char));
    printf("short: %d bytes\n", sizeof(short));
    printf("int: %d bytes\n", sizeof(int));
    printf("long: %d bytes\n", sizeof(long));
    printf("float: %d bytes\n", sizeof(float));
    printf("double: %d bytes\n", sizeof(double));
    
    printf("\n=== RANGE TIpe Data ===\n");
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("FLOAT_MIN: %e\n", FLT_MIN);
    printf("FLOAT_MAX: %e\n", FLT_MAX);
    
    return 0;
}