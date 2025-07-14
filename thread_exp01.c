#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sched.h>
void * printPlus(void* args){
	for(int i=0;i<200;i++){
		printf("+");
		usleep(500);
	}
	return NULL;
}

void * printMin(void* args){
	for(int i=0;i<200;i++){
		printf("-");
		usleep(500);
	}
}

int main(){
   pthread_t t1,t2;
   pthread_create(&t1,NULL,printPlus,NULL);
   pthread_create(&t2,NULL,printMin,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
    printf("Start\n");
	return 0;
}
