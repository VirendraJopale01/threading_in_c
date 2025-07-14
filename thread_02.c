#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
//return from thread
void* myturn(void* args){
int *ptr=(int *)malloc(sizeof(int));
*ptr=5;
	for(int i=0;i<*ptr;i++){
		sleep(1);
		printf("My turn %d\n",i);
		
	}
	return ptr;
}
void yourturn( ){
	for(int i=0;i<4;i++){
		sleep(2);
		printf("Your turn %d\n",i);
	}
	return;
}
int main(){
 // myturn();
 // yourturn();
 pthread_t p1;
 int v=4;
 pthread_create(&p1,NULL,myturn,NULL);
// pthread_create(&p2,NULL,yourturn,NULL);
int *res;
yourturn();
pthread_join(p1,(void **)&res);
printf("Result after return form thread %d\n",*res);
	return 0;
}
