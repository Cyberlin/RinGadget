#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
		for (int i = 0; i < 10; i++) {
				sleep(1);
				printf("Printing GeeksQuiz from Thread \n");
		}
		return NULL;
}
void* colin(void* arg){
		for(int i =0;i<5;i++){
				sleep(1);
				printf("I am colin\n");
		}
		return NULL;
}
int main()
{
		pthread_t thread_id,colin_id;
		printf("Before Thread\n");
		pthread_create(&thread_id, NULL, myThreadFun, NULL);
		pthread_create(&colin_id, NULL, colin, NULL);
		pthread_join(thread_id, NULL);
		printf("After Thread\n");
		exit(0);
}
