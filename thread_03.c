#include<stdio.h>
#include<stdint.h>
#include<pthread.h>

#define BIG 1000000000UL
uint32_t counter=0;
pthread_mutex_t lock= PTHREAD_MUTEX_INITIALIZER;
void* count_to_big(void * args){
	for(uint32_t i=0;i<BIG;i++){
	pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(){
//	count_to_big();
pthread_t t;
	pthread_create(&t,NULL,count_to_big,NULL);
	count_to_big(NULL);
	pthread_join(t,NULL);
	printf("Done , Counter=%u\n",counter);
}
