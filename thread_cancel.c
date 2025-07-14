#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void* myFun(void * args){
while(1){
	printf("Hii");
	sleep(1);
}

	return NULL;
}
int main(){

   pthread_t th1;
   pthread_create(&th1,NULL,myFun,NULL);
   sleep(5);
   pthread_cancel(th1);
   pthread_join(th1,NULL);
   printf("THread Ending");
	return 0;
}
