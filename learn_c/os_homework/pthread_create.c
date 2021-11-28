#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void* myThread1(void)
{
		for (int i = 0; i < 10; i++) {
				printf("11111111\n");
				sleep(1);
		}
		return NULL;
}
void* myThread2(void)
{
		for (int i = 0; i < 10; i++) {
				printf("22222222323325325\n");
				sleep(1);
		}
		return NULL;
}

int main(int argc, char* argv[])
{
		int i = 0;
		int ret = 0;
		pthread_t id1, id2;
		ret = pthread_create(&id1, NULL, (void*)myThread1, NULL);
		if (ret) {
				printf("Create pthread error 1\n");
				return -1;
		}
		ret = pthread_create(&id2, NULL, (void*)myThread2, NULL);
		if (ret) {
				printf("Create pthread error 2\n");
				return -1;
		}

		pthread_join(id1, NULL);
		pthread_join(id2, NULL);

		return 0;
}
