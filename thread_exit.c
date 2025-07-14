#include<stdio.h>
#include<pthread.h>
void* fun(void* args){
	printf("I am thread");

	pthread_exit(NULL);
	printf("Will not run");
	return NULL;
}
int main(){
   pthread_t th1;
   pthread_create(&th1,NULL,fun,NULL);
   pthread_join(th1,NULL);
	return 0;
}
