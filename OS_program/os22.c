#include <stdio.h>
#include <pthread.h>
void *thread(void *arg)
{
for (;;)
printf("Thread (%s)\n", arg);
return NULL;
}
int main()
{
pthread_t a, b;
char arg_a[10] = "I am a boy", arg_b[11] = "I am a girl";
pthread_create(&a, NULL, thread, &arg_a);
pthread_create(&b, NULL, thread, &arg_b);
pthread_join(a, NULL);
pthread_join(b, NULL);
return 0;
}
