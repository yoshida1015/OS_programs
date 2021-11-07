#include <stdio.h>
int a = 10;
int b = 20;
int c = 30;
int main() {
int *p = &b;
*(p - 1) = 11;
*(p + 1) = 33;
 
 printf("a = %d, b= %d, c = %d\n", a, b, c);

 printf("a:%p \nb:%p \nc:%p \n",&a,&b,&c);

 printf("p-1:%p \np:%p \np+1:%p \n",(p-1),p,(p+1));
 
printf("a = %d, b= %d, c = %d\n", a, b, c);
return 0;
}
