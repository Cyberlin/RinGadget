#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 10

pthread_t thread[2];
pthread_mutex_t mut;
int num = 0, i;
void* thread1()
{
		printf("Thread1: I am thread1\n");
		for (int i = 0; i < MAX; i++) {
				pthread_mutex_lock(&mut);
				printf("thread1: number =%d\n", num);
				num++;
				pthread_mutex_unlock(&mut);
				sleep(1);
		}
		pthread_exit(NULL);
}
void* thread2()
{
		printf("thread2: I am thread 2\n");
		for (int i = 0; i < MAX; i++) {
				pthread_mutex_lock(&mut);
				printf("thread2: number =%d\n", num);
				num++;
				pthread_mutex_unlock(&mut);
				sleep(1);
		}
		pthread_exit(NULL);
}
void thread_create(void)
{
		int temp;
		memset(&thread, 0, sizeof(thread));
		if ((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0) {
				printf("create thread1 failed!\n");
		} else {
				printf("create thread1 success\n");
		}
		if ((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0) {
				printf("create thread2 failed\n");
		} else {
				printf("create thread2 success\n");
		}
}
void thread_wait(void)
{
		if (thread[0] != 0) {
				pthread_join(thread[0], NULL);
				printf("thread 1 end!\n");
		}
		if (thread[1] != 0) {
				pthread_join(thread[1], NULL);
				printf("thread 2 end!\n");
		}
}
int main()
{
		pthread_mutex_init(&mut, NULL);
		printf("I am main,I am creating thread\n");
		thread_create();
		printf("I am main, I am waiting thread end\n");
		thread_wait();
		return 0;
}
