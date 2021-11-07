#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 1
#define MAL_BUF 4
int i;
void hijack()
{
puts("control hijacked!");
exit(1);
}
void overflow(char **a, int cnt)
{
char *buf[MAX_BUF];
 for (i = 0; i < cnt; i++){
//printf("start\n");
   printf("a   :%p\n",*a);
   printf("buf1:%p\n",&buf[i]);
    printf("buf1:%c\n",buf[i]);
        printf("buf1:%p\n",buf[i]);
buf[i] = *a++;
  printf("buf2:%p\n",&buf[i]);
   printf("buf2:%c\n",buf[i]);
       printf("buf2:%p\n",buf[i]);
//printf("finish\n");
 }
// do something useful on buf
}
int main()
{
char *a[MAL_BUF];
for (i = 0; i < MAL_BUF; i++) {
a[i] = (char*)hijack;
 printf("%p\n",hijack);
}
 printf("\n");
overflow(a, MAL_BUF);
return 0;
}
