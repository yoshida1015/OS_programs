#include <stdio.h>

int fact(int n) {
int r;
if (n == 0) {
printf("In fact(0): &r == %p\n", &r);
r = 1;
} else {
printf("In fact(%d) before call: &r == %p\n", n, &r);
r = n * fact(n - 1);
printf("In fact(%d) after call: &r == %p\n", n, &r);
}
return r;
}
int main() {
printf("fact(2) = %d\n", fact(2));
return 0;
}
