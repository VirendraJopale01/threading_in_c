#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* fun(void* args){
	pthread_t thisTh=pthread_self();
	printf("Id is %lu",(unsigned long)thisTh);
	return NULL;
}
int main(){
    pthread_t th1;
    pthread_create(&th1,NULL,fun,NULL);
    pthread_join(th1,NULL);
 
	return 0;
}
