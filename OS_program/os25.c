#include <pthread.h>
#define N 5

static int p=0;
static int m= 0;

pthread_t a, b;

int buffer[N];
/* リングバッファ */
int inptr = 0, outptr = 0;
int count = 0;
/* バッファに入っているデータの数 */
/* 条件変数の宣言 */
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; /* ロック変数の宣言 */
void producer()
/* 生産者 */
{
int data;
for (;;) {
data = produce(); /* データを作る */
pthread_mutex_lock(&lock);
while (count >= N) pthread_cond_wait(&full, &lock); /* 満杯なら待つ */
buffer[inptr] = data;
inptr = (inptr + 1) % N;
count = count + 1;
pthread_cond_signal(&empty); /* バッファにデータを追加したことを通知 */
pthread_mutex_unlock(&lock);
}
}
void consumer()
/* 消費者 */
{
int data;
for (;;) {
pthread_mutex_lock(&lock);
while (count == 0) pthread_cond_wait(&empty, &lock);
/* 空なら待つ */
data = buffer[outptr];
outptr = (outptr + 1) % N;
count = count - 1;
pthread_cond_signal(&full);
/* バッファに空きができたことを通知 */
pthread_mutex_unlock(&lock);
consume(data);
/* データを消費 */
}
}
int produce(){
  p++;
  return p;
}
int consume(int a){
  m+=a;
  return m;
}

int main(){
  
  pthread_create(&a, NULL, producer, NULL);
  pthread_create(&b, NULL, consumer, NULL);
  printf("%d",m);
}
