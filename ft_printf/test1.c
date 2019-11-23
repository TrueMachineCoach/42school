#include <stdio.h>
#include <float.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#define MANTISSA 23

union DOUBLE {
    struct {
        long long frac : 23;
        unsigned exp : 8;
        unsigned sign : 1;
    } bin;
    float f;
};

char *fpfrc2bin (char *s, float fvalue)
{
    /* obtain fractional value from fvalue */
    float fv = fvalue > 1.0 ? fvalue - (int)fvalue : fvalue;
    char *p = s;
    unsigned char it = 0;

    while (fv > 0 && it < MANTISSA + 1)
    {   /* convert fraction */
        fv = fv * 2.0;
        *p++ = ((int)fv) ? '1' : '0';
        *p = 0;  /* nul-terminate */
        fv = ((int)fv >= 1) ? fv - 1.0 : fv;
        it++;
    }

    return s;
}

int main(void) {
    float f = 5.120;
    char *str = (char*)malloc(50);

    bzero(str, 50);
    str = fpfrc2bin(str, f);
    printf("%s", str);
    return 0;
}