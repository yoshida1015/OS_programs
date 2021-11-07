#include <stdio.h>
#include <stdlib.h>
int a;
static int b;
int c = 100;
static int d = 200;
int main() {
char *p, *q;
p = malloc(1024);
q = malloc(512);

printf("a is at %p\n", &a);
printf("b is at %p\n", &b);
printf("c is at %p\n", &c);
printf("d is at %p\n", &d);
printf("p is %p\n", &p);
printf("q is %p\n", &q);
return 0;

}
