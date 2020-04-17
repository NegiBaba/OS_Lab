#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s;
int counter=5;
//pthread_mutex_t L1=PTHREAD_MUTEX_INITIALIZER;
void* f1()
{ int a;
// pthread_mutex_lock(&L1);
a=counter;
a=a+1;
sleep(1);
counter=a;
sem_post(&s);
printf("The value of counter is %d\n", counter);
}
void* f2()
{
int a;
sem_wait(&s);
a=counter;
a=a-1;
sleep(1);
counter=a;
sem_post(&s);
printf("The value of counter is %d\n", counter);
}
int main()
{
pthread_t t1,t2;
//pthread_mutex_init(&L1,NULL);
pthread_create(&t1,NULL,f1,NULL);
pthread_create(&t2,NULL,f2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("The value of counter is %d\n",counter);
}
