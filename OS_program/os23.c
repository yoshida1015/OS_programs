#include <stdio.h>
#include <pthread.h>
static int count = 0;
/* ロック変数の宣言 */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *arg)
{
  
/* ロック変数の確保 */
pthread_mutex_lock(&mutex);
  
 
int i;
int tmp;
for (i = 0; i < 1000; i++) {
tmp = count;
sched_yield();
tmp = tmp + 1;
sched_yield();
count = tmp;
}
 /* ロック変数の解放 */
pthread_mutex_unlock(&mutex);
return NULL;
}
void *threadB(void *arg)
{
 
/* ロック変数の確保 */
pthread_mutex_lock(&mutex);
  
int i;
int tmp;
for (i = 0; i < 1000; i++) {
tmp = count;
sched_yield();
tmp = tmp - 1;
sched_yield();
count = tmp;
}
 /* ロック変数の解放 */
pthread_mutex_unlock(&mutex);
return NULL;
}
int main()
{
 
pthread_t a, b;
pthread_create(&a, NULL, threadA, NULL);
pthread_create(&b, NULL, threadB, NULL);
pthread_join(a, NULL);
pthread_join(b, NULL);
printf("count = %d\n", count);

 
return 0;
}
