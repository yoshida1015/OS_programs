#include <stdio.h>
int *poe(int *p) {
return p;
}
int *foo() {
int x = 10;
return poe(&x);
}
int bar() {
int x = 100;
return x;
}
int main() {
int *p;
int q;
p = foo();
printf("*p == %d\n", *p);
q = bar();
printf("*p == %d\n", *p);
return 0;
}
