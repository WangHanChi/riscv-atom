#include <stdio.h>

void main(int argc, char ** agrv)
{
    int a = 3, b = 5, c = 0, d = 0, e = 0, f = 0;
    printf("Here test the M-Extension\n");
    c = a * b;
    d = 1000 * 1000;
    e = d / c;
    c = 0;
    f = d % c;
    printf("a : %d\n", a);
    printf("b : %d\n", b);
    printf("c : %d\n", c);
    printf("d : %d\n", d);
    printf("e : %d\n", e);
    printf("f : %d\n", f);
    return;
}
